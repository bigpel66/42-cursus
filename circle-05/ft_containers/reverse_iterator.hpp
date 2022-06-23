// Copyright @bigpel66

#ifndef CIRCLE_05_FT_CONTAINERS_REVERSE_ITERATOR_HPP_
#define CIRCLE_05_FT_CONTAINERS_REVERSE_ITERATOR_HPP_

#include "./iterator_traits.hpp"

namespace ft {

/* reverese_iterator */
template <class Iterator>
class reverse_iterator {
 public:
  typedef Iterator iterator_type;
  typedef typename ft::iterator_traits<iterator_type>::difference_type difference_type;
  typedef typename ft::iterator_traits<iterator_type>::value_type value_type;
  typedef typename ft::iterator_traits<iterator_type>::pointer pointer;
  typedef typename ft::iterator_traits<iterator_type>::reference reference;
  typedef typename ft::iterator_traits<iterator_type>::iterator_category iterator_category;

  /* constructor & destructor */
  reverse_iterator(void) : iterator(iterator_type()) {}
  explicit reverse_iterator(iterator_type i) : iterator(i) {}
  template <class Other>
  reverse_iterator(const reverse_iterator<Other>& i) : iterator(i.base()) {}
  ~reverse_iterator(void) {}

  /* member function for util */
  template <class Other>
  reverse_iterator& operator=(const reverse_iterator<Other>& i) {
    iterator = i.base();
    return *this;
  }
  iterator_type base(void) const { return iterator; }
  reference operator*(void) const {
    iterator_type tmp = iterator;
    return *--tmp;
  }
  reference operator[](difference_type n) const {
    return *(*this + n);
  }
  pointer operator->(void) const { return &operator*(); }

  /* increment & decrement */
  reverse_iterator& operator++(void) {
    --iterator;
    return *this;
  }
  reverse_iterator& operator--(void) {
    ++iterator;
    return *this;
  }
  reverse_iterator operator++(int) {
    reverse_iterator tmp(*this);
    --iterator;
    return tmp;
  }
  reverse_iterator operator--(int) {
    reverse_iterator tmp(*this);
    ++iterator;
    return tmp;
  }

  /* arithmetic operators */
  reverse_iterator operator+(difference_type n) const {
    return reverse_iterator(iterator - n);
  }
  reverse_iterator operator-(difference_type n) const {
    return reverse_iterator(iterator + n);
  }
  reverse_iterator& operator+=(difference_type n) {
    iterator -= n;
    return *this;
  }
  reverse_iterator& operator-=(difference_type n) {
    iterator += n;
    return *this;
  }

 private:
  Iterator iterator;
};

/* special case of arithmetic operators */
template <class Iterator>
reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n,
                                     const reverse_iterator<Iterator>& i) {
  return reverse_iterator<Iterator>(i.base() - n);
}

template <class Iterator1, class Iterator2>
typename reverse_iterator<Iterator1>::difference_type operator-(const reverse_iterator<Iterator1>& x,
                                                                const reverse_iterator<Iterator2>& y) {
  return y.base() - x.base();
}

/* relational operators */
template <class Iterator1, class Iterator2>
bool operator==(const reverse_iterator<Iterator1>& x,
                const reverse_iterator<Iterator2>& y) {
  return x.base() == y.base();
}

template <class Iterator1, class Iterator2>
bool operator!=(const reverse_iterator<Iterator1>& x,
                const reverse_iterator<Iterator2>& y) {
  return x.base() != y.base();
}

template <class Iterator1, class Iterator2>
bool operator<(const reverse_iterator<Iterator1>& x,
               const reverse_iterator<Iterator2>& y) {
  return x.base() > y.base();
}

template <class Iterator1, class Iterator2>
bool operator<=(const reverse_iterator<Iterator1>& x,
                const reverse_iterator<Iterator2>& y) {
  return x.base() >= y.base();
}

template <class Iterator1, class Iterator2>
bool operator>(const reverse_iterator<Iterator1>& x,
               const reverse_iterator<Iterator2>& y) {
  return x.base() < y.base();
}

template <class Iterator1, class Iterator2>
bool operator>=(const reverse_iterator<Iterator1>& x,
                const reverse_iterator<Iterator2>& y) {
  return x.base() <= y.base();
}

}  // namespace ft

#endif  // CIRCLE_05_FT_CONTAINERS_REVERSE_ITERATOR_HPP_
