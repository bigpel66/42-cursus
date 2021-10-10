/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:52:18 by jseo              #+#    #+#             */
/*   Updated: 2021/10/10 18:59:50 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

void							Dog::makeSound(void) const
{
	std::cout << " [ " << std::setw(W_SIZE) << D_NAME << " ] "
				<< "Bowwow Bowwow" << std::endl;
}

Dog&							Dog::operator=(const Dog& d)
{
	if (this != &d)
		_type = d.getType();
	std::cout << " [ " << std::setw(W_SIZE) << D_NAME << " ] "
				<< "Assigned" << std::endl;
	return (*this);
}

Dog::Dog(void)
	:	Animal()
{
	_type = "Dog";
	std::cout << " [ " << std::setw(W_SIZE) << D_NAME << " ] "
				<< "Default constructed" << std::endl;
}

Dog::Dog(const Dog& d)
	:	Animal()
{
	_type = d.getType();
	std::cout << " [ " << std::setw(W_SIZE) << D_NAME << " ] "
				<< "Copy constructed" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << " [ " << std::setw(W_SIZE) << D_NAME << " ] "
			<< "Destructed" << std::endl;
}
