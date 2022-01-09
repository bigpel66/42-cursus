// Copyright @bigpel66

#include "Base.hpp"

int main(void) {
  for (int i = 0 ; i < 10 ; ++i) {
    Base* base = generate();
    identify(base);
    identify(*base);
    std::cout << std::endl;
    delete base;
  }
  return 0;
}
