/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 21:26:14 by jseo              #+#    #+#             */
/*   Updated: 2021/10/12 14:41:22 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	Bureaucrat			b1("Admin", 1);
	Bureaucrat			b2("Jseo", 15);
	Bureaucrat			b3("Dohykim", 70);
	Bureaucrat			b4("Hyson", 140);

	Form*				f1 = new PresidentialPardonForm("Chang Chen");
	Form*				f2 = new RobotomyRequestForm("Terminator");
	Form*				f3 = new ShrubberyCreationForm("Fangorn");

	std::cout << b1 << std::endl
				<< b2 << std::endl
				<< b3 << std::endl
				<< b4 << std::endl;
	std::cout << std::endl;
	std::cout << *f1 << std::endl
				<< *f2 << std::endl
				<< *f3 << std::endl;
	std::cout << std::endl;
	b2.signForm(*f1);
	b3.signForm(*f2);
	b4.signForm(*f3);
	std::cout << std::endl;
	b2.executeForm(*f1);
	b3.executeForm(*f2);
	b4.executeForm(*f3);
	std::cout << std::endl;
	b1.executeForm(*f1);
	b1.executeForm(*f2);
	b1.executeForm(*f3);

	delete f3;
	delete f2;
	delete f1;
	return (0);
}
