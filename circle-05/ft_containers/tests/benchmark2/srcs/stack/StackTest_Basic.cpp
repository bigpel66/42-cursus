#include "../includes/Log.hpp"
#include "../includes/StackTest.hpp"
#include "../includes/UnitTester.hpp"
#include <algorithm>
#include <iostream>
#include <list>
#include <stack>

namespace StackTest {

// -------------------------------------------------------------------------- //
//                                 constructor                                //
// -------------------------------------------------------------------------- //

void _stack_constructor_default()
{
	set_explanation_("result differs from std behavior");
	ft::stack<int>  ft;
	std::stack<int> std;
	_compare_stacks(ft, std);
}

void _stack_constructor_copy()
{
	set_explanation_("copy result differs from std behavior");
	ft::stack<int>  ft;
	std::stack<int> std;
	_set_compare_stacks(ft, std);

	ft::stack<int>  ft_cpy(ft);
	std::stack<int> std_cpy(std);
	_compare_stacks(ft_cpy, std_cpy);
}

void stack_constructor()
{
	load_subtest_(_stack_constructor_default);
	load_subtest_(_stack_constructor_copy);
}

// -------------------------------------------------------------------------- //
//                                 destructor                                 //
// -------------------------------------------------------------------------- //

void _stack_destructor()
{
	set_explanation_("destructor cruses");
	{
		ft::stack<int> ft;
	}
}

void stack_destructor()
{
	load_subtest_(_stack_destructor);
}

// -------------------------------------------------------------------------- //
//                                  operator=                                 //
// -------------------------------------------------------------------------- //

void _stack_assignemnt_operator_basic()
{
	set_explanation_("copy behavior changes original or new stack");
	ft::stack<int>  ft;
	std::stack<int> std;
	_set_compare_stacks(ft, std);

	ft::stack<int>  ft_copy;
	std::stack<int> std_copy;
	ft_copy  = ft;
	std_copy = std;
	_compare_stacks(ft, std);
	_compare_stacks(ft_copy, std_copy);
}

void stack_assignment_operator()
{
	load_subtest_(_stack_assignemnt_operator_basic);
}

} // namespace StackTest
