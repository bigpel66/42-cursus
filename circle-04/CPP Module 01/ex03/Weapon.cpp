/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 17:09:42 by jseo              #+#    #+#             */
/*   Updated: 2021/10/07 19:06:34 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

const std::string				&Weapon::getType(void) const
{
	return (_type);
}

void							Weapon::setType(const std::string& type)
{
	std::cout << "[ Weapon Type ]\t\tis changed " << _type;
	_type = type;
	std::cout << " to " << _type << std::endl;
}

Weapon::Weapon(void) {}

Weapon::Weapon(const std::string& type) : _type(type)
{
	std::cout << "[ Weapon Type ]\t\t" << _type << " is " << GREEN << "generated" << EOC << std::endl;
}

Weapon::~Weapon(void)
{
	std::cout << "[ Weapon Type ]\t\t" << _type << " is " << RED << "broken" << EOC << std::endl;
}
