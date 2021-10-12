/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 03:25:52 by jseo              #+#    #+#             */
/*   Updated: 2021/10/12 14:24:53 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

void										PresidentialPardonForm::execute(const Bureaucrat& b) const
{
	executable(b);
	std::cout << "<" << getName() << "> has been pardoned by Zafod Beeblebrox" << std::endl;
}

PresidentialPardonForm&						PresidentialPardonForm::operator=(const PresidentialPardonForm& p)
{
	return (*(dynamic_cast<PresidentialPardonForm*>(&(Form::operator=(p)))));
}

PresidentialPardonForm::PresidentialPardonForm(void)
	: Form()
{
	setType(P_NAME);
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	:	Form(target, P_SIGN, P_EXEC)
{
	setType(P_NAME);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& p)
	:	Form(p)
{
	setType(P_NAME);
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}
