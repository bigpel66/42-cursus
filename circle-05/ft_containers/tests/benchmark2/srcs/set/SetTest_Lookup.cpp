#include "../includes/SetTest.hpp"
#include "../includes/UnitTester.hpp"
#include <iostream>
#include <set>

namespace SetTest {

/* -------------------------------------------------------------------------- */
/*                                    count                                   */
/* -------------------------------------------------------------------------- */

void _set_count_expect_0()
{
	set_explanation_("does not return 0 on non-existing int key");
	size_t       size = 12;
	ft::set<int> ft   = _set_set(size, true);

	UnitTester::assert_(ft.count(size + 1) == 0);
}

void _set_count_expect_1()
{
	set_explanation_("does not return 1 on existing int key");
	size_t       size = 12;
	ft::set<int> ft   = _set_set(size, true);

	UnitTester::assert_(ft.count(0) == 1);
}

void set_count()
{
	load_subtest_(_set_count_expect_0);
	load_subtest_(_set_count_expect_1);
}

/* -------------------------------------------------------------------------- */
/*                                    find                                    */
/* -------------------------------------------------------------------------- */

void _set_find_dne()
{
	size_t       size = 12;
	ft::set<int> ft   = _set_set(size, true);

	set_explanation_("does not return end() on non-existing int key");
	UnitTester::assert_(ft.find(size + 1) == ft.end());
}

void _set_find_exist()
{
	size_t       size = 12;
	ft::set<int> ft   = _set_set(size, true);

	int                    key = 1;
	ft::set<int>::iterator it  = ft.find(key);
	set_explanation_("returning end() on existing int key");
	UnitTester::assert_(it != ft.end());
	set_explanation_("returned iterator is not pointing to the key-value set");
	UnitTester::assert_(*it == key);
}

void set_find()
{
	load_subtest_(_set_find_dne);
	load_subtest_(_set_find_exist);
}

/* -------------------------------------------------------------------------- */
/*                                 equal_range                                */
/* -------------------------------------------------------------------------- */

void _set_equal_range()
{
	size_t       size = 12;
	ft::set<int> ft   = _set_set(size, true);

	typedef ft::set<int>::iterator iterator;
	int                            val = 1;
	ft::pair<iterator, iterator>   it  = ft.equal_range(val);

	set_explanation_("unexpected; it.first expected to be equal to val");
	UnitTester::assert_(it.first == ft.find(val));
	set_explanation_("unexpected; it.second expected to be one-past p.first");
	UnitTester::assert_(it.second == ft.find(val + 1));
}

void _set_equal_range_no_not_less()
{
	size_t       size = 12;
	ft::set<int> ft   = _set_set(size, true);

	typedef ft::set<int>::iterator iterator;
	int                            val = -1;
	ft::pair<iterator, iterator>   it  = ft.equal_range(val);

	set_explanation_("unexpected; it.first expected to be equal to val");
	UnitTester::assert_(it.first == ft.begin());
	set_explanation_("unexpected; it.second expected to be begin()");
	UnitTester::assert_(it.second == ft.begin());
}

void _set_equal_range_no_greater()
{
	size_t       size = 12;
	ft::set<int> ft   = _set_set(size, true);

	typedef ft::set<int>::iterator iterator;
	int                            val = size - 1;
	ft::pair<iterator, iterator>   it  = ft.equal_range(val);

	set_explanation_("unexpected; it.first expected to be equal to val");
	UnitTester::assert_(it.first == ft.find(val));
	set_explanation_("unexpected; it.second expected to be end()");
	UnitTester::assert_(it.second == ft.end());
}

void set_equal_range()
{
	load_subtest_(_set_equal_range);
	load_subtest_(_set_equal_range_no_not_less);
	load_subtest_(_set_equal_range_no_greater);
}

/* -------------------------------------------------------------------------- */
/*                                 lower_bound                                */
/* -------------------------------------------------------------------------- */

void _set_lower_bound()
{
	size_t       size = 12;
	ft::set<int> ft   = _set_set(size, true);

	int                    val = 1;
	ft::set<int>::iterator it  = ft.lower_bound(val);

	set_explanation_("it expected to be equal to val");
	UnitTester::assert_(it == ft.find(val));
}

void _set_lower_bound_const()
{
	size_t       size = 12;
	ft::set<int> ft   = _set_set(size, true);

	const int              val = 7;
	ft::set<int>::iterator it  = ft.lower_bound(val);

	set_explanation_("it expected to be equal to val");
	UnitTester::assert_(it == ft.find(val));
}

void _set_lower_bound_last()
{
	size_t       size = 12;
	ft::set<int> ft   = _set_set(size, true);

	int                    val = size - 1;
	ft::set<int>::iterator it  = ft.lower_bound(val);

	set_explanation_("it expected to be equal to val");
	UnitTester::assert_(it == ft.find(val));
}

void _set_lower_bound_dne()
{
	size_t       size = 12;
	ft::set<int> ft   = _set_set(size, true);

	int                    val = -1;
	ft::set<int>::iterator it  = ft.lower_bound(val);

	set_explanation_("it expected to be equal to begin()");
	UnitTester::assert_(it == ft.begin());
}

void _set_lower_bound_greatest()
{
	size_t       size = 24;
	ft::set<int> ft   = _set_set(size, true);

	int                    val = size;
	ft::set<int>::iterator it  = ft.lower_bound(val);

	set_explanation_("it expected to be equal to end()");
	UnitTester::assert_(it == ft.end());
}

void set_lower_bound()
{
	load_subtest_(_set_lower_bound);
	load_subtest_(_set_lower_bound_const);
	load_subtest_(_set_lower_bound_last);
	load_subtest_(_set_lower_bound_dne);
	load_subtest_(_set_lower_bound_greatest);
}

/* -------------------------------------------------------------------------- */
/*                                 upper_bound                                */
/* -------------------------------------------------------------------------- */

void _set_upper_bound()
{
	size_t       size = 12;
	ft::set<int> ft   = _set_set(size, true);

	int                    val = 1;
	ft::set<int>::iterator it  = ft.upper_bound(val);

	set_explanation_("it expected to be equal to val + 1");
	UnitTester::assert_(it == ft.find(val + 1));
}

void _set_upper_bound_const()
{
	size_t       size = 12;
	ft::set<int> ft   = _set_set(size, true);

	const int              val = 7;
	ft::set<int>::iterator it  = ft.upper_bound(val);

	set_explanation_("it expected to be equal to val + 1");
	UnitTester::assert_(it == ft.find(val + 1));
}

void _set_upper_bound_dne()
{
	size_t       size = 12;
	ft::set<int> ft   = _set_set(size, true);

	int                    val = -1;
	ft::set<int>::iterator it  = ft.upper_bound(val);

	set_explanation_("it expected to be equal to begin()");
	UnitTester::assert_(it == ft.begin());
}

void _set_upper_bound_greatest()
{
	size_t       size = 24;
	ft::set<int> ft   = _set_set(size, true);

	int                    val = size;
	ft::set<int>::iterator it  = ft.upper_bound(val);

	set_explanation_("it expected to be equal to end()");
	UnitTester::assert_(it == ft.end());
}

void set_upper_bound()
{
	load_subtest_(_set_upper_bound);
	load_subtest_(_set_upper_bound_const);
	load_subtest_(_set_upper_bound_dne);
	load_subtest_(_set_upper_bound_greatest);
}

} // namespace SetTest
