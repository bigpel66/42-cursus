// Copyright @bigpel66

#ifndef CIRCLE_05_FT_CONTAINERS_VECTOR_HPP_
#define CIRCLE_05_FT_CONTAINERS_VECTOR_HPP_

#include <algorithm>
#include <limits>
#include <memory>
#include <stdexcept>
#include "./algorithm.hpp"
#include "./iterator_traits.hpp"
#include "./random_access_iterator.hpp"
#include "./reverse_iterator.hpp"
#include "./type_traits.hpp"

namespace ft {

/* vector */
template <typename T, class Allocator = std::allocator<T> >
class vector {
 public:
  typedef T value_type;

  typedef Allocator allocator_type;
  typedef typename allocator_type::template rebind<value_type>::other type_allocator;
  typedef std::allocator_traits<type_allocator> type_traits;
  typedef typename type_traits::pointer pointer;
  typedef typename type_traits::const_pointer const_pointer;
  typedef value_type& reference;
  typedef const value_type& const_reference;

  typedef typename std::size_t size_type;
  typedef typename std::ptrdiff_t difference_type;

  typedef ft::random_access_iterator<value_type> iterator;
  typedef ft::random_access_iterator<const value_type> const_iterator;
  typedef ft::reverse_iterator<iterator> reverse_iterator;
  typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

  /* constructor & destructor */
  explicit vector(const allocator_type& alloc = allocator_type())
    : __begin(ft::nil),
      __end(ft::nil),
      __cap(ft::nil),
      __alloc(alloc) {}
  explicit vector(size_type n,
                  const value_type& value = value_type(),
                  const allocator_type& alloc = allocator_type())
    : __alloc(alloc) {
    __init(n);
    __construct(n, value);
  }
  template <class InputIterator>
  vector(InputIterator first,
         InputIterator last,
         const allocator_type& alloc = allocator_type(),
         typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = ft::nil)
    : __alloc(alloc) {
    size_type n = std::distance(first, last);
    __init(n);
    __construct(n);
    std::copy(first, last, __begin);
  }
  vector(const vector& v)
    : __alloc(v.__alloc) {
    size_type n = v.size();
    __init(v.capacity());
    __construct(n);
    std::copy(v.__begin, v.__end, __begin);
  }
  ~vector(void) {
    if (__begin == ft::nil) {
      return;
    }
    size_type pre_capacity = capacity();
    __destruct(__begin);
    __alloc.deallocate(__begin, pre_capacity);
  }

  /* member function for util */
  vector& operator=(const vector& v) {
    if (this != &v) {
      assign(v.__begin, v.__end);
    }
    return *this;
  }

  /* iterators */
  iterator begin(void) {
    return iterator(__begin);
  }
  const_iterator begin(void) const {
    return const_iterator(__begin);
  }
  iterator end(void) {
    return iterator(__end);
  }
  const_iterator end(void) const {
    return const_iterator(__end);
  }
  reverse_iterator rbegin(void) {
    return reverse_iterator(end());
  }
  const_reverse_iterator rbegin(void) const {
    return const_reverse_iterator(end());
  }
  reverse_iterator rend(void) {
    return reverse_iterator(begin());
  }
  const_reverse_iterator rend(void) const {
    return const_reveres_iterator(begin());
  }

  /* element access */
  reference operator[](size_type n) {
    return __begin[n];
  }
  const_reference operator[](size_type n) const {
    return __begin[n];
  }
  reference at(size_type n) {
    if (n >= size()) {
      throw std::out_of_range("index out of range");
    }
    return __begin[n];
  }
  const_reference at(size_type n) const {
    if (n >= size()) {
      throw std::out_of_range("index out of range");
    }
    return __begin[n];
  }
  reference front(void) {
    return *__begin;
  }
  const_reference front(void) const {
    return *__begin;
  }
  reference back(void) {
    return *(__end - 1);
  }
  const_reference back(void) const {
    return *(__end - 1);
  }
  T* data(void) throw() {
    return reinterpret_cast<T*>(__begin);
  }
  const T* data(void) const throw() {
    return reinterpret_cast<const T*>(__begin);
  }

  /* capacity */
  size_type size(void) const {
    return static_cast<size_type>(__end - __begin);
  }
  size_type max_size(void) const {
    return std::min<size_type>(std::numeric_limits<size_type>::max(),
                               type_traits::max_size(type_allocator()));
  }
  void resize(size_type n, value_type value = value_type()) {
    if (size() > n) {
      size_type diff = size() - n;
      __destruct(diff);
    } else if (size() < n) {
      size_type diff = n - size();
      if (capacity() < n) {
        reserve(n);
      }
      __construct(diff, value);
    }
  }
  size_type capacity(void) const {
    return static_cast<size_type>(__cap - __begin);
  }
  bool empty(void) const { return __begin == __end; }
  void reserve(size_type n) {
    if (n <= size() || n <= capacity()) {
      return;
    }
    if (n < capacity() * 2) {
      n = capacity() * 2;
    }
    size_type pre_size = size();
    size_type pre_capacity = capacity();
    pointer begin = __alloc.allocate(n);
    std::uninitialized_copy(__begin, __end, begin);
    __destruct(__begin);
    __alloc.deallocate(__begin, pre_capacity);
    __begin = begin;
    __end = __begin + pre_size;
    __cap = __begin + n;
  }

