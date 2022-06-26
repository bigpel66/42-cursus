// Copyright @bigple66

#ifndef CIRCLE_05_FT_CONTAINERS_RBTREE_HPP_
#define CIRCLE_05_FT_CONTAINERS_RBTREE_HPP_

#include <algorithm>
#include <limits>
#include <memory>
#include "./iterator_traits.hpp"
#include "./pair.hpp"
#include "./type_traits.hpp"

namespace ft {

/* tree_node */
template <typename T>
struct __tree_node {
  typedef T value_type;
  typedef bool binary_type;

  __tree_node* __parent;
  __tree_node* __left;
  __tree_node* __right;
  value_type __value;
  binary_type __is_black;

  /* constructor & destructor */
  __tree_node(void)
    : __parent(ft::nil),
      __left(ft::nil),
      __right(ft::nil),
      __value(value_type()),
      __is_black(binary_type()) {}
  __tree_node(const value_type& value)
    : __parent(ft::nil),
      __left(ft::nil),
      __right(ft::nil),
      __value(value),
      __is_black(binary_type()) {}
  __tree_node(const __tree_node& n)
    : __parent(n.__parent),
      __left(n.__left),
      __right(n.__right),
      __value(n.__value),
      __is_black(n.__is_black) {}
  ~__tree_node(void) {}

  /* member function for util */
  __tree_node& operator=(const __tree_node& n) {
    if (this != &n) {
      __parent = n.__parent;
      __left = n.__left;
      __right = n.__right;
      __value = n.__value;
      __is_black = n.__is_black;
    }
    return *this;
  }
};

/* non member function for util */
template <class NodePtr>
bool __is_left_child(const NodePtr& ptr) {
  return ptr == ptr->__parent->__left;
}

template <class NodePtr>
bool __is_right_child(const NodePtr& ptr) {
  return ptr == ptr->__parent->__right;
}

template <class NodePtr>
bool __is_black_color(const NodePtr& ptr) {
  return ptr->__is_black;
}

template <class NodePtr>
bool __is_red_color(const NodePtr& ptr) {
  return !ptr->__is_black;
}

template <class NodePtr>
NodePtr __get_min_node(NodePtr ptr, NodePtr nil) {
  while (ptr->__left != nil) {
    ptr = ptr->__left;
  }
  return ptr;
}

template <class NodePtr>
NodePtr __get_max_node(NodePtr ptr, NodePtr nil) {
  while (ptr->__right != nil) {
    ptr = ptr->__right;
  }
  return ptr;
}

template <class NodePtr>
NodePtr __get_next_node(NodePtr ptr, NodePtr nil) {
  if (ptr->__right != nil) {
    return __get_min_node(ptr->__right, nil);
  }
  while (!__is_left_child(ptr)) {
    ptr = ptr->__parent;
  }
  return ptr->__parent;
}

template <class NodePtr>
NodePtr __get_prev_node(NodePtr ptr, NodePtr nil) {
  if (ptr->__left != nil) {
    return __get_max_node(ptr->__left, nil);
  }
  while (!__is_right_child(ptr)) {
    ptr = ptr->__parent;
  }
  return ptr->__parent;
}

template <typename U, typename V, class Comp>
bool __is_equal(const U& u, const V& v, Comp comp) {
  return !comp(u, v) && !comp(v, u);
}

/* tree_iterator */
template <typename U, typename V>
class __tree_iterator {
 public:
  typedef U value_type;
  typedef value_type* pointer;
  typedef value_type& reference;
  typedef V* iterator_type;
  typedef typename ft::iterator_traits<iterator_type>::difference_type difference_type;
  typedef typename ft::iterator_traits<iterator_type>::value_type node_type;
  typedef typename ft::iterator_traits<iterator_type>::pointer node_pointer;
  typedef typename ft::iterator_traits<iterator_type>::reference node_reference;
  typedef typename ft::iterator_traits<iterator_type>::iterator_category iterator_category;

