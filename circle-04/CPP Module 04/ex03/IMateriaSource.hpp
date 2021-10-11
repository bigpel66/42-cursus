/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 22:41:39 by jseo              #+#    #+#             */
/*   Updated: 2021/10/11 12:16:07 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __I_MATERIA_SOURCE_H__
# define __I_MATERIA_SOURCE_H__

# include "AMateria.hpp"

class IMateriaSource
{
	public:
		virtual void						learnMateria(AMateria* am) = 0;
		virtual AMateria*					createMateria(const std::string& type) = 0;

		virtual ~IMateriaSource(void) {}
};

#endif
