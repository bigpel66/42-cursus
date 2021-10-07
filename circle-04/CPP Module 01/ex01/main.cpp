/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:43:59 by jseo              #+#    #+#             */
/*   Updated: 2021/10/07 15:56:53 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	std::cout << "Creating a Horde of " << NB_ZOMBIE << " Zombies"
				<< std::endl << std::endl;
	Zombie			*z = Zombie::zombieHorde(NB_ZOMBIE, Zombie::randomName());
	std::cout << std::endl << "Burying a Horde of " << NB_ZOMBIE << " Zombies"
				<< std::endl << std::endl;
	delete[] z;
	return (0);
}
