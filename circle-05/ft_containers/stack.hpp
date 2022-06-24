// Copyright @bigpel66

#ifndef CIRCLE_05_FT_CONTAINERS_STACK_HPP_
#define CIRCLE_05_FT_CONTAINERS_STACK_HPP_

#include "./vector.hpp"

namespace ft {

/* stack */
template <typename T, class Container = ft::vector<T> >
class stack {
 public:
  typedef Container container_type;
  typedef typename container_type::value_type value_type;
  typedef typename container_type::size_type size_type;
  typedef typename container_type::reference reference;
  typedef typename container_type::const_reference const_reference;

  /* constructor & destructor */
  explicit stack(const container_type& container = container_type())
    : c(container) {}
  stack(const stack& s) : c(s.c) {}
  ~stack(void) {}

  /* member function for util */
  stack& operator=(const stack& s) {
    if (this != &s) {
      c = s.c;
    }
    return *this;
  }

  /* element access */
  reference top(void) {
    return c.back();
  }
  const_reference top(void) const {
    return c.back();
  }

  /* capacity */
  bool empty(void) const {
    return c.empty();
  }

  size_type size(void) const {
    return c.size();
  }

  /* modifiers */
  void push(const value_type& value) {
    c.push_back(value);
  }
  void pop(void) {
    c.pop_back();
  }

  /* friend non member function for relational operators */
  friend bool operator==(const stack& x, const stack& y) {
    return x.c == y.c;
  }
  friend bool operator!=(const stack& x, const stack& y) {
    return x.c != y.c;
  }
  friend bool operator<(const stack& x, const stack& y) {
    return x.c < y.c;
  }
  friend bool operator<=(const stack& x, const stack& y) {
    return x.c <= y.c;
  }
  friend bool operator>(const stack& x, const stack& y) {
    return x.c > y.c;
  }
  friend bool operator>=(const stack& x, const stack& y) {
    return x.c >= y.c;
  }

 protected:
  container_type c;
};

}  // namespace ft

#endif  // CIRCLE_05_FT_CONTAINERS_STACK_HPP_
