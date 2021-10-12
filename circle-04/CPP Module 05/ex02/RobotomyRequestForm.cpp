/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 03:51:38 by jseo              #+#    #+#             */
/*   Updated: 2021/10/12 14:30:55 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

void										RobotomyRequestForm::execute(const Bureaucrat &b) const
{
	executable(b);
	double		scale = Random::randr(0.0, 1.0);
	if (scale > 0.5)
	{
		std::cout << "drrrrrrrrrrrrrrr..." << std::endl;
		std::cout << "<" << getName() << "> has been robotomized successfully" << std::endl;
	}
	else
	{
		std::cout << "br br br..." << std::endl;
	 	std::cout << "<" << getName() << "> failed to be robotomized" << std::endl;
	}
}

RobotomyRequestForm&						RobotomyRequestForm::operator=(const RobotomyRequestForm& r)
{
	return (*(dynamic_cast<RobotomyRequestForm*>(&(Form::operator=(r)))));
}

RobotomyRequestForm::RobotomyRequestForm(void)
	:	Form()
{
	setType(R_NAME);
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	:	Form(target, R_SIGN, R_EXEC)
{
	setType(R_NAME);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& r)
	:	Form(r)
{
	setType(R_NAME);
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}
