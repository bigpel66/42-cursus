/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 14:15:01 by jseo              #+#    #+#             */
/*   Updated: 2021/10/09 23:51:05 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	std::string	s = "Jseo";
	DiamondTrap	d(s);

	std::cout << std::endl;
	d.whoAmI();
	std::cout << std::endl;

	std::cout << "HP is " << d.getHP() << std::endl;;
	std::cout << std::endl;

	std::cout << "EP is " << d.getEP() << std::endl;;
	std::cout << std::endl;

	std::cout << "AD is " << d.getAD() << std::endl;;
	std::cout << std::endl;

	std::cout << std::endl;
	d.attack(s);
	std::cout << std::endl;

	d.print(std::cout);
	return (0);
}
