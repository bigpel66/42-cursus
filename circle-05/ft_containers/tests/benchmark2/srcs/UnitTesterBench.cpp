#include "./includes/UnitTester.hpp"
#include <cmath>
#include <ctime>
#include <iostream>
#include <time.h>

void UnitTester::_bench_sandbox(t_unit_subtests& current_test)
{
	clock_t time;

	time = clock();
	current_test.func_test_ptr();
	time                = clock() - time;
	current_test.result = time;
}

float _calc_time_in_msec(clock_t time)
{
	return time / (float)CLOCKS_PER_SEC * 1000;
}

void _display_time(float time_in_sec, bool left)
{
	int precision = 8;
	int width     = precision * 2;

	if (left) {
		std::cout << std::left;
	} else {
		std::cout << std::right;
	}
	std::cout << std::setw(width) << std::setprecision(precision) << time_in_sec;
}

void _display_time(std::string type)
{
	int precision = 8;
	int width     = precision * 2;

	if (type == "std") {
		std::cout << std::left;
	} else {
		std::cout << std::right;
	}
	std::cout << std::setw(width) << std::setprecision(precision) << type;
}

void UnitTester::_display_percentage(float std, float ft)
{
	double times = ft / std * 100;
	times        = floor(times) / 100;

	std::cout << " | (x " << std::left << std::setw(4) << times << ") ";
	if (times < k_max_times_allowed) {
		std::cout << COLOR_SUCCESS "[OK] " COLOR_CLEAR;
		_cnt_success += 1;
	} else {
		std::cout << COLOR_FAILED "[KO] " COLOR_CLEAR;
	}
}

void UnitTester::_display_funcname(std::string func_name, std::string type_stirng)
{
	func_name = func_name.substr((type_stirng + '_').length());

	int width = k_max_subfunc_name + 2 - func_name.length();
	std::cout << ":";
	std::cout << std::setw(width / 2) << " " << func_name << std::setw(width / 2 + (width % 2))
	          << " ";
	std::cout << ":";
}

void UnitTester::_print_bench_subheader(const std::string& type_string)
{
	std::cout << std::setfill('=') << std::setw(k_table_width) << "=" << std::setfill(' ');
	std::cout << std::endl;

	_display_time("std");
	_display_funcname(type_string + "_" + type_string, type_string);
	_display_time("ft");

	std::cout << std::endl;
	std::cout << std::setfill('-') << std::setw(k_table_width) << "-" << std::setfill(' ');
}

void UnitTester::_display_bench_result(t_unit_subtests& current_test)
{
	static const char* prev_func_name;
	static t_stl_types type;
	std::string        type_string = _stl_type_to_string(current_test.type);
	static float       std_time;
	float              ft_time;

	if (type != current_test.type) {
		if (type)
			std::cout << "\n" << std::endl;
		_print_bench_subheader(type_string);

		type = current_test.type;
	}
	if (!prev_func_name || strcmp(prev_func_name, current_test.func_name)) {
		std::cout << std::endl;
		std_time = _calc_time_in_msec(current_test.result);
		_display_time(std_time, true);
		_display_funcname(current_test.func_name, type_string);
		prev_func_name = current_test.func_name;
	} else {
		ft_time = _calc_time_in_msec(current_test.result);
		_display_time(ft_time, false);
		_display_percentage(std_time, ft_time);
	}
	std::cout << std::flush;
}

int UnitTester::run_bench_tests(void)
{
	std::list<t_unit_subtests>::iterator current = _func_subtest_table.begin();
	std::list<t_unit_subtests>::iterator it_end  = _func_subtest_table.end();

	for (; current != it_end; ++current) {
		_bench_sandbox(*current);
		_display_bench_result(*current);
		_cnt_total += 1;
	}
	_cnt_total /= 2;
	_display_total();
	if (_cnt_success == _cnt_total)
		return (0);
	return (1);
}
