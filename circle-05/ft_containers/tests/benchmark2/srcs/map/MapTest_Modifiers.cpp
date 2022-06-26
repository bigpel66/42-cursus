#include "../includes/MapTest.hpp"
#include "../includes/UnitTester.hpp"
#include <iostream>
#include <map>

namespace MapTest {

// -------------------------------------------------------------------------- //
//                                    clear                                   //
// -------------------------------------------------------------------------- //

void _map_clear_size_check()
{
	set_explanation_("size not 0");
	int               size = 10;
	ft::map<int, int> ft   = _set_map(size);

	UnitTester::assert_(ft.size() != 0);
	ft.clear();
	UnitTester::assert_(ft.size() == 0);
}

void _map_clear_empty_check()
{
	set_explanation_("is empty not true");
	int               size = 10;
	ft::map<int, int> ft   = _set_map(size, true);

	UnitTester::assert_(!ft.empty());
	ft.clear();
	UnitTester::assert_(ft.empty());
}

void map_clear()
{
	load_subtest_(_map_clear_size_check);
	load_subtest_(_map_clear_empty_check);
}

// -------------------------------------------------------------------------- //
//                                   insert                                   //
// -------------------------------------------------------------------------- //

void _map_insert_single()
{
	set_explanation_("value not inserted at expected point");
	int               size = 10;
	ft::map<int, int> ft   = _set_map(size);

	int key   = 24;
	int value = 42;
	ft.insert(ft::make_pair(key, value));
	UnitTester::assert_(ft[key] == value);
}

void _map_insert_return_value()
{
	set_explanation_("return key-value is not equal to inserted key-value");
	int               size = 10;
	ft::map<int, int> ft   = _set_map(size);

	ft::pair<ft::map<int, int>::iterator, bool> ret;
	ft::map<int, int>::iterator                 it;

	int key   = 24;
	int value = 42;
	ret       = ft.insert(ft::make_pair(key, value));
	it        = ret.first;

	UnitTester::assert_(ret.second == true);
	UnitTester::assert_(it->first == key);
	UnitTester::assert_(it->second == value);
}

void _map_insert_hint()
{
	set_explanation_("insert with hint does not work");
	int               size = 10;
	ft::map<int, int> ft   = _set_map(size, true);

	int key   = 24;
	int value = 42;
	ft.insert(ft.end(), ft::make_pair(key, value));
	UnitTester::assert_(ft[key] == value);
}

void _map_insert_return_value_false()
{
	int               size = 7;
	ft::map<int, int> ft   = _set_map(size, true);

	ft::pair<ft::map<int, int>::iterator, bool> ret;
	ft::map<int, int>::iterator                 it;

	int key   = size - 1;
	int value = 42;
	ret       = ft.insert(ft::make_pair(key, value));
	it        = ret.first;

	set_explanation_("duplicate keys succedded in insertion");
	UnitTester::assert_(ret.second == false);
	set_explanation_("duplicate key insertion returned an unrelated element");
	UnitTester::assert_(it->first == key);
	set_explanation_("duplicate key insertion returned new element");
	UnitTester::assert_(it->second != value);
}

void _map_insert_iterator()
{
	size_t             size   = 12;
	ft::map<int, char> ft_src = _set_map_char(size, false);
	ft::map<int, char> ft     = _set_map_char(size, true);

	ft.insert(ft_src.begin(), ft_src.end());

	set_explanation_("wrong size; elements not inserted");
	UnitTester::assert_(ft.size() != size);
	set_explanation_("wrong size; some elements not inserted");
	UnitTester::assert_(ft.size() == size * 2);
}

void _map_insert_compare()
{
	set_explanation_("result differs from std");
	size_t                     src_size = 22;
	ft::map<int, std::string>  ft_src;
	std::map<int, std::string> std_src;
	_set_compare_maps(ft_src, std_src, src_size);

	size_t                     size = 57;
	ft::map<int, std::string>  ft;
	std::map<int, std::string> std;
	_set_compare_maps(ft, std, size);

	ft.insert(ft_src.begin(), ft_src.end());
	std.insert(std_src.begin(), std_src.end());
	_compare_maps(ft, std);
}

void _map_insert_iterator_invalidation()
{
	int                         size     = 10;
	ft::map<int, int>           ft       = _set_map(size);
	ft::map<int, int>::iterator it       = ft.begin();
	int                         prev_key = it->first;

	set_explanation_("something went wrong");
	UnitTester::assert_(prev_key == it->first);

	int key   = -123;
	int value = -111;
	set_explanation_("insert invalidate iterators");
	ft.insert(ft::make_pair(key, value));
	UnitTester::assert_(prev_key == it->first);
}

void map_insert()
{
	load_subtest_(_map_insert_single);
	load_subtest_(_map_insert_return_value);
	load_subtest_(_map_insert_return_value_false);
	load_subtest_(_map_insert_hint);
	load_subtest_(_map_insert_iterator);
	load_subtest_(_map_insert_compare);
	load_subtest_(_map_insert_iterator_invalidation);
}
// -------------------------------------------------------------------------- //
//                                    erase                                   //
// -------------------------------------------------------------------------- //

void _map_erase_one()
{
	int                         size = 10;
	ft::map<int, int>           ft   = _set_map(size, true);
	ft::map<int, int>::iterator it   = ++(++ft.begin());
	int                         key  = it->first;

	set_explanation_("count() not working");
	UnitTester::assert_(ft.count(key) == 1);
	ft.erase(it);
	set_explanation_("the third element not erased");
	UnitTester::assert_(ft.count(key) == 0);
}

void _map_erase_head()
{
	int                         size = 10;
	ft::map<int, int>           ft   = _set_map(size, true);
	ft::map<int, int>::iterator it   = ft.begin();
	int                         key  = it->first;

	set_explanation_("count() not working");
	UnitTester::assert_(ft.count(key) == 1);
	ft.erase(it);
	set_explanation_("the first element not erased");
	UnitTester::assert_(ft.count(key) == 0);
}

void _map_erase_tail()
{
	int                         size = 10;
	ft::map<int, int>           ft   = _set_map(size, true);
	ft::map<int, int>::iterator it   = --ft.end();
	int                         key  = it->first;

	set_explanation_("count() not working");
	UnitTester::assert_(ft.count(key) == 1);
	ft.erase(it);
	set_explanation_("the last element not erased");
	UnitTester::assert_(ft.count(key) == 0);
}

void _map_erase_range()
{
	set_explanation_("elements in range not erased");
	int               size = 21;
	ft::map<int, int> ft   = _set_map(size, true);

	ft.erase(ft.begin(), ft.end());
	UnitTester::assert_(ft.size() == 0);
}

void _map_erase_compare()
{
	set_explanation_("result differs from std");
	int                        size = 42;
	ft::map<int, std::string>  ft;
	std::map<int, std::string> std;
	_set_compare_maps(ft, std, size);

	ft::map<int, std::string>::iterator  ft_start  = ++ft.begin();
	std::map<int, std::string>::iterator std_start = ++std.begin();
	ft::map<int, std::string>::iterator  ft_end    = --(--ft.end());
	std::map<int, std::string>::iterator std_end   = --(--std.end());

	ft.erase(ft_start, ft_end);
	std.erase(std_start, std_end);
	_compare_maps(ft, std);
}

void _map_erase_iterator_invalidation()
{
	int                         size     = 10;
	ft::map<int, int>           ft       = _set_map(size);
	ft::map<int, int>::iterator it       = ft.begin();
	ft::map<int, int>::iterator it_next  = ++(++it);
	int                         prev_key = it->first;
	int                         next_key = it_next->first;

	set_explanation_("something went wrong");
	UnitTester::assert_(prev_key == it->first);
	UnitTester::assert_(next_key == it_next->first);

	set_explanation_("erase invalidates iterators");
	ft.erase(++ft.begin());
	UnitTester::assert_(prev_key == it->first);
	UnitTester::assert_(next_key == it_next->first);
}

void map_erase()
{
	load_subtest_(_map_erase_one);
	load_subtest_(_map_erase_head);
	load_subtest_(_map_erase_tail);
	load_subtest_(_map_erase_range);
	load_subtest_(_map_erase_compare);
	load_subtest_(_map_erase_iterator_invalidation);
}

// -------------------------------------------------------------------------- //
//                                    swap                                    //
// -------------------------------------------------------------------------- //

void _map_swap_basic()
{
	set_explanation_("swapped value not correct");
	size_t            size_a = 10;
	size_t            size_b = 20;
	ft::map<int, int> ft_a   = _set_map(size_a, false);
	ft::map<int, int> ft_b   = _set_map(size_b, true);

	ft_a.swap(ft_b);
	for (size_t i = 0; i < size_b; ++i) {
		ft_a[i] = i;
	}
}

void _map_swap_compare()
{
	set_explanation_("result differs from std");
	ft::map<int, std::string>  ft_a;
	std::map<int, std::string> std_a;
	_set_compare_maps(ft_a, std_a);

	ft::map<int, std::string>  ft_b;
	std::map<int, std::string> std_b;
	_set_compare_maps(ft_b, std_b);

	ft_a.swap(ft_b);
	std_a.swap(std_b);
	_compare_maps(ft_a, std_a);
	_compare_maps(ft_b, std_b);
}

void _map_swap_iterator()
{
	set_explanation_("iterator is invalidated");
	ft::map<int, int>           ft_a    = _set_map();
	ft::map<int, int>           ft_b    = _set_map();
	ft::map<int, int>::iterator it_a    = ft_a.begin();
	ft::map<int, int>::iterator it_b    = ft_b.begin();
	int                         value_a = it_a->first;
	int                         value_b = it_b->first;

	UnitTester::assert_(it_a->first == value_a);
	UnitTester::assert_(it_b->first == value_b);
	ft_a.swap(ft_b);
	UnitTester::assert_(it_a->first == value_a);
	UnitTester::assert_(it_b->first == value_b);
	UnitTester::assert_(ft_a.begin()->first == value_b);
	UnitTester::assert_(ft_b.begin()->first == value_a);
}

void map_swap()
{
	load_subtest_(_map_swap_basic);
	load_subtest_(_map_swap_compare);
	load_subtest_(_map_swap_iterator);
}

} // namespace MapTest
