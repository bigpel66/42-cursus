
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 17:03:39 by jseo              #+#    #+#             */
/*   Updated: 2021/10/07 17:09:39 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WEAPON_H__
# define __WEAPON_H__

#include <iostream>
#include <string>

# define RED						"\033[0;31m"
# define YELLOW						"\033[1;33m"
# define GREEN						"\033[0;32m"
# define BLUE						"\033[0;34m"
# define EOC						"\033[0;0m"

class Weapon
{
	private:
		std::string				_type;

		Weapon(void);

	public:
		const std::string				&getType(void) const;
		void							setType(const std::string& type);

		Weapon(const std::string& type);
		~Weapon(void);
};

#endif
