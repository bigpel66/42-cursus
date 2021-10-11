/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 03:54:20 by jseo              #+#    #+#             */
/*   Updated: 2021/10/12 03:57:07 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

void										ShrubberyCreationForm::execute(const Bureaucrat& b) const
{
	//
}

ShrubberyCreationForm&						ShrubberyCreationForm::operator=(const ShrubberyCreationForm& s)
{
	return (*(dynamic_cast<ShrubberyCreationForm*>(&(Form::operator=(s)))));
}

ShrubberyCreationForm::ShrubberyCreationForm(void)
	:	Form()
{
	setType(S_NAME);
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	:	Form(target, S_SIGN, S_EXEC)
{
	setType(S_NAME);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& s)
	:	Form(s)
{
	setType(S_NAME);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}
