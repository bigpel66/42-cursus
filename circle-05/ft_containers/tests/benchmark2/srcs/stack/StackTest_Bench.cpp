#include "../includes/StackTest.hpp"
#include "../includes/UnitTester.hpp"
#include <stack>

namespace StackTest {

/* -------------------------------------------------------------------------- */
/*                         benchmark copy_constructor                         */
/* -------------------------------------------------------------------------- */
void _bench_stack_copy_constructor_ft()
{
	int            size = 10000;
	ft::stack<int> ft   = _set_stack(size);
	ft::stack<int> copy(ft);
}

void _bench_stack_copy_constructor_std()
{
	int                                size = 10000;
	std::stack<int, std::vector<int> > std  = _set_stack_std(size);
	std::stack<int, std::vector<int> > copy(std);
}

void bench_stack_copy_constructor()
{
	load_subtest_(_bench_stack_copy_constructor_std);
	load_subtest_(_bench_stack_copy_constructor_ft);
}

/* -------------------------------------------------------------------------- */
/*                             benchmark operator=                            */
/* -------------------------------------------------------------------------- */
void _bench_stack_assignment_operator_ft()
{
	int            size = 10000;
	ft::stack<int> ft   = _set_stack(size);
	ft::stack<int> copy;
	copy = ft;
}

void _bench_stack_assignment_operator_std()
{
	int                                size = 10000;
	std::stack<int, std::vector<int> > std  = _set_stack_std(size);
	std::stack<int, std::vector<int> > copy;
	copy = std;
}

void bench_stack_assignment_operator()
{
	load_subtest_(_bench_stack_assignment_operator_std);
	load_subtest_(_bench_stack_assignment_operator_ft);
}

/* -------------------------------------------------------------------------- */
/*                               benchmark push                               */
/* -------------------------------------------------------------------------- */
void _bench_stack_push_ft()
{
	ft::stack<int> ft;

	for (int i = 0; i < 10000; ++i) {
		ft.push(i);
	}
}
void _bench_stack_push_std()
{
	std::stack<int, std::vector<int> > std;

	for (int i = 0; i < 10000; ++i) {
		std.push(i);
	}
}

void bench_stack_push()
{
	load_subtest_(_bench_stack_push_std);
	load_subtest_(_bench_stack_push_ft);
}

/* -------------------------------------------------------------------------- */
/*                                benchmark pop                               */
/* -------------------------------------------------------------------------- */
void _bench_stack_pop_ft()
{
	ft::stack<int> ft;

	for (int i = 0; i < 10000; ++i) {
		ft.push(i);
	}
	for (int i = 0; i < 10000; ++i) {
		ft.pop();
	}
}

void _bench_stack_pop_std()
{
	std::stack<int, std::vector<int> > std;

	for (int i = 0; i < 10000; ++i) {
		std.push(i);
	}
	for (int i = 0; i < 10000; ++i) {
		std.pop();
	}
}

void bench_stack_pop()
{
	load_subtest_(_bench_stack_pop_std);
	load_subtest_(_bench_stack_pop_ft);
}

} // namespace StackTest
