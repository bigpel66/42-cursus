#ifndef STACKTEST_HPP
#define STACKTEST_HPP

#include "./UnitTester.hpp"
#include <iostream>
#include <vector>

#if STD
#include <stack>
namespace ft = std;
#else
#include "../../../../includes/stack.hpp"
#endif

#define TABLE_SIZE 0xF00
typedef struct s_unit_tests t_unit_tests;

namespace StackTest {

void stack_constructor();
void stack_destructor();
void stack_assignment_operator();

/* Element access */
void stack_top();

/* Capacity */
void stack_empty();
void stack_size();

/* Modifiers */
void stack_push();
void stack_pop();

/* Non-member functions */
void stack_operator_e();
void stack_operator_ne();
void stack_operator_l();
void stack_operator_le();
void stack_operator_g();
void stack_operator_ge();

/* Other Templates */
void stack_std_deque();
void stack_std_list();

/* Benchmark */
void bench_stack_copy_constructor();
void bench_stack_assignment_operator();
void bench_stack_push();
void bench_stack_pop();

extern t_unit_tests func_test_table[TABLE_SIZE];

void                               _set_int_array(int* array, int size = 12, bool accend = false);
ft::stack<int>                     _assign_stack(int size = 6, bool accend = false);
ft::stack<int>                     _set_stack(int size = 6, bool accend = false);
std::stack<int, std::vector<int> > _set_stack_std(int size = 6, bool accend = false);
ft::stack<char>                    _set_stack_char(size_t size = 6, bool accend = false);
ft::stack<std::string>             _set_stack_string(size_t size = 6, bool random = false);

void _assign_compare_stacks(
    ft::stack<int>& ft_data, std::stack<int>& std_data, int size = 6, bool accend = false);
void _set_compare_stacks(
    ft::stack<int>& ft_data, std::stack<int>& std_data, int size = 6, bool accend = false);

template <class T>
void _compare_stacks(ft::stack<T> ft_stk, std::stack<T> std_stk)
{
	UnitTester::assert_(ft_stk.size() == std_stk.size());

	size_t size = std_stk.size();
	for (size_t i = 0; i < size; ++i) {
		UnitTester::assert_(ft_stk.top() == std_stk.top());
		ft_stk.pop();
		std_stk.pop();
	}
}

template <class T>
void _debug(ft::stack<T>& ft_stk, std::string name = "")
{
	std::cerr << std::endl;
	std::cerr << "[" << name << "] ";
	size_t size = ft_stk.size();
	for (size_t i = 0; i < size; ++i) {
		std::cerr << i << ": " << ft_stk[i] << " ";
	}
	std::cerr << std::endl;
}

} // namespace StackTest

#endif /* STACKTEST_HPP */
