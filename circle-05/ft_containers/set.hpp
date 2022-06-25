// Copyright @bigpel66

#ifndef CIRCLE_05_FT_CONTAINERS_SET_HPP_
#define CIRCLE_05_FT_CONTAINERS_SET_HPP_

#include <functional>
#include <memory>
#include "./algorithm.hpp"
#include "./pair.hpp"
#include "./rbtree.hpp"
#include "./reverse_iterator.hpp"

namespace ft {

/* set */
template <typename T,
          class Compare = std::less<T>,
          class Allocator = std::allocator<T> >
class set {
 public:
  typedef T key_type;
  typedef T value_type;
  typedef Compare compare_type;
  typedef Compare key_compare;
  typedef Compare value_compare;

  typedef Allocator allocator_type;
  typedef typename allocator_type::template rebind<value_type>::other type_allocator;
  typedef std::allocator_traits<type_allocator> type_traits;
  typedef typename type_traits::pointer pointer;
  typedef typename type_traits::const_pointer const_pointer;
  typedef value_type& reference;
  typedef const value_type& const_reference;

  typedef std::size_t size_type;
  typedef std::ptrdiff_t difference_type;

  typedef typename ft::__rbtree<const value_type, key_type, value_compare, allocator_type>::iterator iterator;
  typedef typename ft::__rbtree<const value_type, key_type, value_compare, allocator_type>::const_iterator const_iterator;
  typedef ft::reverse_iterator<iterator> reverse_iterator;
  typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

  /* constructor & destructor */
  explicit set(const compare_type& comp = compare_type(),
               const allocator_type& alloc = allocator_type())
    : __comp(comp), __alloc(alloc), __tree(comp, alloc) {}
  template <class InputIterator>
  set(InputIterator first,
      InputIterator last,
      const compare_type& comp = compare_type(),
      const allocator_type& alloc = allocator_type(),
      typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = ft::nil)
    : __comp(comp), __alloc(alloc), __tree(comp, alloc) {
    insert(first, last);
  }
  set(const set& s)
    : __comp(s.__comp), __alloc(s.__alloc), __tree(s.__tree) {}
  ~set(void) {}

  /* member function for util */
  set& operator=(const set& s) {
    if (this != &s) {
      __comp = s.__comp;
      __alloc = s.__alloc;
      __tree = s.__tree;
    }
    return *this;
  }

  /* iterators */
  iterator begin(void) {
    return __tree.begin();
  }
  const_iterator begin(void) const {
    return __tree.begin();
  }
  iterator end(void) {
    return __tree.end();
  }
  const_iterator end(void) const {
    return __tree.end();
  }
  reverse_iterator rbegin(void) {
    return reverse_iterator(end());
  }
  const_reverse_iterator rbegin(void) const {
    return reverse_iterator(end());
  }
  reverse_iterator rend(void) {
    return reverse_iterator(begin());
  }
  const_reverse_iterator rend(void) const {
    return reverse_iterator(begin());
  }

  /* capacity */
  bool empty(void) const {
    return __tree.empty();
  }
  size_type size(void) const {
    return __tree.size();
  }
  size_type max_size(void) const {
    return __tree.max_size();
  }

  /* modifiers */
  ft::pair<iterator, bool> insert(const value_type& value) {
    return __tree.insert(value);
  }
  iterator insert(iterator position, const value_type& value) {
    return __tree.insert(position, value);
  }
  template <class InputIterator>
  void insert(InputIterator first, InputIterator last) {
    __tree.insert(first, last);
  }
  void erase(iterator position) {
    __tree.erase(position);
  }
  size_type erase(const value_type& value) {
    return __tree.erase(value);
  }
  void erase(iterator first, iterator last) {
    __tree.erase(first, last);
  }
  void swap(set& s) {
    __tree.swap(s.__tree);
  }
  void clear(void) {
    __tree.clear();
  }

  /* observers */
  key_compare key_comp(void) const {
    return __comp;
  }
  value_compare value_comp(void) const {
    return __comp;
  }

  /* loopup operations */
  iterator find(const value_type& value) const {
    return __tree.find(value);
  }
  size_type count(const value_type& value) const {
    return !(find(value) == end());
  }
  iterator lower_bound(const value_type& value) const {
    return __tree.lower_bound(value);
  }
  iterator upper_bound(const value_type& value) const {
    return __tree.upper_bound(value);
  }
  pair<iterator, iterator> equal_range(const value_type& value) const {
    return __tree.equal_range(value);
  }

  /* allocator */
  allocator_type get_allocator(void) const {
    return __tree.get_allocator();
  }

 private:
  compare_type __comp;
  allocator_type __alloc;
  ft::__rbtree<const value_type, key_type, value_compare, allocator_type> __tree;
};

/* relational operators */
template <class T, class Compare, class Allocator>
bool operator==(const ft::set<T, Compare, Allocator>& x,
                const ft::set<T, Compare, Allocator>& y) {
  return x.size() == y.size() && ft::equal(x.begin(), x.end(), y.begin());
}

template <class T, class Compare, class Allocator>
bool operator!=(const ft::set<T, Compare, Allocator>& x,
                const ft::set<T, Compare, Allocator>& y) {
  return !(x == y);
}

template <class T, class Compare, class Allocator>
bool operator<(const ft::set<T, Compare, Allocator>& x,
               const ft::set<T, Compare, Allocator>& y) {
  return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
}

template <class T, class Compare, class Allocator>
bool operator<=(const ft::set<T, Compare, Allocator>& x,
                const ft::set<T, Compare, Allocator>& y) {
  return !(y < x);
}

template <class T, class Compare, class Allocator>
bool operator>(const ft::set<T, Compare, Allocator>& x,
               const ft::set<T, Compare, Allocator>& y) {
  return y < x;
}

template <class T, class Compare, class Allocator>
bool operator>=(const ft::set<T, Compare, Allocator>& x,
                const ft::set<T, Compare, Allocator>& y) {
  return !(x < y);
}

/* non member function for util */
template <typename T, class Compare, class Allocator>
void swap(ft::set<T, Compare, Allocator>& x,
          ft::set<T, Compare, Allocator>& y) {
  x.swap(y);
}

}  // namespace ft

#endif  // CIRCLE_05_FT_CONTAINERS_SET_HPP_
