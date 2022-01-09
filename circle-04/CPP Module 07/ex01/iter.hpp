// Copyright @bigpel66

#ifndef CIRCLE_04_CPP_MODULE_07_EX01_ITER_HPP_
#define CIRCLE_04_CPP_MODULE_07_EX01_ITER_HPP_

#include <cstddef>
#include <iostream>
#include <string>

template <typename T>
void iter(T* arr, std::size_t len, void (*f)(const T&)) {
  for (std::size_t i = 0 ; i < len ; ++i)
    f(arr[i]);
  std::cout << std::endl;
}

template <typename T>
void print(const T& arg) {
  std::cout << arg << "\t";
}

#endif  // CIRCLE_04_CPP_MODULE_07_EX01_ITER_HPP_
