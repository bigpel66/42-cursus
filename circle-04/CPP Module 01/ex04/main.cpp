// Copyright @bigpel66

#include "Replace.hpp"

int main(int argc, char **argv) {
  if (argc !=  4)
    std::cout << "Command Not Formatted Well" << std::endl
          << "./replace [ File Name ] [ String1 for SRC ] [ String2 for DST ]"
          << std::endl;
  else
    Replace::process(argv[1], argv[2], argv[3]);
  return 0;
}
