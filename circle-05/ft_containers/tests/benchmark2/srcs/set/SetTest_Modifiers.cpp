#include "../includes/SetTest.hpp"
#include "../includes/UnitTester.hpp"
#include <iostream>
#include <set>

namespace SetTest {

// -------------------------------------------------------------------------- //
//                                    clear                                   //
// -------------------------------------------------------------------------- //

void _set_clear_size_check()
{
	set_explanation_("size not 0");
	int          size = 10;
	ft::set<int> ft   = _set_set(size);

	UnitTester::assert_(ft.size() != 0);
	ft.clear();
	UnitTester::assert_(ft.size() == 0);
}

void _set_clear_empty_check()
{
	set_explanation_("is empty not true");
	int          size = 10;
	ft::set<int> ft   = _set_set(size, true);

	UnitTester::assert_(!ft.empty());
	ft.clear();
	UnitTester::assert_(ft.empty());
}

void set_clear()
{
	load_subtest_(_set_clear_size_check);
	load_subtest_(_set_clear_empty_check);
}

// -------------------------------------------------------------------------- //
//                                   insert                                   //
// -------------------------------------------------------------------------- //

void _set_insert_single()
{
	set_explanation_("value not inserted at expected point");
	int          size = 10;
	ft::set<int> ft   = _set_set(size);

	int key = 24;
	UnitTester::assert_(ft.count(key) == 0);
	ft.insert(key);
	UnitTester::assert_(ft.count(key) == 1);
}

void _set_insert_return_value()
{
	set_explanation_("return key-value is not equal to inserted key-value");
	int          size = 10;
	ft::set<int> ft   = _set_set(size);

	ft::pair<ft::set<int>::iterator, bool> ret;
	ft::set<int>::iterator                 it;

	int key = 24;
	ret     = ft.insert(key);

	UnitTester::assert_(*(ret.first) == key);
	UnitTester::assert_(ret.second == true);
}

void _set_insert_hint() {}

void _set_insert_iterator()
{
	size_t        size   = 12;
	ft::set<char> ft_src = _set_set_char(size, false);
	ft::set<char> ft     = _set_set_char(size, true);

	ft.insert(ft_src.begin(), ft_src.end());

	// _debug(ft, "ft");
	// _debug(ft_src, "src");
	set_explanation_("wrong size; elements not inserted");
	UnitTester::assert_(ft.size() != size);
	set_explanation_("wrong size; some elements not inserted");
	UnitTester::assert_(ft.size() == size * 2);
}

void _set_insert_compare()
{
	set_explanation_("result differs from std");
	size_t                src_size = 22;
	ft::set<std::string>  ft_src;
	std::set<std::string> std_src;
	_set_compare_sets(ft_src, std_src, src_size);

	size_t                size = 57;
	ft::set<std::string>  ft;
	std::set<std::string> std;
	_set_compare_sets(ft, std, size);

	ft.insert(ft_src.begin(), ft_src.end());
	std.insert(std_src.begin(), std_src.end());
	_compare_sets(ft, std);
}

void set_insert()
{
	load_subtest_(_set_insert_single);
	load_subtest_(_set_insert_return_value);
	load_subtest_(_set_insert_hint);
	load_subtest_(_set_insert_iterator);
	load_subtest_(_set_insert_compare);
}
// -------------------------------------------------------------------------- //
//                                    erase                                   //
// -------------------------------------------------------------------------- //

void _set_erase_one()
{
	int                    size = 10;
	ft::set<int>           ft   = _set_set(size, true);
	ft::set<int>::iterator it   = ++(++ft.begin());
	int                    key  = *it;

	set_explanation_("count() not working");
	UnitTester::assert_(ft.count(key) == 1);
	ft.erase(it);
	set_explanation_("the third element not erased");
	UnitTester::assert_(ft.count(key) == 0);
}

void _set_erase_head()
{
	int                    size = 10;
	ft::set<int>           ft   = _set_set(size, true);
	ft::set<int>::iterator it   = ft.begin();
	int                    key  = *it;

	set_explanation_("count() not working");
	UnitTester::assert_(ft.count(key) == 1);
	ft.erase(it);
	set_explanation_("the first element not erased");
	UnitTester::assert_(ft.count(key) == 0);
}

void _set_erase_tail()
{
	int                    size = 10;
	ft::set<int>           ft   = _set_set(size, true);
	ft::set<int>::iterator it   = --ft.end();
	int                    key  = *it;

	set_explanation_("count() not working");
	UnitTester::assert_(ft.count(key) == 1);
	ft.erase(it);
	set_explanation_("the last element not erased");
	UnitTester::assert_(ft.count(key) == 0);
}

void _set_erase_range()
{
	set_explanation_("elements in range not erased");
	int          size = 21;
	ft::set<int> ft   = _set_set(size, true);

	ft.erase(ft.begin(), ft.end());
	UnitTester::assert_(ft.size() == 0);
}

void _set_erase_compare()
{
	set_explanation_("result differs from std");
	int                   size = 42;
	ft::set<std::string>  ft;
	std::set<std::string> std;
	_set_compare_sets(ft, std, size);

	ft::set<std::string>::iterator  ft_start  = ++ft.begin();
	std::set<std::string>::iterator std_start = ++std.begin();
	ft::set<std::string>::iterator  ft_end    = --(--ft.end());
	std::set<std::string>::iterator std_end   = --(--std.end());

	ft.erase(ft_start, ft_end);
	std.erase(std_start, std_end);
	_compare_sets(ft, std);
}

void set_erase()
{
	load_subtest_(_set_erase_one);
	load_subtest_(_set_erase_head);
	load_subtest_(_set_erase_tail);
	load_subtest_(_set_erase_range);
	load_subtest_(_set_erase_compare);
}

// -------------------------------------------------------------------------- //
//                                    swap                                    //
// -------------------------------------------------------------------------- //

void _set_swap_basic()
{
	set_explanation_("swapped value not correct");
	size_t       size_a = 10;
	size_t       size_b = 20;
	ft::set<int> ft_a   = _set_set(size_a, false); // random
	ft::set<int> ft_b   = _set_set(size_b, true); // accend

	ft_a.swap(ft_b);
	int i = 0;
	for (ft::set<int>::iterator it = ft_a.begin(); it != ft_a.end(); ++it, ++i) {
		UnitTester::assert_(*it == i);
	}
}

void _set_swap_compare()
{
	set_explanation_("result differs from std");
	ft::set<std::string>  ft_a;
	std::set<std::string> std_a;
	_set_compare_sets(ft_a, std_a);

	ft::set<std::string>  ft_b;
	std::set<std::string> std_b;
	_set_compare_sets(ft_b, std_b);

	ft_a.swap(ft_b);
	std_a.swap(std_b);
	_compare_sets(ft_a, std_a);
	_compare_sets(ft_b, std_b);
}

void _set_swap_iterator()
{
	set_explanation_("iterator is invalidated");
	ft::set<int>           ft_a    = _set_set();
	ft::set<int>           ft_b    = _set_set();
	ft::set<int>::iterator it_a    = ft_a.begin();
	ft::set<int>::iterator it_b    = ft_b.begin();
	int                    value_a = *it_a;
	int                    value_b = *it_b;

	UnitTester::assert_(*it_a == value_a);
	UnitTester::assert_(*it_b == value_b);
	ft_a.swap(ft_b);
	UnitTester::assert_(*it_a == value_a);
	UnitTester::assert_(*it_b == value_b);
	UnitTester::assert_(*(ft_a.begin()) == value_b);
	UnitTester::assert_(*(ft_b.begin()) == value_a);
}

void set_swap()
{
	load_subtest_(_set_swap_basic);
	load_subtest_(_set_swap_compare);
	load_subtest_(_set_swap_iterator);
}

} // namespace SetTest
