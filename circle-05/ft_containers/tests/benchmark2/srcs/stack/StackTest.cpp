#include "../includes/StackTest.hpp"
#include "../includes/Log.hpp"
#include "../includes/UnitTester.hpp"
#include <algorithm>
#include <iostream>
#include <list>
#include <stack>

namespace StackTest {

#define FAIL TEST_FAILED

#ifdef BENCH
t_unit_tests func_test_table[] = {
	{   "stack_copy_constructor",    bench_stack_copy_constructor, FAIL, STACK},
	{"stack_assignment_operator", bench_stack_assignment_operator, FAIL, STACK},
	{	           "stack_push",                bench_stack_push, FAIL, STACK},
    {                "stack_pop",                 bench_stack_pop, FAIL, STACK},
 // ------------------- Terminater (Do not comment out) ------------------ //
	{	                   "\0",	                        NULL, FAIL, STACK}
};
#else
t_unit_tests func_test_table[] = {
	{	    "stack_constructor",         stack_constructor, FAIL, STACK},
	{	     "stack_destructor",          stack_destructor, FAIL, STACK},
	{"stack_assignment_operator", stack_assignment_operator, FAIL, STACK},
 // --------------------------- Element access --------------------------- //
	{	            "stack_top",                 stack_top, FAIL, STACK},
 // ------------------------------ Capacity ----------------------------- //
	{	          "stack_empty",               stack_empty, FAIL, STACK},
    {               "stack_size",                stack_size, FAIL, STACK},
 // ------------------------------ Modifiers ----------------------------- //
	{	           "stack_push",                stack_push, FAIL, STACK},
    {                "stack_pop",                 stack_pop, FAIL, STACK},
 // ------------------------ Non-member functions ------------------------ //
	{	     "stack_operator_e",          stack_operator_e, FAIL, STACK},
	{	    "stack_operator_ne",         stack_operator_ne, FAIL, STACK},
	{	     "stack_operator_l",          stack_operator_l, FAIL, STACK},
	{	    "stack_operator_le",         stack_operator_le, FAIL, STACK},
	{	     "stack_operator_g",          stack_operator_g, FAIL, STACK},
	{	    "stack_operator_ge",         stack_operator_ge, FAIL, STACK},
 // --------------------------- Other Templates -------------------------- //
	{	      "stack_std_deque",           stack_std_deque, FAIL, STACK},
	{	       "stack_std_list",            stack_std_list, FAIL, STACK},
 // ------------------- Terminater (Do not comment out) ------------------ //
	{	                   "\0",	                  NULL, FAIL, STACK}
};
#endif

void _set_int_array(int* array, int size, bool accend)
{
	for (int i = 0; i < size; ++i) {
		if (accend)
			array[i] = i;
		else
			array[i] = std::rand();
	}
}

ft::stack<int> _assign_stack(int size, bool accend)
{
	ft::stack<int> data;

	for (int i = 0; i < size; ++i) {
		if (accend) {
			data.push(i);
		} else {
			data.push(std::rand());
		}
	}
	return data;
}

ft::stack<int> _set_stack(int size, bool accend)
{
	ft::stack<int> data;

	for (int i = 0; i < size; ++i) {
		if (accend) {
			data.push(i);
		} else {
			data.push(std::rand());
		}
	}
	return data;
}

std::stack<int, std::vector<int> > _set_stack_std(int size, bool accend)
{
	std::stack<int, std::vector<int> > data;

	for (int i = 0; i < size; ++i) {
		if (accend) {
			data.push(i);
		} else {
			data.push(std::rand());
		}
	}
	return data;
}

ft::stack<char> _set_stack_char(size_t size, bool accend)
{
	ft::stack<char> data;
	char            val;

	for (size_t i = 0; i < size; ++i) {

		if (accend) {
			val = 'a' + i;
		} else
			val = 'a' + std::rand() % 26;
		data.push(val);
	}
	return data;
}

ft::stack<std::string> _set_stack_string(size_t size, bool random)
{
	ft::stack<std::string> data;
	std::string            strs[]   = { "42", "Tokyo", "Hello", "World", "!" };
	size_t                 patterns = 5;
	std::string            val;
	int                    index;

	for (size_t i = 0; i < size; ++i) {
		if (random)
			index = std::rand() % patterns;
		else
			index = i % patterns;
		val = strs[index] + strs[std::max(index - 1, 0)];
		data.push(val);
	}
	return data;
}

void _assign_compare_stacks(
    ft::stack<int>& ft_data, std::stack<int>& std_data, int size, bool accend)
{
	for (int i = 0; i < size; ++i) {
		if (accend) {
			ft_data.push(i);
			std_data.push(i);
		} else {
			int value = std::rand();
			ft_data.push(value);
			std_data.push(value);
		}
	}
}

void _set_compare_stacks(ft::stack<int>& ft_data, std::stack<int>& std_data, int size, bool accend)
{
	for (int i = 0; i < size; ++i) {
		if (accend) {
			ft_data.push(i);
			std_data.push(i);
		} else {
			int value = std::rand();
			ft_data.push(value);
			std_data.push(value);
		}
	}
}

} // namespace StackTest
