/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:50:01 by jseo              #+#    #+#             */
/*   Updated: 2021/10/07 15:56:38 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie		*z[NB_ZOMBIE];

	std::cout << "Creating " << NB_ZOMBIE << " Random Heap Zombies"
				<< std::endl << std::endl;
	for (int i = 0 ; i < NB_ZOMBIE ; ++i)
		z[i] = Zombie::newZombie(Zombie::randomName());
	std::cout << std::endl << "Creating " << NB_ZOMBIE << " Random Stack Zombies"
				<< std::endl << std::endl;
	for (int i = 0 ; i < NB_ZOMBIE ; ++i)
		Zombie::randomChump(Zombie::randomName());
	std::cout << std::endl << "Burying " << NB_ZOMBIE << " Random Heap Zombies"
				<< std::endl << std::endl;
	for (int i = 0 ; i < NB_ZOMBIE ; ++i)
		delete z[i];
	return (0);
}
