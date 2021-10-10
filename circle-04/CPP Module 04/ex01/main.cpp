/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 20:32:43 by jseo              #+#    #+#             */
/*   Updated: 2021/10/10 21:41:56 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

void	test_normal(void)
{
	const Animal*	i = new Cat();
	const Animal*	j = new Dog();

	std::cout << std::endl;
	i->makeSound();
	j->makeSound();
	std::cout << std::endl;

	delete j;
	delete i;
}

void	test_array(void)
{
	Animal*			meta[I_SIZE / 5];
	Dog*			collie;

	for (int i = 0 ; i < I_SIZE / 5 ; ++i)
	{
		if (!(i % 2))
			meta[i] = new Cat();
		else
		 	meta[i] = new Dog();
	}
	collie = new Dog((*dynamic_cast<Dog *>(meta[1])));
	for (int i = 0 ; i < I_SIZE / 5 ; ++i)
		delete meta[i];
	std::cout << *collie->getBrain();
	delete collie;
}

int		main(void)
{
	std::cout << std::setfill('=') << std::setw(50) << "\n" << std::setfill(' ');
	test_normal();
	std::cout << std::setfill('=') << std::setw(50) << "\n" << std::setfill(' ');
	test_array();
	std::cout << std::setfill('=') << std::setw(50) << "\n" << std::setfill(' ');
	return (0);
}
