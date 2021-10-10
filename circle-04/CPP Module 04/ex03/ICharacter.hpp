/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 22:34:39 by jseo              #+#    #+#             */
/*   Updated: 2021/10/11 02:33:40 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __I_CHARACTER_H__
# define __I_CHARACTER_H__

# include "AMateria.hpp"
# include <string>
# include <iomanip>
# include <iostream>

# define W_SIZE								30

class ICharacter
{
	public:
		virtual const std::string&			getName(void) const = 0;
		virtual void						equip(AMateria* am) = 0;
		virtual AMateria*					unequip(int idx) = 0;
		virtual void						use(int idx, ICharacter& ic) = 0;

		virtual ~ICharacter(void);

		ICharacter(void);
};

#endif
