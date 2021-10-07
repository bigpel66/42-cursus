/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:29:09 by jseo              #+#    #+#             */
/*   Updated: 2021/10/07 15:53:50 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie			*Zombie::zombieHorde(int N, std::string name)
{
	Zombie		*z = new Zombie[N];

	for (int i = 0 ; i < N ; ++i)
		z[i].setName(name);
	return (z);
}
