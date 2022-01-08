// Copyright @bigpel66

#include "Intern.hpp"

const char* Intern::NoMatchingTypeException::what(void) const throw() {
  return ("No Matching Type");
}

Form* Intern::makeForm(const std::string& type, const std::string& name) {
  std::string literals[F_TYPE] = { P_FORM, R_FORM, S_FORM };

  try {
    for (int i = 0 ; i < F_TYPE ; ++i) {
      if (literals[i] == type) {
        std::cout << "Intern creates <" << type
          << " : " << name << ">" << std::endl;
        switch (i) {
          case 0:
            return new PresidentialPardonForm(name);
            break;
          case 1:
            return new RobotomyRequestForm(name);
            break;
          case 2:
            return new ShrubberyCreationForm(name);
            break;
        }
      }
    }
    throw NoMatchingTypeException();
  } catch (std::exception& e) {
    std::cerr << "Intern cannot create <" <<type << " : " << name
      << "> because <" << e.what() << ">" << std::endl;
    return NULL;
  }
}

Intern& Intern::operator=(const Intern& i) {
  static_cast<void>(i);
  return *this;
}

Intern::Intern(void) {}

Intern::Intern(const Intern& i) { static_cast<void>(i); }

Intern::~Intern(void) {}
