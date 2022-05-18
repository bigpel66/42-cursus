// Copyright @bigpel66

#include "./Headers.hpp"

void Headers::operator+=(const std::string& requested_string) {
}

Header& Headers::operator[](std::size_t index) {
  return _headers[index];
}

std::size_t Headers::size(void) const {
  return _headers.size();
}

std::size_t Headers::last_index(void) const {
  return _headers.size() - 1;
}

Header& Headers::last_header(void) {
  return _headers[last_index()];
}
