/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 22:52:48 by jseo              #+#    #+#             */
/*   Updated: 2021/10/11 02:39:14 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

const AMateria*								Character::getAMateria(int idx) const
{
	return (_am[idx]);
}

const std::string&							Character::getName(void) const
{
	return (_name);
}

void										Character::equip(AMateria* am)
{
	for (int i = 0 ; i < AM_SIZE ; ++i)
	{
		if (!_am[i])
		{
			_am[i] = am;
			std::cout << "[ " << std::setw(W_SIZE) << "equip Function on Character" << " ] by "
					<< _name << std::endl;
			return ;
		}
	}
	std::cout << "[ " << std::setw(W_SIZE) << "equip Function on Character" << " ] by "
					<< _name << " Failed (FULL)" << std::endl;
}

AMateria*									Character::unequip(int idx)
{

	if (idx >= 0 && idx < AM_SIZE && _am[idx])
	{
		AMateria* temp;
		temp = _am[idx];
		_am[idx] = NULL;
		std::cout << "[ " << std::setw(W_SIZE) << "unequip Function on Character" << " ] by "
					<< _name << std::endl;
		return (temp);
	}
	std::cout << "[ " << std::setw(W_SIZE) << "unequip Function on Character" << " ] by "
					<< _name << " Failed (EMPTY)" << std::endl;
	return (NULL);
}

void										Character::use(int idx, ICharacter& ic)
{
	if (idx >= 0 && idx < AM_SIZE && _am[idx])
		_am[idx]->use(ic);
	else
		std::cout << "[ " << std::setw(W_SIZE) << "use Function on Character" << " ] by "
					<< _name << " Failed (Empty or Wrong Access)" << std::endl;
}

Character&									Character::operator=(const Character& c)
{
	if (this != &c)
	{
		_name = c.getName();
		for (int i = 0 ; i < AM_SIZE ; ++i)
		{
			if (_am[i])
			{
				delete _am[i];
				_am[i] = NULL;
			}
			_am[i] = c.getAMateria(i)->clone();
		}
	}
	std::cout << "[ " << std::setw(W_SIZE) << "Assignation on Character" << " ]" << std::endl;
	return (*this);
}

Character::Character(void)
	:	_name("")
{
	for (int i = 0 ; i < AM_SIZE ; ++i)
		_am[i] = NULL;
	std::cout << "[ " << std::setw(W_SIZE) << "Default Constructor on Character" << " ]" << std::endl;
}

Character::Character(const std::string& name)
	:	_name(name)
{
	for (int i = 0 ; i < AM_SIZE ; ++i)
		_am[i] = NULL;
	std::cout << "[ " << std::setw(W_SIZE) << "Named Constructor on Character" << " ]" << std::endl;
}

Character::Character(const Character& c)
	:	_name(c.getName())
{
	for (int i = 0 ; i < AM_SIZE ; ++i)
	{
		if (_am[i])
		{
			delete _am[i];
			_am[i] = NULL;
		}
		_am[i] = c.getAMateria(i)->clone();
	}
	std::cout << "[ " << std::setw(W_SIZE) << "Copy Constructor on Character" << " ]" << std::endl;
}

Character::~Character(void)
{
	for (int i = 0 ; i < AM_SIZE ; ++i)
	{
		if (_am[i])
		{
			delete _am[i];
			_am[i] = NULL;
		}
	}
	std::cout << "[ " << std::setw(W_SIZE) << "Destructor on Character" << " ]" << std::endl;
}
