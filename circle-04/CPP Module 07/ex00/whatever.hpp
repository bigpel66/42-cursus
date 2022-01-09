// Copyright @bigpel66

#ifndef CIRCLE_04_CPP_MODULE_07_EX00_WHATEVER_HPP_
#define CIRCLE_04_CPP_MODULE_07_EX00_WHATEVER_HPP_

#include <iostream>
#include <string>

template <typename T>
void tswap(T* a, T* b) {
  T* temp;

  temp = a;
  a = b;
  b = temp;
}

template <typename T>
const T& tmin(const T& a, const T& b) {
  return a < b ? a : b;
}

template <typename T>
const T& tmax(const T& a, const T& b) {
  return a > b ? a : b;
}

template <typename T>
void test(T a, T b) {
  std::cout << "a = " << a << ", b = " << b << std::endl;
  tswap(&a, &b);
  std::cout << "a = " << a << ", b = " << b << std::endl;
  std::cout << "min(a, b) = " << tmin(a, b) << std::endl;
  std::cout << "max(a, b) = " << tmax(a, b) << std::endl;
  std::cout << std::endl;
}

#endif  // CIRCLE_04_CPP_MODULE_07_EX00_WHATEVER_HPP_
