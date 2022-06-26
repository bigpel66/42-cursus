#include "../includes/Log.hpp"
#include "../includes/StackTest.hpp"
#include "../includes/UnitTester.hpp"
#include <algorithm>
#include <iostream>
#include <list>
#include <stack>

namespace StackTest {

/* -------------------------------------------------------------------------- */
/*                                     top                                    */
/* -------------------------------------------------------------------------- */

void _stack_top() {}

void stack_top()
{
	load_subtest_(_stack_top);
}

// -------------------------------------------------------------------------- //
//                                    empty                                   //
// -------------------------------------------------------------------------- //

void _stack_empty_true()
{
	set_explanation_("empty check not working. Really!?");
	ft::stack<int> ft_data = _set_stack(0, true);
	UnitTester::assert_(ft_data.empty() == true);
}

void _stack_empty_false()
{
	set_explanation_("empty check not working. Really!?");
	size_t         size    = 42;
	ft::stack<int> ft_data = _set_stack(size, true);
	UnitTester::assert_(ft_data.empty() == false);
}

void stack_empty()
{
	load_subtest_(_stack_empty_true);
	load_subtest_(_stack_empty_false);
}

// -------------------------------------------------------------------------- //
//                                    size                                    //
// -------------------------------------------------------------------------- //

void _stack_size_zero()
{
	set_explanation_("wrong size returned on size 0");
	ft::stack<int> ft_data = _set_stack(0, true);
	UnitTester::assert_(ft_data.size() == 0);
}

void _stack_size_one()
{
	set_explanation_("wrong size returned on size 1");
	ft::stack<int> ft_data = _set_stack(1, true);
	UnitTester::assert_(ft_data.size() == 1);
}

void _stack_size_more()
{
	set_explanation_("wrong size returned on size more than 1");
	size_t         size    = 42;
	ft::stack<int> ft_data = _set_stack(size, true);
	UnitTester::assert_(ft_data.size() == size);
}

void stack_size()
{
	load_subtest_(_stack_size_zero);
	load_subtest_(_stack_size_one);
	load_subtest_(_stack_size_more);
}

/* -------------------------------------------------------------------------- */
/*                                    push                                    */
/* -------------------------------------------------------------------------- */

void _stack_push_empty()
{
	set_explanation_("added value not correct");
	ft::stack<int> ft;

	int value = 42;
	ft.push(value);
	UnitTester::assert_(ft.top() == value);
}

void _stack_push_one()
{
	set_explanation_("added value not correct");
	int            size = 10;
	ft::stack<int> ft   = _set_stack(size, true);

	int value = 42;
	ft.push(value);
	UnitTester::assert_(ft.top() == value);
}

void _stack_push_compare()
{
	set_explanation_("result differs from std");
	ft::stack<int>  ft;
	std::stack<int> std;
	_set_compare_stacks(ft, std);
	_compare_stacks(ft, std);
}

void stack_push()
{
	load_subtest_(_stack_push_empty);
	load_subtest_(_stack_push_one);
	load_subtest_(_stack_push_compare);
}

/* -------------------------------------------------------------------------- */
/*                                     pop                                    */
/* -------------------------------------------------------------------------- */

void _stack_pop_one()
{
	set_explanation_("size not reduced");
	size_t         size = 10;
	ft::stack<int> ft   = _set_stack(size, true);

	ft.pop();
	UnitTester::assert_(ft.size() == size - 1);
}

void _stack_pop_compare()
{
	set_explanation_("result differs from std");
	size_t          size = 16;
	ft::stack<int>  ft;
	std::stack<int> std;
	_set_compare_stacks(ft, std, size);

	for (size_t i = 0; i < size - 1; ++i) {
		ft.pop();
		std.pop();
		_compare_stacks(ft, std);
	}
}

void stack_pop()
{
	load_subtest_(_stack_pop_one);
	load_subtest_(_stack_pop_compare);
}

} // namespace StackTest
