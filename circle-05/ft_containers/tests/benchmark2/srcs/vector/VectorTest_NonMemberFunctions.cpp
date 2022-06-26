#include "../includes/Log.hpp"
#include "../includes/UnitTester.hpp"
#include "../includes/VectorTest.hpp"
#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

namespace VectorTest {

// -------------------------------------------------------------------------- //
//                                 operator==                                 //
// -------------------------------------------------------------------------- //

void _vector_operator_e_true()
{
	set_explanation_("wrong result on value int");
	int             size_1 = 10;
	int             size_2 = size_1;
	ft::vector<int> ft_1   = _set_vector(size_1, true);
	ft::vector<int> ft_2   = _set_vector(size_2, true);

	UnitTester::assert_((ft_1 == ft_2) == true);
}

void _vector_operator_e_true_empty()
{
	set_explanation_("empty vectors are not equal");
	ft::vector<int> ft_1;
	ft::vector<int> ft_2;

	UnitTester::assert_((ft_1 == ft_2) == true);
}

void _vector_operator_e_false()
{
	set_explanation_("wrong result on size difference");
	int             size_1 = 10;
	int             size_2 = 12;
	ft::vector<int> ft_1   = _set_vector(size_1, true);
	ft::vector<int> ft_2   = _set_vector(size_2, true);

	UnitTester::assert_((ft_1 == ft_2) == false);
}
void _vector_operator_e_false2()
{
	set_explanation_("wrong result on value and size difference");
	int             size_1 = 10;
	int             size_2 = 7;
	ft::vector<int> ft_1   = _set_vector(size_1);
	ft::vector<int> ft_2   = _set_vector(size_2);

	UnitTester::assert_((ft_1 == ft_2) == false);
}

void _vector_operator_e_same()
{
	set_explanation_("vector not same to itself!?");
	int                     size_1 = 10;
	ft::vector<std::string> ft_1   = _set_vector_string(size_1);

	UnitTester::assert_((ft_1 == ft_1) == true);
}

void _vector_operator_e_compare()
{
	set_explanation_("int result differs from std");
	ft::vector<int>  ft_1;
	std::vector<int> std_1;
	_set_compare_vectors(ft_1, std_1);
	ft::vector<int>  ft_2;
	std::vector<int> std_2;
	_set_compare_vectors(ft_2, std_2);

	bool val1 = ft_1 == ft_2;
	UnitTester::assert_(val1 == (std_1 == std_2));
}

void _vector_operator_e_const_and_non_const()
{
	set_explanation_("const and non-const cannot be compared");
	size_t                size     = 13;
	ft::vector<int>       ft       = _set_vector(size, true);
	const ft::vector<int> ft_const = _set_vector(size, true);

	UnitTester::assert_(ft == ft_const);
}

void vector_operator_e()
{
	load_subtest_(_vector_operator_e_true);
	load_subtest_(_vector_operator_e_true_empty);
	load_subtest_(_vector_operator_e_false);
	load_subtest_(_vector_operator_e_false2);
	load_subtest_(_vector_operator_e_same);
	load_subtest_(_vector_operator_e_compare);
	load_subtest_(_vector_operator_e_const_and_non_const);
}

// -------------------------------------------------------------------------- //
//                                 operator!=                                 //
// -------------------------------------------------------------------------- //

void _vector_operator_ne_true()
{
	set_explanation_("wrong result on value std::string");
	int                     size_1 = 2;
	int                     size_2 = 13;
	ft::vector<std::string> ft_1   = _set_vector_string(size_1);
	ft::vector<std::string> ft_2   = _set_vector_string(size_2);

	UnitTester::assert_((ft_1 != ft_2) == true);
}

void _vector_operator_ne_true2()
{
	set_explanation_("wrong result on different content");
	int                     size_1 = 24;
	int                     size_2 = size_1;
	ft::vector<std::string> ft_1   = _set_vector_string(size_1, true);
	ft::vector<std::string> ft_2   = _set_vector_string(size_2, true);

	UnitTester::assert_((ft_1 != ft_2) == true);
}

void _vector_operator_ne_false()
{
	set_explanation_("wrong result on same content");
	int                     size_1 = 24;
	int                     size_2 = size_1;
	ft::vector<std::string> ft_1   = _set_vector_string(size_1);
	ft::vector<std::string> ft_2   = _set_vector_string(size_2);

	UnitTester::assert_((ft_1 != ft_2) == false);
}

void _vector_operator_ne_same()
{
	set_explanation_("vector not same to itself!?");
	int                     size_1 = 10;
	ft::vector<std::string> ft_1   = _set_vector_string(size_1);

	UnitTester::assert_((ft_1 != ft_1) == false);
}

void _vector_operator_ne_compare()
{
	set_explanation_("int result differs from std");
	ft::vector<int>  ft_1;
	std::vector<int> std_1;
	_set_compare_vectors(ft_1, std_1);
	ft::vector<int>  ft_2;
	std::vector<int> std_2;
	_set_compare_vectors(ft_2, std_2);

	bool val1 = ft_1 != ft_2;
	UnitTester::assert_(val1 == (std_1 != std_2));
}

void _vector_operator_ne_const_and_non_const()
{
	set_explanation_("const and non-const cannot be compared");
	size_t                size     = 13;
	ft::vector<int>       ft       = _set_vector(size, true);
	const ft::vector<int> ft_const = _set_vector(size, true);

	UnitTester::assert_((ft != ft_const) == false);
}

void vector_operator_ne()
{
	load_subtest_(_vector_operator_ne_true);
	load_subtest_(_vector_operator_ne_true2);
	load_subtest_(_vector_operator_ne_false);
	load_subtest_(_vector_operator_ne_same);
	load_subtest_(_vector_operator_ne_compare);
	load_subtest_(_vector_operator_ne_const_and_non_const);
}

// -------------------------------------------------------------------------- //
//                                 operator<                                 //
// -------------------------------------------------------------------------- //

void _vector_operator_l_true()
{
	set_explanation_("char vector size difference not evaluated correctly");
	int              size = 10;
	ft::vector<char> ft_0 = _set_vector_char(size, true);
	ft::vector<char> ft_1 = _set_vector_char(size, true);

	ft_0.pop_back();
	// _debug(ft_0, "0");
	// _debug(ft_1, "1");
	UnitTester::assert_((ft_0 < ft_1) == true);
}

void _vector_operator_l_false()
{
	set_explanation_("char vector size difference not evaluated correctly");
	int              size  = 10;
	int              size2 = 1;
	ft::vector<char> ft_0  = _set_vector_char(size, true);
	ft::vector<char> ft_1  = _set_vector_char(size2, true);

	// _debug(ft_0, "0");
	// _debug(ft_1, "1");
	UnitTester::assert_((ft_0 < ft_1) == false);
}

void _vector_operator_l_same()
{
	set_explanation_("equal int values not evaluated correctly");
	int             size = 10;
	ft::vector<int> ft   = _set_vector(size, true);

	UnitTester::assert_((ft < ft) == false);
}

void _vector_operator_l_compare()
{
	set_explanation_("int result differs from std");
	ft::vector<int>  ft_1;
	std::vector<int> std_1;
	_set_compare_vectors(ft_1, std_1);
	ft::vector<int>  ft_2;
	std::vector<int> std_2;
	_set_compare_vectors(ft_2, std_2);

	bool val1 = ft_1 < ft_2;
	bool val2 = ft_2 < ft_1;
	UnitTester::assert_(val1 == (std_1 < std_2));
	UnitTester::assert_(val2 == (std_2 < std_1));
}

void _vector_operator_l_const_and_non_const()
{
	set_explanation_("const and non-const cannot be compared");
	size_t                size     = 13;
	ft::vector<int>       ft       = _set_vector(size, true);
	const ft::vector<int> ft_const = _set_vector(size, true);

	UnitTester::assert_((ft > ft_const) == false);
}

void vector_operator_l()
{
	load_subtest_(_vector_operator_l_true);
	load_subtest_(_vector_operator_l_false);
	load_subtest_(_vector_operator_l_same);
	load_subtest_(_vector_operator_l_compare);
	load_subtest_(_vector_operator_l_const_and_non_const);
}

// -------------------------------------------------------------------------- //
//                                 operator<=                                 //
// -------------------------------------------------------------------------- //

void _vector_operator_le_true()
{
	set_explanation_("std::string vector size difference not evaluated correctly");
	int                     size = 10;
	ft::vector<std::string> ft_0 = _set_vector_string(size, false);
	ft::vector<std::string> ft_1 = _set_vector_string(size, false);

	ft_0.pop_back();
	// _debug(ft_0, "0");
	// _debug(ft_1, "1");
	UnitTester::assert_((ft_0 <= ft_1) == true);
}

void _vector_operator_le_false()
{
	set_explanation_("char vector size difference not evaluated correctly");
	int              size_1 = 0;
	int              size_2 = 12;
	ft::vector<char> ft_1   = _set_vector_char(size_1, true);
	ft::vector<char> ft_2   = _set_vector_char(size_2, true);

	UnitTester::assert_((ft_2 <= ft_1) == false);
}

void _vector_operator_le_same()
{
	set_explanation_("equal std::string values not evaluated correctly");
	int                     size = 10;
	ft::vector<std::string> ft   = _set_vector_string(size, true);

	UnitTester::assert_((ft <= ft) == true);
}

void _vector_operator_le_compare()
{
	set_explanation_("int result differs from std");
	ft::vector<int>  ft_1;
	std::vector<int> std_1;
	_set_compare_vectors(ft_1, std_1);
	ft::vector<int>  ft_2;
	std::vector<int> std_2;
	_set_compare_vectors(ft_2, std_2);

	bool val1 = ft_1 <= ft_2;
	bool val2 = ft_2 <= ft_1;
	UnitTester::assert_(val1 == (std_1 <= std_2));
	UnitTester::assert_(val2 == (std_2 <= std_1));
}

void vector_operator_le()
{
	load_subtest_(_vector_operator_le_true);
	load_subtest_(_vector_operator_le_false);
	load_subtest_(_vector_operator_le_same);
	load_subtest_(_vector_operator_le_compare);
}

// -------------------------------------------------------------------------- //
//                                 operator>                                  //
// -------------------------------------------------------------------------- //

void _vector_operator_g_true()
{
	set_explanation_("char vector size difference not evaluated correctly");
	int              size_1 = 21;
	int              size_2 = 12;
	ft::vector<char> ft_1   = _set_vector_char(size_1, true);
	ft::vector<char> ft_2   = _set_vector_char(size_2, true);

	UnitTester::assert_((ft_1 > ft_2) == true);
}

void _vector_operator_g_false()
{
	set_explanation_("char vector size difference not evaluated correctly");
	int              size = 12;
	ft::vector<char> ft_1 = _set_vector_char(size, false);
	ft::vector<char> ft_2 = ft_1;

	ft_1.pop_back();
	// _debug(ft_1, "1");
	// _debug(ft_2, "2");
	UnitTester::assert_((ft_1 > ft_2) == false);
}

void _vector_operator_g_same()
{
	set_explanation_("equal std::string values not evaluated correctly");
	int                     size = 10;
	ft::vector<std::string> ft   = _set_vector_string(size, true);

	UnitTester::assert_((ft > ft) == false);
}

void _vector_operator_g_compare()
{
	set_explanation_("int result differs from std");
	ft::vector<int>  ft_1;
	std::vector<int> std_1;
	_set_compare_vectors(ft_1, std_1);
	ft::vector<int>  ft_2;
	std::vector<int> std_2;
	_set_compare_vectors(ft_2, std_2);

	bool val1 = ft_1 > ft_2;
	bool val2 = ft_2 > ft_1;
	UnitTester::assert_(val1 == (std_1 > std_2));
	UnitTester::assert_(val2 == (std_2 > std_1));
}

void vector_operator_g()
{
	load_subtest_(_vector_operator_g_true);
	load_subtest_(_vector_operator_g_false);
	load_subtest_(_vector_operator_g_same);
	load_subtest_(_vector_operator_g_compare);
}

// -------------------------------------------------------------------------- //
//                                 operator>=                                 //
// -------------------------------------------------------------------------- //

void _vector_operator_ge_true()
{
	set_explanation_("std::string vector size difference not evaluated correctly");
	ft::vector<std::string> ft_1 = _set_vector_string();
	ft::vector<std::string> ft_2 = ft_1;

	std::string value = "apple";
	ft_1.push_back(value);
	// _debug(ft_1, "1");
	// _debug(ft_2, "2");
	UnitTester::assert_((ft_1 >= ft_2) == true);
}

void _vector_operator_ge_false()
{
	set_explanation_("std::string vector size difference not evaluated correctly");
	int                     size = 12;
	ft::vector<std::string> ft_1 = _set_vector_string(size, false);
	ft::vector<std::string> ft_2 = ft_1;

	ft_1.pop_back();
	// _debug(ft_1, "1");
	// _debug(ft_2, "2");
	UnitTester::assert_((ft_1 >= ft_2) == false);
}

void _vector_operator_ge_same()
{
	set_explanation_("equal int values not evaluated correctly");
	int             size = 42;
	ft::vector<int> ft   = _set_vector(size);

	UnitTester::assert_((ft >= ft) == true);
}

void _vector_operator_ge_compare()
{
	set_explanation_("int result differs from std");
	ft::vector<int>  ft_1;
	std::vector<int> std_1;
	_set_compare_vectors(ft_1, std_1);
	ft::vector<int>  ft_2;
	std::vector<int> std_2;
	_set_compare_vectors(ft_2, std_2);

	bool val1 = ft_1 >= ft_2;
	bool val2 = ft_2 >= ft_1;
	UnitTester::assert_(val1 == (std_1 >= std_2));
	UnitTester::assert_(val2 == (std_2 >= std_1));
}

void vector_operator_ge()
{
	load_subtest_(_vector_operator_ge_true);
	load_subtest_(_vector_operator_ge_false);
	load_subtest_(_vector_operator_ge_same);
	load_subtest_(_vector_operator_ge_compare);
}

// -------------------------------------------------------------------------- //
//                                  ft::swap                                  //
// -------------------------------------------------------------------------- //

void _vector_ft_swap_basic()
{
	set_explanation_("swapped value not correct");
	size_t          size_a = 10;
	size_t          size_b = 20;
	ft::vector<int> ft_a   = _set_vector(size_a, false);
	ft::vector<int> ft_b   = _set_vector(size_b, true);

	ft::swap(ft_a, ft_b);
	for (size_t i = 0; i < size_b; ++i) {
		ft_a[i] = i;
	}
}

void _vector_ft_swap_compare()
{
	set_explanation_("result differs from std");
	ft::vector<int>  ft_a;
	std::vector<int> std_a;
	_set_compare_vectors(ft_a, std_a);

	ft::vector<int>  ft_b;
	std::vector<int> std_b;
	_set_compare_vectors(ft_b, std_b);

	ft::swap(ft_a, ft_b);
	std::swap(std_a, std_b);
	_compare_vectors(ft_a, std_a);
	_compare_vectors(ft_b, std_b);
}

void _vector_ft_swap_iterator_invalidation()
{
	size_t                    size_a = 42;
	size_t                    size_b = 24;
	ft::vector<int>           ft_a   = _set_vector(size_a, true);
	ft::vector<int>           ft_b   = _set_vector(size_b, false);
	ft::vector<int>::iterator it_a   = ft_a.begin();
	ft::vector<int>::iterator it_b   = ft_b.begin();

	ft::swap(ft_a, ft_b);
	set_explanation_("tester failuer: both vectors have the same value");
	UnitTester::assert_(ft_a[0] != ft_b[0]);
	set_explanation_("iterators are invalidated");
	UnitTester::assert_(ft_a.begin() == it_b);
	UnitTester::assert_(ft_b.begin() == it_a);
}

void _vector_ft_swap_pointer_invalidation()
{
	size_t                   size_a = 42;
	size_t                   size_b = 24;
	ft::vector<int>          ft_a   = _set_vector(size_a, true);
	ft::vector<int>          ft_b   = _set_vector(size_b, false);
	size_t                   index  = 17;
	ft::vector<int>::pointer ptr_a  = &ft_a[index];
	ft::vector<int>::pointer ptr_b  = &ft_b[index];

	ft::swap(ft_a, ft_b);
	set_explanation_("tester failuer: both vectors have the same value");
	UnitTester::assert_(ft_a[index] != ft_b[index]);
	set_explanation_("pointers are invalidated");
	UnitTester::assert_(ft_a[index] == *ptr_b);
	UnitTester::assert_(ft_b[index] == *ptr_a);
}

void _vector_ft_swap_reference_invalidation()
{
	size_t                     size_a = 42;
	size_t                     size_b = 24;
	ft::vector<int>            ft_a   = _set_vector(size_a, true);
	ft::vector<int>            ft_b   = _set_vector(size_b, false);
	size_t                     index  = 10;
	ft::vector<int>::reference ref_a  = ft_a[index];
	ft::vector<int>::reference ref_b  = ft_b[index];

	ft::swap(ft_a, ft_b);
	set_explanation_("tester failuer: both vectors have the same value");
	UnitTester::assert_(ft_a[index] != ft_b[index]);
	set_explanation_("references are invalidated");
	UnitTester::assert_(ft_a[index] == ref_b);
	UnitTester::assert_(ft_b[index] == ref_a);
}

void vector_ft_swap()
{
	load_subtest_(_vector_ft_swap_basic);
	load_subtest_(_vector_ft_swap_compare);
	load_subtest_(_vector_ft_swap_iterator_invalidation);
	load_subtest_(_vector_ft_swap_pointer_invalidation);
	load_subtest_(_vector_ft_swap_reference_invalidation);
}

} // namespace VectorTest
