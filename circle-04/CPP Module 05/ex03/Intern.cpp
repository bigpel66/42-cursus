/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:59:14 by jseo              #+#    #+#             */
/*   Updated: 2021/10/12 16:38:37 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

const char*									Intern::NoMatchingTypeException::what(void) const throw()
{
	return ("No Matching Type");
}

Form*										Intern::makeForm(const std::string& type, const std::string& name)
{
	std::string								literals[F_TYPE] = { P_FORM, R_FORM, S_FORM };

	try
	{
		for (int i = 0 ; i < F_TYPE ; ++i)
		{
			if (literals[i] == type)
			{
				std::cout << "Intern creates <" << type << " : " << name << ">" << std::endl;
				switch (i)
				{
					case 0:
						return (new PresidentialPardonForm(name));
						break ;
					case 1:
						return (new RobotomyRequestForm(name));
						break ;
					case 2:
						return (new ShrubberyCreationForm(name));
						break ;
				}
			}
		}
		throw (NoMatchingTypeException());
	}
	catch (std::exception& e)
	{
		std::cerr << "Intern cannot create <" <<type << " : " << name << "> because <" << e.what() << ">" << std::endl;
		return (NULL);
	}
}

Intern&										Intern::operator=(const Intern& i)
{
	static_cast<void>(i);
	return (*this);
}

Intern::Intern(void) {}

Intern::Intern(const Intern& i) { static_cast<void>(i); }

Intern::~Intern(void) {}
