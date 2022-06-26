#include "../includes/MapTest.hpp"
#include "../includes/UnitTester.hpp"
#include <iostream>
#include <map>

namespace MapTest {

/* -------------------------------------------------------------------------- */
/*                                     at                                     */
/* -------------------------------------------------------------------------- */

void _map_at_basic()
{
	set_explanation_("does not return the right value");

	int               size = 10;
	ft::map<int, int> ft   = _set_map(size, true);

	for (int i = 0; i < size; ++i) {
		UnitTester::assert_(ft.at(i) == i);
	}
}

void _map_at_compare()
{
	set_explanation_("ft behaviour differs from std");

	int                        size = 20;
	ft::map<int, std::string>  ft;
	std::map<int, std::string> std;
	_set_compare_maps(ft, std, size);

	for (int i = 0; i < size; i++) {
		UnitTester::assert_(ft.at(i) == std.at(i));
	}
}

void _map_at_out_of_range()
{
	set_explanation_("out of range does not throw appropriate exception");

	int               size = 4;
	ft::map<int, int> ft   = _set_map(size, true);

	for (int i = 0; i < size + 3; ++i) {
		try {
			ft.at(i);
		} catch (std::out_of_range& e) {
			UnitTester::assert_(strlen(e.what()) != 0);
		} catch (std::exception& e) {
			UnitTester::assert_(false);
		}
	}
}

void map_at()
{
	load_subtest_(_map_at_basic);
	load_subtest_(_map_at_compare);
	load_subtest_(_map_at_out_of_range);
}

// -------------------------------------------------------------------------- //
//                                 operator[]                                 //
// -------------------------------------------------------------------------- //

void _map_subscript_operator_basic()
{
	set_explanation_("does not return right value. Really!?");
	int               size = 12;
	ft::map<int, int> ft   = _set_map(size, true);

	for (int i = 0; i < size; ++i)
		UnitTester::assert_(ft[i] == i);
}

void _map_subscript_operator_compare()
{
	set_explanation_("does not return right value. Really!?");
	int                        size = 12;
	ft::map<int, std::string>  ft;
	std::map<int, std::string> std;
	_set_compare_maps(ft, std, 12);

	for (int i = 0; i < size; ++i)
		UnitTester::assert_(ft[i] == std[i]);
}

void map_subscript_operator()
{
	load_subtest_(_map_subscript_operator_basic);
	load_subtest_(_map_subscript_operator_compare);
}

} // namespace MapTest
