#include "../includes/Log.hpp"
#include "../includes/UnitTester.hpp"
#include "../includes/VectorTest.hpp"
#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

namespace VectorTest {

// -------------------------------------------------------------------------- //
//                                     at                                     //
// -------------------------------------------------------------------------- //

void _vector_at_basic()
{
	set_explanation_("does not return the right value");

	int             size = 10;
	ft::vector<int> data = _set_vector(size, true);

	for (int i = 0; i < size; ++i)
		UnitTester::assert_(data.at(i) == i);
}

void _vector_at_compare()
{
	set_explanation_("ft behaviour differs from std");

	int              size = 20;
	ft::vector<int>  ft;
	std::vector<int> std;
	_set_compare_vectors(ft, std, size);

	for (int i = 0; i < size; ++i)
		UnitTester::assert_(ft.at(i) == std.at(i));
}

void _vector_at_out_of_range()
{
	set_explanation_("out of range does not throw appropriate exception");

	int             size    = 4;
	ft::vector<int> ft_data = _set_vector(size, true);

	for (int i = 0; i < size + 3; ++i) {
		try {
			ft_data.at(i);
		} catch (std::out_of_range& e) {
			UnitTester::assert_(strlen(e.what()) != 0);
		} catch (std::exception& e) {
			UnitTester::assert_(false);
		}
	}
}

void vector_at()
{
	load_subtest_(_vector_at_basic);
	load_subtest_(_vector_at_compare);
	load_subtest_(_vector_at_out_of_range);
}

// -------------------------------------------------------------------------- //
//                                 operator[]                                 //
// -------------------------------------------------------------------------- //

void _vector_subscript_operator_basic()
{
	set_explanation_("does not return right value. Really!?");
	int             size    = 12;
	ft::vector<int> ft_data = _set_vector(size, true);

	for (int i = 0; i < size; ++i)
		UnitTester::assert_(ft_data[i] == i);
}

void _vector_subscript_operator_compare()
{
	set_explanation_("does not return right value. Really!?");
	int              size = 12;
	ft::vector<int>  ft_data;
	std::vector<int> std_data;
	_set_compare_vectors(ft_data, std_data, 12);

	for (int i = 0; i < size; ++i)
		UnitTester::assert_(ft_data[i] == std_data[i]);
}

void vector_subscript_operator()
{
	load_subtest_(_vector_subscript_operator_basic);
	load_subtest_(_vector_subscript_operator_compare);
}

// -------------------------------------------------------------------------- //
//                                    front                                   //
// -------------------------------------------------------------------------- //

void _vector_front_basic_int()
{
	set_explanation_("does not return the right value");
	int             size = 12;
	ft::vector<int> ft   = _set_vector(size, true);
	UnitTester::assert_(ft.front() == 0);
}

void _vector_front_basic_char()
{
	int              size  = 12;
	char             value = '*';
	ft::vector<char> ft(size, value);
	set_explanation_("does not return the right value");
	UnitTester::assert_(ft.front() == value);

	char new_value = '+';
	ft[0]          = new_value;
	set_explanation_("does not return the updated value");
	UnitTester::assert_(ft.front() == new_value);
}

void _vector_front_compare()
{
	set_explanation_("result differs from std");
	ft::vector<int>  ft;
	std::vector<int> std;
	_set_compare_vectors(ft, std);

	UnitTester::assert_(ft.front() == std.front());
}

void vector_front()
{
	load_subtest_(_vector_front_basic_int);
	load_subtest_(_vector_front_basic_char);
	load_subtest_(_vector_front_compare);
}

// -------------------------------------------------------------------------- //
//                                    back                                    //
// -------------------------------------------------------------------------- //

void _vector_back_basic_int()
{
	set_explanation_("does not return the right value");
	int             size = 10;
	ft::vector<int> ft   = _set_vector(size, true);
	UnitTester::assert_(ft.back() == size - 1);
}

void _vector_back_basic_char()
{
	int              size  = 10;
	char             value = '*';
	ft::vector<char> ft(size, value);
	set_explanation_("does not return the right value");
	UnitTester::assert_(ft.back() == value);

	char new_value = '+';
	ft[size - 1]   = new_value;
	set_explanation_("does not return the updated value");
	UnitTester::assert_(ft.back() == new_value);
}

void _vector_back_compare()
{
	set_explanation_("result differs from std");
	ft::vector<int>  ft;
	std::vector<int> std;
	_set_compare_vectors(ft, std);

	UnitTester::assert_(ft.back() == std.back());
}

void vector_back()
{
	load_subtest_(_vector_back_basic_int);
	load_subtest_(_vector_back_basic_char);
	load_subtest_(_vector_back_compare);
}

// -------------------------------------------------------------------------- //
//                                    data                                    //
// -------------------------------------------------------------------------- //

void _vector_data_basic()
{
	set_explanation_("does not return the right value");
	int             size = 10;
	ft::vector<int> ft   = _set_vector(size, true);

	UnitTester::assert_(*ft.data() == 0);
}

void _vector_data_compare()
{
	set_explanation_("result differs from std");
	ft::vector<int>  ft;
	std::vector<int> std;
	_set_compare_vectors(ft, std);

	UnitTester::assert_(*ft.data() == *std.data());
}

void vector_data()
{
	load_subtest_(_vector_data_basic);
	load_subtest_(_vector_data_compare);
}

} // namespace VectorTest
