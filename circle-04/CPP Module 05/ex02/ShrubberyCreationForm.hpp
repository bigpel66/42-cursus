/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 01:44:00 by jseo              #+#   #+#             */
/*   Updated: 2022/01/08 21:27:25 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CIRCLE_04_CPP_MODULE_05_EX02_SHRUBBERYCREATIONFORM_HPP_
#define CIRCLE_04_CPP_MODULE_05_EX02_SHRUBBERYCREATIONFORM_HPP_

#include <string>
#include "Form.hpp"

#define S_NAME            "ShrubberyCreationForm"
#define S_SIGN            145
#define S_EXEC            137

class ShrubberyCreationForm : public Form {
 private:
  ShrubberyCreationForm(void);

 public:
  void execute(const Bureaucrat& b) const;

  ShrubberyCreationForm& operator=(const ShrubberyCreationForm& s);
  ShrubberyCreationForm(const std::string& target);
  ShrubberyCreationForm(const ShrubberyCreationForm& s);
  ~ShrubberyCreationForm(void);
};

#endif  // CIRCLE_04_CPP_MODULE_05_EX02_SHRUBBERYCREATIONFORM_HPP_
