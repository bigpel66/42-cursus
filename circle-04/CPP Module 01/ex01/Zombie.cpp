/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:22:21 by jseo              #+#    #+#             */
/*   Updated: 2021/10/07 19:04:10 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void			Zombie::announce(void) const
{
	std::cout << "<" << _name << "> BraiiiiiiinnnzzzZ..." << std::endl;
}

void			Zombie::setName(const std::string& name)
{
	_name = name;
	announce();
}

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

Zombie::Zombie(void)
{
	std::cout << "For the Horde!!!" << std::endl;
}

Zombie::Zombie(const std::string& name)
	: _name(name)
{
	announce();
}

Zombie::~Zombie(void)
{
	std::cout << "<" << _name << "> Buried..." << std::endl;
}
