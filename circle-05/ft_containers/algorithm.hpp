// Copyright @bigpel66

#ifndef CIRCLE_05_FT_CONTAINERS_ALGORITHM_HPP_
#define CIRCLE_05_FT_CONTAINERS_ALGORITHM_HPP_

#include <cstdint>
#include <stdexcept>

namespace ft {

/* equal */
template <class InputIterator1, class InputIterator2>
bool equal(InputIterator1 first1,
           InputIterator1 last1,
           InputIterator2 first2) {
  for ( ; first1 != last1 ; first1++, first2++) {
    if (!(*first1 == *first2)) {
      return false;
    }
  }
  return true;
}

template <class InputIterator1, class InputIterator2, class BinaryPredicate>
bool equal(InputIterator1 first1,
           InputIterator1 last1,
           InputIterator2 first2,
           BinaryPredicate pred) {
  for ( ; first1 != last1 ; first1++, first2++) {
    if (!pred(*first1, *first2)) {
      return false;
    }
    return true;
  }
}

/* lexicographical_compare */
template <class InputIterator1, class InputIterator2>
bool lexicographical_compare(InputIterator1 first1,
                             InputIterator1 last1,
                             InputIterator2 first2,
                             InputIterator2 last2) {
  for ( ; first2 != last2 ; first1++, first2++) {
    if (first1 == last1 || *first1 < *first2) {
      return true;
    }
    if (*first1 > *first2) {
      return false;
    }
  }
  return false;
}

template <class InputIterator1, class InputIterator2, class Compare>
bool lexicographical_compare(InputIterator1 first1,
                             InputIterator1 last1,
                             InputIterator2 first2,
                             InputIterator2 last2,
                             Compare comp) {
  for ( ; first2 != last2 ; first1++, first2++) {
    if (first1 == last1 || comp(*first1, *first2)) {
      return true;
    }
    if (comp(*first2, *first1)) {
      return false;
    }
  }
  return false;
}

}  // namespace ft

#endif  // CIRCLE_05_FT_CONTAINERS_ALGORITHM_HPP_
