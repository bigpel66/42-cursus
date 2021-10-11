/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 22:49:41 by jseo              #+#    #+#             */
/*   Updated: 2021/10/11 19:43:48 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

void	test_normal(void)
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

void	test_other(void)
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	src->learnMateria(NULL);
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());

	AMateria* tmp;
	tmp = src->createMateria("icecure");

	ICharacter* me = new Character("me");
	ICharacter* bob = new  Character("bob");

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	AMateria* tmp1 = src->createMateria("ice");
	me->equip(tmp1);
	AMateria* tmp2 = src->createMateria("cure");
	me->equip(tmp);

	me->unequip(2);
	me->unequip(3);

	bob->equip(tmp1);
	bob->equip(tmp2);

	me->use(0, *bob);
	me->use(1, *bob);

	bob->use(0, *me);
	bob->use(1, *me);

	delete bob;
	delete me;
	delete src;
}

int		main(void)
{
	std::cout << std::setfill('=') << std::setw(100) << "\n" << std::setfill(' ');
	test_normal();
	std::cout << std::setfill('=') << std::setw(100) << "\n" << std::setfill(' ');
	test_other();
	std::cout << std::setfill('=') << std::setw(100) << "\n" << std::setfill(' ');
	return (0);
}
