#include "./includes/TestSelecter.hpp"
#include <iostream>
#include <signal.h>
#include <unistd.h>
#include <vector>

namespace Suppresser {
t_unit_tests func_test_table[] = {
	{"\0", NULL, TEST_FAILED, VECTOR}
};
}

std::list<t_unit_subtests> UnitTester::_func_subtest_table;
const char*                UnitTester::_current_func_name;
t_stl_types                UnitTester::_current_func_type;

volatile int g_pid = 0;

std::string _stl_type_to_string(t_stl_types type);

UnitTester::UnitTester() : _cnt_success(0), _cnt_total(0) {}

UnitTester::~UnitTester() {}

void UnitTester::_load_test(t_unit_tests* func_test_table, const std::vector<std::string>& lst)
{
	std::string test_name;

	for (size_t i = 0; func_test_table[i].func_name[0]; ++i) {
		_current_func_name = func_test_table[i].func_name;
		_current_func_type = func_test_table[i].type;

		test_name = _current_func_name;
		test_name = test_name.substr((_stl_type_to_string(_current_func_type) + '_').length());

		if (lst.empty() || std::find(lst.begin(), lst.end(), test_name) != lst.end()) {
			func_test_table[i].func_test_ptr();
		}
	}
}

void UnitTester::load_subtest(void (*func)(void), char* func_name)
{
	t_unit_subtests func_subtest;

	func_subtest.func_name     = _current_func_name;
	func_subtest.subtest_name  = func_name;
	func_subtest.func_test_ptr = func;
	func_subtest.type          = _current_func_type;
	_func_subtest_table.push_back(func_subtest);
}

void UnitTester::assert_(bool evaluate)
{
	if (evaluate == false)
		exit(TEST_FAILED);
}

void UnitTester::assert_diff_(bool evaluate)
{
	if (evaluate == false)
		exit(TEST_DIFF);
}

void set_explanation(int* fds)
{
	close(fds[1]);
	dup2(fds[0], STDIN_FILENO);
	Log::_current_explanation = "";
	std::string line;
	while (std::getline(std::cin, line, '\n')) {
		if (!line.empty())
			Log::_current_explanation = line;
	}
	close(fds[0]);
	std::cin.clear();
	std::clearerr(stdin);
}

void UnitTester::_set_test_result(t_unit_subtests& current_test, int wstatus)
{
	if (WIFEXITED(wstatus)) {
		current_test.result = static_cast<t_test_status>(WEXITSTATUS(wstatus));
		return;
	}
	if (WIFSIGNALED(wstatus)) {
		switch (WTERMSIG(wstatus)) {
		case SIGILL:
			current_test.result = TEST_ILL;
			return;
		case SIGABRT:
			current_test.result = TEST_ABORT;
			return;
		case SIGBUS:
			current_test.result = TEST_BUS;
			return;
		case SIGSEGV:
			current_test.result = TEST_SEGV;
			return;
		case SIGKILL:
			current_test.result = TEST_TIMEOUT;
			return;
		default:
			current_test.result = TEST_UNEXPECTED;
			std::cerr << "signal: " << WTERMSIG(wstatus) << std::endl;
		}
	}
}

void _timeout_handler(int val)
{
	(void)val;
	kill(g_pid, SIGKILL);
}

void UnitTester::_sandbox(t_unit_subtests& current_test)
{
	int   fds[2];
	pid_t pid;
	int   wstatus;

	if (pipe(fds))
		throw std::runtime_error("pipe");
	pid = fork();
	if (pid < 0)
		throw std::runtime_error("fork");
	if (pid == 0) {
		close(fds[0]);
		dup2(fds[1], STDOUT_FILENO);
		current_test.func_test_ptr();
		exit(EXIT_SUCCESS);
	} else {
		g_pid = pid;
		signal(SIGALRM, _timeout_handler);
		alarm(1);
		wait(&wstatus);
		_set_test_result(current_test, wstatus);
		set_explanation(fds);
	}
}

std::string UnitTester::_stl_type_to_string(t_stl_types type)
{
	switch (type) {
	case VECTOR:
		return "vector";
	case MAP:
		return "map";
	case STACK:
		return "stack";
	case SET:
		return "set";
	default:
		break;
	}
	return "";
}

void UnitTester::_print_subheader(const std::string& header)
{
	int fill_width = 42 - header.length();
	int leftside   = fill_width / 2;

	std::cout << std::setfill('=');
	std::cout << std::setw(leftside) << std::right << " ";
	std::cout << header;
	std::cout << std::setw(fill_width - leftside) << std::left << " " << std::flush;
	std::cout << std::setfill(' ');
}