  /* constructor & destructor */
  __tree_iterator(void) : __cur(ft::nil), __nil(ft::nil) {}
  __tree_iterator(node_pointer cur, node_pointer nil)
    : __cur(cur), __nil(nil) {}
  __tree_iterator(const __tree_iterator& i)
    : __cur(i.__cur), __nil(i.__nil) {}
  ~__tree_iterator(void) {}

  /* member function for util */
  __tree_iterator& operator=(const __tree_iterator& i) {
    if (this != &i) {
      __cur = i.__cur;
      __nil = i.__nil;
    }
    return *this;
  }

  /* element access */
  node_pointer base(void) const { return __cur; }
  pointer operator->(void) const { return &__cur->__value; }
  reference operator*(void) const { return __cur->__value; }

  /* increment & decrement */
  __tree_iterator& operator++(void) {
    __cur = ft::__get_next_node(__cur, __nil);
    return *this;
  }
  __tree_iterator& operator--(void) {
    __cur = ft::__get_prev_node(__cur, __nil);
    return *this;
  }
  __tree_iterator operator++(int) {
    __tree_iterator tmp(*this);
    ++(*this);
    return tmp;
  }
  __tree_iterator operator--(int) {
    __tree_iterator tmp(*this);
    --(*this);
    return tmp;
  }

  /* relational operators */
  template <typename T>
  bool operator==(const __tree_iterator<T, node_type>& i) const {
    return __cur == i.base();
  }
  template <typename T>
  bool operator!=(const __tree_iterator<T, node_type>& i) const {
    return !(*this == i);
  }

  /* const type overloading */
  operator __tree_iterator<const value_type, node_type>(void) const {
    return __tree_iterator<const value_type, node_type>(__cur, __nil);
  }

  /* non member function for util */
  friend bool operator==(const __tree_iterator& x, const __tree_iterator& y) {
    return x.__cur == y.__cur;
  }
  friend bool operator!=(const __tree_iterator& x, const __tree_iterator& y) {
    return !(x == y);
  }

 private:
  node_pointer __cur;
  node_pointer __nil;
};

/* rbtree */
template <typename T, class Key, class Comp, class Allocator>
class __rbtree {
 public:
  typedef T value_type;
  typedef Key key_type;
  typedef Comp compare_type;

  typedef __tree_node<value_type> node_type;
  typedef __tree_node<value_type>* node_pointer;
  typedef __tree_iterator<value_type, node_type> iterator;
  typedef __tree_iterator<const value_type, node_type> const_iterator;

  typedef Allocator allocator_type;
  typedef typename allocator_type::template rebind<node_type>::other node_allocator;
  typedef std::allocator_traits<node_allocator> node_traits;

  typedef std::size_t size_type;
  typedef std::ptrdiff_t difference_type;

  /* constructor & destructor */
  __rbtree(const compare_type& comp, const allocator_type& alloc)
    : __comp(comp), __alloc(alloc), __size(size_type()) {
    __nil = __alloc.allocate(1);
    __alloc.construct(__nil, value_type());
    __nil->__is_black = true;
    __nil->__parent = __nil;
    __nil->__left = __nil;
    __nil->__right = __nil;
    __end = __construct_node(value_type());
    __end->__is_black = true;
    __begin = __end;
  }
  __rbtree(const __rbtree& t)
    : __comp(t.__comp), __alloc(t.__alloc), __size(size_type()) {
    __nil = __alloc.allocate(1);
    __alloc.construct(__nil, value_type());
    __nil->__is_black = true;
    __nil->__parent = __nil;
    __nil->__left = __nil;
    __nil->__right = __nil;
    __end = __construct_node(value_type());
    __end->__is_black = true;
    __begin = __end;
    insert(t.begin(), t.end());
  }
  ~__rbtree(void) {
    __destruct_node_recursive(__end);
    __destruct_node(__nil);
  }

