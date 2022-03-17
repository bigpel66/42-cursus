// Copyright @bigpel66

#include "span.hpp"

const char* Span::CannotStoreException::what(void) const throw() {
  return "Not Enough Capacity";
}

const char* Span::CannotSpanException::what(void) const throw() {
  return "Not Enough Element";
}

const std::vector<int>& Span::getData(void) const {
  return _data;
}

void  Span::addNumber(int value) {
  if (_data.size() == _data.capacity())
    throw CannotStoreException();
  _data.push_back(value);
}

std::size_t Span::shortestSpan(void) {
  if (_data.size() < 2)
    throw CannotSpanException();
  std::vector<int> diff(_data);
  std::sort(std::begin(diff), std::end(diff));
  std::adjacent_difference(std::begin(diff), std::end(diff), std::begin(diff));
  std::transform(std::begin(diff),
                  std::end(diff),
                  std::begin(diff),
                  Functor());
                  // [] (int& i) { return std::abs(i); });
  return *std::min_element(std::begin(diff), std::end(diff));
}

std::size_t Span::longestSpan(void) {
  if (_data.size() < 2)
    throw CannotSpanException();
  std::pair<std::vector<int>::iterator, std::vector<int>::iterator> p_iter
    = std::minmax_element(std::begin(_data), std::end(_data));
  return *(p_iter.second) - *(p_iter.first);
}

Span& Span::operator=(const Span& s) {
  if (_data.capacity() != s.getData().capacity())
    return *this;
  if (this != &s) {
    _data.clear();
    _data.reserve(s.getData().capacity());
    std::copy(std::begin(s.getData()),
              std::end(s.getData()),
              std::back_inserter(_data));
  }
  return *this;
}

Span::Span(void)
  : _data(0, 0) {
  _data.reserve(0);
}

Span::Span(std::size_t n)
  : _data(0, 0) {
  _data.reserve(n);
}

Span::Span(const Span& s)
  : _data(0, 0) {
  _data.reserve(s.getData().capacity());
  std::copy(std::begin(s.getData()),
            std::end(s.getData()),
            std::back_inserter(_data));
}

Span::~Span(void) {}
