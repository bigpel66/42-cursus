/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 22:52:49 by jseo              #+#    #+#             */
/*   Updated: 2021/10/11 01:06:04 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

AMateria*									Cure::clone(void) const
{
	std::cout << "[ " << std::setw(W_SIZE) << "clone Function on Cure" << " ]" << std::endl;
	return (new Cure());
}

void										Cure::use(ICharacter& ic)
{
	std::cout << "[ " << std::setw(W_SIZE) << "use Function on Cure" << " ] by"
					<< ic.getName() << std::endl;
}

Cure&										Cure::operator=(const Cure& c)
{
	if (this != &c)
		_type = c.getType();
	std::cout << "[ " << std::setw(W_SIZE) << "Assignation on Cure" << " ]" << std::endl;
	return (*this);
}

Cure::Cure(void)
	:	AMateria(C_NAME)
{
	std::cout << "[ " << std::setw(W_SIZE) << "Default Constructor on Cure" << " ]" << std::endl;
}

Cure::Cure(const std::string& type)
	:	AMateria(type)
{
	std::cout << "[ " << std::setw(W_SIZE) << "Named Constructor on Cure" << " ]" << std::endl;
}

Cure::Cure(const Cure& c)
	:	AMateria(c.getType())
{
	std::cout << "[ " << std::setw(W_SIZE) << "Copy Constructor on Cure" << " ]" << std::endl;
}

Cure::~Cure(void)
{
	std::cout << "[ " << std::setw(W_SIZE) << "Destructor on Cure" << " ]" << std::endl;
}
