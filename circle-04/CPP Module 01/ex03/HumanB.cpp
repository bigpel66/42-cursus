/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:13:00 by jseo              #+#    #+#             */
/*   Updated: 2021/10/07 19:10:07 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void							HumanB::setWeapon(Weapon &w)
{
	_w = &w;
}

void							HumanB::attack(void) const
{
	std::cout << "[ " << BLUE << _name << EOC << " ]\t\t\t";
	if (_w)
		std::cout << BLUE << "attacks" << EOC << " with his " << _w->getType() << std::endl;
	else
		std::cout << "has no weapon" << std::endl;
}

HumanB::HumanB(void) {}

HumanB::HumanB(const std::string& name) : _name(name), _w(NULL)
{
		std::cout << "[ " << BLUE << _name << EOC << " ]\t\t\t" << "is " << GREEN << "respawned" << EOC << " without any Weapon" << std::endl;
}

HumanB::~HumanB(void)
{
		std::cout << "[ " << BLUE << _name << EOC << " ]\t\t\t" << "is " << RED << "dead" << EOC << std::endl;
}