  /* member function for util */
  __rbtree& operator=(const __rbtree& t) {
    if (this != &t) {
      __rbtree tmp(t);
      swap(tmp);
    }
    return *this;
  }

  /* iterators */
  iterator begin(void) {
    return iterator(__begin, __nil);
  }
  const_iterator begin(void) const {
    return const_iterator(__begin, __nil);
  }
  iterator end(void) {
    return iterator(__end, __nil);
  }
  const_iterator end(void) const {
    return const_iterator(__end, __nil);
  }

  /* capacity */
  size_type size(void) const {
    return __size;
  }
  size_type max_size(void) const {
    return std::min<size_type>(std::numeric_limits<size_type>::max(),
                               node_traits::max_size(node_allocator()));
  }
  bool empty(void) const {
    return __size == 0;
  }

  /* modifiers */
  ft::pair<iterator, bool> insert(const value_type& value) {
    node_pointer ptr = __search_parent(value);
    if (ptr != __end && __is_equal(ptr->__value, value, __comp)) {
      return ft::make_pair(iterator(ptr, __nil), false);
    }
    return ft::make_pair(iterator(__insert_internal(value, ptr), __nil), true);
  }
  iterator insert(iterator position, const value_type& value) {
    node_pointer ptr = __search_parent(value, position.base());
    if (ptr != __end && __is_equal(ptr->__value, value, __comp)) {
      return iterator(ptr, __nil);
    }
    return iterator(__insert_internal(value, ptr), __nil);
  }
  template <class InputIterator>
  void insert(InputIterator first, InputIterator last) {
    for ( ; first != last ; first++) {
      insert(*first);
    }
  }
  iterator erase(iterator position) {
    if (__size == 0) {
      return iterator(__nil, __nil);
    }
    iterator tmp(position);
    ++tmp;
    if (position == begin()) {
      __begin = tmp.base();
    }
    --__size;
    __remove_internal(position.base());
    __destruct_node(position.base());
    return tmp;
  }
  template <typename U>
  size_type erase(const U& value) {
    iterator i(__find_internal(value), __nil);
    if (i == end()) {
      return 0;
    }
    if (i == begin()) {
      iterator tmp(i);
      ++tmp;
      __begin = tmp.base();
    }
    --__size;
    __remove_internal(i.base());
    __destruct_node(i.base());
    return 1;
  }
  void erase(iterator first, iterator last) {
    for ( ; first != last ; ) {
      first = erase(first);
    }
  }
  void swap(__rbtree& t) {
    std::swap(__nil, t.__nil);
    std::swap(__begin, t.__begin);
    std::swap(__end, t.__end);
    std::swap(__comp, t.__comp);
    std::swap(__alloc, t.__alloc);
    std::swap(__size, t.__size);
  }
  void clear(void) {
    __rbtree tmp(__comp, __alloc);
    swap(tmp);
  }

  /* lookup operations */
  iterator find(const key_type& key) {
    return iterator(__find_internal(key), __nil);
  }
  const_iterator find(const key_type& key) const {
    return const_iterator(__find_internal(key), __nil);
  }
  iterator lower_bound(const key_type& key) {
    return iterator(__lower_bound_internal(key), __nil);
  }
  const_iterator lower_bound(const key_type& key) const {
    return const_iterator(__lower_bound_internal(key), __nil);
  }
  iterator upper_bound(const key_type& key) {
    return iterator(__upper_bound_internal(key), __nil);
  }
  const_iterator upper_bound(const key_type& key) const {
    return const_iterator(__upper_bound_internal(key), __nil);
  }
  ft::pair<iterator, iterator> equal_range(const key_type& key) {
    return __equal_range_internal(key);
  }
  ft::pair<const_iterator, const_iterator> equal_range(const key_type& key) const {
    return __equal_range_internal(key);
  }

