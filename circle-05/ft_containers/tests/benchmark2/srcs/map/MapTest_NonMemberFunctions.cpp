#include "../includes/MapTest.hpp"
#include "../includes/UnitTester.hpp"
#include <iostream>
#include <map>

namespace MapTest {

// -------------------------------------------------------------------------- //
//                                 operator==                                 //
// -------------------------------------------------------------------------- //

void _map_operator_e_true()
{
	set_explanation_("wrong result on value int");
	int               size_1 = 10;
	int               size_2 = size_1;
	ft::map<int, int> ft_1   = _set_map(size_1, true);
	ft::map<int, int> ft_2   = _set_map(size_2, true);

	UnitTester::assert_((ft_1 == ft_2) == true);
}

void _map_operator_e_true_empty()
{
	set_explanation_("empty maps are not equal");
	ft::map<int, int> ft_1;
	ft::map<int, int> ft_2;

	UnitTester::assert_((ft_1 == ft_2) == true);
}

void _map_operator_e_false()
{
	set_explanation_("wrong result on size difference");
	int               size_1 = 10;
	int               size_2 = 12;
	ft::map<int, int> ft_1   = _set_map(size_1, true);
	ft::map<int, int> ft_2   = _set_map(size_2, true);

	UnitTester::assert_((ft_1 == ft_2) == false);
}
void _map_operator_e_false2()
{
	set_explanation_("wrong result on value and size difference");
	int               size_1 = 10;
	int               size_2 = 7;
	ft::map<int, int> ft_1   = _set_map(size_1);
	ft::map<int, int> ft_2   = _set_map(size_2);

	UnitTester::assert_((ft_1 == ft_2) == false);
}

void _map_operator_e_same()
{
	set_explanation_("map not same to itself!?");
	int                       size_1 = 10;
	ft::map<int, std::string> ft_1   = _set_map_string(size_1);

	UnitTester::assert_((ft_1 == ft_1) == true);
}

void _map_operator_e_compare()
{
	set_explanation_("int result differs from std");
	ft::map<int, std::string>  ft_1;
	std::map<int, std::string> std_1;
	_set_compare_maps(ft_1, std_1);

	ft::map<int, std::string>  ft_2;
	std::map<int, std::string> std_2;
	_set_compare_maps(ft_2, std_2);

	bool val1 = ft_1 == ft_2;
	UnitTester::assert_(val1 == (std_1 == std_2));
}

void map_operator_e()
{
	load_subtest_(_map_operator_e_true);
	load_subtest_(_map_operator_e_true_empty);
	load_subtest_(_map_operator_e_false);
	load_subtest_(_map_operator_e_false2);
	load_subtest_(_map_operator_e_same);
	load_subtest_(_map_operator_e_compare);
}

// -------------------------------------------------------------------------- //
//                                 operator!=                                 //
// -------------------------------------------------------------------------- //

void _map_operator_ne_true()
{
	set_explanation_("wrong result on value std::string");
	int                       size_1 = 2;
	int                       size_2 = 13;
	ft::map<int, std::string> ft_1   = _set_map_string(size_1);
	ft::map<int, std::string> ft_2   = _set_map_string(size_2);

	UnitTester::assert_((ft_1 != ft_2) == true);
}

void _map_operator_ne_true2()
{
	set_explanation_("wrong result on different content");
	int                       size_1 = 24;
	int                       size_2 = size_1;
	ft::map<int, std::string> ft_1   = _set_map_string(size_1, true);
	ft::map<int, std::string> ft_2   = _set_map_string(size_2, true);

	UnitTester::assert_((ft_1 != ft_2) == false);
}

void _map_operator_ne_false()
{
	set_explanation_("wrong result on same content");
	int                       size_1 = 24;
	int                       size_2 = size_1;
	ft::map<int, std::string> ft_1   = _set_map_string(size_1);
	ft::map<int, std::string> ft_2   = _set_map_string(size_2);

	UnitTester::assert_((ft_1 != ft_2) == true);
}

void _map_operator_ne_same()
{
	set_explanation_("map not same to itself!?");
	int                       size_1 = 10;
	ft::map<int, std::string> ft_1   = _set_map_string(size_1);

	UnitTester::assert_((ft_1 != ft_1) == false);
}

void _map_operator_ne_compare()
{
	set_explanation_("int result differs from std");
	ft::map<int, std::string>  ft_1;
	std::map<int, std::string> std_1;
	_set_compare_maps(ft_1, std_1);
	ft::map<int, std::string>  ft_2;
	std::map<int, std::string> std_2;
	_set_compare_maps(ft_2, std_2);

	bool val1 = ft_1 != ft_2;
	UnitTester::assert_(val1 == (std_1 != std_2));
}

void map_operator_ne()
{
	load_subtest_(_map_operator_ne_true);
	load_subtest_(_map_operator_ne_true2);
	load_subtest_(_map_operator_ne_false);
	load_subtest_(_map_operator_ne_same);
	load_subtest_(_map_operator_ne_compare);
}

// -------------------------------------------------------------------------- //
//                                 operator<                                  //
// -------------------------------------------------------------------------- //

void _map_operator_l_true()
{
	set_explanation_("char map size difference not evaluated correctly");
	int                size = 10;
	ft::map<int, char> ft_0 = _set_map_char(size, true);
	ft::map<int, char> ft_1 = _set_map_char(size, true);

	ft_0.erase(--ft_0.end());
	// _debug(ft_0, "0");
	// _debug(ft_1, "1");
	UnitTester::assert_((ft_0 < ft_1) == true);
}

void _map_operator_l_false()
{
	set_explanation_("char map size difference not evaluated correctly");
	int                size  = 10;
	int                size2 = 1;
	ft::map<int, char> ft_0  = _set_map_char(size, true);
	ft::map<int, char> ft_1  = _set_map_char(size2, true);

	// _debug(ft_0, "0");
	// _debug(ft_1, "1");
	UnitTester::assert_((ft_0 < ft_1) == false);
}

void _map_operator_l_same()
{
	set_explanation_("equal int values not evaluated correctly");
	int               size = 10;
	ft::map<int, int> ft   = _set_map(size, true);

	UnitTester::assert_((ft < ft) == false);
}

void _map_operator_l_compare()
{
	set_explanation_("int result differs from std");
	ft::map<int, std::string>  ft_1;
	std::map<int, std::string> std_1;
	_set_compare_maps(ft_1, std_1);
	ft::map<int, std::string>  ft_2;
	std::map<int, std::string> std_2;
	_set_compare_maps(ft_2, std_2);

	bool val1 = ft_1 < ft_2;
	bool val2 = ft_2 < ft_1;
	UnitTester::assert_(val1 == (std_1 < std_2));
	UnitTester::assert_(val2 == (std_2 < std_1));
}

void map_operator_l()
{
	load_subtest_(_map_operator_l_true);
	load_subtest_(_map_operator_l_false);
	load_subtest_(_map_operator_l_same);
	load_subtest_(_map_operator_l_compare);
}

// -------------------------------------------------------------------------- //
//                                 operator<=                                 //
// -------------------------------------------------------------------------- //

void _map_operator_le_true()
{
	set_explanation_("std::string map size difference not evaluated correctly");
	int                       size = 10;
	ft::map<int, std::string> ft_0 = _set_map_string(size, true);
	ft::map<int, std::string> ft_1 = _set_map_string(size, true);

	ft_0.erase(--ft_0.end());
	// _debug(ft_0, "0");
	// _debug(ft_1, "1");
	UnitTester::assert_((ft_0 <= ft_1) == true);
}

void _map_operator_le_false()
{
	set_explanation_("char map size difference not evaluated correctly");
	int                size_1 = 0;
	int                size_2 = 12;
	ft::map<int, char> ft_1   = _set_map_char(size_1, true);
	ft::map<int, char> ft_2   = _set_map_char(size_2, true);

	UnitTester::assert_((ft_2 <= ft_1) == false);
}

void _map_operator_le_same()
{
	set_explanation_("equal std::string values not evaluated correctly");
	int                       size = 10;
	ft::map<int, std::string> ft   = _set_map_string(size, true);

	UnitTester::assert_((ft <= ft) == true);
}

void _map_operator_le_compare()
{
	set_explanation_("int result differs from std");
	ft::map<int, std::string>  ft_1;
	std::map<int, std::string> std_1;
	_set_compare_maps(ft_1, std_1);
	ft::map<int, std::string>  ft_2;
	std::map<int, std::string> std_2;
	_set_compare_maps(ft_2, std_2);

	bool val1 = ft_1 <= ft_2;
	bool val2 = ft_2 <= ft_1;
	UnitTester::assert_(val1 == (std_1 <= std_2));
	UnitTester::assert_(val2 == (std_2 <= std_1));
}

void map_operator_le()
{
	load_subtest_(_map_operator_le_true);
	load_subtest_(_map_operator_le_false);
	load_subtest_(_map_operator_le_same);
	load_subtest_(_map_operator_le_compare);
}

// -------------------------------------------------------------------------- //
//                                 operator>                                  //
// -------------------------------------------------------------------------- //

void _map_operator_g_true()
{
	set_explanation_("char map size difference not evaluated correctly");
	int                size_1 = 21;
	int                size_2 = 12;
	ft::map<int, char> ft_1   = _set_map_char(size_1, true);
	ft::map<int, char> ft_2   = _set_map_char(size_2, true);

	UnitTester::assert_((ft_1 > ft_2) == true);
}

void _map_operator_g_false()
{
	set_explanation_("char map size difference not evaluated correctly");
	int                size = 12;
	ft::map<int, char> ft_1 = _set_map_char(size, false);
	ft::map<int, char> ft_2 = ft_1;

	ft_1.erase(--ft_1.end());
	// _debug(ft_1, "1");
	// _debug(ft_2, "2");
	UnitTester::assert_((ft_1 > ft_2) == false);
}

void _map_operator_g_same()
{
	set_explanation_("equal std::string values not evaluated correctly");
	int                       size = 10;
	ft::map<int, std::string> ft   = _set_map_string(size, true);

	UnitTester::assert_((ft > ft) == false);
}

void _map_operator_g_compare()
{
	set_explanation_("int result differs from std");
	ft::map<int, std::string>  ft_1;
	std::map<int, std::string> std_1;
	_set_compare_maps(ft_1, std_1);
	ft::map<int, std::string>  ft_2;
	std::map<int, std::string> std_2;
	_set_compare_maps(ft_2, std_2);

	bool val1 = ft_1 > ft_2;
	bool val2 = ft_2 > ft_1;
	UnitTester::assert_(val1 == (std_1 > std_2));
	UnitTester::assert_(val2 == (std_2 > std_1));
}

void map_operator_g()
{
	load_subtest_(_map_operator_g_true);
	load_subtest_(_map_operator_g_false);
	load_subtest_(_map_operator_g_same);
	load_subtest_(_map_operator_g_compare);
}

// -------------------------------------------------------------------------- //
//                                 operator>=                                 //
// -------------------------------------------------------------------------- //

void _map_operator_ge_true()
{
	set_explanation_("std::string map size difference not evaluated correctly");
	ft::map<int, std::string> ft_1 = _set_map_string();
	ft::map<int, std::string> ft_2 = ft_1;

	int         key   = 42;
	std::string value = "apple";
	ft_1[key]         = value;
	// _debug(ft_1, "1");
	// _debug(ft_2, "2");
	UnitTester::assert_((ft_1 >= ft_2) == true);
}

void _map_operator_ge_false()
{
	set_explanation_("std::string map size difference not evaluated correctly");
	int                       size = 12;
	ft::map<int, std::string> ft_1 = _set_map_string(size, false);
	ft::map<int, std::string> ft_2 = ft_1;

	ft_1.erase(--ft_1.end());
	// _debug(ft_1, "1");
	// _debug(ft_2, "2");
	UnitTester::assert_((ft_1 >= ft_2) == false);
}

void _map_operator_ge_same()
{
	set_explanation_("equal int values not evaluated correctly");
	int               size = 42;
	ft::map<int, int> ft   = _set_map(size);

	UnitTester::assert_((ft >= ft) == true);
}

void _map_operator_ge_compare()
{
	set_explanation_("int result differs from std");
	ft::map<int, std::string>  ft_1;
	std::map<int, std::string> std_1;
	_set_compare_maps(ft_1, std_1);
	ft::map<int, std::string>  ft_2;
	std::map<int, std::string> std_2;
	_set_compare_maps(ft_2, std_2);

	bool val1 = ft_1 >= ft_2;
	bool val2 = ft_2 >= ft_1;
	UnitTester::assert_(val1 == (std_1 >= std_2));
	UnitTester::assert_(val2 == (std_2 >= std_1));
}

void map_operator_ge()
{
	load_subtest_(_map_operator_ge_true);
	load_subtest_(_map_operator_ge_false);
	load_subtest_(_map_operator_ge_same);
	load_subtest_(_map_operator_ge_compare);
}

// -------------------------------------------------------------------------- //
//                                  ft::swap                                  //
// -------------------------------------------------------------------------- //

void _map_ft_swap_basic()
{
	set_explanation_("swapped value not correct");
	size_t            size_a = 10;
	size_t            size_b = 20;
	ft::map<int, int> ft_a   = _set_map(size_a, false);
	ft::map<int, int> ft_b   = _set_map(size_b, true);

	ft::swap(ft_a, ft_b);
	UnitTester::assert_(ft_a.size() == size_b);
	UnitTester::assert_(ft_b.size() == size_a);
}

void _map_ft_swap_compare()
{
	set_explanation_("result differs from std");
	ft::map<int, std::string>  ft_a;
	std::map<int, std::string> std_a;
	_set_compare_maps(ft_a, std_a);

	ft::map<int, std::string>  ft_b;
	std::map<int, std::string> std_b;
	_set_compare_maps(ft_b, std_b);

	ft::swap(ft_a, ft_b);
	std::swap(std_a, std_b);
	_compare_maps(ft_a, std_a);
	_compare_maps(ft_b, std_b);
}

void map_ft_swap()
{
	load_subtest_(_map_ft_swap_basic);
	load_subtest_(_map_ft_swap_compare);
}

/* -------------------------------------------------------------------------- */
/*                                ft::make_pair                               */
/* -------------------------------------------------------------------------- */

void _map_ft_make_pair_basic()
{
	int                        first   = 42;
	std::string                second  = "Tokyo";
	ft::pair<int, std::string> ft_pair = ft::make_pair(first, second);

	UnitTester::assert_(ft_pair.first == first);
	UnitTester::assert_(ft_pair.second == second);
}

void _map_ft_make_pair_compare()
{
	int                         first    = 42;
	std::string                 second   = "Tokyo";
	ft::pair<int, std::string>  ft_pair  = ft::make_pair(first, second);
	std::pair<int, std::string> std_pair = std::make_pair(first, second);

	UnitTester::assert_(ft_pair.first == std_pair.first);
	UnitTester::assert_(ft_pair.second == std_pair.second);
}

void map_ft_make_pair()
{
	load_subtest_(_map_ft_make_pair_basic);
	load_subtest_(_map_ft_make_pair_compare);
}

} // namespace MapTest
