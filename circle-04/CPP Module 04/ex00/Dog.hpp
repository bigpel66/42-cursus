/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:49:29 by jseo              #+#    #+#             */
/*   Updated: 2021/10/10 18:56:41 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DOG_H__
# define __DOG_H__

# include "Animal.hpp"

# define D_NAME					"Dog"

class Dog : public Animal
{
	public:
		void					makeSound(void) const;

		Dog&					operator=(const Dog& d);
		Dog(void);
		Dog(const Dog& d);
		virtual ~Dog(void);
};

#endif
