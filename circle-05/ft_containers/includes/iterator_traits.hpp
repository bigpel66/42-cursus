// Copyright @bigpel66

#ifndef CIRCLE_05_FT_CONTAINERS_ITERATOR_TRAITS_HPP_
#define CIRCLE_05_FT_CONTAINERS_ITERATOR_TRAITS_HPP_

#include <cstddef>
#include <iterator>

namespace ft {

/* iterator_traits */
template <class Iterator>
struct iterator_traits {
  typedef typename Iterator::difference_type difference_type;
  typedef typename Iterator::value_type value_type;
  typedef typename Iterator::pointer pointer;
  typedef typename Iterator::reference reference;
  typedef typename Iterator::iterator_category iterator_category;
};

template <typename T>
struct iterator_traits<T*> {
  typedef std::ptrdiff_t difference_type;
  typedef T value_type;
  typedef T* pointer;
  typedef T& reference;
  typedef std::random_access_iterator_tag iterator_category;
};

template <typename T>
struct iterator_traits<const T*> {
  typedef std::ptrdiff_t difference_type;
  typedef T value_type;
  typedef const T* pointer;
  typedef const T& reference;
  typedef std::random_access_iterator_tag iterator_category;
};

}  // namespace ft

#endif  // CIRCLE_05_FT_CONTAINERS_ITERATOR_TRAITS_HPP_
