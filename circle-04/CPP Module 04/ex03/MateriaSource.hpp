/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 22:52:58 by jseo              #+#    #+#             */
/*   Updated: 2021/10/10 22:55:31 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MATERIA_SOURCE_H__
# define __MATERIA_SOURCE_H__

#include "ICharacter.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		void								learnMateria(AMateria* am);
		AMateria*							createMateria(const std::string& type);

		MateriaSource&						operator=(const MateriaSource& ms);
		MateriaSource(void);
		MateriaSource(const MateriaSource& ms);
		virtual ~MateriaSource(void);
};

#endif
