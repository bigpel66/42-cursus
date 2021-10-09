/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 19:00:44 by jseo              #+#    #+#             */
/*   Updated: 2021/10/09 23:44:01 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void							ScavTrap::attack(const std::string& target)
{
	if (!_hp)
	{
		std::cout << "[ " << S_NAME << " ] "
					<< "[ " << YELLOW << std::setw(W_SIZE) << "Not Attacked" << EOC << " ] "
					<< _name << " ( Already Dead )" << std::endl;
		return ;
	}
	if (!_ep)
		std::cout << "[ " << S_NAME << " ] "
					<< "[ " << YELLOW << std::setw(W_SIZE) << "Not Attacked" << EOC << " ] "
					<< _name << " ( Not Enough Energy )" << std::endl;
	else
	{
		--_ep;
		std::cout << "[ " << S_NAME << " ] "
					<< "[ " << GREEN << std::setw(W_SIZE) << "Attacked" << EOC << " ] "
					<< _name << " to " << target << std::endl;
	}
}

void							ScavTrap::guardGate(void) const
{
	std::cout << "[ " << S_NAME << " ] "
				<< "[ " << GREEN << std::setw(W_SIZE) << "Entered" << EOC << " ] "
				<< _name << " ( Gate Keeper Mode )" << std::endl;
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
	:	ClapTrap(S_NAME)
{
	*(const_cast<std::string *>(&_class_name)) = S_NAME;
	*(const_cast<unsigned int *>(&_class_hp)) = S_HP;
	*(const_cast<unsigned int *>(&_class_ep)) = S_EP;
	*(const_cast<unsigned int *>(&_class_ad)) = S_AD;
	_hp = _class_hp;
	_ep = _class_ep;
	_ad = _class_ad;
	std::cout << "[ " << S_NAME << " ]"
					<< " [ login ] " << _name << std::endl;
}

ScavTrap::ScavTrap(const std::string& name)
	:	ClapTrap(name)
{
	*(const_cast<std::string *>(&_class_name)) = S_NAME;
	*(const_cast<unsigned int *>(&_class_hp)) = S_HP;
	*(const_cast<unsigned int *>(&_class_ep)) = S_EP;
	*(const_cast<unsigned int *>(&_class_ad)) = S_AD;
	_hp = _class_hp;
	_ep = _class_ep;
	_ad = _class_ad;
	std::cout << "[ " << S_NAME << " ]"
					<< " [ login ] " << _name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& s)
{
	*(const_cast<std::string *>(&_class_name)) = S_NAME;
	*(const_cast<unsigned int *>(&_class_hp)) = S_HP;
	*(const_cast<unsigned int *>(&_class_ep)) = S_EP;
	*(const_cast<unsigned int *>(&_class_ad)) = S_AD;
	_name = s.getName();
	_hp = s.getHP();
	_ep = s.getEP();
	_ad = s.getAD();
	std::cout << "[ " << S_NAME << " ]"
				<< " [ login ] " << _name << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "[ " << S_NAME << " ]"
					<< " [ logout ] " << _name << std::endl;
	*(const_cast<std::string *>(&_class_name)) = C_NAME;
}
