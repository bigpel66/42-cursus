// Copyright @bigpel66

#ifndef CIRCLE_04_CPP_MODULE_08_EX00_EASYFIND_HPP_
#define CIRCLE_04_CPP_MODULE_08_EX00_EASYFIND_HPP_

#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <stdexcept>
#include <string>
#include <vector>

template <typename C>
typename C::iterator easyfind(C* container, int value) {
  typename C::iterator iter = std::find(std::begin(*container),
                                        std::end(*container),
                                        value);
  if (iter == std::end(*container))
    throw std::runtime_error(std::string("Value ") +
          std::to_string(value) +
          std::string(" is not in C"));
  return iter;
}

/*
**  template <typename C, typename... Arg>
**  void test(C* container, int value, Arg... args) {
**    *container = C{args...};
**    try {
**      typename C::iterator iter = easyfind(container, value);
**      std::cout << "Value " << value << " found on Index "
**        << std::distance(std::begin(*container), iter) << std::endl;
**    } catch (std::exception& e) {
**      std::cerr << e.what() << std::endl;
**    }
**  }
*/

#endif  // CIRCLE_04_CPP_MODULE_08_EX00_EASYFIND_HPP_
