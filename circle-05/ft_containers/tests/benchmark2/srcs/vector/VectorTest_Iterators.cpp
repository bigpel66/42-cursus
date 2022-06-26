#include "../includes/Log.hpp"
#include "../includes/UnitTester.hpp"
#include "../includes/VectorTest.hpp"
#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

namespace VectorTest {

// -------------------------------------------------------------------------- //
//                                    begin                                   //
// -------------------------------------------------------------------------- //

void _vector_begin_basic()
{
	set_explanation_("does not return the right value");
	int             size = 12;
	ft::vector<int> data = _set_vector(size, true);

	UnitTester::assert_(*data.begin() == 0);
}

void _vector_begin_increment()
{
	set_explanation_("post increment returns wrong value");
	int             size = 12;
	ft::vector<int> data = _set_vector(size, true);

	UnitTester::assert_(*data.begin() == 0);
	UnitTester::assert_(*++data.begin() == 1);
	UnitTester::assert_(*++(++data.begin()) == 2);
}

void _vector_begin_decrement()
{
	set_explanation_("post decrement returns wrong value");
	int             size = 12;
	ft::vector<int> data = _set_vector(size, true);

	ft::vector<int>::iterator it = data.begin() + 3;

	UnitTester::assert_(*it == 3);
	UnitTester::assert_(*--it == 2);
	UnitTester::assert_(*--it == 1);
	UnitTester::assert_(*--it == 0);
}

void vector_begin()
{
	load_subtest_(_vector_begin_basic);
	load_subtest_(_vector_begin_increment);
}

// -------------------------------------------------------------------------- //
//                                    end                                   //
// -------------------------------------------------------------------------- //

void _vector_end_basic()
{
	set_explanation_("does not return the right value");
	int             size = 7;
	ft::vector<int> data = _set_vector(size, true);

	UnitTester::assert_(*--data.end() == size - 1);
}

void _vector_end_increment()
{
	set_explanation_("post increment returns wrong value");
	int             size = 9;
	ft::vector<int> data = _set_vector(size, true);

	UnitTester::assert_(*--data.end() == size - 1);
	UnitTester::assert_(*--(--data.end()) == size - 2);
	UnitTester::assert_(*--(--(--data.end())) == size - 3);
}

void vector_end()
{
	load_subtest_(_vector_end_basic);
	load_subtest_(_vector_end_increment);
}

// -------------------------------------------------------------------------- //
//                                    rbegin                                  //
// -------------------------------------------------------------------------- //

void _vector_rbegin_basic()
{
	set_explanation_("does not return the right value");
	int             size = 12;
	ft::vector<int> data = _set_vector(size, true);

	UnitTester::assert_(*data.rbegin() == size - 1);
}

void _vector_rbegin_increment()
{
	set_explanation_("post increment returns wrong value");
	int             size = 12;
	ft::vector<int> data = _set_vector(size, true);

	UnitTester::assert_(*data.rbegin() == size - 1);
	UnitTester::assert_(*++data.rbegin() == size - 2);
	UnitTester::assert_(*++(++data.rbegin()) == size - 3);
}

void vector_rbegin()
{
	load_subtest_(_vector_rbegin_basic);
	load_subtest_(_vector_rbegin_increment);
}

// -------------------------------------------------------------------------- //
//                                    rend                                    //
// -------------------------------------------------------------------------- //

void _vector_rend_basic()
{
	set_explanation_("does not return the right value");
	int             size = 7;
	ft::vector<int> data = _set_vector(size, true);

	UnitTester::assert_(*--data.rend() == 0);
}

void _vector_rend_increment()
{
	set_explanation_("post increment returns wrong value");
	int             size = 9;
	ft::vector<int> data = _set_vector(size, true);

	UnitTester::assert_(*--data.rend() == 0);
	UnitTester::assert_(*--(--data.rend()) == 1);
	UnitTester::assert_(*--(--(--data.rend())) == 2);
}

void vector_rend()
{
	load_subtest_(_vector_rend_basic);
	load_subtest_(_vector_rend_increment);
}

} // namespace VectorTest
