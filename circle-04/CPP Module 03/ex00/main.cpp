/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 14:12:59 by jseo              #+#    #+#             */
/*   Updated: 2021/10/09 18:23:21 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	std::string s1 = "Jseo";
	std::string s2 = "Hyson";

	ClapTrap c1(s1);
	ClapTrap c2(s2);
	std::cout << std::endl;

	c1.beRepaired(10);

	c1.attack(s2);
	c2.takeDamage(5);

	c2.beRepaired(3);
	c2.beRepaired(2);

	c2.attack(s1);
	c1.takeDamage(10);

	c1.beRepaired(10);
	c1.attack(s2);

	c2.attack(s1);
	c1.takeDamage(5);

	std::cout << std::endl;
	return (0);
}
