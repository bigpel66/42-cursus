/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 22:52:55 by jseo              #+#    #+#             */
/*   Updated: 2021/10/11 12:32:46 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

const AMateria*								MateriaSource::getAMateria(int idx) const
{
	return (_am[idx]);
}

void										MateriaSource::learnMateria(AMateria* am)
{
	if (!am)
		return ;
	for (int i = 0 ; i < AM_SIZE ; ++i)
	{
		if (!_am[i])
		{
			_am[i] = am;
			std::cout << "[ " << std::setw(W_SIZE) << "learnMateria Function on MateriaSource" << " ] "
					<< am->getType() << std::endl;
			return ;
		}
	}
	std::cout << "[ " << std::setw(W_SIZE) << "learnMateria Function on MateriaSource" << " ] "
					<< am->getType() << " Failed (FULL)" << std::endl;
}

AMateria*									MateriaSource::createMateria(const std::string& type)
{
	for (int i = 0 ; i < AM_SIZE ; ++i)
	{
		if (_am[i] && _am[i]->getType() == type)
		{
			std::cout << "[ " << std::setw(W_SIZE) << "createMateria Function on MateriaSource" << " ] "
					<< type << std::endl;
			return (_am[i]->clone());
		}
	}
	std::cout << "[ " << std::setw(W_SIZE) << "createMateria Function on MateriaSource" << " ] "
				<< type << " Failed (Not Found)" << std::endl;
	return (NULL);
}

MateriaSource&								MateriaSource::operator=(const MateriaSource& ms)
{
	const AMateria*		temp;

	if (this != &ms)
	{
		for (int i = 0 ; i < AM_SIZE ; ++i)
		{
			if (_am[i])
			{
				delete _am[i];
				_am[i] = NULL;
			}
			temp = ms.getAMateria(i);
			if (temp)
				_am[i] = temp->clone();
		}
	}
	std::cout << "[ " << std::setw(W_SIZE) << "Assignation on MateriaSource" << " ]" << std::endl;
	return (*this);
}

MateriaSource::MateriaSource(void)
{
	for (int i = 0 ; i < AM_SIZE ; ++i)
		_am[i] = NULL;
	std::cout << "[ " << std::setw(W_SIZE) << "Default Constructor on MateriaSource" << " ]" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& ms)
{
	const AMateria*		temp;

	for (int i = 0 ; i < AM_SIZE ; ++i)
	{
		if (_am[i])
		{
			delete _am[i];
			_am[i] = NULL;
		}
		temp = ms.getAMateria(i);
		if (temp)
			_am[i] = temp->clone();
	}
	std::cout << "[ " << std::setw(W_SIZE) << "Copy Constructor on MateriaSource" << " ]" << std::endl;
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0 ; i < AM_SIZE ; ++i)
	{
		if (_am[i])
		{
			delete _am[i];
			_am[i] = NULL;
		}
	}
	std::cout << "[ " << std::setw(W_SIZE) << "Destructor on MateriaSource" << " ]" << std::endl;
}
