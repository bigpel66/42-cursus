/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 22:52:58 by jseo              #+#    #+#             */
/*   Updated: 2021/10/11 12:18:15 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MATERIA_SOURCE_H__
# define __MATERIA_SOURCE_H__

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria*							_am[AM_SIZE];

	public:
		const AMateria*						getAMateria(int idx) const;
		void								learnMateria(AMateria* am);
		AMateria*							createMateria(const std::string& type);

		MateriaSource&						operator=(const MateriaSource& ms);
		MateriaSource(void);
		MateriaSource(const MateriaSource& ms);
		virtual ~MateriaSource(void);
};

#endif
