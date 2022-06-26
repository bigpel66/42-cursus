#include "../includes/SetTest.hpp"
#include "../includes/UnitTester.hpp"
#include <iostream>
#include <set>

namespace SetTest {

/* -------------------------------------------------------------------------- */
/*                                    empty                                   */
/* -------------------------------------------------------------------------- */

void _set_empty_true()
{
	set_explanation_("empty check not working. Really!?");
	ft::set<int> ft_data = _set_set(0, true);
	UnitTester::assert_(ft_data.empty() == true);
}

void _set_empty_false()
{
	set_explanation_("empty check not working. Really!?");
	size_t       size    = 42;
	ft::set<int> ft_data = _set_set(size, true);
	UnitTester::assert_(ft_data.empty() == false);
}

void set_empty()
{
	load_subtest_(_set_empty_true);
	load_subtest_(_set_empty_false);
}

// -------------------------------------------------------------------------- //
//                                    size                                    //
// -------------------------------------------------------------------------- //

void _set_size_zero()
{
	set_explanation_("wrong size returned on size 0");
	ft::set<int> ft_data = _set_set(0, true);
	UnitTester::assert_(ft_data.size() == 0);
}

void _set_size_one()
{
	set_explanation_("wrong size returned on size 1");
	ft::set<int> ft_data = _set_set(1, true);
	UnitTester::assert_(ft_data.size() == 1);
}

void _set_size_more()
{
	set_explanation_("wrong size returned on size more than 1");
	size_t       size    = 42;
	ft::set<int> ft_data = _set_set(size, true);
	UnitTester::assert_(ft_data.size() == size);
}

void set_size()
{
	load_subtest_(_set_size_zero);
	load_subtest_(_set_size_one);
	load_subtest_(_set_size_more);
}

// -------------------------------------------------------------------------- //
//                                  max_size                                  //
// -------------------------------------------------------------------------- //

void _set_max_size_multiple()
{
	int          size = 10;
	ft::set<int> ft   = _set_set(size);
	ft::set<int> ft2  = _set_set(size + 100);

	set_explanation_("0 returned");
	UnitTester::assert_(ft.max_size() != 0);
	set_explanation_("multiple sets does not return the same max value");
	UnitTester::assert_(ft.max_size() == ft2.max_size());
}

void _set_max_size_compare()
{
	set_explanation_("result differs from std");
	ft::set<std::string>  ft;
	std::set<std::string> std;
	_set_compare_sets(ft, std);

	UnitTester::assert_(ft.max_size() == std.max_size());
}

void set_max_size()
{
	load_subtest_(_set_max_size_multiple);
	load_subtest_(_set_max_size_compare);
}

} // namespace SetTest
