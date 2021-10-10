/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:26:28 by jseo              #+#    #+#             */
/*   Updated: 2021/10/10 19:27:08 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

void							WrongCat::makeSound(void) const
{
	std::cout << " [ " << std::setw(W_SIZE) << WC_NAME << " ] "
				<< "Meow Meow" << std::endl;
}

WrongCat&						WrongCat::operator=(const WrongCat& wc)
{
	if (this != &wc)
		_type = wc.getType();
	std::cout << " [ " << std::setw(W_SIZE) << WC_NAME << " ] "
				<< "Assigned" << std::endl;
	return (*this);
}

WrongCat::WrongCat(void)
	:	WrongAnimal()
{
	_type = WC_NAME;
	std::cout << " [ " << std::setw(W_SIZE) << WC_NAME << " ] "
				<< "Default constructed" << std::endl;
}

WrongCat::WrongCat(const WrongCat& wc)
	:	WrongAnimal()
{
	_type = wc.getType();
	std::cout << " [ " << std::setw(W_SIZE) << WC_NAME << " ] "
				<< "Copy constructed" << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << " [ " << std::setw(W_SIZE) << WC_NAME << " ] "
			<< "Destructed" << std::endl;
}
