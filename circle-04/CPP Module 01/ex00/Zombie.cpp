/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:22:21 by jseo              #+#    #+#             */
/*   Updated: 2021/10/07 15:08:17 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>

std::string		Zombie::randomName(void)
{
	static std::string		characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	std::string				temp(10, '\0');
	std::string::iterator	iter = temp.begin();
	std::string::iterator	end = temp.end();

	while (iter != end)
		*iter++ = characters.at(static_cast<int>(Random::randr(0.0, 61.0)));
	return (temp);
}

void			Zombie::announce(void) const
{
	std::cout << "<" << _name << "> BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(void)
{
	std::cout << "This will not be called due to the private member" << std::endl;
}

Zombie::Zombie(const std::string name)
	: _name(name) {}

Zombie::~Zombie(void)
{
	std::cout << "<" << _name << "> Buried..." << std::endl;
}
