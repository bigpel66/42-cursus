// Copyright @pruiz-ca
// Modified by @bigpel66

#include "./benchmark.hpp"

int main(void) {
  std::cout << "Benchmark : \n" << std:: endl;
  benchmark_map();
  benchmark_set();
  benchmark_stack();
  benchmark_vector();
  return 0;
}
