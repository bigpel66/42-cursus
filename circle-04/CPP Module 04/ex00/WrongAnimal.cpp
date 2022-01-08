// Copyright @bigpel66

#include "WrongAnimal.hpp"

void WrongAnimal::setType(const std::string& type) {
  _type = type;
}

std::string WrongAnimal::getType(void) const {
  return _type;
}

void WrongAnimal::makeSound(void) const {
  std::cout << " [ " << std::setw(W_SIZE) << WA_NAME << " ] "
    << "Cannot Make Sound Yet" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& wa) {
  if (this != &wa)
    _type = wa.getType();
  std::cout << " [ " << std::setw(W_SIZE) << WA_NAME << " ] "
    << "Assigned" << std::endl;
  return *this;
}

WrongAnimal::WrongAnimal(void)
  : _type(WA_NAME) {
  std::cout << " [ " << std::setw(W_SIZE) << WA_NAME << " ] "
    << "Default constructed" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& wa)
  : _type(wa.getType()) {
  std::cout << " [ " << std::setw(W_SIZE) << WA_NAME << " ] "
    << "Copy constructed" << std::endl;
}

WrongAnimal::~WrongAnimal(void) {
  std::cout << " [ " << std::setw(W_SIZE) << WA_NAME << " ] "
    << "Destructed" << std::endl;
}

std::ostream&         operator<<(std::ostream& o, const WrongAnimal& wa) {
  return o << wa.getType() << " ";
}
