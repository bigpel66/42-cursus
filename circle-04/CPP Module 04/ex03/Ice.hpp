/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 22:32:39 by jseo              #+#    #+#             */
/*   Updated: 2021/10/11 01:18:57 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ICE_H__
# define __ICE_H__

# include "AMateria.hpp"

# define I_NAME								"ice"

class Ice : public AMateria
{
	public:
		AMateria*							clone(void) const;
		void								use(ICharacter& ic);

		// Does Not Make Sense
		Ice&								operator=(const Ice& i);

		Ice(void);
		Ice(const std::string& type);
		Ice(const Ice& i);
		virtual ~Ice(void);
};

#endif
