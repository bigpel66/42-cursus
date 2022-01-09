// Copyright @bigpel66

#include "Convert.hpp"

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cout << "Command Not Formatted Well" << std::endl
      << "./convert [ Convert Input ]" << std::endl;
  } else {
    std::cout << Convert(argv[1]);
  }
  return 0;
}
