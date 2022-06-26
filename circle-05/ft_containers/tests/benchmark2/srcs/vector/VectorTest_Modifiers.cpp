#include "../includes/Log.hpp"
#include "../includes/UnitTester.hpp"
#include "../includes/VectorTest.hpp"
#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

namespace VectorTest {

// -------------------------------------------------------------------------- //
//                                    clear                                   //
// -------------------------------------------------------------------------- //

void _vector_clear_size_check()
{
	set_explanation_("size not 0");
	int             size = 10;
	ft::vector<int> ft   = _set_vector(size);

	UnitTester::assert_(ft.size() != 0);
	ft.clear();
	UnitTester::assert_(ft.size() == 0);
}

void _vector_clear_capacity_check()
{
	set_explanation_("capacity modified after clear");
	int             size = 10;
	ft::vector<int> ft   = _set_vector(size);

	size_t capacity = ft.capacity();
	UnitTester::assert_(capacity != 0);
	ft.clear();
	UnitTester::assert_(ft.capacity() != 0);
	UnitTester::assert_(ft.capacity() == capacity);
}

void _vector_clear_empty_check()
{
	set_explanation_("is empty not true");
	int             size = 10;
	ft::vector<int> ft   = _set_vector(size, true);

	UnitTester::assert_(!ft.empty());
	ft.clear();
	UnitTester::assert_(ft.empty());
}

void vector_clear()
{
	load_subtest_(_vector_clear_size_check);
	load_subtest_(_vector_clear_capacity_check);
	load_subtest_(_vector_clear_empty_check);
}

// -------------------------------------------------------------------------- //
//                                   insert                                   //
// -------------------------------------------------------------------------- //

void _vector_insert_single()
{
	set_explanation_("value not inserted at expected point");
	int             size = 10;
	ft::vector<int> ft   = _set_vector(size);

	ft::vector<int>::iterator it    = ft.begin();
	int                       value = 42;
	ft.insert(it, value);
	UnitTester::assert_(ft[0] == value);
}

void _vector_insert_double()
{
	set_explanation_("value not inserted at expected point");
	int             size = 10;
	ft::vector<int> ft   = _set_vector(size);

	ft::vector<int>::iterator it    = ft.begin();
	int                       value = 42;
	ft.insert(it, 2, value);
	UnitTester::assert_(ft[0] == value);
	UnitTester::assert_(ft[1] == value);
}

void _vector_insert_multiple()
{
	set_explanation_("value not inserted at expected point");
	int                     size = 10;
	ft::vector<std::string> ft   = _set_vector_string(size);

	ft::vector<std::string>::iterator it    = ft.begin();
	std::string                       value = "Vector Test";
	size_t                            count = 5;

	ft.insert(it, 5, value);
	for (size_t i = 0; i < count; ++i) {
		UnitTester::assert_(ft[i] == value);
	}
}

void _vector_insert_iterator()
{
	set_explanation_("value not inserted at expected point");
	size_t           size  = 12;
	char             value = 'x';
	ft::vector<char> ft_src(size, value);

	ft::vector<char> ft = _set_vector_char(size, true);

	ft::vector<char>::iterator it = ft.begin() + 2;
	ft.insert(it, ft_src.begin(), ft_src.end());

	// `it` no longer valid, get a new one:
	it = ft.begin() + 2;
	for (size_t i = 0; it != ft.end() && i < size; ++it, ++i) {
		UnitTester::assert_(*it == value);
	}
}

void _vector_insert_compare()
{
	set_explanation_("result differs from std");
	size_t           src_size = 22;
	ft::vector<int>  ft_src;
	std::vector<int> std_src;
	_set_compare_vectors(ft_src, std_src, src_size);

	size_t           size = 57;
	ft::vector<int>  ft;
	std::vector<int> std;
	_set_compare_vectors(ft, std, size);

	// insert_point < size
	int insert_point = 13;
	ft.insert(ft.begin() + insert_point, ft_src.begin(), ft_src.end());
	std.insert(std.begin() + insert_point, std_src.begin(), std_src.end());
	_compare_vectors(ft, std);
}

void vector_insert()
{
	load_subtest_(_vector_insert_single);
	load_subtest_(_vector_insert_double);
	load_subtest_(_vector_insert_multiple);
	load_subtest_(_vector_insert_iterator);
	load_subtest_(_vector_insert_compare);
}
// -------------------------------------------------------------------------- //
//                                    erase                                   //
// -------------------------------------------------------------------------- //

void _vector_erase_one()
{
	set_explanation_("an element not erased");
	size_t          size = 10;
	ft::vector<int> ft   = _set_vector(size, true);

	ft.erase(ft.begin() + 3);
	UnitTester::assert_(ft.size() == size - 1);
}

void _vector_erase_head()
{
	set_explanation_("the first element not erased");
	int             size = 10;
	ft::vector<int> ft   = _set_vector(size, true);

	ft.erase(ft.begin());
	UnitTester::assert_(ft[0] == 1);
}

void _vector_erase_tail()
{
	set_explanation_("the last element not erased");
	int             size = 10;
	ft::vector<int> ft   = _set_vector(size, true);

	ft.erase(--ft.end());
	size = ft.size();
	UnitTester::assert_(ft[size - 1] == size - 1);
}

void _vector_erase_range()
{
	set_explanation_("elements in range not erased");
	int             size = 21;
	ft::vector<int> ft   = _set_vector(size, true);

	// erase_len < size
	int erase_len = 5;
	ft.erase(ft.begin(), ft.begin() + erase_len);
	UnitTester::assert_(ft[0] == erase_len);
}

void _vector_erase_compare()
{
	set_explanation_("result differs from std");
	int              size = 42;
	ft::vector<int>  ft;
	std::vector<int> std;
	_set_compare_vectors(ft, std, size);

	size_t                     start_position = 2;
	ft::vector<int>::iterator  ft_start       = ft.begin() + start_position;
	std::vector<int>::iterator std_start      = std.begin() + start_position;

	size_t len = 15;
	ft.erase(ft_start, ft_start + len);
	std.erase(std_start, std_start + len);
	_compare_vectors(ft, std);
}

void vector_erase()
{
	load_subtest_(_vector_erase_one);
	load_subtest_(_vector_erase_head);
	load_subtest_(_vector_erase_tail);
	load_subtest_(_vector_erase_range);
	load_subtest_(_vector_erase_compare);
}

// -------------------------------------------------------------------------- //
//                                  push_back                                 //
// -------------------------------------------------------------------------- //

void _vector_push_back_empty()
{
	set_explanation_("added value not correct");
	ft::vector<int> ft;

	int value = 42;
	ft.push_back(value);
	UnitTester::assert_(ft[0] == value);
}

void _vector_push_back_one()
{
	set_explanation_("added value not correct");
	int             size = 10;
	ft::vector<int> ft   = _set_vector(size, true);

	int value = 42;
	ft.push_back(value);
	UnitTester::assert_(ft[size] == value);
}

void _vector_push_back_compare()
{
	set_explanation_("result differs from std");
	ft::vector<int>  ft;
	std::vector<int> std;
	_set_compare_vectors(ft, std);
	_compare_vectors(ft, std);
}

void vector_push_back()
{
	load_subtest_(_vector_push_back_empty);
	load_subtest_(_vector_push_back_one);
	load_subtest_(_vector_push_back_compare);
}

// -------------------------------------------------------------------------- //
//                                  pop_back                                  //
// -------------------------------------------------------------------------- //

void _vector_pop_back_empty()
{
	set_explanation_("size not (size_t)-1 on empty (undefined behavior)");
	ft::vector<int> ft;
	ft.pop_back();

	UnitTester::assert_diff_(ft.size() == static_cast<size_t>(-1));
}

void _vector_pop_back_one()
{
	set_explanation_("size not reduced");
	size_t          size = 10;
	ft::vector<int> ft   = _set_vector(size, true);

	ft.pop_back();
	UnitTester::assert_(ft.size() == size - 1);
}

void _vector_pop_back_compare_zero()
{
	set_explanation_(
	    "result differs from std after pop_back on empty int vector (undefined behavior)");
	ft::vector<int>  ft;
	std::vector<int> std;

	ft.pop_back();
	std.pop_back();
	UnitTester::assert_diff_(ft.size() == std.size());
}

void _vector_pop_back_compare()
{
	set_explanation_("result differs from std");
	size_t           size = 16;
	ft::vector<int>  ft;
	std::vector<int> std;
	_set_compare_vectors(ft, std, size);

	for (size_t i = 0; i < size; ++i) {
		ft.pop_back();
		std.pop_back();
		_compare_vectors(ft, std);
	}
}

void vector_pop_back()
{
	load_subtest_(_vector_pop_back_empty);
	load_subtest_(_vector_pop_back_one);
	load_subtest_(_vector_pop_back_compare_zero);
	load_subtest_(_vector_pop_back_compare);
}

// -------------------------------------------------------------------------- //
//                                   resize                                   //
// -------------------------------------------------------------------------- //

void _vector_resize_expand()
{
	set_explanation_("size not expanded or initialized");
	int             size = 10;
	ft::vector<int> ft   = _set_vector(size, true);

	size_t new_size = 19;
	ft.resize(new_size);
	UnitTester::assert_(ft.size() == new_size);
	UnitTester::assert_(ft[new_size - 1] == 0);
}

void _vector_resize_reduce()
{
	set_explanation_("size not reduced");
	int             size = 7;
	ft::vector<int> ft   = _set_vector(size, true);

	size_t new_size = 2;
	ft.resize(new_size);
	UnitTester::assert_(ft.size() == new_size);
}

void _vector_resize_same()
{
	set_explanation_("size changed");
	int             size = 5;
	ft::vector<int> ft   = _set_vector(size, true);

	size_t new_size = size;
	ft.resize(new_size);
	UnitTester::assert_(ft.size() == new_size);
}

void _vector_resize_initializer()
{
	set_explanation_("initializer not applied");
	int             size = 8;
	ft::vector<int> ft   = _set_vector(size, true);

	size_t new_size    = 24;
	int    initializer = 4242;
	ft.resize(new_size, initializer);
	for (size_t i = size; i < new_size; ++i) {
		UnitTester::assert_(ft[i] == initializer);
	}
}

void vector_resize()
{
	load_subtest_(_vector_resize_expand);
	load_subtest_(_vector_resize_reduce);
	load_subtest_(_vector_resize_same);
	load_subtest_(_vector_resize_initializer);
}

// -------------------------------------------------------------------------- //
//                                    swap                                    //
// -------------------------------------------------------------------------- //

void _vector_swap_basic()
{
	set_explanation_("swapped value not correct");
	size_t          size_a = 10;
	size_t          size_b = 20;
	ft::vector<int> ft_a   = _set_vector(size_a, false);
	ft::vector<int> ft_b   = _set_vector(size_b, true);

	ft_a.swap(ft_b);
	for (size_t i = 0; i < size_b; ++i) {
		ft_a[i] = i;
	}
}

void _vector_swap_compare()
{
	set_explanation_("result differs from std");
	ft::vector<int>  ft_a;
	std::vector<int> std_a;
	_set_compare_vectors(ft_a, std_a);

	ft::vector<int>  ft_b;
	std::vector<int> std_b;
	_set_compare_vectors(ft_b, std_b);

	ft_a.swap(ft_b);
	std_a.swap(std_b);
	_compare_vectors(ft_a, std_a);
	_compare_vectors(ft_b, std_b);
}

void _vector_swap_iterator_invalidation()
{
	ft::vector<int>           ft_a    = _set_vector();
	ft::vector<int>           ft_b    = _set_vector();
	ft::vector<int>::iterator it_a    = ft_a.begin();
	ft::vector<int>::iterator it_b    = ft_b.begin();
	int                       value_a = ft_a[0];
	int                       value_b = ft_b[0];

	set_explanation_("tester failuer: set values are wrong");
	UnitTester::assert_(*it_a == value_a);
	UnitTester::assert_(*it_b == value_b);
	ft_a.swap(ft_b);
	set_explanation_("iterators are invalidated");
	UnitTester::assert_(*it_a == value_a);
	UnitTester::assert_(*it_b == value_b);
	UnitTester::assert_(*ft_a.begin() == value_b);
	UnitTester::assert_(*ft_b.begin() == value_a);
}

void _vector_swap_pointer_invalidation()
{
	size_t                   size_a = 42;
	size_t                   size_b = 24;
	ft::vector<int>          ft_a   = _set_vector(size_a, true);
	ft::vector<int>          ft_b   = _set_vector(size_b, false);
	size_t                   index  = 17;
	ft::vector<int>::pointer ptr_a  = &ft_a[index];
	ft::vector<int>::pointer ptr_b  = &ft_b[index];

	ft_b.swap(ft_a);
	set_explanation_("tester failuer: both vectors have the same value");
	UnitTester::assert_(ft_a[index] != ft_b[index]);
	set_explanation_("pointers are invalidated");
	UnitTester::assert_(ft_a[index] == *ptr_b);
	UnitTester::assert_(ft_b[index] == *ptr_a);
}

void _vector_swap_reference_invalidation()
{
	size_t                     size_a = 42;
	size_t                     size_b = 24;
	ft::vector<int>            ft_a   = _set_vector(size_a, true);
	ft::vector<int>            ft_b   = _set_vector(size_b, false);
	size_t                     index  = 10;
	ft::vector<int>::reference ref_a  = ft_a[index];
	ft::vector<int>::reference ref_b  = ft_b[index];

	ft_a.swap(ft_b);
	set_explanation_("tester failuer: both vectors have the same value");
	UnitTester::assert_(ft_a[index] != ft_b[index]);
	set_explanation_("references are invalidated");
	UnitTester::assert_(ft_a[index] == ref_b);
	UnitTester::assert_(ft_b[index] == ref_a);
}

void vector_swap()
{
	load_subtest_(_vector_swap_basic);
	load_subtest_(_vector_swap_compare);
	load_subtest_(_vector_swap_iterator_invalidation);
	load_subtest_(_vector_swap_pointer_invalidation);
	load_subtest_(_vector_swap_reference_invalidation);
}

} // namespace VectorTest
