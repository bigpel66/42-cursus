#ifndef SETTEST_HPP
#define SETTEST_HPP

#include "./UnitTester.hpp"
#include <iostream>
#include <set>

#if STD
namespace ft = std;
#else
#include "../../../../includes/set.hpp"
#endif

#define TABLE_SIZE 0xF00
typedef struct s_unit_tests t_unit_tests;

namespace SetTest {

void set_constructor();
void set_destructor();
void set_assignment_operator();
void set_get_allocator();

/* Iterators */
void set_begin();
void set_end();
void set_rbegin();
void set_rend();

/* Capacity */
void set_empty();
void set_size();
void set_max_size();

/* Modifiers */
void set_clear();
void set_insert();
void set_erase();
void set_swap();

/* Lookup */
void set_count();
void set_find();
void set_equal_range();
void set_lower_bound();
void set_upper_bound();

/* Observers */
void set_key_comp();
void set_value_comp();

/* Non-member functions */
void set_operator_e();
void set_operator_ne();
void set_operator_l();
void set_operator_le();
void set_operator_g();
void set_operator_ge();
void set_ft_swap();

/* Benchmark */
void bench_set_copy_constructor();
void bench_set_assignment_operator();
void bench_set_subscript_operator();
void bench_set_insert();
void bench_set_erase();
void bench_set_find();
void bench_set_equal_range();

extern t_unit_tests func_test_table[TABLE_SIZE];

ft::set<int>         _set_set(int size = 6, bool accend = false);
std::set<int>        _set_set_std(int size = 6, bool accend = false);
ft::set<char>        _set_set_char(int size = 6, bool accend = false);
ft::set<std::string> _set_set_string(int size = 6, bool accend = false);
void                 _set_compare_sets(
                    ft::set<std::string>& ft_data, std::set<std::string>& std_data, int size = 6);

/* --------------------------- template functions --------------------------- */

template <class Key, class T>
void _compare_sets(ft::set<Key, T>& ft, std::set<Key, T>& std)
{
	UnitTester::assert_(ft.size() == std.size());
	typename ft::set<Key, T>::iterator  it  = ft.begin();
	typename std::set<Key, T>::iterator its = std.begin();

	for (; it != ft.end(); ++it, ++its) {
		UnitTester::assert_(*it == *its);
	}
}

template <class Key, class T>
void _debug(ft::set<Key, T>& ft, std::string name = "")
{
	std::cerr << std::endl;
	std::cerr << "[" << name << "] ";
	std::cerr << "size=" << ft.size() << " | ";

	typename ft::set<Key, T>::iterator it = ft.begin();
	for (; it != ft.end(); ++it) {
		std::cerr << *it << " ";
	}
	std::cerr << std::endl;
}

} // namespace SetTest

#endif /* SETTEST_HPP */
