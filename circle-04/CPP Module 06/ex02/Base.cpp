// Copyright @bigpel66

#include "Base.hpp"

Base* generate(void) {
  int opt = static_cast<int>(Random::randr(0.0, 10.0)) / 3;
  switch (opt) {
    case 0:
      std::cout << "Answer is A" << std::endl;
      return new A();
    case 1:
      std::cout << "Answer is B" << std::endl;
      return new B();
    case 2:
      std::cout << "Answer is C" << std::endl;
      return new C();
    default:
      return NULL;
  }
}

void identify(Base* p) {
  if (dynamic_cast<A*>(p)) {
    std::cout << "A" << std::endl;
  } else if (dynamic_cast<B*>(p)) {
    std::cout << "B" << std::endl;
  } else if (dynamic_cast<C*>(p)) {
    std::cout << "C" << std::endl;
  }
}

static bool try_cast(const Base& p, const std::string& s) {
  try {
    if (s == "A") {
      (void)dynamic_cast<const A&>(p);
    } else if (s == "B") {
      (void)dynamic_cast<const B&>(p);
    } else if (s == "C") {
      (void)dynamic_cast<const C&>(p);
    }
    std::cout << s << std::endl;
  } catch (std::exception&) {}
  return false;
}

void identify(const Base& p) {
  if (try_cast(p, "A") || try_cast(p, "B") || try_cast(p, "C"))
    return;
}
