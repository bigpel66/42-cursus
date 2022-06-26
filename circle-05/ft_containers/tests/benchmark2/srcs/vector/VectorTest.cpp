#include "../includes/VectorTest.hpp"
#include "../includes/Log.hpp"
#include "../includes/UnitTester.hpp"
#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

namespace VectorTest {

#define FAIL TEST_FAILED

#ifdef BENCH
t_unit_tests func_test_table[] = {
	{   "vector_copy_constructor",    bench_vector_copy_constructor, FAIL, VECTOR},
	{"vector_assignment_operator", bench_vector_assignment_operator, FAIL, VECTOR},
	{	         "vector_insert",              bench_vector_insert, FAIL, VECTOR},
	{	          "vector_erase",               bench_vector_erase, FAIL, VECTOR},
	{	      "vector_push_back",           bench_vector_push_back, FAIL, VECTOR},
	{	       "vector_pop_back",            bench_vector_pop_back, FAIL, VECTOR},
 // ------------------- Terminater (Do not comment out) ------------------ //
	{	                    "\0",	                         NULL, FAIL, VECTOR}
};

#else
t_unit_tests func_test_table[] = {
	{	    "vector_constructor",         vector_constructor, FAIL, VECTOR},
	{	     "vector_destructor",          vector_destructor, FAIL, VECTOR},
	{"vector_assignment_operator", vector_assignment_operator, FAIL, VECTOR},
	{	         "vector_assign",              vector_assign, FAIL, VECTOR},
	{	  "vector_get_allocator",       vector_get_allocator, FAIL, VECTOR},
 // --------------------------- Element access --------------------------- //
	{	             "vector_at",                  vector_at, FAIL, VECTOR},
	{ "vector_subscript_operator",  vector_subscript_operator, FAIL, VECTOR},
	{	          "vector_front",               vector_front, FAIL, VECTOR},
    {               "vector_back",                vector_back, FAIL, VECTOR},
	{	           "vector_data",                vector_data, FAIL, VECTOR},
 // ------------------------------ Iterators ----------------------------- //
	{	          "vector_begin",               vector_begin, FAIL, VECTOR},
    {                "vector_end",                 vector_end, FAIL, VECTOR},
	{	         "vector_rbegin",              vector_rbegin, FAIL, VECTOR},
    {               "vector_rend",                vector_rend, FAIL, VECTOR},
 // ------------------------------ Capacity ----------------------------- //
	{	          "vector_empty",               vector_empty, FAIL, VECTOR},
    {               "vector_size",                vector_size, FAIL, VECTOR},
	{	       "vector_max_size",            vector_max_size, FAIL, VECTOR},
	{	        "vector_reserve",             vector_reserve, FAIL, VECTOR},
	{	       "vector_capacity",            vector_capacity, FAIL, VECTOR},
 // ------------------------------ Modifiers ----------------------------- //
	{	          "vector_clear",               vector_clear, FAIL, VECTOR},
	{	         "vector_insert",              vector_insert, FAIL, VECTOR},
	{	          "vector_erase",               vector_erase, FAIL, VECTOR},
	{	      "vector_push_back",           vector_push_back, FAIL, VECTOR},
	{	       "vector_pop_back",            vector_pop_back, FAIL, VECTOR},
	{	         "vector_resize",              vector_resize, FAIL, VECTOR},
    {               "vector_swap",                vector_swap, FAIL, VECTOR},
 // ------------------------ Non-member functions ------------------------ //
	{	     "vector_operator_e",          vector_operator_e, FAIL, VECTOR},
	{	    "vector_operator_ne",         vector_operator_ne, FAIL, VECTOR},
	{	     "vector_operator_l",          vector_operator_l, FAIL, VECTOR},
	{	    "vector_operator_le",         vector_operator_le, FAIL, VECTOR},
	{	     "vector_operator_g",          vector_operator_g, FAIL, VECTOR},
	{	    "vector_operator_ge",         vector_operator_ge, FAIL, VECTOR},
	{	        "vector_ft_swap",             vector_ft_swap, FAIL, VECTOR},
 // ------------------- Terminater (Do not comment out) ------------------ //
	{	                    "\0",	                   NULL, FAIL, VECTOR}
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

ft::vector<int> _assign_vector(int size, bool accend)
{
	ft::vector<int> data(size);

	for (int i = 0; i < size; ++i) {
		if (accend) {
			data.at(i) = i;
		} else {
			data.at(i) = std::rand();
		}
	}
	return data;
}

ft::vector<int> _set_vector(int size, bool accend)
{
	ft::vector<int> data;

	for (int i = 0; i < size; ++i) {
		if (accend) {
			data.push_back(i);
		} else {
			data.push_back(std::rand());
		}
	}
	return data;
}

std::vector<int> _set_vector_std(int size, bool accend)
{
	std::vector<int> data;

	for (int i = 0; i < size; ++i) {
		if (accend) {
			data.push_back(i);
		} else {
			data.push_back(std::rand());
		}
	}
	return data;
}

ft::vector<char> _set_vector_char(size_t size, bool accend)
{
	ft::vector<char> data;
	char             val;

	for (size_t i = 0; i < size; ++i) {

		if (accend) {
			val = 'a' + i;
		} else
			val = 'a' + std::rand() % 26;
		data.push_back(val);
	}
	return data;
}

ft::vector<std::string> _set_vector_string(size_t size, bool random)
{
	ft::vector<std::string> data;
	std::string             strs[]   = { "42", "Tokyo", "Hello", "World", "!" };
	size_t                  patterns = 5;
	std::string             val;
	int                     index;

	for (size_t i = 0; i < size; ++i) {
		if (random)
			index = std::rand() % patterns;
		else
			index = i % patterns;
		val = strs[index] + strs[std::max(index - 1, 0)];
		data.push_back(val);
	}
	return data;
}

void _assign_compare_vectors(
    ft::vector<int>& ft_data, std::vector<int>& std_data, int size, bool accend)
{
	for (int i = 0; i < size; ++i) {
		if (accend) {
			ft_data.at(i)  = i;
			std_data.at(i) = i;
		} else {
			int value      = std::rand();
			ft_data.at(i)  = value;
			std_data.at(i) = value;
		}
	}
}

void _set_compare_vectors(
    ft::vector<int>& ft_data, std::vector<int>& std_data, int size, bool accend)
{
	for (int i = 0; i < size; ++i) {
		if (accend) {
			ft_data.push_back(i);
			std_data.push_back(i);
		} else {
			int value = std::rand();
			ft_data.push_back(value);
			std_data.push_back(value);
		}
	}
}

} // namespace VectorTest
