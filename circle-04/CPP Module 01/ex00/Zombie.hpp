/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 13:31:40 by jseo              #+#    #+#             */
/*   Updated: 2021/10/07 15:10:06 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ZOMBIE_H__
# define __ZOMBIE_H__

# include "Random.hpp"
# include <iostream>
# include <string>

# define NB_ZOMBIE				10

class Zombie
{
	private:
		std::string				_name;

		Zombie(void);

	public:
		static std::string		randomName(void);
		void					announce(void) const;

		Zombie(const std::string name);
		~Zombie(void);
};

Zombie							*newZombie(std::string name);
void							randomChump(std::string name);

#endif
