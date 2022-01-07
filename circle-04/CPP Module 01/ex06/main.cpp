// Copyright @bigpel66

#include "Karen.hpp"

int main(int argc, char **argv) {
  Karen k;

  if (argc != 2)
    std::cout << "Command Not Formatted Well" << std::endl
          << "./karenFilter [ Level ]" << std::endl;
  else
    k.complain(argv[1]);
  return 0;
}
