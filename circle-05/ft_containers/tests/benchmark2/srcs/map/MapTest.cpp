#include "../includes/MapTest.hpp"

namespace MapTest {

#define FAIL TEST_FAILED

#ifdef BENCH
t_unit_tests func_test_table[] = {
	{   "map_copy_constructor",    bench_map_copy_constructor, FAIL, MAP},
	{"map_assignment_operator", bench_map_assignment_operator, FAIL, MAP},
	{ "map_subscript_operator",  bench_map_subscript_operator, FAIL, MAP},
	{	         "map_insert",              bench_map_insert, FAIL, MAP},
	{	    "map_insert_hint",         bench_map_insert_hint, FAIL, MAP},
	{	          "map_erase",               bench_map_erase, FAIL, MAP},
    {               "map_find",                bench_map_find, FAIL, MAP},
	{	    "map_equal_range",         bench_map_equal_range, FAIL, MAP},
 // ------------------- Terminater (Do not comment out) ------------------ //
	{	                 "\0",	                      NULL, FAIL, MAP}
};
#else
t_unit_tests func_test_table[] = {
	{	    "map_constructor",         map_constructor, FAIL, MAP},
	{	     "map_destructor",          map_destructor, FAIL, MAP},
	{"map_assignment_operator", map_assignment_operator, FAIL, MAP},
	{	  "map_get_allocator",       map_get_allocator, FAIL, MAP},
 // --------------------------- Element access --------------------------- //
	{	             "map_at",	              map_at, FAIL, MAP},
	{ "map_subscript_operator",  map_subscript_operator, FAIL, MAP},
 // ------------------------------ Iterators ----------------------------- //
	{	          "map_begin",               map_begin, FAIL, MAP},
    {                "map_end",                 map_end, FAIL, MAP},
	{	         "map_rbegin",              map_rbegin, FAIL, MAP},
    {               "map_rend",                map_rend, FAIL, MAP},
 // ------------------------------ Capacity ----------------------------- //
	{	          "map_empty",               map_empty, FAIL, MAP},
    {               "map_size",                map_size, FAIL, MAP},
	{	       "map_max_size",            map_max_size, FAIL, MAP},
 // ------------------------------ Modifiers ----------------------------- //
	{	          "map_clear",               map_clear, FAIL, MAP},
    {             "map_insert",              map_insert, FAIL, MAP},
	{	          "map_erase",               map_erase, FAIL, MAP},
    {               "map_swap",                map_swap, FAIL, MAP},
 // ------------------------------- Lookup ------------------------------- //
	{	          "map_count",               map_count, FAIL, MAP},
    {               "map_find",                map_find, FAIL, MAP},
	{	    "map_equal_range",         map_equal_range, FAIL, MAP},
	{	    "map_lower_bound",         map_lower_bound, FAIL, MAP},
	{	    "map_upper_bound",         map_upper_bound, FAIL, MAP},
 // ------------------------------ Observers ----------------------------- //
	{	       "map_key_comp",            map_key_comp, FAIL, MAP},
    {         "map_value_comp",          map_value_comp, FAIL, MAP},
 // ------------------------ Non-member functions ------------------------ //
	{	     "map_operator_e",          map_operator_e, FAIL, MAP},
	{	    "map_operator_ne",         map_operator_ne, FAIL, MAP},
	{	     "map_operator_l",          map_operator_l, FAIL, MAP},
	{	    "map_operator_le",         map_operator_le, FAIL, MAP},
	{	     "map_operator_g",          map_operator_g, FAIL, MAP},
	{	    "map_operator_ge",         map_operator_ge, FAIL, MAP},
    {            "map_ft_swap",             map_ft_swap, FAIL, MAP},
 // ------------------------------ ft::pair ------------------------------ //
	{	   "map_ft_make_pair",        map_ft_make_pair, FAIL, MAP},
 // ------------------- Terminater (Do not comment out) ------------------ //
	{	                 "\0",	                NULL, FAIL, MAP}
};
#endif

ft::map<int, int> _set_map(int size, bool accend)
{
	ft::map<int, int> data;

	for (int i = 0; i < size; ++i) {
		if (accend) {
			data[i] = i;
		} else {
			data[i] = std::rand();
		}
	}
	return data;
}

std::map<int, int> _set_map_std(int size, bool accend)
{
	std::map<int, int> data;

	for (int i = 0; i < size; ++i) {
		if (accend) {
			data[i] = i;
		} else {
			data[i] = std::rand();
		}
	}
	return data;
}

ft::map<int, char> _set_map_char(int size, bool accend)
{
	ft::map<int, char> data;

	for (int i = 0; i < size; ++i) {
		if (accend) {
			data[i] = 'a' + i;
		} else {
			data[std::rand()] = 'a' + std::rand() % 26;
		}
	}
	return data;
}

ft::map<int, std::string> _set_map_string(int size, bool accend)
{
	ft::map<int, std::string> data;

	for (int i = 0; i < size; ++i) {
		if (accend) {
			data[i] = 'a' + i;
		} else {
			data[i] = 'a' + std::rand() % 26;
		}
	}
	return data;
}

void _set_compare_maps(
    ft::map<int, std::string>& ft_data, std::map<int, std::string>& std_data, int size)
{
	std::string val;
	std::string strs[]   = { "42", "Tokyo", "Hello", "World", "!" };
	size_t      patterns = 5;

	for (int i = 0; i < size; ++i) {
		int index = std::rand() % patterns;

		val = strs[index] + strs[std::max(index - 1, 0)];
		ft_data.insert(ft::pair<int, std::string>(i, val));
		std_data.insert(std::pair<int, std::string>(i, val));
	}
}

} // namespace MapTest
