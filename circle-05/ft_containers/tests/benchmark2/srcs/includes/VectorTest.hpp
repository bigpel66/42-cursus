#ifndef VectorTest_HPP
#define VectorTest_HPP

#include "./UnitTester.hpp"
#include <iostream>

#if STD
#include <vector>
namespace ft = std;
#else
#include "../../../../includes/vector.hpp"
#endif

#define TABLE_SIZE 0xF00
typedef struct s_unit_tests t_unit_tests;

namespace VectorTest {

void vector_constructor();
void vector_destructor();
void vector_assignment_operator();
void vector_assign();
void vector_get_allocator();

/* Element access */
void vector_at();
void vector_subscript_operator();
void vector_front();
void vector_back();
void vector_data();

/* Iterators */
void vector_begin();
void vector_end();
void vector_rbegin();
void vector_rend();

/* Capacity */
void vector_empty();
void vector_size();
void vector_max_size();
void vector_reserve();
void vector_capacity();

/* Modifiers */
void vector_clear();
void vector_insert();
void vector_erase();
void vector_push_back();
void vector_pop_back();
void vector_resize();
void vector_swap();

/* Non-member functions */
void vector_operator_e();
void vector_operator_ne();
void vector_operator_l();
void vector_operator_le();
void vector_operator_g();
void vector_operator_ge();
void vector_ft_swap();

/* Benchmark */
void bench_vector_copy_constructor();
void bench_vector_assignment_operator();
void bench_vector_insert();
void bench_vector_erase();
void bench_vector_push_back();
void bench_vector_pop_back();

extern t_unit_tests func_test_table[TABLE_SIZE];

void                    _set_int_array(int* array, int size = 12, bool accend = false);
ft::vector<int>         _assign_vector(int size = 6, bool accend = false);
ft::vector<int>         _set_vector(int size = 6, bool accend = false);
std::vector<int>        _set_vector_std(int size = 6, bool accend = false);
ft::vector<char>        _set_vector_char(size_t size = 6, bool accend = false);
ft::vector<std::string> _set_vector_string(size_t size = 6, bool random = false);

void _assign_compare_vectors(
    ft::vector<int>& ft_data, std::vector<int>& std_data, int size = 6, bool accend = false);
void _set_compare_vectors(
    ft::vector<int>& ft_data, std::vector<int>& std_data, int size = 6, bool accend = false);

template <class T>
void _compare_vectors(ft::vector<T>& ft_vec, std::vector<T>& std_vec)
{
	UnitTester::assert_(ft_vec.size() == std_vec.size());

	size_t size = std_vec.size();
	for (size_t i = 0; i < size; ++i) {
		UnitTester::assert_(ft_vec[i] == std_vec[i]);
	}
}

template <class T>
void _debug(ft::vector<T>& ft_vec, std::string name = "")
{
	std::cerr << std::endl;
	std::cerr << "[" << name << "] ";
	size_t size = ft_vec.size();
	for (size_t i = 0; i < size; ++i) {
		std::cerr << i << ": " << ft_vec[i] << " ";
	}
	std::cerr << std::endl;
}

} // namespace VectorTest

#endif /* VectorTest_HPP */
