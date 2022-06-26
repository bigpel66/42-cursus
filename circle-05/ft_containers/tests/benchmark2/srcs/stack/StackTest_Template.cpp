#include "../includes/Log.hpp"
#include "../includes/StackTest.hpp"
#include "../includes/UnitTester.hpp"
#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <stack>

namespace StackTest {

/* -------------------------------------------------------------------------- */
/*                                 std::deque                                 */
/* -------------------------------------------------------------------------- */

void _stack_std_deque()
{
	ft::stack<int, std::deque<int> > deque_stack;

	int size = 42;
	for (int i = 0; i < size; ++i) {
		deque_stack.push(i);
	}
	UnitTester::assert_(deque_stack.top() == size - 1);
}

void stack_std_deque()
{
	load_subtest_(_stack_std_deque);
}

/* -------------------------------------------------------------------------- */
/*                                  std::list                                 */
/* -------------------------------------------------------------------------- */

void _stack_std_list()
{
	ft::stack<int, std::list<int> > list_stack;

	int size = 42;
	for (int i = 0; i < size; ++i) {
		list_stack.push(i);
	}
	UnitTester::assert_(list_stack.top() == size - 1);
}

void stack_std_list()
{
	load_subtest_(_stack_std_list);
}

} // namespace StackTest
