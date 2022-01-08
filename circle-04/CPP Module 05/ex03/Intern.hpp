// Copyright @bigpel66

#ifndef CIRCLE_04_CPP_MODULE_05_EX03_INTERN_HPP_
#define CIRCLE_04_CPP_MODULE_05_EX03_INTERN_HPP_

#include <string>

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
 public:
  class NoMatchingTypeException
    : public std::exception {
   public:
      const char* what(void) const throw();
  };

  Form* makeForm(const std::string& type, const std::string& name);

  Intern(void);
  Intern& operator=(const Intern& i);
  Intern(const Intern& i);
  ~Intern(void);
};

#endif  // CIRCLE_04_CPP_MODULE_05_EX03_INTERN_HPP_
