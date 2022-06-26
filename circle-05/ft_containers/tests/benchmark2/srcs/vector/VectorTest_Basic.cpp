#include "../includes/Log.hpp"
#include "../includes/UnitTester.hpp"
#include "../includes/VectorTest.hpp"
#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

namespace VectorTest {

// -------------------------------------------------------------------------- //
//                                 constructor                                //
// -------------------------------------------------------------------------- //

void _vector_constructor_default()
{
	set_explanation_("result differs from std behavior");
	ft::vector<int>  ft;
	std::vector<int> std;
	_compare_vectors(ft, std);
}

void _vector_constructor_int()
{
	set_explanation_("result differs from std behavior");
	size_t           size  = 21;
	int              value = 42;
	ft::vector<int>  ft(size, value);
	std::vector<int> std(size, value);
	_compare_vectors(ft, std);
}

void _vector_constructor_float()
{
	set_explanation_("result differs from std behavior");
	size_t             size  = 21;
	float              value = 42.4242;
	ft::vector<float>  ft(size, value);
	std::vector<float> std(size, value);
	_compare_vectors(ft, std);
}

void _vector_constructor_string()
{
	set_explanation_("result differs from std behavior");
	size_t                   size  = 21;
	std::string              value = "42Tokyo";
	ft::vector<std::string>  ft(size, value);
	std::vector<std::string> std(size, value);
	_compare_vectors(ft, std);
}

void _vector_constructor_iterator_int()
{
	set_explanation_("result differs from std behavior");
	int  array[100];
	int* array_end = array + 100;
	_set_int_array(array, 100);

	ft::vector<int>  ft(array, array_end);
	std::vector<int> std(array, array_end);
	_compare_vectors(ft, std);
}

void _vector_constructor_iterator_vector()
{
	set_explanation_("result differs from std behavior");
	int  array[100];
	int* array_end = array + 100;
	_set_int_array(array, 100);
	std::vector<int> vec_array(array, array_end);

	std::vector<int>::iterator it     = vec_array.begin();
	std::vector<int>::iterator it_end = vec_array.end();
	ft::vector<int>            ft(it, it_end);
	std::vector<int>           std(it, it_end);
	_compare_vectors(ft, std);
}

void _vector_constructor_copy()
{
	set_explanation_("copy result differs from std behavior");
	ft::vector<int>  ft;
	std::vector<int> std;
	_set_compare_vectors(ft, std);

	ft::vector<int>  ft_cpy(ft);
	std::vector<int> std_cpy(std);
	_compare_vectors(ft_cpy, std_cpy);
}

void vector_constructor()
{
	load_subtest_(_vector_constructor_default);
	load_subtest_(_vector_constructor_int);
	load_subtest_(_vector_constructor_float);
	load_subtest_(_vector_constructor_string);
	load_subtest_(_vector_constructor_iterator_int);
	load_subtest_(_vector_constructor_iterator_vector);
	load_subtest_(_vector_constructor_copy);
}

// -------------------------------------------------------------------------- //
//                                 destructor                                 //
// -------------------------------------------------------------------------- //

void _vector_destructor()
{
	set_explanation_("destructor cruses");
	{
		ft::vector<int> ft;
	}
}

void vector_destructor()
{
	load_subtest_(_vector_destructor);
}

// -------------------------------------------------------------------------- //
//                                  operator=                                 //
// -------------------------------------------------------------------------- //

void _vector_assignemnt_operator_basic()
{
	set_explanation_("copy behavior changes original or new vector");
	ft::vector<int>  ft;
	std::vector<int> std;
	_set_compare_vectors(ft, std);

	ft::vector<int>  ft_copy;
	std::vector<int> std_copy;
	ft_copy  = ft;
	std_copy = std;
	_compare_vectors(ft, std);
	_compare_vectors(ft_copy, std_copy);
}

void vector_assignment_operator()
{
	load_subtest_(_vector_assignemnt_operator_basic);
}

// -------------------------------------------------------------------------- //
//                                   assign                                   //
// -------------------------------------------------------------------------- //

void _vector_assign_basic()
{
	set_explanation_("value not assigned");
	ft::vector<char> ft;
	size_t           size  = 12;
	char             value = 'a';
	ft.assign(size, value);
	for (size_t i = 0; i < size; ++i)
		UnitTester::assert_(ft[i] == value);
}

void _vector_assign_overwrite()
{
	set_explanation_("value not overwritten");
	size_t          size = 7;
	ft::vector<int> ft   = _set_vector(size);

	int value = 1024;
	ft.assign(size, value);
	for (size_t i = 0; i < size; ++i)
		UnitTester::assert_(ft[i] == value);
}

void _vector_assign_compare()
{
	set_explanation_("value differs from assigned std vector");
	ft::vector<int>  ft;
	std::vector<int> std;
	_set_compare_vectors(ft, std);

	size_t size  = 12;
	int    value = 42;
	ft.assign(size, value);
	std.assign(size, value);
	_compare_vectors(ft, std);
}

void vector_assign()
{
	load_subtest_(_vector_assign_basic);
	load_subtest_(_vector_assign_overwrite);
	load_subtest_(_vector_assign_compare);
}

// -------------------------------------------------------------------------- //
//                                get_allocator                               //
// -------------------------------------------------------------------------- //

template <class T>
class AllocatorTest : public std::allocator<T>
{
  private:
	size_t _size;

  public:
	AllocatorTest() : _size(sizeof(T)){};
	~AllocatorTest(){};
	size_t get_type_size() const { return _size; };
};

void _vector_get_allocator_default()
{
	set_explanation_("allocator is not returned");
	ft::vector<int> ft;

	std::allocator<std::string> alloc;
	UnitTester::assert_(ft.get_allocator() == alloc); // always return true
}

void _vector_get_allocator_basic()
{
	set_explanation_("allocator is not returned");
	ft::vector<int, AllocatorTest<int> > ft;

	std::allocator<std::string> alloc;
	UnitTester::assert_(ft.get_allocator() == alloc); // always return true
}

void _vector_get_allocator_type()
{
	set_explanation_("allocator is not returned");
	ft::vector<int, AllocatorTest<int> > ft;

	UnitTester::assert_(ft.get_allocator().get_type_size() == sizeof(int));
}

void vector_get_allocator()
{
	load_subtest_(_vector_get_allocator_default);
	load_subtest_(_vector_get_allocator_basic);
	load_subtest_(_vector_get_allocator_type);
}

} // namespace VectorTest
