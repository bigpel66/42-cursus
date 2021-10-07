/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 17:31:00 by jseo              #+#    #+#             */
/*   Updated: 2021/10/07 18:30:07 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMAN_A__
# define __HUMAN_A__

# include "Weapon.hpp"

class HumanA
{
	private:
		std::string		_name;
		Weapon			&_w;

	public:
		void			attack(void) const;

		HumanA(const std::string name, Weapon &w);
		~HumanA(void);
};

#endif
