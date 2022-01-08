// Copyright @bigpel66

#include "PresidentialPardonForm.hpp"

void PresidentialPardonForm::execute(const Bureaucrat& b) const {
  executable(b);
  std::cout << "<" << getName()
    << "> has been pardoned by Zafod Beeblebrox" << std::endl;
}

PresidentialPardonForm&
  PresidentialPardonForm::operator=(const PresidentialPardonForm& p) {
  return *(dynamic_cast<PresidentialPardonForm*>(&(Form::operator=(p))));
}

PresidentialPardonForm::PresidentialPardonForm(void)
  : Form() {
  setType(P_NAME);
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
  : Form(target, P_SIGN, P_EXEC) {
  setType(P_NAME);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& p)
  : Form(p) {
  setType(P_NAME);
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}
