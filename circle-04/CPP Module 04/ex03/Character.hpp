/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 23:01:13 by jseo              #+#    #+#             */
/*   Updated: 2021/10/11 19:36:16 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CHARACTER_H__
# define __CHARACTER_H__

# include "ICharacter.hpp"

class AMateria;

class Character : public ICharacter
{
	private:
		AMateria*							_am[AM_SIZE];
		std::string							_name;

	public:
		const AMateria*						getAMateria(int idx) const;
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
