#include "./includes/UnitTester.hpp"
#include <iostream>

const std::string Log::k_logfile            = "result.log";
std::string       Log::_current_explanation = "";

Log::Log()
{
	_open_logfile();
}

Log::~Log() {}

void Log::set_explanation(std::string explanation)
{
	_current_explanation = explanation;
}

void Log::write_to_logfile(t_unit_subtests& current_test)
{
	static const char* prev_func_name;

	if (current_test.result == TEST_SUCCESS)
		return;
	if (!prev_func_name || strcmp(prev_func_name, current_test.func_name) != 0) {
		_logfile_stream << "[" << current_test.func_name << "]" << std::endl;
		prev_func_name = current_test.func_name;
	}
	std::string display_subtest_name(current_test.subtest_name);
	_logfile_stream << std::left << std::setw(30) << display_subtest_name << ": ";
	if (current_test.result == TEST_DIFF) {
		_logfile_stream << "[DIFF: " << _current_explanation << "]" << std::endl;
	} else {
		_logfile_stream << "[FAIL: " << _current_explanation << "]" << std::endl;
	}
}

void Log::_open_logfile()
{
	_logfile_stream.open(k_logfile, std::ios::out);
	if (!_logfile_stream.good())
		throw std::runtime_error("open");
}
