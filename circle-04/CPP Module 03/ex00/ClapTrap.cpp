/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:43:08 by jseo              #+#    #+#             */
/*   Updated: 2021/10/09 18:16:W_SIZE by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <ios>

const std::string				ClapTrap::_class_name = "ClapTrap";
const unsigned int				ClapTrap::_class_hp = 10;
const unsigned int				ClapTrap::_class_ep = 10;
const unsigned int				ClapTrap::_class_ad = 0;

void							ClapTrap::attack(const std::string& target)
{
	if (!_hp)
	{
		std::cout << "[ " << ClapTrap::getClassName() << " ] "
					<< "[ " << YELLOW << std::setw(W_SIZE) << "Not Attacked" << EOC << " ] "
					<< _name << " ( Already Dead )" << std::endl;
		return ;
	}
	if (!_ep)
		std::cout << "[ " << ClapTrap::getClassName() << " ] "
					<< "[ " << YELLOW << std::setw(W_SIZE) << "Not Attacked" << EOC << " ] "
					<< _name << " ( Not Enough Energy )" << std::endl;
	else
	{
		--_ep;
		std::cout << "[ " << ClapTrap::getClassName() << " ] "
					<< "[ " << GREEN << std::setw(W_SIZE) << "Attacked" << EOC << " ] "
					<< _name << " to " << target << std::endl;
	}
}

void							ClapTrap::takeDamage(unsigned int amount)
{
	if (!_hp)
	{
		std::cout << "[ " << ClapTrap::getClassName() << " ] "
					<< "[ " << YELLOW << std::setw(W_SIZE) << "Not Damaged" << EOC << " ] "
					<< _name << " ( Already Dead )" << std::endl;
		return ;
	}
	if (_hp <= amount)
	{
		_hp = 0;
	 	std::cout << "[ " << ClapTrap::getClassName() << " ] "
					<< "[ " << RED << std::setw(W_SIZE) << "Died" << EOC << " ] ";
	}
	else
	{
		_hp -= amount;
		std::cout << "[ " << ClapTrap::getClassName() << " ] "
					<< "[ " << RED << std::setw(W_SIZE) << "Damaged" << EOC << " ] ";
	}
	std::cout << _name << " ( -" << std::setw(2) << amount << " --> " << std::setw(2) << _hp << " )" << std::endl;
}

void							ClapTrap::beRepaired(unsigned int amount)
{
	if (!_hp)
	{
		std::cout << "[ " << ClapTrap::getClassName() << " ] "
					<< "[ " << YELLOW << std::setw(W_SIZE) << "Not Reapired" << EOC << " ] "
					<< _name << " ( Already Dead )" << std::endl;
		return ;
	}
	if (_hp + amount > ClapTrap::getClassHP())
		_hp = ClapTrap::getClassHP();
	else
		_hp += amount;
	std::cout << "[ " << ClapTrap::getClassName() << " ] "
				<< "[ " << GREEN << std::setw(W_SIZE) << "Repaired" << EOC << " ] "
				<< _name << " ( +" << std::setw(2) << amount << " --> " << std::setw(2) << _hp << " )" << std::endl;
}

std::string						ClapTrap::getName(void) const
{
	return (_name);
}

unsigned int					ClapTrap::getHP(void) const
{
	return (_hp);
}

unsigned int					ClapTrap::getEP(void) const
{
	return (_ep);
}

unsigned int					ClapTrap::getAD(void) const
{
	return (_ad);
}

std::string						ClapTrap::getClassName(void)
{
	return (ClapTrap::_class_name);
}

unsigned int					ClapTrap::getClassHP(void)
{
	return (ClapTrap::_class_hp);
}

unsigned int					ClapTrap::getClassEP(void)
{
	return (ClapTrap::_class_ep);
}

unsigned int					ClapTrap::getClassAD(void)
{
	return (ClapTrap::_class_ad);
}

ClapTrap&						ClapTrap::operator=(const ClapTrap& c)
{
	if (this != &c)
	{
		_name = c.getName();
		_hp = c.getHP();
		_ep = c.getEP();
		_ad = c.getAD();
	}
	return (*this);
}

ClapTrap::ClapTrap(void)
	: _name(ClapTrap::getClassName()), _hp(ClapTrap::getClassHP()), _ep(ClapTrap::getClassEP()), _ad(ClapTrap::getClassAD())
{
	std::cout << "[ " << ClapTrap::getClassName() << " ]"
					<< " [ login ] " << _name << std::endl;
};

ClapTrap::ClapTrap(const std::string& name)
	: _name(name), _hp(ClapTrap::getClassHP()), _ep(ClapTrap::getClassEP()), _ad(ClapTrap::getClassAD())
{
	std::cout << "[ " << ClapTrap::getClassName() << " ]"
					<< " [ login ] " << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& c)
	: _name(c.getName()), _hp(c.getHP()), _ep(c.getEP()), _ad(c.getAD())
{
	std::cout << "[ " << ClapTrap::getClassName() << " ]"
					<< " [ login ] " << _name << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "[ " << ClapTrap::getClassName() << " ]"
					<< " [ logout ] " << _name << std::endl;
}
