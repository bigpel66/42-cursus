// Copyright @pruiz-ca
// Modified by @bigpel66

#include "./benchmark.hpp"

/* Timer */
Timer::Timer(void) : __start(0) {}
Timer::Timer(const Timer& t) : __start(t.__start) {}
Timer::~Timer(void) {}
Timer& Timer::operator=(const Timer& t) {
  if (this != &t) {
    __start = t.__start;
  }
  return *this;
}
void Timer::start(void) {
  __start = std::clock();
}
std::clock_t Timer::stop(void) {
  return std::clock() - __start;
}

/* benchmark */
void benchmark_map(void) {
  std::cout << "\033[1;34m--- MAP BENCHMARK ⚡ ---\033[0m" << std::endl;
  std::clock_t std;
  std::clock_t ft;
  std::map<int, bool> std_map;
  ft::map<int, bool> ft_map;
  std = map_insert_growing(200000, std_map);
  std::cout << "std: " << std << std::endl;
  ft = map_insert_growing(200000, ft_map);
  std::cout << "ft: " << ft << std::endl;
  if (static_cast<double>(ft) / static_cast<double>(std) < 1.0000) {
  std::cout << "our map is " << static_cast<double>(std) / static_cast<double>(ft) << " times faster. ";
  } else {
    std::cout << "our map is " << static_cast<double>(ft) / static_cast<double>(std) << " times slower. ";
  }
  if (static_cast<double>(ft) / static_cast<double>(std) < 20.0000) {
    std::cout << "\033[1;32m[PASS]\033[0m" << std::endl;
  } else {
    std::cout << "\033[1;31m[FAIL]\033[0m" << std::endl;
  }
  std::cout << std::endl;
}

void benchmark_set(void) {
  std::cout << "\033[1;34m--- SET BENCHMARK ⚡ ---\033[0m" << std::endl;
  std::clock_t std;
  std::clock_t ft;
  std::set<int> std_set;
  ft::set<int> ft_set;
  std = set_insert_growing(200000, std_set);
  std::cout << "std: " << std << std::endl;
  ft = set_insert_growing(200000, ft_set);
  std::cout << "ft: " << ft << std::endl;
  if (static_cast<double>(ft) / static_cast<double>(std) < 1.0000) {
  std::cout << "our set is " << static_cast<double>(std) / static_cast<double>(ft) << " times faster. ";
  } else {
    std::cout << "our set is " << static_cast<double>(ft) / static_cast<double>(std) << " times slower. ";
  }
  if (static_cast<double>(ft) / static_cast<double>(std) < 20.0000) {
    std::cout << "\033[1;32m[PASS]\033[0m" << std::endl;
  } else {
    std::cout << "\033[1;31m[FAIL]\033[0m" << std::endl;
  }
  std::cout << std::endl;
}

void benchmark_stack(void) {
  std::cout << "\033[1;34m--- STACK BENCHMARK ⚡ ---\033[0m" << std::endl;
  std::clock_t std;
  std::clock_t ft;
  std::stack<int> std_stack;
  ft::stack<int> ft_stack;
  std = stack_insert_growing(200001, std_stack);
  std::cout << "std: " << std << std::endl;
  ft = stack_insert_growing(200001, ft_stack);
  std::cout << "ft: " << ft << std::endl;
  if (static_cast<double>(ft) / static_cast<double>(std) < 1.0000) {
  std::cout << "our stack is " << static_cast<double>(std) / static_cast<double>(ft) << " times faster. ";
  } else {
    std::cout << "our stack is " << static_cast<double>(ft) / static_cast<double>(std) << " times slower. ";
  }
  if (static_cast<double>(ft) / static_cast<double>(std) < 20.0000) {
    std::cout << "\033[1;32m[PASS]\033[0m" << std::endl;
  } else {
    std::cout << "\033[1;31m[FAIL]\033[0m" << std::endl;
  }
  std::cout << std::endl;
}

void benchmark_vector(void) {
  std::cout << "\033[1;34m--- VECTOR BENCHMARK ⚡ ---\033[0m" << std::endl;
  std::clock_t std;
  std::clock_t ft;
  std::vector<int> std_vector;
  ft::vector<int> ft_vector;
  std = vector_insert_growing(200000, std_vector);
  std::cout << "std: " << std << std::endl;
  ft = vector_insert_growing(200000, ft_vector);
  std::cout << "ft: " << ft << std::endl;
  if (static_cast<double>(ft) / static_cast<double>(std) < 1.0000) {
  std::cout << "our vector is " << static_cast<double>(std) / static_cast<double>(ft) << " times faster. ";
  } else {
    std::cout << "our vector is " << static_cast<double>(ft) / static_cast<double>(std) << " times slower. ";
  }
  if (static_cast<double>(ft) / static_cast<double>(std) < 20.0000) {
    std::cout << "\033[1;32m[PASS]\033[0m" << std::endl;
  } else {
    std::cout << "\033[1;31m[FAIL]\033[0m" << std::endl;
  }
  std::cout << std::endl;
}
