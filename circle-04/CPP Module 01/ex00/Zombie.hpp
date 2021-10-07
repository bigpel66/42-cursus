/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 13:31:40 by jseo              #+#    #+#             */
/*   Updated: 2021/10/07 19:02:10 by jseo             ###   ########.fr       */
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
		static Zombie			*newZombie(std::string name);
		static void				randomChump(std::string name);

		void					announce(void) const;
		static std::string		randomName(void);

		Zombie(const std::string& name);
		~Zombie(void);
};

#endif
