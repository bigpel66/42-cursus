#include "../includes/MapTest.hpp"
#include "../includes/UnitTester.hpp"
#include <iostream>
#include <map>

namespace MapTest {

/* -------------------------------------------------------------------------- */
/*                                    empty                                   */
/* -------------------------------------------------------------------------- */

void _map_empty_true()
{
	set_explanation_("empty check not working. Really!?");
	ft::map<int, int> ft_data = _set_map(0, true);
	UnitTester::assert_(ft_data.empty() == true);
}

void _map_empty_false()
{
	set_explanation_("empty check not working. Really!?");
	size_t            size    = 42;
	ft::map<int, int> ft_data = _set_map(size, true);
	UnitTester::assert_(ft_data.empty() == false);
}

void map_empty()
{
	load_subtest_(_map_empty_true);
	load_subtest_(_map_empty_false);
}

// -------------------------------------------------------------------------- //
//                                    size                                    //
// -------------------------------------------------------------------------- //

void _map_size_zero()
{
	set_explanation_("wrong size returned on size 0");
	ft::map<int, int> ft_data = _set_map(0, true);
	UnitTester::assert_(ft_data.size() == 0);
}

void _map_size_one()
{
	set_explanation_("wrong size returned on size 1");
	ft::map<int, int> ft_data = _set_map(1, true);
	UnitTester::assert_(ft_data.size() == 1);
}

void _map_size_more()
{
	set_explanation_("wrong size returned on size more than 1");
	size_t            size    = 42;
	ft::map<int, int> ft_data = _set_map(size, true);
	UnitTester::assert_(ft_data.size() == size);
}

void map_size()
{
	load_subtest_(_map_size_zero);
	load_subtest_(_map_size_one);
	load_subtest_(_map_size_more);
}

// -------------------------------------------------------------------------- //
//                                  max_size                                  //
// -------------------------------------------------------------------------- //

void _map_max_size_multiple()
{
	int               size = 10;
	ft::map<int, int> ft   = _set_map(size);
	ft::map<int, int> ft2  = _set_map(size + 100);

	set_explanation_("0 returned");
	UnitTester::assert_(ft.max_size() != 0);
	set_explanation_("multiple maps does not return the same max value");
	UnitTester::assert_(ft.max_size() == ft2.max_size());
}

void _map_max_size_compare()
{
	set_explanation_("result differs from std");
	ft::map<int, std::string>  ft;
	std::map<int, std::string> std;
	_set_compare_maps(ft, std);

	UnitTester::assert_(ft.max_size() == std.max_size());
}

void map_max_size()
{
	load_subtest_(_map_max_size_multiple);
	load_subtest_(_map_max_size_compare);
}

} // namespace MapTest
