// Copyright @bigpel66

#include "Dog.hpp"

const Brain *Dog::getBrain(void) const {
  if (_b)
    return _b;
  return NULL;
}

void Dog::makeSound(void) const {
  std::cout << " [ " << std::setw(W_SIZE) << D_NAME << " ] "
    << "Bowwow Bowwow" << std::endl;
}

Dog& Dog::operator=(const Dog& d) {
  if (this != &d) {
    _type = d.getType();
    *_b = *d.getBrain();
  }
  std::cout << " [ " << std::setw(W_SIZE) << D_NAME << " ] "
    << "Assigned" << std::endl;
  return *this;
}

Dog::Dog(void)
  : Animal(), _b(NULL) {
  _type = "Dog";
  _b = new Brain();
  std::cout << " [ " << std::setw(W_SIZE) << D_NAME << " ] "
    << "Default constructed" << std::endl;
}

Dog::Dog(const Dog& d)
  : Animal(), _b(NULL) {
  _type = d.getType();
  _b = new Brain(*d.getBrain());
  std::cout << " [ " << std::setw(W_SIZE) << D_NAME << " ] "
    << "Copy constructed" << std::endl;
}

Dog::~Dog(void) {
  std::cout << " [ " << std::setw(W_SIZE) << D_NAME << " ] "
    << "Destructed" << std::endl;
  delete _b;
}
