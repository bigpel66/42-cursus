/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 14:13:32 by jseo              #+#    #+#             */
/*   Updated: 2021/10/09 22:10:29 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FRAG_TRAP_H__
# define __FRAG_TRAP_H__

# include "ClapTrap.hpp"

# define F_NAME						"FragTrap"
# define F_HP						100
# define F_EP						100
# define F_AD						30

class FragTrap : public ClapTrap
{
	public:
		void						hiFivesGuys(void) const;

		FragTrap&					operator=(const FragTrap& f);
		FragTrap(void);
		FragTrap(const std::string& name);
		FragTrap(const FragTrap& f);
		virtual ~FragTrap(void);
};

#endif