  /* allocator */
  allocator_type get_allocator(void) const {
    return __alloc;
  }

 private:
  node_pointer __nil;
  node_pointer __begin;
  node_pointer __end;
  compare_type __comp;
  node_allocator __alloc;
  size_type __size;

  /* root */
  node_pointer __get_root(void) const {
    return __end->__left;
  }
  void __set_root(const node_pointer ptr) {
    ptr->__parent = __end;
    __end->__left = ptr;
  }

  /* modifiers */
  node_pointer __construct_node(const value_type& value) {
    node_pointer ptr = __alloc.allocate(1);
    __alloc.construct(ptr, value);
    ptr->__parent = __nil;
    ptr->__left = __nil;
    ptr->__right = __nil;
    ptr->__is_black = false;
    return ptr;
  }
  void __destruct_node(node_pointer ptr) {
    __alloc.destroy(ptr);
    __alloc.deallocate(ptr, 1);
  }
  void __destruct_node_recursive(node_pointer ptr) {
    if (ptr == __nil) {
      return;
    }
    __destruct_node_recursive(ptr->__left);
    __destruct_node_recursive(ptr->__right);
    __destruct_node(ptr);
  }
  node_pointer __search_parent(const value_type& value, node_pointer position = ft::nil) {
    if (position && position != __end) {
      if (__comp(value, position->__value) && position->__left == __nil) {
        iterator prev = iterator(position, __nil);
        if (prev == begin() || __comp(*--prev, value)) {
          return position;
        }
      } else if (position->__right == __nil) {
        iterator next = iterator(position, __nil);
        if (next == end() || __comp(value, *++next)) {
          return position;
        }
      }
    }
    node_pointer cur = __get_root();
    node_pointer tmp = __end;
    for ( ; cur != __nil ; ) {
      tmp = cur;
      if (__comp(value, cur->__value)) {
        cur = cur->__left;
      } else if (__comp(cur->__value, value)) {
        cur = cur->__right;
      } else {
        return cur;
      }
    }
    return tmp;
  }
  node_pointer __insert_internal(const value_type& value, node_pointer parent) {
    node_pointer ptr = __construct_node(value);
    if (parent == __end) {
      __set_root(ptr);
    } else if (__comp(value, parent->__value)) {
      parent->__left = ptr;
    } else {
      parent->__right = ptr;
    }
    ptr->__parent = parent;
    __insert_fixup(ptr);
    __insert_update(ptr);
    return ptr;
  }
  void __insert_fixup(node_pointer ptr) {
    while (__is_red_color(ptr->__parent)) {
      if (__is_left_child(ptr->__parent)) {
        __insert_fixup_left(ptr);
      } else {
        __insert_fixup_right(ptr);
      }
    }
    __get_root()->__is_black = true;
  }
  void __insert_fixup_left(node_pointer& ptr) {
    node_pointer uncle = ptr->__parent->__parent->__right;
    if (__is_red_color(uncle)) {
      ptr->__parent->__is_black = true;
      uncle->__is_black = true;
      uncle->__parent->__is_black = false;
      ptr = uncle->__parent;
    } else {
      if (__is_right_child(ptr)) {
        ptr = ptr->__parent;
        __rotate_left(ptr);
      }
      ptr->__parent->__is_black = true;
      ptr->__parent->__parent->__is_black = false;
      __rotate_right(ptr->__parent->__parent);
    }
  }
  void __insert_fixup_right(node_pointer& ptr) {
    node_pointer uncle = ptr->__parent->__parent->__left;
    if (__is_red_color(uncle)) {
      ptr->__parent->__is_black = true;
      uncle->__is_black = true;
      uncle->__parent->__is_black = false;
      ptr = uncle->__parent;
    } else {
      if (__is_left_child(ptr)) {
        ptr = ptr->__parent;
        __rotate_right(ptr);
      }
      ptr->__parent->__is_black = true;
      ptr->__parent->__parent->__is_black = false;
      __rotate_left(ptr->__parent->__parent);
    }
  }
  void __insert_update(const node_pointer ptr) {
    if (__begin == __end || __comp(ptr->__value, __begin->__value)) {
      __begin = ptr;
    }
    __size++;
  }
  void __remove_internal(node_pointer ptr) {
    node_pointer recolor_node;
    node_pointer fixup_node = ptr;
    bool original_color = __is_black_color(ptr);
    if (ptr->__left == __nil) {
      recolor_node = ptr->__right;
      __transplant(ptr, ptr->__right);
    } else if (ptr->__right == __nil) {
      recolor_node = ptr->__left;
      __transplant(ptr, ptr->__left);
    } else {
      fixup_node = __get_min_node(ptr->__right, __nil);
      original_color = __is_black_color(fixup_node);
      recolor_node = fixup_node->__right;
      if (fixup_node->__parent == ptr) {
        recolor_node->__parent = fixup_node;
      } else {
        __transplant(fixup_node, fixup_node->__right);
        fixup_node->__right = ptr->__right;
        fixup_node->__right->__parent = fixup_node;
      }
      __transplant(ptr, fixup_node);
      fixup_node->__left = ptr->__left;
      fixup_node->__left->__parent = fixup_node;
      fixup_node->__is_black = __is_black_color(ptr);
    }
    if (original_color) {
      __remove_fixup(recolor_node);
    }
  }
  void __remove_fixup(node_pointer ptr) {
    while (ptr != __get_root() && __is_black_color(ptr)) {
      if (__is_left_child(ptr)) {
        __remove_fixup_left(ptr);
      } else {
        __remove_fixup_right(ptr);
      }
    }
    ptr->__is_black = true;
  }
  void __remove_fixup_left(node_pointer& ptr) {
    node_pointer sibling = ptr->__parent->__right;
    if (__is_red_color(sibling)) {
      sibling->__is_black = true;
      ptr->__parent->__is_black = false;
      __rotate_left(ptr->__parent);
      sibling = ptr->__parent->__right;
    }
    if (__is_black_color(sibling->__left) && __is_black_color(sibling->__right)) {
      sibling->__is_black = false;
      ptr = ptr->__parent;
    } else if (__is_black_color(sibling->__right)) {
      sibling->__left->__is_black = true;
      sibling->__is_black = false;
      __rotate_right(sibling);
      sibling = ptr->__parent->__right;
    }
    if (__is_red_color(sibling->__right)) {
      sibling->__is_black = __is_black_color(ptr->__parent);
      ptr->__parent->__is_black = true;
      sibling->__right->__is_black = true;
      __rotate_left(ptr->__parent);
      ptr = __get_root();
    }
  }
  void __remove_fixup_right(node_pointer& ptr) {
    node_pointer sibling = ptr->__parent->__left;
    if (__is_red_color(sibling)) {
      sibling->__is_black = true;
      ptr->__parent->__is_black = false;
      __rotate_right(ptr->__parent);
      sibling = ptr->__parent->__left;
    }
    if (__is_black_color(sibling->__right) && __is_black_color(sibling->__left)) {
      sibling->__is_black = false;
      ptr = ptr->__parent;
    } else if (__is_black_color(sibling->__left)) {
      sibling->__right->__is_black = true;
      sibling->__is_black = false;
      __rotate_left(sibling);
      sibling = ptr->__parent->__left;
    }
    if (__is_red_color(sibling->__left)) {
      sibling->__is_black = __is_black_color(ptr->__parent);
      ptr->__parent->__is_black = true;
      sibling->__left->__is_black = true;
      __rotate_right(ptr->__parent);
      ptr = __get_root();
    }
  }
  void __transplant(node_pointer former, node_pointer latter) {
    if (former->__parent == __end) {
      __set_root(latter);
    } else if (__is_left_child(former)) {
      former->__parent->__left = latter;
    } else {
      former->__parent->__right = latter;
    }
    latter->__parent = former->__parent;
  }
  void __rotate_left(node_pointer ptr) {
    node_pointer child = ptr->__right;
    ptr->__right = child->__left;
    if (ptr->__right != __nil) {
      ptr->__right->__parent = ptr;
    }
    node_pointer parent = ptr->__parent;
    child->__parent = parent;
    if (parent == __end) {
      __set_root(child);
    } else if (__is_left_child(ptr)) {
      parent->__left = child;
    } else {
      parent->__right = child;
    }
    child->__left = ptr;
    ptr->__parent = child;
  }
  void __rotate_right(node_pointer ptr) {
    node_pointer child = ptr->__left;
    ptr->__left = child->__right;
    if (ptr->__left != __nil) {
      ptr->__left->__parent = ptr;
    }
    node_pointer parent = ptr->__parent;
    child->__parent = parent;
    if (parent == __end) {
      __set_root(child);
    } else if (__is_left_child(ptr)) {
      parent->__left = child;
    } else {
      parent->__right = child;
    }
    child->__right = ptr;
    ptr->__parent = child;
  }

