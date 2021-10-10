/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 17:45:35 by jseo              #+#    #+#             */
/*   Updated: 2021/10/10 18:55:38 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ANIMAL_H__
# define __ANIMAL_H__

# include <iomanip>
# include <iostream>
# include <string>

# define W_SIZE					12
# define A_NAME					"Animal"

class Animal
{
	protected:
		std::string				_type;

	public:
		void					setType(const std::string& type);
		std::string				getType(void) const;
		virtual void			makeSound(void) const;

		Animal&					operator=(const Animal& a);
		Animal(void);
		Animal(const Animal& a);
		virtual ~Animal(void);
};

std::ostream&					operator<<(std::ostream& o, const Animal& a);

#endif
