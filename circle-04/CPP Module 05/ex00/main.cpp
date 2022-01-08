// Copyright @bigpel66

#include "Bureaucrat.hpp"

void b_call(const Bureaucrat& b, int& (Bureaucrat::*f)(void)) {
  try {
    (*(const_cast<Bureaucrat*>(&b)).*f)();
    std::cout << b << std::endl;
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
}

void b_make(const std::string& name, const int& grade) {
  try {
    Bureaucrat b(name, grade);
    std::cout << b << std::endl;
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
}
int main(void) {
  Bureaucrat j("Jseo", 1);
  Bureaucrat h("Hyson", 150);

  std::cout << j << std::endl
    << h << std::endl;
  std::cout << std::endl;
  b_call(j, &Bureaucrat::incrementGrade);
  b_call(h, &Bureaucrat::decrementGrade);
  std::cout << std::endl;
  b_make("Jseo", 0);
  b_make("Hyson", 151);
  std::cout << std::endl;
  b_make("Jseo", 70);
  b_make("Hyson", 70);
  std::cout << std::endl;
  b_call(j, &Bureaucrat::decrementGrade);
  b_call(h, &Bureaucrat::incrementGrade);
  std::cout << std::endl;
  b_call(j, &Bureaucrat::decrementGrade);
  b_call(h, &Bureaucrat::incrementGrade);
  return 0;
}
