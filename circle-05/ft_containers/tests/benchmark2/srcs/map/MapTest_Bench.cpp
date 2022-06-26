#include "../includes/MapTest.hpp"
#include "../includes/UnitTester.hpp"
#include <map>

namespace MapTest {
/* -------------------------------------------------------------------------- */
/*                         benchmark copy_constructor                         */
/* -------------------------------------------------------------------------- */
void _bench_map_copy_constructor_ft()
{
	int               size = 10000;
	ft::map<int, int> ft   = _set_map(size);
	ft::map<int, int> copy(ft);
}

void _bench_map_copy_constructor_std()
{
	int                size = 10000;
	std::map<int, int> std  = _set_map_std(size);
	std::map<int, int> copy(std);
}

void bench_map_copy_constructor()
{
	load_subtest_(_bench_map_copy_constructor_std);
	load_subtest_(_bench_map_copy_constructor_ft);
}

/* -------------------------------------------------------------------------- */
/*                             benchmark operator=                            */
/* -------------------------------------------------------------------------- */
void _bench_map_assignment_operator_ft()
{
	int               size = 10000;
	ft::map<int, int> ft   = _set_map(size);
	ft::map<int, int> copy;
	copy = ft;
}

void _bench_map_assignment_operator_std()
{
	int                size = 10000;
	std::map<int, int> std  = _set_map_std(size);
	std::map<int, int> copy;
	copy = std;
}

void bench_map_assignment_operator()
{
	load_subtest_(_bench_map_assignment_operator_std);
	load_subtest_(_bench_map_assignment_operator_ft);
}

/* -------------------------------------------------------------------------- */
/*                            benchmark operator[]                            */
/* -------------------------------------------------------------------------- */
void _bench_map_subscript_operator_ft()
{
	size_t            size   = 10000;
	ft::map<int, int> ft_src = _set_map(size, false);
}

void _bench_map_subscript_operator_std()
{
	size_t             size   = 10000;
	std::map<int, int> ft_src = _set_map_std(size, false);
}

void bench_map_subscript_operator()
{
	load_subtest_(_bench_map_subscript_operator_std);
	load_subtest_(_bench_map_subscript_operator_ft);
}

/* -------------------------------------------------------------------------- */
/*                              benchmark insert                              */
/* -------------------------------------------------------------------------- */
void _bench_map_insert_ft()
{
	ft::map<int, int> ft;
	int            count = 10000;

	for (int i = 0; i < count; ++i) {
		ft.insert(ft::make_pair(i, i));
	}
}

void _bench_map_insert_std()
{
	std::map<int, int> std;
	int             count = 10000;

	for (int i = 0; i < count; ++i) {
		std.insert(std::make_pair(i, i));
	}
}

void bench_map_insert()
{
	load_subtest_(_bench_map_insert_std);
	load_subtest_(_bench_map_insert_ft);
}

/* -------------------------------------------------------------------------- */
/*                         benchmark insert with hint                         */
/* -------------------------------------------------------------------------- */
void _bench_map_insert_hint_next_ft()
{
	ft::map<int, int>           ft;
	ft::map<int, int>::iterator hint  = ft.begin();
	int                      count = 10000;

	for (int i = count; i > 0; --i) {
		hint = ft.insert(hint, ft::make_pair(i, i));
	}
}

void _bench_map_insert_hint_next_std()
{
	std::map<int, int>           std;
	std::map<int, int>::iterator hint  = std.begin();
	int                       count = 10000;

	for (int i = count; i > 0; --i) {
		hint = std.insert(hint, std::make_pair(i, i));
	}
}

void _bench_map_insert_hint_prev_ft()
{
	ft::map<int, int>           ft;
	ft::map<int, int>::iterator hint  = ft.begin();
	int                      count = 10000;

	for (int i = 0; i < count; ++i) {
		hint = ft.insert(hint, ft::make_pair(i, i));
	}
}

void _bench_map_insert_hint_prev_std()
{
	std::map<int, int>           std;
	std::map<int, int>::iterator hint  = std.begin();
	int                       count = 10000;

	for (int i = 0; i < count; ++i) {
		hint = std.insert(hint, std::make_pair(i, i));
	}
}

void bench_map_insert_hint()
{
	/*
	// c++11 faster (insertion just prior to the hint)
	load_subtest_(_bench_map_insert_hint_next_std);
	load_subtest_(_bench_map_insert_hint_next_ft);
	*/
	// c++98 faster (insertion just after the hint)
	load_subtest_(_bench_map_insert_hint_prev_std);
	load_subtest_(_bench_map_insert_hint_prev_ft);
}

/* -------------------------------------------------------------------------- */
/*                               benchmark erase                              */
/* -------------------------------------------------------------------------- */
void _bench_map_erase_ft()
{
	int               size = 10000;
	ft::map<int, int> ft   = _set_map(size, true);

	for (int i = 0; i < 1000; ++i) {
		ft.erase(ft.begin());
	}
}

void _bench_map_erase_std()
{
	int                size = 10000;
	std::map<int, int> std  = _set_map_std(size, true);

	for (int i = 0; i < 1000; ++i) {
		std.erase(std.begin());
	}
}

void bench_map_erase()
{
	load_subtest_(_bench_map_erase_std);
	load_subtest_(_bench_map_erase_ft);
}

/* -------------------------------------------------------------------------- */
/*                               benchmark find                               */
/* -------------------------------------------------------------------------- */
void _bench_map_find_ft()
{
	int               size = 10000;
	ft::map<int, int> ft   = _set_map(size, false);

	for (int i = 0; i < 10000; ++i) {
		ft.find(i);
	}
}
void _bench_map_find_std()
{
	int                size = 10000;
	std::map<int, int> std  = _set_map_std(size, false);

	for (int i = 0; i < 10000; ++i) {
		std.find(i);
	}
}

void bench_map_find()
{
	load_subtest_(_bench_map_find_std);
	load_subtest_(_bench_map_find_ft);
}

/* -------------------------------------------------------------------------- */
/*                            benchmark equal_range                           */
/* -------------------------------------------------------------------------- */
void _bench_map_equal_range_ft()
{
	int               size = 10000;
	ft::map<int, int> ft   = _set_map(size, false);

	for (int i = 0; i < 10000; ++i) {
		ft.equal_range(i);
	}
}

void _bench_map_equal_range_std()
{
	int                size = 10000;
	std::map<int, int> std  = _set_map_std(size, false);

	for (int i = 0; i < 10000; ++i) {
		std.equal_range(i);
	}
}

void bench_map_equal_range()
{
	load_subtest_(_bench_map_equal_range_std);
	load_subtest_(_bench_map_equal_range_ft);
}

} // namespace MapTest
