/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 22:31:06 by jseo              #+#    #+#             */
/*   Updated: 2021/10/10 23:01:00 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CURE_H__
# define __CURE_H__

# include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		AMateria*							clone(void) const;
		void								use(ICharacter& ic);

		Cure&								operator=(const Cure& c);
		Cure(void);
		Cure(const std::string& type);
		Cure(const Cure& c);
		virtual ~Cure(void);
};

#endif
