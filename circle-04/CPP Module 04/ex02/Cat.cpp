/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:39:50 by jseo              #+#    #+#             */
/*   Updated: 2021/10/10 20:29:27 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

const Brain						*Cat::getBrain(void) const
{
	if (_b)
		return (_b);
	return (NULL);
}

void							Cat::makeSound(void) const
{
	std::cout << " [ " << std::setw(W_SIZE) << C_NAME << " ] "
				<< "Meow Meow" << std::endl;
}

Cat&							Cat::operator=(const Cat& c)
{
	if (this != &c)
	{
		_type = c.getType();
		*_b = *c.getBrain();
	}
	std::cout << " [ " << std::setw(W_SIZE) << C_NAME << " ] "
				<< "Assigned" << std::endl;
	return (*this);
}

Cat::Cat(void)
	:	Animal(), _b(NULL)
{
	_type = C_NAME;
	_b = new Brain();
	std::cout << " [ " << std::setw(W_SIZE) << C_NAME << " ] "
				<< "Default constructed" << std::endl;
}

Cat::Cat(const Cat& c)
	:	Animal(), _b(NULL)
{
	_type = c.getType();
	_b = new Brain(*c.getBrain());
	std::cout << " [ " << std::setw(W_SIZE) << C_NAME << " ] "
				<< "Copy constructed" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << " [ " << std::setw(W_SIZE) << C_NAME << " ] "
			<< "Destructed" << std::endl;
	delete _b;
}
