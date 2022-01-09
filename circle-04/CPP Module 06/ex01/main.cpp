// Copyright @bigpel66

#include "Data.hpp"

int main(void) {
  Data d1;
  Data d2("Macbook Pro 16''", 2141, 2799.0, 2000.0);
  uintptr_t p1 = serialize(&d1);
  uintptr_t p2 = serialize(&d2);

  std::cout << &d1 << std::endl;
  std::cout << d1;
  print(p1);
  std::cout << &d2 << std::endl;
  std::cout << d2;
  print(p2);
  return 0;
}
