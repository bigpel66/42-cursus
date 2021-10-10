/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 23:01:13 by jseo              #+#    #+#             */
/*   Updated: 2021/10/10 23:04:41 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CHARACTER_H__
# define __CHARACTER_H__

# include "ICharacter.hpp"

class Character : public ICharacter
{
	public:
		const std::string& 					getName(void) const;
		void								equip(AMateria* am);
		void								unequip(int idx);
		void								use(int idx, ICharacter& ic);

		Character&							operator=(const Character& c);
		Character(void);
		Character(const std::string& name);
		Character(const Character& c);
		virtual ~Character(void);
};

#endif
