// Copyright @bigpel66

#include "Cure.hpp"
#include "ICharacter.hpp"

AMateria* Cure::clone(void) const {
  return new Cure();
}

void Cure::use(const ICharacter& ic) {
  std::cout << "[ " << std::setw(W_SIZE)
    << "use Function on Cure" << " ]"
    << " * heals " << ic.getName() << "'s wounds *" << std::endl;
}

// Does Not Make Sense
Cure& Cure::operator=(const Cure& c) {
  if (this != &c)
    _type = c.getType();
  std::cout << "[ " << std::setw(W_SIZE)
    << "Assignation on Cure" << " ]" << std::endl;
  return *this;
}

Cure::Cure(void)
  : AMateria(C_NAME) {
  std::cout << "[ " << std::setw(W_SIZE)
    << "Default Constructor on Cure" << " ]" << std::endl;
}

Cure::Cure(const std::string& type)
  : AMateria(type) {
  std::cout << "[ " << std::setw(W_SIZE)
    << "Named Constructor on Cure" << " ]" << std::endl;
}

Cure::Cure(const Cure& c)
  : AMateria(c.getType()) {
  std::cout << "[ " << std::setw(W_SIZE)
    << "Copy Constructor on Cure" << " ]" << std::endl;
}

Cure::~Cure(void) {
  std::cout << "[ " << std::setw(W_SIZE)
    << "Destructor on Cure" << " ]" << std::endl;
}
