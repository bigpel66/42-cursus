// Copyright @bigpel66

#ifndef CIRCLE_04_CPP_MODULE_05_EX01_FORM_HPP_
#define CIRCLE_04_CPP_MODULE_05_EX01_FORM_HPP_

#include <exception>
#include <string>

#include "Bureaucrat.hpp"

class Form {
 private:
  const std::string _name;
  const int _sign_grade;
  const int _exec_grade;
  bool _signed;

  Form(void);

 public:
  class GradeTooHighException
    : public std::exception {
   public:
      const char* what(void) const throw();
  };

  class GradeTooLowException
    : public std::exception {
   public:
      const char* what(void) const throw();
  };

  const std::string& getName(void) const;
  const int& getSignGrade(void) const;
  const int& getExecGrade(void) const;
  const bool& getSigned(void) const;

  void beSigned(const Bureaucrat& b);

  Form& operator=(const Form& f);
  Form(const Form& f);
  Form(const std::string& name,
        const int& sign_grade,
        const int& exec_grade);
  ~Form(void);
};

std::ostream& operator<<(std::ostream& o, const Form& f);

#endif  // CIRCLE_04_CPP_MODULE_05_EX01_FORM_HPP_
