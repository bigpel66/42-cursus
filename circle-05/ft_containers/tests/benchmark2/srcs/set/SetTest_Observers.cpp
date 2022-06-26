#include "../includes/SetTest.hpp"
#include "../includes/UnitTester.hpp"
#include <iostream>
#include <set>

namespace SetTest {

/* -------------------------------------------------------------------------- */
/*                                  key_comp                                  */
/* -------------------------------------------------------------------------- */

void _set_key_comp()
{
	set_explanation_("result differs from std");
	int                   size = 42;
	ft::set<std::string>  ft;
	std::set<std::string> std;
	_set_compare_sets(ft, std, size);

	ft::set<std::string>::key_compare  ft_comp  = ft.key_comp();
	std::set<std::string>::key_compare std_comp = std.key_comp();
	UnitTester::assert_(
	    ft_comp(*(ft.begin()), *(++ft.begin())) == std_comp(*(std.begin()), *(++std.begin())));
}

void set_key_comp()
{
	load_subtest_(_set_key_comp);
}

/* -------------------------------------------------------------------------- */
/*                                 value_comp                                 */
/* -------------------------------------------------------------------------- */

void _set_value_comp()
{
	set_explanation_("result differs from std");
	int                   size = 42;
	ft::set<std::string>  ft;
	std::set<std::string> std;
	_set_compare_sets(ft, std, size);

	ft::set<std::string>::key_compare  ft_comp  = ft.key_comp();
	std::set<std::string>::key_compare std_comp = std.key_comp();
	UnitTester::assert_(
	    ft_comp(*(ft.begin()), *(++ft.begin())) == std_comp(*(std.begin()), *(++std.begin())));
}

void set_value_comp()
{
	load_subtest_(_set_value_comp);
}

} // namespace SetTest
