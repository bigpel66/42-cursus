/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 17:34:48 by jseo              #+#    #+#             */
/*   Updated: 2021/10/07 18:30:10 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMAN_B__
# define __HUMAN_B__

# include "Weapon.hpp"

class HumanB
{
	private:
		std::string		_name;
		Weapon			*_w;

		HumanB(void);

	public:
		void			setWeapon(Weapon &w);
		void			attack(void) const;

		HumanB(const std::string name);
		~HumanB(void);
};

#endif