void UnitTester::_display_result(t_unit_subtests& current_test)
{
	static const char* prev_func_name;
	static t_stl_types type;
	std::string        type_stirng = _stl_type_to_string(current_test.type);

	if (type != current_test.type) {
		if (type)
			std::cout << "\n" << std::endl;
		_print_subheader(type_stirng);
		type = current_test.type;
	}
	if (!prev_func_name || strcmp(prev_func_name, current_test.func_name)) {
		std::cout << std::endl;

		std::string func_name(current_test.func_name);
		std::cout << std::left << std::setw(k_max_subfunc_name)
		          << func_name.substr((type_stirng + '_').length()) << ": ";
		prev_func_name = current_test.func_name;
	}

	switch (current_test.result) {
	case TEST_SUCCESS:
		std::cout << COLOR_SUCCESS "[OK] " COLOR_CLEAR;
		_cnt_success += 1;
		break;
	case TEST_FAILED:
		std::cout << COLOR_FAILED "[KO] " COLOR_CLEAR;
		break;
	case TEST_DIFF:
		std::cout << COLOR_CLEAR "[DIFF] " COLOR_CLEAR;
		_cnt_total -= 1;
		break;
	case TEST_ILL:
		std::cout << COLOR_FAILED "[ILLIGAL] " COLOR_CLEAR;
		break;
	case TEST_ABORT:
		std::cout << COLOR_FAILED "[ABORT] " COLOR_CLEAR;
		break;
	case TEST_BUS:
		std::cout << COLOR_FAILED "[BUS] " COLOR_CLEAR;
		break;
	case TEST_SEGV:
		std::cout << COLOR_FAILED "[SEGV] " COLOR_CLEAR;
		break;
	case TEST_TIMEOUT:
		std::cout << COLOR_WARNING "[TIMEOUT] " COLOR_CLEAR;
		break;
	case TEST_UNEXPECTED:
		std::cout << COLOR_FAILED "[???] " COLOR_CLEAR;
		break;
	}
	std::cout << std::flush;
}

void UnitTester::_display_total()
{
	if (_cnt_total == 0) {
		std::cerr << "ERROR: No tests found" << std::endl;
		return;
	}
	std::cout << COLOR_BORD << "\n\n[RESULT] ";
	if (_cnt_success == _cnt_total)
		std::cout << COLOR_SUCCESS;
	else
		std::cout << COLOR_FAILED;
	std::cout << _cnt_success << "/" << _cnt_total << COLOR_CLEAR;

	int score_persentage = 100 * _cnt_success / _cnt_total;
	std::cout << " tests passed (" << COLOR_BORD << score_persentage << "%" << COLOR_CLEAR << ")"
	          << std::endl;
}

int UnitTester::run_tests(void)
{
	std::list<t_unit_subtests>::iterator current = _func_subtest_table.begin();
	std::list<t_unit_subtests>::iterator it_end  = _func_subtest_table.end();

	for (; current != it_end; ++current) {
		_sandbox(*current);
		_display_result(*current);
		_log.write_to_logfile(*current);
		_cnt_total += 1;
	}
	_display_total();
	if (_cnt_success == _cnt_total)
		return (0);
	return (1);
}

void UnitTester::load_tests(int ac, char** av)
{
	t_stl_types              stl = NONE;
	std::string              argv;
	std::vector<std::string> lst;

	for (int i = 1; i < ac; ++i) {
		argv = av[i];
		if (argv == "vector") {
			stl = VECTOR;
		} else if (argv == "map") {
			stl = MAP;
		} else if (argv == "stack") {
			stl = STACK;
		} else if (argv == "set") {
			stl = SET;
		} else {
			lst.push_back(argv);
		}
	}
	switch (stl) {
	case VECTOR:
		_load_test(VectorTest::func_test_table, lst);
		break;
	case MAP:
		_load_test(MapTest::func_test_table, lst);
		break;
	case STACK:
		_load_test(StackTest::func_test_table, lst);
		break;
	case SET:
		_load_test(SetTest::func_test_table, lst);
		break;
	default:
		_load_test(VectorTest::func_test_table, lst);
		_load_test(MapTest::func_test_table, lst);
		_load_test(StackTest::func_test_table, lst);
		_load_test(SetTest::func_test_table, lst);
	}
}
