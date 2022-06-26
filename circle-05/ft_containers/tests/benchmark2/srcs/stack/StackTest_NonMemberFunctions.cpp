#include "../includes/Log.hpp"
#include "../includes/StackTest.hpp"
#include "../includes/UnitTester.hpp"
#include <algorithm>
#include <iostream>
#include <list>
#include <stack>

namespace StackTest {

// -------------------------------------------------------------------------- //
//                                 operator==                                 //
// -------------------------------------------------------------------------- //

void _stack_operator_e_true()
{
	set_explanation_("wrong result on value int");
	int            size_1 = 10;
	int            size_2 = size_1;
	ft::stack<int> ft_1   = _set_stack(size_1, true);
	ft::stack<int> ft_2   = _set_stack(size_2, true);

	UnitTester::assert_((ft_1 == ft_2) == true);
}

void _stack_operator_e_true_empty()
{
	set_explanation_("empty stacks are not equal");
	ft::stack<int> ft_1;
	ft::stack<int> ft_2;

	UnitTester::assert_((ft_1 == ft_2) == true);
}

void _stack_operator_e_false()
{
	set_explanation_("wrong result on size difference");
	int            size_1 = 10;
	int            size_2 = 12;
	ft::stack<int> ft_1   = _set_stack(size_1, true);
	ft::stack<int> ft_2   = _set_stack(size_2, true);

	UnitTester::assert_((ft_1 == ft_2) == false);
}
void _stack_operator_e_false2()
{
	set_explanation_("wrong result on value and size difference");
	int            size_1 = 10;
	int            size_2 = 7;
	ft::stack<int> ft_1   = _set_stack(size_1);
	ft::stack<int> ft_2   = _set_stack(size_2);

	UnitTester::assert_((ft_1 == ft_2) == false);
}

void _stack_operator_e_same()
{
	set_explanation_("stack not same to itself!?");
	int                    size_1 = 10;
	ft::stack<std::string> ft_1   = _set_stack_string(size_1);

	UnitTester::assert_((ft_1 == ft_1) == true);
}

void _stack_operator_e_compare()
{
	set_explanation_("int result differs from std");
	ft::stack<int>  ft_1;
	std::stack<int> std_1;
	_set_compare_stacks(ft_1, std_1);
	ft::stack<int>  ft_2;
	std::stack<int> std_2;
	_set_compare_stacks(ft_2, std_2);

	bool val1 = ft_1 == ft_2;
	UnitTester::assert_(val1 == (std_1 == std_2));
}

void stack_operator_e()
{
	load_subtest_(_stack_operator_e_true);
	load_subtest_(_stack_operator_e_true_empty);
	load_subtest_(_stack_operator_e_false);
	load_subtest_(_stack_operator_e_false2);
	load_subtest_(_stack_operator_e_same);
	load_subtest_(_stack_operator_e_compare);
}

// -------------------------------------------------------------------------- //
//                                 operator!=                                 //
// -------------------------------------------------------------------------- //

void _stack_operator_ne_true()
{
	set_explanation_("wrong result on value std::string");
	int                    size_1 = 2;
	int                    size_2 = 13;
	ft::stack<std::string> ft_1   = _set_stack_string(size_1);
	ft::stack<std::string> ft_2   = _set_stack_string(size_2);

	UnitTester::assert_((ft_1 != ft_2) == true);
}

void _stack_operator_ne_true2()
{
	set_explanation_("wrong result on different content");
	int                    size_1 = 24;
	int                    size_2 = size_1;
	ft::stack<std::string> ft_1   = _set_stack_string(size_1, true);
	ft::stack<std::string> ft_2   = _set_stack_string(size_2, true);

	UnitTester::assert_((ft_1 != ft_2) == true);
}

void _stack_operator_ne_false()
{
	set_explanation_("wrong result on same content");
	int                    size_1 = 24;
	int                    size_2 = size_1;
	ft::stack<std::string> ft_1   = _set_stack_string(size_1);
	ft::stack<std::string> ft_2   = _set_stack_string(size_2);

	UnitTester::assert_((ft_1 != ft_2) == false);
}

void _stack_operator_ne_same()
{
	set_explanation_("stack not same to itself!?");
	int                    size_1 = 10;
	ft::stack<std::string> ft_1   = _set_stack_string(size_1);

	UnitTester::assert_((ft_1 != ft_1) == false);
}

void _stack_operator_ne_compare()
{
	set_explanation_("int result differs from std");
	ft::stack<int>  ft_1;
	std::stack<int> std_1;
	_set_compare_stacks(ft_1, std_1);
	ft::stack<int>  ft_2;
	std::stack<int> std_2;
	_set_compare_stacks(ft_2, std_2);

	bool val1 = ft_1 != ft_2;
	UnitTester::assert_(val1 == (std_1 != std_2));
}

void stack_operator_ne()
{
	load_subtest_(_stack_operator_ne_true);
	load_subtest_(_stack_operator_ne_true2);
	load_subtest_(_stack_operator_ne_false);
	load_subtest_(_stack_operator_ne_same);
	load_subtest_(_stack_operator_ne_compare);
}

// -------------------------------------------------------------------------- //
//                                 operator<                                 //
// -------------------------------------------------------------------------- //

void _stack_operator_l_true()
{
	set_explanation_("char stack size difference not evaluated correctly");
	int             size = 10;
	ft::stack<char> ft_0 = _set_stack_char(size, true);
	ft::stack<char> ft_1 = _set_stack_char(size, true);

	ft_0.pop();
	// _debug(ft_0, "0");
	// _debug(ft_1, "1");
	UnitTester::assert_((ft_0 < ft_1) == true);
}

void _stack_operator_l_false()
{
	set_explanation_("char stack size difference not evaluated correctly");
	int             size  = 10;
	int             size2 = 1;
	ft::stack<char> ft_0  = _set_stack_char(size, true);
	ft::stack<char> ft_1  = _set_stack_char(size2, true);

	// _debug(ft_0, "0");
	// _debug(ft_1, "1");
	UnitTester::assert_((ft_0 < ft_1) == false);
}

void _stack_operator_l_same()
{
	set_explanation_("equal int values not evaluated correctly");
	int            size = 10;
	ft::stack<int> ft   = _set_stack(size, true);

	UnitTester::assert_((ft < ft) == false);
}

void _stack_operator_l_compare()
{
	set_explanation_("int result differs from std");
	ft::stack<int>  ft_1;
	std::stack<int> std_1;
	_set_compare_stacks(ft_1, std_1);
	ft::stack<int>  ft_2;
	std::stack<int> std_2;
	_set_compare_stacks(ft_2, std_2);

	bool val1 = ft_1 < ft_2;
	bool val2 = ft_2 < ft_1;
	UnitTester::assert_(val1 == (std_1 < std_2));
	UnitTester::assert_(val2 == (std_2 < std_1));
}

void stack_operator_l()
{
	load_subtest_(_stack_operator_l_true);
	load_subtest_(_stack_operator_l_false);
	load_subtest_(_stack_operator_l_same);
	load_subtest_(_stack_operator_l_compare);
}

// -------------------------------------------------------------------------- //
//                                 operator<=                                 //
// -------------------------------------------------------------------------- //

void _stack_operator_le_true()
{
	set_explanation_("std::string stack size difference not evaluated correctly");
	int                    size = 10;
	ft::stack<std::string> ft_0 = _set_stack_string(size, false);
	ft::stack<std::string> ft_1 = _set_stack_string(size, false);

	ft_0.pop();
	// _debug(ft_0, "0");
	// _debug(ft_1, "1");
	UnitTester::assert_((ft_0 <= ft_1) == true);
}

void _stack_operator_le_false()
{
	set_explanation_("char stack size difference not evaluated correctly");
	int             size_1 = 0;
	int             size_2 = 12;
	ft::stack<char> ft_1   = _set_stack_char(size_1, true);
	ft::stack<char> ft_2   = _set_stack_char(size_2, true);

	UnitTester::assert_((ft_2 <= ft_1) == false);
}

void _stack_operator_le_same()
{
	set_explanation_("equal std::string values not evaluated correctly");
	int                    size = 10;
	ft::stack<std::string> ft   = _set_stack_string(size, true);

	UnitTester::assert_((ft <= ft) == true);
}

void _stack_operator_le_compare()
{
	set_explanation_("int result differs from std");
	ft::stack<int>  ft_1;
	std::stack<int> std_1;
	_set_compare_stacks(ft_1, std_1);
	ft::stack<int>  ft_2;
	std::stack<int> std_2;
	_set_compare_stacks(ft_2, std_2);

	bool val1 = ft_1 <= ft_2;
	bool val2 = ft_2 <= ft_1;
	UnitTester::assert_(val1 == (std_1 <= std_2));
	UnitTester::assert_(val2 == (std_2 <= std_1));
}

void stack_operator_le()
{
	load_subtest_(_stack_operator_le_true);
	load_subtest_(_stack_operator_le_false);
	load_subtest_(_stack_operator_le_same);
	load_subtest_(_stack_operator_le_compare);
}

// -------------------------------------------------------------------------- //
//                                 operator>                                  //
// -------------------------------------------------------------------------- //

void _stack_operator_g_true()
{
	set_explanation_("char stack size difference not evaluated correctly");
	int             size_1 = 21;
	int             size_2 = 12;
	ft::stack<char> ft_1   = _set_stack_char(size_1, true);
	ft::stack<char> ft_2   = _set_stack_char(size_2, true);

	UnitTester::assert_((ft_1 > ft_2) == true);
}

void _stack_operator_g_false()
{
	set_explanation_("char stack size difference not evaluated correctly");
	int             size = 12;
	ft::stack<char> ft_1 = _set_stack_char(size, false);
	ft::stack<char> ft_2 = ft_1;

	ft_1.pop();
	// _debug(ft_1, "1");
	// _debug(ft_2, "2");
	UnitTester::assert_((ft_1 > ft_2) == false);
}

void _stack_operator_g_same()
{
	set_explanation_("equal std::string values not evaluated correctly");
	int                    size = 10;
	ft::stack<std::string> ft   = _set_stack_string(size, true);

	UnitTester::assert_((ft > ft) == false);
}

void _stack_operator_g_compare()
{
	set_explanation_("int result differs from std");
	ft::stack<int>  ft_1;
	std::stack<int> std_1;
	_set_compare_stacks(ft_1, std_1);
	ft::stack<int>  ft_2;
	std::stack<int> std_2;
	_set_compare_stacks(ft_2, std_2);

	bool val1 = ft_1 > ft_2;
	bool val2 = ft_2 > ft_1;
	UnitTester::assert_(val1 == (std_1 > std_2));
	UnitTester::assert_(val2 == (std_2 > std_1));
}

void stack_operator_g()
{
	load_subtest_(_stack_operator_g_true);
	load_subtest_(_stack_operator_g_false);
	load_subtest_(_stack_operator_g_same);
	load_subtest_(_stack_operator_g_compare);
}

// -------------------------------------------------------------------------- //
//                                 operator>=                                 //
// -------------------------------------------------------------------------- //

void _stack_operator_ge_true()
{
	set_explanation_("std::string stack size difference not evaluated correctly");
	ft::stack<std::string> ft_1 = _set_stack_string();
	ft::stack<std::string> ft_2 = ft_1;

	std::string value = "apple";
	ft_1.push(value);
	// _debug(ft_1, "1");
	// _debug(ft_2, "2");
	UnitTester::assert_((ft_1 >= ft_2) == true);
}

void _stack_operator_ge_false()
{
	set_explanation_("std::string stack size difference not evaluated correctly");
	int                    size = 12;
	ft::stack<std::string> ft_1 = _set_stack_string(size, false);
	ft::stack<std::string> ft_2 = ft_1;

	ft_1.pop();
	// _debug(ft_1, "1");
	// _debug(ft_2, "2");
	UnitTester::assert_((ft_1 >= ft_2) == false);
}

void _stack_operator_ge_same()
{
	set_explanation_("equal int values not evaluated correctly");
	int            size = 42;
	ft::stack<int> ft   = _set_stack(size);

	UnitTester::assert_((ft >= ft) == true);
}

void _stack_operator_ge_compare()
{
	set_explanation_("int result differs from std");
	ft::stack<int>  ft_1;
	std::stack<int> std_1;
	_set_compare_stacks(ft_1, std_1);
	ft::stack<int>  ft_2;
	std::stack<int> std_2;
	_set_compare_stacks(ft_2, std_2);

	bool val1 = ft_1 >= ft_2;
	bool val2 = ft_2 >= ft_1;
	UnitTester::assert_(val1 == (std_1 >= std_2));
	UnitTester::assert_(val2 == (std_2 >= std_1));
}

void stack_operator_ge()
{
	load_subtest_(_stack_operator_ge_true);
	load_subtest_(_stack_operator_ge_false);
	load_subtest_(_stack_operator_ge_same);
	load_subtest_(_stack_operator_ge_compare);
}

} // namespace StackTest