  /* modifiers */
  template <class InputIterator>
  void assign(InputIterator first,
              InputIterator last,
              typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = ft::nil) {
    size_type n = std::distance(first, last);
    if (capacity() < n) {
      reserve(n);
    }
    std::copy(first, last, __begin);
    __end = __begin + n;
  }
  void assign(size_type n, const value_type& value) {
    if (capacity() < n) {
      reserve(n);
    }
    std::fill_n(__begin, n, value);
    __end = __begin + n;
  }
  void push_back(const value_type& value) {
    size_type n = size() + 1;
    if (capacity() < n) {
      reserve(n);
    }
    __construct(1);
    *(__end - 1) = value;
  }
  void pop_back(void) {
    __destruct(1);
  }
  iterator insert(iterator position, const value_type& value) {
    difference_type diff = position - begin();
    if (capacity() < size() + 1) {
      reserve(size() + 1);
    }
    pointer ptr = __begin + diff;
    __construct(1);
    std::copy_backward(ptr, __end - 1, __end);
    *ptr = value;
    return iterator(ptr);
  }
  void insert(iterator position, size_type n, const value_type& value) {
    difference_type diff = position - begin();
    if (capacity() < size() + n) {
      reserve(size() + n);
    }
    pointer ptr = __begin + diff;
    __construct(n);
    std::copy_backward(ptr, __end - n, __end);
    for (size_type i = 0 ; i < n ; i++) {
      ptr[i] = value;
    }
  }
  template <class InputIterator>
  void insert(iterator position,
                InputIterator first,
                InputIterator last,
                typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = ft::nil) {
    difference_type n = std::distance(first, last);
    difference_type diff = position - begin();
    if (capacity() < size() + n) {
      reserve(size() + n);
    }
    pointer ptr = __begin + diff;
    __construct(n);
    std::copy_backward(ptr, __end - n, __end);
    for (InputIterator i = first ; i != last ; i++, ptr++) {
      *ptr = *i;
    }
  }
  iterator erase(iterator position) {
    difference_type diff = position - begin();
    pointer ptr = __begin + diff;
    std::copy(ptr + 1, __end, ptr);
    __destruct(1);
    return iterator(ptr);
  }
  iterator erase(iterator first, iterator last) {
    difference_type n = std::distance(first, last);
    std::copy(last, end(), first);
    __destruct(n);
    return first;
  }
  void swap(vector& v) {
    std::swap(__begin, v.__begin);
    std::swap(__end, v.__end);
    std::swap(__cap, v.__cap);
    std::swap(__alloc, v.__alloc);
  }
  void clear(void) {
    __destruct(__begin);
  }

  /* allocator */
  allocator_type get_allocator(void) const {
    return __alloc;
  }

 private:
  pointer __begin;
  pointer __end;
  pointer __cap;
  allocator_type __alloc;

  /* initialize memory & iterating pointer */
  void __init(size_type n) {
    if (n > max_size()) {
      throw std::length_error("allocation size too big");
    }
    __begin = __alloc.allocate(n);
    __end = __begin;
    __cap = __begin + n;
  }

  /* construct with specific value */
  void __construct(size_type n, T value) {
    for ( ; n > 0 ; __end++, n--) {
      __alloc.construct(__end);
      *__end = value;
    }
  }

  /* construct without value */
  void __construct(size_type n) {
    for ( ; n > 0 ; __end++, n--) {
      __alloc.construct(__end);
    }
  }

  /* destruct with size from end */
  void __destruct(size_type n) {
    for ( ; n > 0 && __end-- ; n--) {
      __alloc.destroy(__end);
    }
  }

  /* destruct from end to pointer */
  void __destruct(pointer until) {
    for ( ; __end != until && __end-- ; ) {
      __alloc.destroy(__end);
    }
  }
};

/* relational operators */
template <typename T, class Allocator>
bool operator==(const ft::vector<T, Allocator>& x,
                const ft::vector<T, Allocator>& y) {
  return x.size() == y.size() &&
         ft::equal(x.begin(), x.end(), y.begin());
}

template <typename T, class Allocator>
bool operator!=(const ft::vector<T, Allocator>& x,
                const ft::vector<T, Allocator>& y) {
  return !(x == y);
}

template <typename T, class Allocator>
bool operator<(const ft::vector<T, Allocator>& x,
               const ft::vector<T, Allocator>& y) {
  return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
}

template <typename T, class Allocator>
bool operator<=(const ft::vector<T, Allocator>& x,
                const ft::vector<T, Allocator>& y) {
  return x == y || x < y;
}

template <typename T, class Allocator>
bool operator>(const ft::vector<T, Allocator>& x,
               const ft::vector<T, Allocator>& y) {
  return !(x <= y);
}

template <typename T, class Allocator>
bool operator>=(const ft::vector<T, Allocator>& x,
                const ft::vector<T, Allocator>& y) {
  return x == y || x > y;
}

/* non member function for util */
template <typename T, class Allocator>
void swap(ft::vector<T, Allocator>& x,
          ft::vector<T, Allocator>& y) {
  x.swap(y);
}

}  // namespace ft

#endif  // CIRCLE_05_FT_CONTAINERS_VECTOR_HPP_
