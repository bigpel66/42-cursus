#include "../includes/MapTest.hpp"
#include "../includes/UnitTester.hpp"
#include <iostream>
#include <map>

namespace MapTest {

/* -------------------------------------------------------------------------- */
/*                                  key_comp                                  */
/* -------------------------------------------------------------------------- */

void _map_key_comp()
{
	set_explanation_("result differs from std");
	int                        size = 42;
	ft::map<int, std::string>  ft;
	std::map<int, std::string> std;
	_set_compare_maps(ft, std, size);

	ft::map<int, std::string>::key_compare  ft_comp  = ft.key_comp();
	std::map<int, std::string>::key_compare std_comp = std.key_comp();
	UnitTester::assert_(ft_comp(ft.begin()->first, (++ft.begin())->first)
	                    == std_comp(std.begin()->first, (++std.begin())->first));
}

void map_key_comp()
{
	load_subtest_(_map_key_comp);
}

/* -------------------------------------------------------------------------- */
/*                                 value_comp                                 */
/* -------------------------------------------------------------------------- */
struct ModCmp {
	bool operator()(const int lhs, const int rhs) const { return (lhs % 97) < (rhs % 97); }
};

void _map_value_comp()
{
	set_explanation_("result differs from std");
	int                         size = 42;
	ft::map<int, char, ModCmp>  ft;
	std::map<int, char, ModCmp> std;
	_set_compare_maps(ft, std, size);

	ft::map<int, char, ModCmp>::value_compare  ft_comp  = ft.value_comp();
	std::map<int, char, ModCmp>::value_compare std_comp = std.value_comp();

	const ft::pair<int, char>  val(ft::make_pair(100, 'a'));
	const std::pair<int, char> val_std(std::make_pair(100, 'a'));

	ft::map<int, char, ModCmp>::iterator  it  = ft.begin();
	std::map<int, char, ModCmp>::iterator its = std.begin();
	for (; it != ft.end(); ++it, ++its) {
		UnitTester::assert_(ft_comp(*it, val) == std_comp(*its, val_std));
	}
}

void map_value_comp()
{
	load_subtest_(_map_value_comp);
}

} // namespace MapTest
