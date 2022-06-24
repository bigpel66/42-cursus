// Copyright @bigpel66

#ifndef CIRCLE_05_FT_CONTAINERS_TREE_NODE_HPP_
#define CIRCLE_05_FT_CONTAINERS_TREE_NODE_HPP_

#include "./type_traits.hpp"

namespace ft {

/* tree_node */
template <typename T>
struct __tree_node {
  typedef __tree_node node_type;
  typedef T value_type;
  typedef bool binary_type;

  __tree_node* _parent;
  __tree_node* _left;
  __tree_node* _right;
  value_type _value;
  binary_type _is_black;

  /* constructor & destructor */
  __tree_node(void)
    : _parent(ft::nil),
      _left(ft::nil),
      _right(ft::nil),
      _value(value_type()),
      _is_black(binary_type()) {}
  __tree_node(const value_type& value)
    : _parent(ft::nil),
      _left(ft::nil),
      _right(ft::nil),
      _value(value),
      _is_black(binary_type()) {}
  __tree_node(const node_type& n)
    : _parent(n._parent),
      _left(n._left),
      _right(n._right),
      _value(n._value),
      _is_black(n._is_black) {}
  ~__tree_node(void) {}

  /* member function for util */
  node_type& operator=(const node_type& n) {
    if (this != &n) {
      _parent = n._parent;
      _left = n._left;
      _right = n._right;
      _value = n._value;
      _is_black = n._is_black;
    }
    return *this;
  }
};

}  // namespace ft

#endif  // CIRCLE_05_FT_CONTAINERS_TREE_NODE_HPP_
