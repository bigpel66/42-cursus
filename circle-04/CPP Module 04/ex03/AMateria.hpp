/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 22:27:15 by jseo              #+#    #+#             */
/*   Updated: 2021/10/11 01:48:38 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __A_MATERIA_H__
# define __A_MATERIA_H__

# include <string>
# include <iomanip>
# include <iostream>

# define W_SIZE								30

class ICharacter;

class AMateria
{
	protected:
		std::string							_type;

	public:
		const std::string&					getType(void) const;

		virtual AMateria*					clone(void) const = 0;
		virtual void						use(ICharacter& ic);

		// Cannot Use
		// AMateria&							operator=(const AMateria& am);

		AMateria(void);
		AMateria(const std::string& type);
		AMateria(const AMateria& am);
		virtual ~AMateria(void);
};

#endif
