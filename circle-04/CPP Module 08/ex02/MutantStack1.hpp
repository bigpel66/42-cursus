// Copyright @bigpel66

#ifndef CIRCLE_04_CPP_MODULE_08_EX02_MUTANTSTACK_HPP_
#define CIRCLE_04_CPP_MODULE_08_EX02_MUTANTSTACK_HPP_

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
 public:
/*
**  using iterator = typename std::stack<T>::container_type::iterator;
**  using const_iterator = typename std::stack<T>::container_type::const_iterator;
**  using reverse_iterator= typename std::stack<T>::container_type::reverse_iterator;
**  using const_reverse_iterator = typename std::stack<T>::container_type::const_reverse_iterator;
*/
  typedef typename std::stack<T>::container_type::iterator
    iterator;
  typedef typename std::stack<T>::container_type::const_iterator
    const_iterator;
  typedef typename std::stack<T>::container_type::reverse_iterator
    reverse_iterator;
  typedef typename std::stack<T>::container_type::const_reverse_iterator
    const_reverse_iterator;

  iterator begin(void) {
    return this->c.begin();
  }

  iterator end(void) {
    return this->c.end();
  }

  const_iterator cbegin(void) const {
    return this->c.cbegin();
  }

  const_iterator cend(void) const {
    return this->c.cend();
  }

  reverse_iterator rbegin(void) {
    return this->c.rbegin();
  }

  reverse_iterator rend(void) {
    return this->c.rend();
  }

  const_reverse_iterator crbegin(void) const {
    return this->c.crbegin();
  }

  const_reverse_iterator crend(void) const {
    return this->c.crend();
  }

/*
**  MutantStack& operator=(const MutantStack& m) = default;
**  MutantStack(void) = default;
**  MutantStack(const MutantStack& m) = default;
**  MutantStack(MutantStack&& m) = default;
**  ~MutantStack(void) = default;
*/

  MutantStack& operator=(const MutantStack& m) {
    if (this != &m) {
      std::stack<T>::operator=(m);
    }
    return *this;
  }
  MutantStack(void) {}
  MutantStack(const MutantStack& m) { *this = m; }
  ~MutantStack(void) {}
};

#endif  // CIRCLE_04_CPP_MODULE_08_EX02_MUTANTSTACK_HPP_
