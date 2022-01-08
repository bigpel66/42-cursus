// Copyright @bigpel66

#ifndef CIRCLE_04_CPP_MODULE_05_EX03_PRESIDENTIALPARDONFORM_HPP_
#define CIRCLE_04_CPP_MODULE_05_EX03_PRESIDENTIALPARDONFORM_HPP_

#include <string>

#include "Form.hpp"

#define P_NAME            "PresidentialPardonForm"
#define P_FORM            "presidential pardon"
#define P_SIGN            25
#define P_EXEC            5

class PresidentialPardonForm : public Form {
 private:
  PresidentialPardonForm(void);

 public:
  void execute(const Bureaucrat& b) const;

  PresidentialPardonForm& operator=(const PresidentialPardonForm& p);
  explicit PresidentialPardonForm(const std::string& target);
  PresidentialPardonForm(const PresidentialPardonForm& p);
  ~PresidentialPardonForm(void);
};

#endif  // CIRCLE_04_CPP_MODULE_05_EX03_PRESIDENTIALPARDONFORM_HPP_
