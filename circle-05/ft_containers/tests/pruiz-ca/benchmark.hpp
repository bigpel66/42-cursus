// Copyright @pruiz-ca
// Modified by @bigpel66

#ifndef CIRCLE_05_FT_CONTAINERS_TESTS_PRUIZ_CA_BENCHMARK_HPP_
#define CIRCLE_05_FT_CONTAINERS_TESTS_PRUIZ_CA_BENCHMARK_HPP_

#include <ctime>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include "../../includes/map.hpp"
#include "../../includes/set.hpp"
#include "../../includes/stack.hpp"
#include "../../includes/vector.hpp"

class Timer {
 private:
  std::clock_t __start;

 public:
  Timer(void);
  Timer(const Timer& t);
  ~Timer(void);
  Timer& operator=(const Timer& t);

  void start(void);
  std::clock_t stop(void);
};

template <class Map>
std::clock_t map_insert_growing(std::size_t times, Map map) {
  Timer t;
  t.start();
  /* insert & find test */
  for (std::size_t i = 0 ; i < times ; i++) {
    map[i] = true;
    map.find(i);
  }
  /* copy constructor & destructor test */
  {
    Map tmp(map);
  }
  return t.stop();
}

template <class Set>
std::clock_t set_insert_growing(std::size_t times, Set set) {
  Timer t;
  t.start();
  /* insert & find test */
  for (std::size_t i = 0 ; i < times ; i++) {
    set.insert(i);
    set.find(i);
  }
  /* copy constructor & destructor test */
  {
    Set tmp(set);
  }
  return t.stop();
}

template <class Stack>
std::clock_t stack_insert_growing(std::size_t times, Stack stack) {
  Timer t;
  t.start();
  /* insert test */
  for (std::size_t i =  0 ; i < times ; i++) {
    stack.push(i);
  }
  /* copy constructor & destructor test */
  {
    Stack tmp(stack);
  }
  /* find & erase test */
  for (std::size_t i = 0 ; i < times ; i++) {
    (void)stack.top();
    stack.pop();
  }
  return t.stop();
}

template <class Vector>
std::clock_t vector_insert_growing(std::size_t times, Vector vector) {
  Timer t;
  t.start();
  /* insert & find test */
  for (std::size_t i = 0 ; i < times ; i++) {
    vector.push_back(i);
    (void)vector[i];
  }
  /* copy constructor & destructor test */
  {
    Vector tmp(vector);
  }
  /* erase test */
  vector.erase(vector.begin(), vector.end());
  return t.stop();
}

void benchmark_map(void);
void benchmark_set(void);
void benchmark_stack(void);
void benchmark_vector(void);

#endif  // CIRCLE_05_FT_CONTAINERS_TESTS_PRUIZ_CA_BENCHMARK_HPP_
