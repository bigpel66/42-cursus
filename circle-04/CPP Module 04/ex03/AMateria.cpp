// Copyright @bigpel66

#include "AMateria.hpp"
#include "ICharacter.hpp"

const std::string& AMateria::getType(void) const {
  return _type;
}

void AMateria::use(const ICharacter& ic) {
  std::cout << "[ " << std::setw(W_SIZE)
    << "use Function on AMatreria" << " ] by "
    << ic.getName() << std::endl;
}

// Does Not Make Sense
AMateria& AMateria::operator=(const AMateria& am) {
  if (this != &am)
    _type = am.getType();
  std::cout << "[ " << std::setw(W_SIZE)
    << "Assignation on AMateria" << " ]" << std::endl;
  return *this;
}

AMateria::AMateria(void)
  : _type("") {
  std::cout << "[ " << std::setw(W_SIZE)
    << "Default Constructor on AMatreria" << " ]" << std::endl;
}

AMateria::AMateria(const std::string& type)
  : _type(type) {
  std::cout << "[ " << std::setw(W_SIZE)
    << "Named Constructor on AMatreria" << " ]" << std::endl;
}

AMateria::AMateria(const AMateria& am)
  : _type(am.getType()) {
  std::cout << "[ " << std::setw(W_SIZE)
    << "Copy Constructor on AMatreria" << " ]" << std::endl;
}

AMateria::~AMateria(void) {
  std::cout << "[ " << std::setw(W_SIZE)
    << "Destructor on AMatreria" << " ]" << std::endl;
}
