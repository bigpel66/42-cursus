// Copyright @bigpel66

#ifndef CIRCLE_04_CPP_MODULE_05_EX03_SHRUBBERYCREATIONFORM_HPP_
#define CIRCLE_04_CPP_MODULE_05_EX03_SHRUBBERYCREATIONFORM_HPP_

#include <string>
#include "Form.hpp"

#define S_NAME            "ShrubberyCreationForm"
#define S_FORM            "shrubbery creation"
#define S_SIGN            145
#define S_EXEC            137

class ShrubberyCreationForm : public Form {
 private:
  ShrubberyCreationForm(void);

 public:
  void execute(const Bureaucrat& b) const;

  ShrubberyCreationForm& operator=(const ShrubberyCreationForm& s);
  explicit ShrubberyCreationForm(const std::string& target);
  ShrubberyCreationForm(const ShrubberyCreationForm& s);
  ~ShrubberyCreationForm(void);
};

#endif  // CIRCLE_04_CPP_MODULE_05_EX03_SHRUBBERYCREATIONFORM_HPP_
