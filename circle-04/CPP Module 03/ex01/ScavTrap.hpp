/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 14:13:32 by jseo              #+#    #+#             */
/*   Updated: 2021/10/09 19:37:11 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCAV_TRAP_H__
# define __SCAV_TRAP_H__

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		static const std::string	_class_name;
		static const unsigned int	_class_hp;
		static const unsigned int	_class_ep;
		static const unsigned int	_class_ad;

	public:
		void					attack(const std::string& target);

		void					guardGate(void) const;

		static std::string			getClassName(void);
		static unsigned int			getClassHP(void);
		static unsigned int			getClassEP(void);
		static unsigned int			getClassAD(void);

		ScavTrap&				operator=(const ScavTrap& s);
		ScavTrap(void);
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap& s);
		virtual ~ScavTrap(void);
};

#endif
