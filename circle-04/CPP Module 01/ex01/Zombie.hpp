/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 13:31:40 by jseo              #+#    #+#             */
/*   Updated: 2021/10/07 15:48:40 by jseo             ###   ########.fr       */
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


	public:
		static Zombie			*zombieHorde(int N, std::string name);

		void					announce(void) const;
		void					setName(const std::string name);
		static std::string		randomName(void);

		Zombie(void);
		Zombie(const std::string name);
		~Zombie(void);
};

#endif
