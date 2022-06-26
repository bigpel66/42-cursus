// Copyright @pruiz-ca
// Modified by @bigpel66

#include "./benchmark.hpp"

int main(void) {
  std::cout << "\033[1;94m" <<
    "# ****************************************************************************** #\n"
    "#                                                                                #\n"
    "#                              containers bench test1                            #\n"
    "#                                                                                #\n"
    "# ****************************************************************************** #\n"
            << "\033[0m" << std::endl;
  benchmark_map();
  benchmark_set();
  benchmark_stack();
  benchmark_vector();
  return 0;
}
