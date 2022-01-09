// Copyright @bigpel66

#ifndef CIRCLE_04_CPP_MODULE_08_EX01_SPAN_HPP_
#define CIRCLE_04_CPP_MODULE_08_EX01_SPAN_HPP_

#include <array>
#include <algorithm>
#include <cstddef>
#include <exception>
#include <numeric>
#include <iostream>
#include <utility>
#include <vector>

class Functor {
 public:
  int operator()(const int& i) { return std::abs(i); }
};

class Span {
 private:
  std::vector<int> _data;

  Span(void);

 public:
  class CannotStoreException
    : public std::exception {
   public:
      const char* what(void) const throw();
  };

  class CannotSpanException
    : public std::exception {
   public:
      const char* what(void) const throw();
  };

  const std::vector<int>& getData(void) const;

  void addNumber(int value);

  template <typename T>
  void addRange(T begin, T end) {
    if (std::distance(begin, end)
        > static_cast<int>(_data.capacity() - _data.size()))
      throw CannotStoreException();
    while (begin != end)
      _data.push_back(*begin++);
  }

  std::size_t shortestSpan(void);
  std::size_t longestSpan(void);

  Span& operator=(const Span& s);
  explicit Span(std::size_t n);
  Span(const Span& s);
  ~Span(void);
};

#endif  // CIRCLE_04_CPP_MODULE_08_EX01_SPAN_HPP_
