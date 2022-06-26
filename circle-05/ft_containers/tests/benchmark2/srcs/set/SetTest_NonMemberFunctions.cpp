#include "../includes/SetTest.hpp"
#include "../includes/UnitTester.hpp"
#include <iostream>
#include <set>

namespace SetTest {

// -------------------------------------------------------------------------- //
//                                 operator==                                 //
// -------------------------------------------------------------------------- //

void _set_operator_e_true()
{
	set_explanation_("wrong result on value int");
	int          size_1 = 10;
	int          size_2 = size_1;
	ft::set<int> ft_1   = _set_set(size_1, true);
	ft::set<int> ft_2   = _set_set(size_2, true);

	UnitTester::assert_((ft_1 == ft_2) == true);
}

void _set_operator_e_true_empty()
{
	set_explanation_("empty sets are not equal");
	ft::set<int> ft_1;
	ft::set<int> ft_2;

	UnitTester::assert_((ft_1 == ft_2) == true);
}

void _set_operator_e_false()
{
	set_explanation_("wrong result on size difference");
	int          size_1 = 10;
	int          size_2 = 12;
	ft::set<int> ft_1   = _set_set(size_1, true);
	ft::set<int> ft_2   = _set_set(size_2, true);

	UnitTester::assert_((ft_1 == ft_2) == false);
}
void _set_operator_e_false2()
{
	set_explanation_("wrong result on value and size difference");
	int          size_1 = 10;
	int          size_2 = 7;
	ft::set<int> ft_1   = _set_set(size_1);
	ft::set<int> ft_2   = _set_set(size_2);

	UnitTester::assert_((ft_1 == ft_2) == false);
}

void _set_operator_e_same()
{
	set_explanation_("set not same to itself!?");
	int                  size_1 = 10;
	ft::set<std::string> ft_1   = _set_set_string(size_1);

	UnitTester::assert_((ft_1 == ft_1) == true);
}

void _set_operator_e_compare()
{
	set_explanation_("int result differs from std");
	ft::set<std::string>  ft_1;
	std::set<std::string> std_1;
	_set_compare_sets(ft_1, std_1);

	ft::set<std::string>  ft_2;
	std::set<std::string> std_2;
	_set_compare_sets(ft_2, std_2);

	bool val1 = ft_1 == ft_2;
	UnitTester::assert_(val1 == (std_1 == std_2));
}

void set_operator_e()
{
	load_subtest_(_set_operator_e_true);
	load_subtest_(_set_operator_e_true_empty);
	load_subtest_(_set_operator_e_false);
	load_subtest_(_set_operator_e_false2);
	load_subtest_(_set_operator_e_same);
	load_subtest_(_set_operator_e_compare);
}

// -------------------------------------------------------------------------- //
//                                 operator!=                                 //
// -------------------------------------------------------------------------- //

void _set_operator_ne_true()
{
	set_explanation_("wrong result on value std::string");
	int                  size_1 = 2;
	int                  size_2 = 13;
	ft::set<std::string> ft_1   = _set_set_string(size_1);
	ft::set<std::string> ft_2   = _set_set_string(size_2);

	UnitTester::assert_((ft_1 != ft_2) == true);
}

void _set_operator_ne_true2()
{
	set_explanation_("wrong result on different content");
	int                  size_1 = 24;
	int                  size_2 = size_1;
	ft::set<std::string> ft_1   = _set_set_string(size_1, true);
	ft::set<std::string> ft_2   = _set_set_string(size_2, true);

	UnitTester::assert_((ft_1 != ft_2) == false);
}

void _set_operator_ne_false()
{
	set_explanation_("wrong result on same content");
	int                  size_1 = 24;
	int                  size_2 = size_1;
	ft::set<std::string> ft_1   = _set_set_string(size_1);
	ft::set<std::string> ft_2   = _set_set_string(size_2);

	UnitTester::assert_((ft_1 != ft_2) == true);
}

void _set_operator_ne_same()
{
	set_explanation_("set not same to itself!?");
	int                  size_1 = 10;
	ft::set<std::string> ft_1   = _set_set_string(size_1);

	UnitTester::assert_((ft_1 != ft_1) == false);
}

void _set_operator_ne_compare()
{
	set_explanation_("int result differs from std");
	ft::set<std::string>  ft_1;
	std::set<std::string> std_1;
	_set_compare_sets(ft_1, std_1);
	ft::set<std::string>  ft_2;
	std::set<std::string> std_2;
	_set_compare_sets(ft_2, std_2);

	bool val1 = ft_1 != ft_2;
	UnitTester::assert_(val1 == (std_1 != std_2));
}

void set_operator_ne()
{
	load_subtest_(_set_operator_ne_true);
	load_subtest_(_set_operator_ne_true2);
	load_subtest_(_set_operator_ne_false);
	load_subtest_(_set_operator_ne_same);
	load_subtest_(_set_operator_ne_compare);
}

// -------------------------------------------------------------------------- //
//                                 operator<                                  //
// -------------------------------------------------------------------------- //

void _set_operator_l_true()
{
	set_explanation_("char set size difference not evaluated correctly");
	int           size = 10;
	ft::set<char> ft_0 = _set_set_char(size, true);
	ft::set<char> ft_1 = _set_set_char(size, true);

	ft_0.erase(--ft_0.end());
	// _debug(ft_0, "0");
	// _debug(ft_1, "1");
	UnitTester::assert_((ft_0 < ft_1) == true);
}

void _set_operator_l_false()
{
	set_explanation_("char set size difference not evaluated correctly");
	int           size  = 10;
	int           size2 = 1;
	ft::set<char> ft_0  = _set_set_char(size, true);
	ft::set<char> ft_1  = _set_set_char(size2, true);

	// _debug(ft_0, "0");
	// _debug(ft_1, "1");
	UnitTester::assert_((ft_0 < ft_1) == false);
}

void _set_operator_l_same()
{
	set_explanation_("equal int values not evaluated correctly");
	int          size = 10;
	ft::set<int> ft   = _set_set(size, true);

	UnitTester::assert_((ft < ft) == false);
}

void _set_operator_l_compare()
{
	set_explanation_("int result differs from std");
	ft::set<std::string>  ft_1;
	std::set<std::string> std_1;
	_set_compare_sets(ft_1, std_1);
	ft::set<std::string>  ft_2;
	std::set<std::string> std_2;
	_set_compare_sets(ft_2, std_2);

	bool val1 = ft_1 < ft_2;
	bool val2 = ft_2 < ft_1;
	UnitTester::assert_(val1 == (std_1 < std_2));
	UnitTester::assert_(val2 == (std_2 < std_1));
}

void set_operator_l()
{
	load_subtest_(_set_operator_l_true);
	load_subtest_(_set_operator_l_false);
	load_subtest_(_set_operator_l_same);
	load_subtest_(_set_operator_l_compare);
}

// -------------------------------------------------------------------------- //
//                                 operator<=                                 //
// -------------------------------------------------------------------------- //

void _set_operator_le_true()
{
	set_explanation_("std::string set size difference not evaluated correctly");
	int                  size = 10;
	ft::set<std::string> ft_0 = _set_set_string(size, true);
	ft::set<std::string> ft_1 = _set_set_string(size, true);

	ft_0.erase(--ft_0.end());
	// _debug(ft_0, "0");
	// _debug(ft_1, "1");
	UnitTester::assert_((ft_0 <= ft_1) == true);
}

void _set_operator_le_false()
{
	set_explanation_("char set size difference not evaluated correctly");
	int           size_1 = 0;
	int           size_2 = 12;
	ft::set<char> ft_1   = _set_set_char(size_1, true);
	ft::set<char> ft_2   = _set_set_char(size_2, true);

	UnitTester::assert_((ft_2 <= ft_1) == false);
}

void _set_operator_le_same()
{
	set_explanation_("equal std::string values not evaluated correctly");
	int                  size = 10;
	ft::set<std::string> ft   = _set_set_string(size, true);

	UnitTester::assert_((ft <= ft) == true);
}

void _set_operator_le_compare()
{
	set_explanation_("int result differs from std");
	ft::set<std::string>  ft_1;
	std::set<std::string> std_1;
	_set_compare_sets(ft_1, std_1);
	ft::set<std::string>  ft_2;
	std::set<std::string> std_2;
	_set_compare_sets(ft_2, std_2);

	bool val1 = ft_1 <= ft_2;
	bool val2 = ft_2 <= ft_1;
	UnitTester::assert_(val1 == (std_1 <= std_2));
	UnitTester::assert_(val2 == (std_2 <= std_1));
}

void set_operator_le()
{
	load_subtest_(_set_operator_le_true);
	load_subtest_(_set_operator_le_false);
	load_subtest_(_set_operator_le_same);
	load_subtest_(_set_operator_le_compare);
}

// -------------------------------------------------------------------------- //
//                                 operator>                                  //
// -------------------------------------------------------------------------- //

void _set_operator_g_true()
{
	set_explanation_("char set size difference not evaluated correctly");
	int           size_1 = 21;
	int           size_2 = 12;
	ft::set<char> ft_1   = _set_set_char(size_1, true);
	ft::set<char> ft_2   = _set_set_char(size_2, true);

	UnitTester::assert_((ft_1 > ft_2) == true);
}

void _set_operator_g_false()
{
	set_explanation_("char set size difference not evaluated correctly");
	int           size = 12;
	ft::set<char> ft_1 = _set_set_char(size, false);
	ft::set<char> ft_2 = ft_1;

	ft_1.erase(--ft_1.end());
	// _debug(ft_1, "1");
	// _debug(ft_2, "2");
	UnitTester::assert_((ft_1 > ft_2) == false);
}

void _set_operator_g_same()
{
	set_explanation_("equal std::string values not evaluated correctly");
	int                  size = 10;
	ft::set<std::string> ft   = _set_set_string(size, true);

	UnitTester::assert_((ft > ft) == false);
}

void _set_operator_g_compare()
{
	set_explanation_("int result differs from std");
	ft::set<std::string>  ft_1;
	std::set<std::string> std_1;
	_set_compare_sets(ft_1, std_1);
	ft::set<std::string>  ft_2;
	std::set<std::string> std_2;
	_set_compare_sets(ft_2, std_2);

	bool val1 = ft_1 > ft_2;
	bool val2 = ft_2 > ft_1;
	UnitTester::assert_(val1 == (std_1 > std_2));
	UnitTester::assert_(val2 == (std_2 > std_1));
}

void set_operator_g()
{
	load_subtest_(_set_operator_g_true);
	load_subtest_(_set_operator_g_false);
	load_subtest_(_set_operator_g_same);
	load_subtest_(_set_operator_g_compare);
}

// -------------------------------------------------------------------------- //
//                                 operator>=                                 //
// -------------------------------------------------------------------------- //

void _set_operator_ge_true()
{
	set_explanation_("std::string set size difference not evaluated correctly");
	ft::set<std::string> ft_1 = _set_set_string();
	ft::set<std::string> ft_2 = ft_1;

	std::string key = "42Tokyo~";
	ft_1.insert(key);
	// _debug(ft_1, "1");
	// _debug(ft_2, "2");
	UnitTester::assert_((ft_1 >= ft_2) == true);
}

void _set_operator_ge_false()
{
	set_explanation_("std::string set size difference not evaluated correctly");
	int                  size = 12;
	ft::set<std::string> ft_1 = _set_set_string(size, false);
	ft::set<std::string> ft_2 = ft_1;

	ft_1.erase(--ft_1.end());
	// _debug(ft_1, "1");
	// _debug(ft_2, "2");
	UnitTester::assert_((ft_1 >= ft_2) == false);
}

void _set_operator_ge_same()
{
	set_explanation_("equal int values not evaluated correctly");
	int          size = 42;
	ft::set<int> ft   = _set_set(size);

	UnitTester::assert_((ft >= ft) == true);
}

void _set_operator_ge_compare()
{
	set_explanation_("int result differs from std");
	ft::set<std::string>  ft_1;
	std::set<std::string> std_1;
	_set_compare_sets(ft_1, std_1);
	ft::set<std::string>  ft_2;
	std::set<std::string> std_2;
	_set_compare_sets(ft_2, std_2);

	bool val1 = ft_1 >= ft_2;
	bool val2 = ft_2 >= ft_1;
	UnitTester::assert_(val1 == (std_1 >= std_2));
	UnitTester::assert_(val2 == (std_2 >= std_1));
}

void set_operator_ge()
{
	load_subtest_(_set_operator_ge_true);
	load_subtest_(_set_operator_ge_false);
	load_subtest_(_set_operator_ge_same);
	load_subtest_(_set_operator_ge_compare);
}

// -------------------------------------------------------------------------- //
//                                  std::swap                                 //
// -------------------------------------------------------------------------- //

void _set_ft_swap_basic()
{
	set_explanation_("swapped value not correct");
	size_t       size_a = 10;
	size_t       size_b = 20;
	ft::set<int> ft_a   = _set_set(size_a, false);
	ft::set<int> ft_b   = _set_set(size_b, true);

	ft::swap(ft_a, ft_b);
	UnitTester::assert_(ft_a.size() == size_b);
	UnitTester::assert_(ft_b.size() == size_a);
}

void _set_ft_swap_compare()
{
	set_explanation_("result differs from std");
	ft::set<std::string>  ft_a;
	std::set<std::string> std_a;
	_set_compare_sets(ft_a, std_a);

	ft::set<std::string>  ft_b;
	std::set<std::string> std_b;
	_set_compare_sets(ft_b, std_b);

	ft::swap(ft_a, ft_b);
	std::swap(std_a, std_b);
	_compare_sets(ft_a, std_a);
	_compare_sets(ft_b, std_b);
}

void set_ft_swap()
{
	load_subtest_(_set_ft_swap_basic);
	load_subtest_(_set_ft_swap_compare);
}

} // namespace SetTest
