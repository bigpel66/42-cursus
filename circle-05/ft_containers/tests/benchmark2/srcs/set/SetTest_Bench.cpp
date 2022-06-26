#include "../includes/SetTest.hpp"
#include "../includes/UnitTester.hpp"
#include <set>

namespace SetTest {
/* -------------------------------------------------------------------------- */
/*                         benchmark copy_constructor                         */
/* -------------------------------------------------------------------------- */
void _bench_set_copy_constructor_ft()
{
	int          size = 10000;
	ft::set<int> ft   = _set_set(size);
	ft::set<int> copy(ft);
}

void _bench_set_copy_constructor_std()
{
	int           size = 10000;
	std::set<int> std  = _set_set_std(size);
	std::set<int> copy(std);
}

void bench_set_copy_constructor()
{
	load_subtest_(_bench_set_copy_constructor_std);
	load_subtest_(_bench_set_copy_constructor_ft);
}

/* -------------------------------------------------------------------------- */
/*                             benchmark operator=                            */
/* -------------------------------------------------------------------------- */
void _bench_set_assignment_operator_ft()
{
	int          size = 10000;
	ft::set<int> ft   = _set_set(size);
	ft::set<int> copy;
	copy = ft;
}

void _bench_set_assignment_operator_std()
{
	int           size = 10000;
	std::set<int> std  = _set_set_std(size);
	std::set<int> copy;
	copy = std;
}

void bench_set_assignment_operator()
{
	load_subtest_(_bench_set_assignment_operator_std);
	load_subtest_(_bench_set_assignment_operator_ft);
}

/* -------------------------------------------------------------------------- */
/*                            benchmark operator[]                            */
/* -------------------------------------------------------------------------- */
void _bench_set_subscript_operator_ft()
{
	size_t       size   = 10000;
	ft::set<int> ft_src = _set_set(size, false);
}

void _bench_set_subscript_operator_std()
{
	size_t        size   = 10000;
	std::set<int> ft_src = _set_set_std(size, false);
}

void bench_set_subscript_operator()
{
	load_subtest_(_bench_set_subscript_operator_std);
	load_subtest_(_bench_set_subscript_operator_ft);
}

/* -------------------------------------------------------------------------- */
/*                              benchmark insert                              */
/* -------------------------------------------------------------------------- */
void _bench_set_insert_ft()
{
	ft::set<int> ft;
	int       count = 10000;

	for (int i = 0; i < count; ++i) {
		ft.insert(i);
	}
}

void _bench_set_insert_std()
{
	std::set<int> std;
	int        count = 10000;

	for (int i = 0; i < count; ++i) {
		std.insert(i);
	}
}

void bench_set_insert()
{
	load_subtest_(_bench_set_insert_std);
	load_subtest_(_bench_set_insert_ft);
}

/* -------------------------------------------------------------------------- */
/*                               benchmark erase                              */
/* -------------------------------------------------------------------------- */
void _bench_set_erase_ft()
{
	int          size = 10000;
	ft::set<int> ft   = _set_set(size, true);

	for (int i = 0; i < 1000; ++i) {
		ft.erase(ft.begin());
	}
}

void _bench_set_erase_std()
{
	int           size = 10000;
	std::set<int> std  = _set_set_std(size, true);

	for (int i = 0; i < 1000; ++i) {
		std.erase(std.begin());
	}
}

void bench_set_erase()
{
	load_subtest_(_bench_set_erase_std);
	load_subtest_(_bench_set_erase_ft);
}

/* -------------------------------------------------------------------------- */
/*                               benchmark find                               */
/* -------------------------------------------------------------------------- */
void _bench_set_find_ft()
{
	int          size = 10000;
	ft::set<int> ft   = _set_set(size, false);

	for (int i = 0; i < 10000; ++i) {
		ft.find(i);
	}
}
void _bench_set_find_std()
{
	int           size = 10000;
	std::set<int> std  = _set_set_std(size, false);

	for (int i = 0; i < 10000; ++i) {
		std.find(i);
	}
}

void bench_set_find()
{
	load_subtest_(_bench_set_find_std);
	load_subtest_(_bench_set_find_ft);
}

/* -------------------------------------------------------------------------- */
/*                            benchmark equal_range                           */
/* -------------------------------------------------------------------------- */
void _bench_set_equal_range_ft()
{
	int          size = 10000;
	ft::set<int> ft   = _set_set(size, false);

	for (int i = 0; i < 10000; ++i) {
		ft.equal_range(i);
	}
}

void _bench_set_equal_range_std()
{
	int           size = 10000;
	std::set<int> std  = _set_set_std(size, false);

	for (int i = 0; i < 10000; ++i) {
		std.equal_range(i);
	}
}

void bench_set_equal_range()
{
	load_subtest_(_bench_set_equal_range_std);
	load_subtest_(_bench_set_equal_range_ft);
}

} // namespace SetTest
