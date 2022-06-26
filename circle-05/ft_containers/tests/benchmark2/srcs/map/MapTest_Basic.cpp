#include "../includes/MapTest.hpp"
#include "../includes/UnitTester.hpp"
#include <iostream>
#include <map>

namespace MapTest {

/* -------------------------------------------------------------------------- */
/*                                 constructor                                */
/* -------------------------------------------------------------------------- */

void _map_constructor_default()
{
	set_explanation_("result differs from std behavior");
	ft::map<int, int>  ft;
	std::map<int, int> std;
	_compare_maps(ft, std);
}

void _map_constructor_is_ordered()
{
	int               size = 123;
	ft::map<int, int> ft;

	for (int i = 10; i < size; ++i) {
		ft[i] = i;
	}
	for (int i = 0; i < 10; ++i) {
		ft[i] = i;
	}

	set_explanation_("map is not ordered");
	ft::map<int, int>::iterator it = ft.begin();
	for (int i = 0; it != ft.end(); ++it, ++i) {
		UnitTester::assert_(it->first == i);
	}
}

void _map_constructor_range()
{
	set_explanation_("result differs from std behavior");
	size_t             size         = 14;
	ft::map<int, int>  map_base     = _set_map(size, true);
	std::map<int, int> map_base_std = _set_map_std(size, true);

	ft::map<int, int>  ft(map_base.begin(), map_base.end());
	std::map<int, int> std(map_base_std.begin(), map_base_std.end());
	_compare_maps(ft, std);
}

void _map_constructor_copy()
{
	set_explanation_("copy result differs from std behavior");
	ft::map<int, std::string>  ft;
	std::map<int, std::string> std;
	_set_compare_maps(ft, std);

	ft::map<int, std::string>  ft_cpy(ft);
	std::map<int, std::string> std_cpy(std);
	_compare_maps(ft_cpy, std_cpy);
}

void map_constructor()
{
	load_subtest_(_map_constructor_default);
	load_subtest_(_map_constructor_is_ordered);
	load_subtest_(_map_constructor_range);
	load_subtest_(_map_constructor_copy);
}

/* -------------------------------------------------------------------------- */
/*                                  destrucor                                 */
/* -------------------------------------------------------------------------- */

void _map_destructor()
{
	{
		set_explanation_("int x int; destructor crushes");
		ft::map<int, int> ft;
	}
	{
		set_explanation_("int x std::string; destructor crushes");
		ft::map<int, std::string> ft;
	}
	{
		set_explanation_("std::string x std::string; destructor crushes");
		ft::map<std::string, std::string> ft;
	}
}

void map_destructor()
{
	load_subtest_(_map_destructor);
}

// -------------------------------------------------------------------------- //
//                                  operator=                                 //
// -------------------------------------------------------------------------- //

void _map_assignemnt_operator_basic()
{
	set_explanation_("copy behavior changes original map");
	ft::map<int, std::string>  ft;
	std::map<int, std::string> std;
	_set_compare_maps(ft, std);

	ft::map<int, std::string>  ft_copy;
	std::map<int, std::string> std_copy;
	ft_copy  = ft;
	std_copy = std;
	_compare_maps(ft, std);
	set_explanation_("copy behavior changes new map");
	_compare_maps(ft_copy, std_copy);
}

void map_assignment_operator()
{
	load_subtest_(_map_assignemnt_operator_basic);
}

// -------------------------------------------------------------------------- //
//                                get_allocator                               //
// -------------------------------------------------------------------------- //

void _map_get_allocator_default()
{
	set_explanation_("allocator is not returned");
	ft::map<int, float> ft;

	std::allocator<std::string> alloc;
	UnitTester::assert_(ft.get_allocator() == alloc); // always return true
}

void map_get_allocator()
{
	load_subtest_(_map_get_allocator_default);
}

} // namespace MapTest
