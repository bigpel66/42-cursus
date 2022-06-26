#include "../includes/MapTest.hpp"
#include "../includes/UnitTester.hpp"
#include <iostream>
#include <map>

namespace MapTest {

/* -------------------------------------------------------------------------- */
/*                                    count                                   */
/* -------------------------------------------------------------------------- */

void _map_count_expect_0()
{
	set_explanation_("does not return 0 on non-existing int key");
	size_t            size = 12;
	ft::map<int, int> ft   = _set_map(size, true);

	UnitTester::assert_(ft.count(size + 1) == 0);
}

void _map_count_expect_1()
{
	set_explanation_("does not return 1 on existing int key");
	size_t            size = 12;
	ft::map<int, int> ft   = _set_map(size, true);

	UnitTester::assert_(ft.count(0) == 1);
}

void map_count()
{
	load_subtest_(_map_count_expect_0);
	load_subtest_(_map_count_expect_1);
}

/* -------------------------------------------------------------------------- */
/*                                    find                                    */
/* -------------------------------------------------------------------------- */

void _map_find_dne()
{
	size_t            size = 12;
	ft::map<int, int> ft   = _set_map(size, true);

	set_explanation_("does not return end() on non-existing int key");
	UnitTester::assert_(ft.find(size + 1) == ft.end());
}

void _map_find_exist()
{
	size_t            size = 12;
	ft::map<int, int> ft   = _set_map(size, true);

	int                         key = 1;
	ft::map<int, int>::iterator it  = ft.find(key);
	set_explanation_("returning end() on existing int key");
	UnitTester::assert_(it != ft.end());
	set_explanation_("returned iterator is not pointing to the key-value set");
	UnitTester::assert_(it->first == key);
}

void map_find()
{
	load_subtest_(_map_find_dne);
	load_subtest_(_map_find_exist);
}

/* -------------------------------------------------------------------------- */
/*                                 equal_range                                */
/* -------------------------------------------------------------------------- */

void _map_equal_range()
{
	size_t            size = 12;
	ft::map<int, int> ft   = _set_map(size, true);

	typedef ft::map<int, int>::iterator iterator;
	int                                 val = 1;
	ft::pair<iterator, iterator>        it  = ft.equal_range(val);

	set_explanation_("unexpected; it.first expected to be equal to val");
	UnitTester::assert_(it.first == ft.find(val));
	set_explanation_("unexpected; it.second expected to be one-past p.first");
	UnitTester::assert_(it.second == ft.find(val + 1));
}

void _map_equal_range_no_not_less()
{
	size_t            size = 12;
	ft::map<int, int> ft   = _set_map(size, true);

	typedef ft::map<int, int>::iterator iterator;
	int                                 val = -1;
	ft::pair<iterator, iterator>        it  = ft.equal_range(val);

	set_explanation_("unexpected; it.first expected to be equal to val");
	UnitTester::assert_(it.first == ft.begin());
	set_explanation_("unexpected; it.second expected to be begin()");
	UnitTester::assert_(it.second == ft.begin());
}

void _map_equal_range_no_greater()
{
	size_t            size = 12;
	ft::map<int, int> ft   = _set_map(size, true);

	typedef ft::map<int, int>::iterator iterator;
	int                                 val = size - 1;
	ft::pair<iterator, iterator>        it  = ft.equal_range(val);

	set_explanation_("unexpected; it.first expected to be equal to val");
	UnitTester::assert_(it.first == ft.find(val));
	set_explanation_("unexpected; it.second expected to be end()");
	UnitTester::assert_(it.second == ft.end());
}

void map_equal_range()
{
	load_subtest_(_map_equal_range);
	load_subtest_(_map_equal_range_no_not_less);
	load_subtest_(_map_equal_range_no_greater);
}

/* -------------------------------------------------------------------------- */
/*                                 lower_bound                                */
/* -------------------------------------------------------------------------- */

void _map_lower_bound()
{
	size_t            size = 12;
	ft::map<int, int> ft   = _set_map(size, true);

	int                         val = 1;
	ft::map<int, int>::iterator it  = ft.lower_bound(val);

	set_explanation_("it expected to be equal to val");
	UnitTester::assert_(it == ft.find(val));
}

void _map_lower_bound_const()
{
	size_t            size = 12;
	ft::map<int, int> ft   = _set_map(size, true);

	const int                   val = 7;
	ft::map<int, int>::iterator it  = ft.lower_bound(val);

	set_explanation_("it expected to be equal to val");
	UnitTester::assert_(it == ft.find(val));
}

void _map_lower_bound_last()
{
	size_t            size = 12;
	ft::map<int, int> ft   = _set_map(size, true);

	int                         val = size - 1;
	ft::map<int, int>::iterator it  = ft.lower_bound(val);

	set_explanation_("it expected to be equal to val");
	UnitTester::assert_(it == ft.find(val));
}

void _map_lower_bound_dne()
{
	size_t            size = 12;
	ft::map<int, int> ft   = _set_map(size, true);

	int                         val = -1;
	ft::map<int, int>::iterator it  = ft.lower_bound(val);

	set_explanation_("it expected to be equal to begin()");
	UnitTester::assert_(it == ft.begin());
}

void _map_lower_bound_greatest()
{
	size_t            size = 24;
	ft::map<int, int> ft   = _set_map(size, true);

	int                         val = size;
	ft::map<int, int>::iterator it  = ft.lower_bound(val);

	set_explanation_("it expected to be equal to end()");
	UnitTester::assert_(it == ft.end());
}

void map_lower_bound()
{
	load_subtest_(_map_lower_bound);
	load_subtest_(_map_lower_bound_const);
	load_subtest_(_map_lower_bound_last);
	load_subtest_(_map_lower_bound_dne);
	load_subtest_(_map_lower_bound_greatest);
}

/* -------------------------------------------------------------------------- */
/*                                 upper_bound                                */
/* -------------------------------------------------------------------------- */

void _map_upper_bound()
{
	size_t            size = 12;
	ft::map<int, int> ft   = _set_map(size, true);

	int                         val = 1;
	ft::map<int, int>::iterator it  = ft.upper_bound(val);

	set_explanation_("it expected to be equal to val + 1");
	UnitTester::assert_(it == ft.find(val + 1));
}

void _map_upper_bound_const()
{
	size_t            size = 12;
	ft::map<int, int> ft   = _set_map(size, true);

	const int                   val = 7;
	ft::map<int, int>::iterator it  = ft.upper_bound(val);

	set_explanation_("it expected to be equal to val + 1");
	UnitTester::assert_(it == ft.find(val + 1));
}

void _map_upper_bound_dne()
{
	size_t            size = 12;
	ft::map<int, int> ft   = _set_map(size, true);

	int                         val = -1;
	ft::map<int, int>::iterator it  = ft.upper_bound(val);

	set_explanation_("it expected to be equal to begin()");
	UnitTester::assert_(it == ft.begin());
}

void _map_upper_bound_greatest()
{
	size_t            size = 24;
	ft::map<int, int> ft   = _set_map(size, true);

	int                         val = size;
	ft::map<int, int>::iterator it  = ft.upper_bound(val);

	set_explanation_("it expected to be equal to end()");
	UnitTester::assert_(it == ft.end());
}

void map_upper_bound()
{
	load_subtest_(_map_upper_bound);
	load_subtest_(_map_upper_bound_const);
	load_subtest_(_map_upper_bound_dne);
	load_subtest_(_map_upper_bound_greatest);
}

} // namespace MapTest
