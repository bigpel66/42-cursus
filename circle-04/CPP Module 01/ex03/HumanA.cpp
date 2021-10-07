/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:06:49 by jseo              #+#    #+#             */
/*   Updated: 2021/10/07 18:39:42 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

void						HumanA::attack(void) const
{
	std::cout << "[ " << YELLOW << _name << EOC << " ]\t\t\t" << "is " << YELLOW << "attakcing" << EOC << " with " << _w.getType() << std::endl;
}

HumanA::HumanA(const std::string name, Weapon& w) : _name(name), _w(w)
{
	std::cout << "[ " << YELLOW << _name << EOC << " ]\t\t\t" << "is " << GREEN << "respawned" << EOC << " with " << _w.getType() << std::endl;
}

HumanA::~HumanA(void)
{
	std::cout << "[ " << YELLOW << _name << EOC << " ]\t\t\t" << "is " << RED << "dead" << EOC << std::endl;
}
