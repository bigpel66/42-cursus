#include "../includes/SetTest.hpp"
#include "../includes/UnitTester.hpp"
#include <iostream>
#include <set>

namespace SetTest {

// -------------------------------------------------------------------------- //
//                                    begin                                   //
// -------------------------------------------------------------------------- //

void _set_begin_basic()
{
	set_explanation_("does not return the right value");
	int          size = 12;
	ft::set<int> ft   = _set_set(size, true);

	UnitTester::assert_(*(ft.begin()) == 0);
}

void _set_begin_increment()
{
	set_explanation_("post increment returns wrong value");
	int          size = 12;
	ft::set<int> ft   = _set_set(size, true);

	UnitTester::assert_(*(ft.begin()) == 0);
	UnitTester::assert_(*(++ft.begin()) == 1);
	UnitTester::assert_(*(++(++ft.begin())) == 2);
}

void _set_begin_decrement()
{
	set_explanation_("post decrement returns wrong value");
	int          size = 12;
	ft::set<int> ft   = _set_set(size, true);

	// ft::set<int>::iterator it = ft.begin();

	// UnitTester::assert_(it->first == 3);
	// UnitTester::assert_(it->first == 3);
	// UnitTester::assert_(it->first == 1);
	// UnitTester::assert_(it->first == 0);
}

void set_begin()
{
	load_subtest_(_set_begin_basic);
	// load_subtest_(_set_begin_increment);
}

// -------------------------------------------------------------------------- //
//                                    end                                   //
// -------------------------------------------------------------------------- //

void _set_end_basic()
{
	set_explanation_("does not return the right value");
	int          size = 7;
	ft::set<int> ft   = _set_set(size, true);

	UnitTester::assert_(*(--ft.end()) == size - 1);
}

void _set_end_increment()
{
	set_explanation_("post increment returns wrong value");
	// ft::set<int> ft   = _set_set(size, true);

	// UnitTester::assert_(*--ft.end() == size - 1);
	// UnitTester::assert_(*--(--ft.end()) == size - 2);
	// UnitTester::assert_(*--(--(--ft.end())) == size - 3);
}

void set_end()
{
	load_subtest_(_set_end_basic);
	// load_subtest_(_set_end_increment);
}

// -------------------------------------------------------------------------- //
//                                    rbegin                                  //
// -------------------------------------------------------------------------- //

void _set_rbegin_basic()
{
	set_explanation_("does not return the right value");
	int          size = 12;
	ft::set<int> ft   = _set_set(size, true);

	UnitTester::assert_(*(ft.rbegin()) == size - 1);
}

void _set_rbegin_increment()
{
	set_explanation_("post increment returns wrong value");
	int          size = 12;
	ft::set<int> ft   = _set_set(size, true);

	// UnitTester::assert_(ft.rbegin() == size - 1);
	// UnitTester::assert_(++ft.rbegin() == size - 2);
	// UnitTester::assert_(++(++ft.rbegin()) == size - 3);
}

void set_rbegin()
{
	load_subtest_(_set_rbegin_basic);
	// load_subtest_(_set_rbegin_increment);
}

// -------------------------------------------------------------------------- //
//                                    rend                                    //
// -------------------------------------------------------------------------- //

void _set_rend_basic()
{
	set_explanation_("does not return the right value");
	int          size = 7;
	ft::set<int> ft   = _set_set(size, true);

	UnitTester::assert_(*(--ft.rend()) == 0);
}

void _set_rend_increment()
{
	set_explanation_("post increment returns wrong value");
	int          size = 9;
	ft::set<int> ft   = _set_set(size, true);

	// UnitTester::assert_(*--ft.rend() == 0);
	// UnitTester::assert_(*--(--ft.rend()) == 1);
	// UnitTester::assert_(*--(--(--ft.rend())) == 2);
}

void set_rend()
{
	load_subtest_(_set_rend_basic);
	// load_subtest_(_set_rend_increment);
}

} // namespace SetTest
