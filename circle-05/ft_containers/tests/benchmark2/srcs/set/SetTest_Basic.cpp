#include "../includes/SetTest.hpp"
#include "../includes/UnitTester.hpp"
#include <iostream>
#include <set>

namespace SetTest {

/* -------------------------------------------------------------------------- */
/*                                 constructor                                */
/* -------------------------------------------------------------------------- */

void _set_constructor_default()
{
	set_explanation_("result differs from std behavior");
	ft::set<int>  ft;
	std::set<int> std;
	_compare_sets(ft, std);
}

void _set_constructor_range()
{
	set_explanation_("result differs from std behavior");
	size_t        size         = 14;
	ft::set<int>  set_base     = _set_set(size, true);
	std::set<int> set_base_std = _set_set_std(size, true);

	ft::set<int>  ft(set_base.begin(), set_base.end());
	std::set<int> std(set_base_std.begin(), set_base_std.end());
	_compare_sets(ft, std);
}

void _set_constructor_copy()
{
	set_explanation_("copy result differs from std behavior");
	ft::set<std::string>  ft;
	std::set<std::string> std;
	_set_compare_sets(ft, std);

	ft::set<std::string>  ft_cpy(ft);
	std::set<std::string> std_cpy(std);
	_compare_sets(ft_cpy, std_cpy);
}

void set_constructor()
{
	load_subtest_(_set_constructor_default);
	load_subtest_(_set_constructor_range);
	load_subtest_(_set_constructor_copy);
}

/* -------------------------------------------------------------------------- */
/*                                  destrucor                                 */
/* -------------------------------------------------------------------------- */

void _set_destructor()
{
	{
		set_explanation_("int x int; destructor crushes");
		ft::set<int> ft;
	}
	{
		set_explanation_("int x std::string; destructor crushes");
		ft::set<std::string> ft;
	}
	{
		set_explanation_("std::string x std::string; destructor crushes");
		ft::set<std::string, std::string> ft;
	}
}

void set_destructor()
{
	load_subtest_(_set_destructor);
}

// -------------------------------------------------------------------------- //
//                                  operator=                                 //
// -------------------------------------------------------------------------- //

void _set_assignemnt_operator_basic()
{
	set_explanation_("copy behavior changes original set");
	ft::set<std::string>  ft;
	std::set<std::string> std;
	_set_compare_sets(ft, std);

	ft::set<std::string>  ft_copy;
	std::set<std::string> std_copy;
	ft_copy  = ft;
	std_copy = std;
	_compare_sets(ft, std);
	set_explanation_("copy behavior changes new set");
	_compare_sets(ft_copy, std_copy);
}

void set_assignment_operator()
{
	load_subtest_(_set_assignemnt_operator_basic);
}

// -------------------------------------------------------------------------- //
//                                get_allocator                               //
// -------------------------------------------------------------------------- //

void _set_get_allocator_default()
{
	set_explanation_("allocator is not returned");
	ft::set<float> ft;

	std::allocator<std::string> alloc;
	UnitTester::assert_(ft.get_allocator() == alloc); // always return true
}

void set_get_allocator()
{
	load_subtest_(_set_get_allocator_default);
}

} // namespace SetTest
