// Copyright @bigpel66

#ifndef CIRCLE_05_FT_CONTAINERS_RANDOM_ACCESS_ITERATOR_HPP_
#define CIRCLE_05_FT_CONTAINERS_RANDOM_ACCESS_ITERATOR_HPP_

#include <iterator>
#include "./iterator_traits.hpp"
#include "./type_traits.hpp"

namespace ft {

/* random_access_iterator */
template <typename T>
class random_access_iterator
  : public std::iterator<std::random_access_iterator_tag, T> {
 public:
  typedef T* iterator_type;
  typedef typename ft::iterator_traits<iterator_type>::value_type value_type;
  typedef typename ft::iterator_traits<iterator_type>::difference_type difference_type;
  typedef typename ft::iterator_traits<iterator_type>::pointer pointer;
  typedef typename ft::iterator_traits<iterator_type>::reference reference;
  typedef typename ft::iterator_traits<iterator_type>::iterator_category iterator_category;

  /* constructor & destructor */
  random_access_iterator(void): __i(ft::nil) {}
  random_access_iterator(T* pointer) : __i(pointer) {}
  template <typename U>
  random_access_iterator(const random_access_iterator<U>& i) : __i(i.base()) {}
  ~random_access_iterator(void) {}

  /* member function for util */
  template <typename U>
  random_access_iterator& operator=(const random_access_iterator<U>& i) {
    __i = i.base();
    return *this;
  }
  iterator_type base(void) const { return __i; }
  pointer operator->(void) const { return __i; }
  reference operator*(void) const { return *__i; }
  reference operator[](difference_type n) const { return __i[n]; }

  /* increment & decrement */
  random_access_iterator& operator++(void) {
    ++__i;
    return *this;
  }
  random_access_iterator& operator--(void) {
    --__i;
    return *this;
  }
  random_access_iterator operator++(int) {
    random_access_iterator tmp(*this);
    ++__i;
    return tmp;
  }
  random_access_iterator operator--(int) {
    random_access_iterator tmp(*this);
    --__i;
    return tmp;
  }

  /* arithmetic operators */
  random_access_iterator operator+(difference_type n) const {
    return random_access_iterator(__i + n);
  }
  random_access_iterator operator-(difference_type n) const {
    return random_access_iterator(__i - n);
  }
  random_access_iterator& operator+=(difference_type n) {
    __i += n;
    return *this;
  }
  random_access_iterator& operator-=(difference_type n) {
    __i -= n;
    return *this;
  }

 private:
  pointer __i;
};

/* special case of arithmetic operators */
template <typename T>
random_access_iterator<T> operator+(typename random_access_iterator<T>::difference_type n,
                                    const random_access_iterator<T>& i) {
  return random_access_iterator<T>(i.base() + n);
}

template <typename T1, typename T2>
typename random_access_iterator<T1>::difference_type operator-(const random_access_iterator<T1>& x,
                                                               const random_access_iterator<T2>& y) {
  return x.base() - y.base();
}

/* relational operators */
template <typename T1, typename T2>
bool operator==(const random_access_iterator<T1>& x,
                const random_access_iterator<T2>& y) {
  return x.base() == y.base();
}

template <typename T1, typename T2>
bool operator!=(const random_access_iterator<T1>& x,
                const random_access_iterator<T2>& y) {
  return x.base() != y.base();
}

template <typename T1, typename T2>
bool operator<(const random_access_iterator<T1>& x,
               const random_access_iterator<T2>& y) {
  return x.base() < y.base();
}

template <typename T1, typename T2>
bool operator<=(const random_access_iterator<T1>& x,
                const random_access_iterator<T2>& y) {
  return x.base() <= y.base();
}

template <typename T1, typename T2>
bool operator>(const random_access_iterator<T1>& x,
               const random_access_iterator<T2>& y) {
  return x.base() > y.base();
}

template <typename T1, typename T2>
bool operator>=(const random_access_iterator<T1>& x,
                const random_access_iterator<T2>& y) {
  return x.base() >= y.base();
}

}  // namespace ft

#endif  // CIRCLE_05_FT_CONTAINERS_RANDOM_ACCESS_ITERATOR_HPP_
