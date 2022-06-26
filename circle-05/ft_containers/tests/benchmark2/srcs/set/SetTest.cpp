#include "../includes/SetTest.hpp"

namespace SetTest {

#define FAIL TEST_FAILED

#ifdef BENCH
t_unit_tests func_test_table[] = {
	{   "set_copy_constructor",    bench_set_copy_constructor, FAIL, SET},
	{"set_assignment_operator", bench_set_assignment_operator, FAIL, SET},
	{ "set_subscript_operator",  bench_set_subscript_operator, FAIL, SET},
	{	         "set_insert",              bench_set_insert, FAIL, SET},
    {              "set_erase",               bench_set_erase, FAIL, SET},
	{	           "set_find",                bench_set_find, FAIL, SET},
	{	    "set_equal_range",         bench_set_equal_range, FAIL, SET},
 // ------------------- Terminater (Do not comment out) ------------------ //
	{	                 "\0",	                      NULL, FAIL, SET}
};
#else
t_unit_tests func_test_table[] = {
	{	    "set_constructor",         set_constructor, FAIL, SET},
	{	     "set_destructor",          set_destructor, FAIL, SET},
	{"set_assignment_operator", set_assignment_operator, FAIL, SET},
	{	  "set_get_allocator",       set_get_allocator, FAIL, SET},
 // ------------------------------ Iterators ----------------------------- //
	{	          "set_begin",               set_begin, FAIL, SET},
    {                "set_end",                 set_end, FAIL, SET},
	{	         "set_rbegin",              set_rbegin, FAIL, SET},
    {               "set_rend",                set_rend, FAIL, SET},
 // ------------------------------ Capacity ----------------------------- //
	{	          "set_empty",               set_empty, FAIL, SET},
    {               "set_size",                set_size, FAIL, SET},
	{	       "set_max_size",            set_max_size, FAIL, SET},
 // ------------------------------ Modifiers ----------------------------- //
	{	          "set_clear",               set_clear, FAIL, SET},
    {             "set_insert",              set_insert, FAIL, SET},
	{	          "set_erase",               set_erase, FAIL, SET},
    {               "set_swap",                set_swap, FAIL, SET},
 // ------------------------------- Lookup ------------------------------- //
	{	          "set_count",               set_count, FAIL, SET},
    {               "set_find",                set_find, FAIL, SET},
	{	    "set_equal_range",         set_equal_range, FAIL, SET},
	{	    "set_lower_bound",         set_lower_bound, FAIL, SET},
	{	    "set_upper_bound",         set_upper_bound, FAIL, SET},
 // ------------------------------ Observers ----------------------------- //
	{	       "set_key_comp",            set_key_comp, FAIL, SET},
    {         "set_value_comp",          set_value_comp, FAIL, SET},
 // ------------------------ Non-member functions ------------------------ //
	{	     "set_operator_e",          set_operator_e, FAIL, SET},
	{	    "set_operator_ne",         set_operator_ne, FAIL, SET},
	{	     "set_operator_l",          set_operator_l, FAIL, SET},
	{	    "set_operator_le",         set_operator_le, FAIL, SET},
	{	     "set_operator_g",          set_operator_g, FAIL, SET},
	{	    "set_operator_ge",         set_operator_ge, FAIL, SET},
    {            "set_ft_swap",             set_ft_swap, FAIL, SET},
 // ------------------- Terminater (Do not comment out) ------------------ //
	{	                 "\0",	                NULL, FAIL, SET}
};
#endif

ft::set<int> _set_set(int size, bool accend)
{
	ft::set<int> data;

	for (int i = 0; i < size; ++i) {
		if (accend) {
			data.insert(i);
		} else {
			data.insert(std::rand());
		}
	}
	return data;
}

std::set<int> _set_set_std(int size, bool accend)
{
	std::set<int> data;

	for (int i = 0; i < size; ++i) {
		if (accend) {
			data.insert(i);
		} else {
			data.insert(std::rand());
		}
	}
	return data;
}

ft::set<char> _set_set_char(int size, bool accend)
{
	ft::set<char> data;

	for (int i = 0; i < size; ++i) {
		if (accend) {
			data.insert('a' + i);
		} else {
			data.insert('Z' - i);
		}
	}
	return data;
}

ft::set<std::string> _set_set_string(int size, bool accend)
{
	ft::set<std::string> data;
	std::string          str = "42Tokyo";

	for (int i = 0; i < size; ++i) {
		if (accend) {
			data.insert(str + static_cast<char>('a' + i));
		} else {
			data.insert(str + static_cast<char>('a' + std::rand() % 26));
		}
	}
	return data;
}

void _set_compare_sets(ft::set<std::string>& ft_data, std::set<std::string>& std_data, int size)
{
	std::string val;
	std::string strs[]   = { "42", "Tokyo", "Hello", "World", "!" };
	size_t      patterns = 5;

	for (int i = 0; i < size; ++i) {
		int index = std::rand() % patterns;

		val = strs[index] + strs[std::max(index - 1, 0)];
		ft_data.insert(val);
		std_data.insert(val);
	}
}

} // namespace SetTest
