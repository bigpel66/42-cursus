/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 14:15:01 by jseo              #+#    #+#             */
/*   Updated: 2021/10/09 23:48:46 by jseo             ###   ########.fr       */
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

	std::cout << d.getHP();
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << d.getEP();
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << d.getAD();
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << std::endl;
	d.attack(s);
	std::cout << std::endl;

	d.print(std::cout);
	return (0);
}
