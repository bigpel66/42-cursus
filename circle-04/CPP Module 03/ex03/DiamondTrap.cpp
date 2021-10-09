/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 22:37:35 by jseo              #+#    #+#             */
/*   Updated: 2021/10/10 08:33:34 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

void								DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

std::string							DiamondTrap::getName(void) const
{
	return (_name);
}

void								DiamondTrap::whoAmI(void) const
{
	std::cout << "[ " << D_NAME << " ] "
				<< "[ " << GREEN << std::setw(W_SIZE) << "Who Am I" << EOC << " ] "
				<< "Diamond: " << _name << " & Clap : " << ClapTrap::_name << std::endl;
}

DiamondTrap&						DiamondTrap::operator=(const DiamondTrap &d)
{
	if (this != &d)
	{
		_name = d.getName();
		_hp = d.getHP();
		_ep = d.getEP();
		_ad = d.getAD();
	}
	return (*this);
}

DiamondTrap::DiamondTrap(void)
	:	ClapTrap(std::string(C_NAME) + "_clap_name")
{
	*(const_cast<std::string *>(&_class_name)) = D_NAME;
	*(const_cast<unsigned int *>(&_class_hp)) = F_HP;
	*(const_cast<unsigned int *>(&_class_ep)) = S_EP;
	*(const_cast<unsigned int *>(&_class_ad)) = F_AD;
	_name = D_NAME;
	_hp = _class_hp;
	_ep = _class_ep;
	_ad = _class_ad;
	std::cout << "[ " << D_NAME << " ]"
					<< " [ login ] " << _name << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name)
	:	ClapTrap(name + "_clap_name")
{
	*(const_cast<std::string *>(&_class_name)) = D_NAME;
	*(const_cast<unsigned int *>(&_class_hp)) = F_HP;
	*(const_cast<unsigned int *>(&_class_ep)) = S_EP;
	*(const_cast<unsigned int *>(&_class_ad)) = F_AD;
	_name = name;
	_hp = _class_hp;
	_ep = _class_ep;
	_ad = _class_ad;
	std::cout << "[ " << D_NAME << " ]"
					<< " [ login ] " << _name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& d)
{
	*(const_cast<std::string *>(&_class_name)) = D_NAME;
	_name = d.getName();
	_hp = d.getHP();
	_ep = d.getEP();
	_ad = d.getAD();
	std::cout << "[ " << D_NAME << " ]"
				<< " [ login ] " << _name << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "[ " << D_NAME << " ]"
					<< " [ logout ] " << _name << std::endl;
}
