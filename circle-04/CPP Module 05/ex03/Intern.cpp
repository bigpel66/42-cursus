/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:59:14 by jseo              #+#    #+#             */
/*   Updated: 2021/10/12 16:27:36 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

const char*									Intern::NoMatchingTypeException::what(void) const throw()
{
	return ("No Matching Type");
}

Form*										Intern::makeForm(const std::string& type, const std::string& name)
{
	std::string								literals[F_TYPE] = { "presidential pardon", "robotomy request", "shrubbery creation" };

	try
	{
		Form*								temp;
		for (int i = 0 ; i < F_TYPE ; ++i)
			if (literals[i] == type)
				switch (i)
				{
					case 0:
						temp = new PresidentialPardonForm(name);
						break ;
					case 1:
						temp = new RobotomyRequestForm(name);
						break ;
					case 2:
						temp = new ShrubberyCreationForm(name);
						break ;
					default:
						throw (NoMatchingTypeException());
				}
		std::cout << "Intern creates <" << type << " : " << name << ">" << std::endl;
		return (temp);
	}
	catch (std::exception& e)
	{
		std::cerr << "Intern cannot create <" <<type << " : " << name << "> because <" << e.what() << ">" << std::endl;
		return (NULL);
	}
}

Intern&										Intern::operator=(const Intern& i)
{

}

Intern::Intern(void) {}

Intern::Intern(const Intern& i) {}

Intern::~Intern(void) {}
