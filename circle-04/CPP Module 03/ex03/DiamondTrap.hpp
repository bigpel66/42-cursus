/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 14:13:32 by jseo              #+#    #+#             */
/*   Updated: 2021/10/09 23:47:46 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DIAMOND_TRAP_H__
# define __DIAMOND_TRAP_H__

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

# define D_NAME						"DiamondTrap"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string					_name;

	public:
		void						attack(const std::string& target);
		std::string					getName(void) const;

		void						whoAmI(void) const;

		DiamondTrap&				operator=(const DiamondTrap& d);
		DiamondTrap(void);
		DiamondTrap(const std::string& name);
		DiamondTrap(const DiamondTrap& d);
		virtual ~DiamondTrap(void);
};

#endif
