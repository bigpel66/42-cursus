/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 19:00:44 by jseo              #+#    #+#             */
/*   Updated: 2021/10/09 19:55:48 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

const std::string				ScavTrap::_class_name = "ScavTrap";
const unsigned int				ScavTrap::_class_hp = 100;
const unsigned int				ScavTrap::_class_ep = 50;
const unsigned int				ScavTrap::_class_ad = 20;

void							ScavTrap::attack(const std::string& target)
{
	if (!_hp)
	{
		std::cout << "[ " << ScavTrap::getClassName() << " ] "
					<< "[ " << YELLOW << std::setw(W_SIZE) << "Not Attacked" << EOC << " ] "
					<< _name << " ( Already Dead )" << std::endl;
		return ;
	}
	if (!_ep)
		std::cout << "[ " << ScavTrap::getClassName() << " ] "
					<< "[ " << YELLOW << std::setw(W_SIZE) << "Not Attacked" << EOC << " ] "
					<< _name << " ( Not Enough Energy )" << std::endl;
	else
	{
		--_ep;
		std::cout << "[ " << ScavTrap::getClassName() << " ] "
					<< "[ " << GREEN << std::setw(W_SIZE) << "Attacked" << EOC << " ] "
					<< _name << " to " << target << std::endl;
	}
}

void							ScavTrap::guardGate(void) const
{
	std::cout << "[ " << ScavTrap::getClassName() << " ] "
				<< "[ " << GREEN << std::setw(W_SIZE) << "Entered" << EOC << " ] "
				<< _name << " ( Gate Keeper Mode )" << std::endl;
}
std::string						ScavTrap::getClassName(void)
{
	return (ScavTrap::_class_name);
}

unsigned int					ScavTrap::getClassHP(void)
{
	return (ScavTrap::_class_hp);
}

unsigned int					ScavTrap::getClassEP(void)
{
	return (ScavTrap::_class_ep);
}

unsigned int					ScavTrap::getClassAD(void)
{
	return (ScavTrap::_class_ad);
}

ScavTrap&						ScavTrap::operator=(const ScavTrap &s)
{
	if (this != &s)
	{
		_name = s.getName();
		_hp = s.getHP();
		_ep = s.getEP();
		_ad = s.getAD();
	}
	return (*this);
}

ScavTrap::ScavTrap(void)
	: ClapTrap("ScavTrap")
{
	_name = ScavTrap::_class_name;
	_hp = ScavTrap::_class_hp;
	_ep = ScavTrap::_class_ep;
	_ad = ScavTrap::_class_ad;
	_max_hp = ScavTrap::_class_hp;
	std::cout << "[ " << ScavTrap::getClassName() << " ]"
					<< " [ login ] " << _name << std::endl;
}

ScavTrap::ScavTrap(const std::string& name)
	: ClapTrap(name)
{
	_hp = ScavTrap::_class_hp;
	_ep = ScavTrap::_class_ep;
	_ad = ScavTrap::_class_ad;
	_max_hp = ScavTrap::_class_hp;
	std::cout << "[ " << ScavTrap::getClassName() << " ]"
					<< " [ login ] " << _name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& s)
{
	_name = s.getName();
	_hp = s.getHP();
	_ep = s.getEP();
	_ad = s.getAD();
	_max_hp = ScavTrap::_class_hp;
	std::cout << "[ " << ScavTrap::getClassName() << " ]"
				<< " [ login ] " << _name << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "[ " << ScavTrap::getClassName() << " ]"
					<< " [ logout ] " << _name << std::endl;
}
