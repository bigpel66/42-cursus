// Copyright @bigpel66

#include "Animal.hpp"

void Animal::setType(const std::string& type) {
  _type = type;
}

std::string Animal::getType(void) const {
  return _type;
}

Animal& Animal::operator=(const Animal& a) {
  if (this != &a)
    _type = a.getType();
  std::cout << " [ " << std::setw(W_SIZE) << A_NAME << " ] "
    << "Assigned" << std::endl;
  return *this;
}

Animal::Animal(void)
  : _type(A_NAME) {
  std::cout << " [ " << std::setw(W_SIZE) << A_NAME << " ] "
    << "Default constructed" << std::endl;
}

Animal::Animal(const Animal& a)
  : _type(a.getType()) {
  std::cout << " [ " << std::setw(W_SIZE) << A_NAME << " ] "
    << "Copy constructed" << std::endl;
}

Animal::~Animal(void) {
  std::cout << " [ " << std::setw(W_SIZE) << A_NAME << " ] "
    << "Destructed" << std::endl;
}

std::ostream& operator<<(std::ostream& o, const Animal& a) {
  return o << a.getType() << " ";
}
