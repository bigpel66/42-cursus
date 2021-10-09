/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 14:13:32 by jseo              #+#    #+#             */
/*   Updated: 2021/10/09 22:41:25 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCAV_TRAP_H__
# define __SCAV_TRAP_H__

# include "ClapTrap.hpp"

# define S_NAME						"ScavTrap"
# define S_HP						100
# define S_EP						50
# define S_AD						20

class ScavTrap : public ClapTrap
{
	public:
		void						attack(const std::string& target);

		void						guardGate(void) const;

		ScavTrap&					operator=(const ScavTrap& s);
		ScavTrap(void);
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap& s);
		virtual ~ScavTrap(void);
};

#endif
