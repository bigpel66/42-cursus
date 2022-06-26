#include "../includes/UnitTester.hpp"
#include "../includes/VectorTest.hpp"
#include <vector>

namespace VectorTest {

/* -------------------------------------------------------------------------- */
/*                         benchmark copy_constructor                         */
/* -------------------------------------------------------------------------- */
void _bench_vector_copy_constructor_ft()
{
	int             size = 10000;
	ft::vector<int> ft   = _set_vector(size);
	ft::vector<int> copy(ft);
}

void _bench_vector_copy_constructor_std()
{
	int              size = 10000;
	std::vector<int> std  = _set_vector_std(size);
	std::vector<int> copy(std);
}

void bench_vector_copy_constructor()
{
	load_subtest_(_bench_vector_copy_constructor_std);
	load_subtest_(_bench_vector_copy_constructor_ft);
}

/* -------------------------------------------------------------------------- */
/*                             benchmark operator=                            */
/* -------------------------------------------------------------------------- */
void _bench_vector_assignment_operator_ft()
{
	int             size = 10000;
	ft::vector<int> ft   = _set_vector(size);
	ft::vector<int> copy;
	copy = ft;
}

void _bench_vector_assignment_operator_std()
{
	int              size = 10000;
	std::vector<int> std  = _set_vector_std(size);
	std::vector<int> copy;
	copy = std;
}

void bench_vector_assignment_operator()
{
	load_subtest_(_bench_vector_assignment_operator_std);
	load_subtest_(_bench_vector_assignment_operator_ft);
}

/* -------------------------------------------------------------------------- */
/*                              benchmark insert                              */
/* -------------------------------------------------------------------------- */
void _bench_vector_insert_ft()
{
	ft::vector<std::string> ft;

	std::string value = "Vector Test";
	size_t      count = 10000;

	ft.insert(ft.begin(), count, value);
}

void _bench_vector_insert_std()
{
	std::vector<std::string> std;

	std::string value = "Vector Test";
	size_t      count = 10000;

	std.insert(std.begin(), count, value);
}

void bench_vector_insert()
{
	load_subtest_(_bench_vector_insert_std);
	load_subtest_(_bench_vector_insert_ft);
}

/* -------------------------------------------------------------------------- */
/*                               benchmark erase                              */
/* -------------------------------------------------------------------------- */
void _bench_vector_erase_ft()
{
	int             size = 10000;
	ft::vector<int> ft   = _set_vector(size, true);

	for (int i = 0; i < 1000; ++i) {
		ft.erase(ft.begin());
	}
}

void _bench_vector_erase_std()
{
	int              size = 10000;
	std::vector<int> std  = _set_vector_std(size, true);

	for (int i = 0; i < 1000; ++i) {
		std.erase(std.begin());
	}
}

void bench_vector_erase()
{
	load_subtest_(_bench_vector_erase_std);
	load_subtest_(_bench_vector_erase_ft);
}

/* -------------------------------------------------------------------------- */
/*                             benchmark push_back                            */
/* -------------------------------------------------------------------------- */
void _bench_vector_push_back_ft()
{
	ft::vector<int> ft;

	for (int i = 0; i < 10000; ++i) {
		ft.push_back(i);
	}
}
void _bench_vector_push_back_std()
{
	std::vector<int> std;

	for (int i = 0; i < 10000; ++i) {
		std.push_back(i);
	}
}

void bench_vector_push_back()
{
	load_subtest_(_bench_vector_push_back_std);
	load_subtest_(_bench_vector_push_back_ft);
}

/* -------------------------------------------------------------------------- */
/*                             benchmark pop_back                             */
/* -------------------------------------------------------------------------- */

void _bench_vector_pop_back_ft()
{
	ft::vector<int> ft;

	for (int i = 0; i < 10000; ++i) {
		ft.push_back(i);
	}
	for (int i = 0; i < 10000; ++i) {
		ft.pop_back();
	}
}

void _bench_vector_pop_back_std()
{
	std::vector<int> std;

	for (int i = 0; i < 10000; ++i) {
		std.push_back(i);
	}
	for (int i = 0; i < 10000; ++i) {
		std.pop_back();
	}
}

void bench_vector_pop_back()
{
	load_subtest_(_bench_vector_pop_back_std);
	load_subtest_(_bench_vector_pop_back_ft);
}

} // namespace VectorTest