  /* lookup operations */
  template <typename U>
  node_pointer __find_internal(const U& value) const {
    node_pointer ptr = __get_root();
    while (ptr != __nil) {
      if (__comp(value, ptr->__value)) {
        ptr = ptr->__left;
      } else if (__comp(ptr->__value, value)) {
        ptr = ptr->__right;
      } else {
        return ptr;
      }
    }
    return __end;
  }
  node_pointer __lower_bound_internal(const key_type& key) const {
    node_pointer ptr = __get_root();
    node_pointer tmp = __end;
    while (ptr != __nil) {
      if (!__comp(ptr->__value, key)) {
        tmp = ptr;
        ptr = ptr->__left;
      } else {
        ptr = ptr->__right;
      }
    }
    return tmp;
  }
  node_pointer __upper_bound_internal(const key_type& key) const {
    node_pointer ptr = __get_root();
    node_pointer tmp = __end;
    while (ptr != __nil) {
      if (__comp(key, ptr->__value)) {
        tmp = ptr;
        ptr = ptr->__left;
      } else {
        ptr = ptr->__right;
      }
    }
    return tmp;
  }
  template <typename U>
  ft::pair<iterator, iterator> __equal_range_internal(const U& value) {
    node_pointer ptr = __get_root();
    node_pointer tmp = __end;
    while (ptr != __nil) {
      if (__comp(value, ptr->__value)) {
        tmp = ptr;
        ptr = ptr->__left;
      } else if (__comp(ptr->__value, value)) {
        ptr = ptr->__right;
      } else {
        if (ptr->__right != __nil) {
          tmp = __get_min_node(ptr->__right, __nil);
        }
        return ft::make_pair(iterator(ptr, __nil), iterator(tmp, __nil));
      }
    }
    return ft::make_pair(iterator(tmp, __nil), iterator(tmp, __nil));
  }
  template <typename U>
  ft::pair<const_iterator, const_iterator> __equal_range_internal(const U& value) const {
    node_pointer ptr = __get_root();
    node_pointer tmp = __end;
    while (ptr != __nil) {
      if (__comp(value, ptr->__value)) {
        tmp = ptr;
        ptr = ptr->__left;
      } else if (__comp(ptr->__value, value)) {
        ptr = ptr->__right;
      } else {
        if (ptr->__right != __nil) {
          tmp = __get_min_node(ptr->__right, __nil);
        }
        return ft::make_pair(const_iterator(ptr, __nil), const_iterator(tmp, __nil));
      }
    }
    return ft::make_pair(const_iterator(tmp, __nil), const_iterator(tmp, __nil));
  }
};

}  // namespace ft

#endif  // CIRCLE_05_FT_CONTAINERS_RBTREE_HPP_
