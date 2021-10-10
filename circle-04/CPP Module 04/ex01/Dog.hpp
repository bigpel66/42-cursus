/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:49:29 by jseo              #+#    #+#             */
/*   Updated: 2021/10/10 20:30:39 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DOG_H__
# define __DOG_H__

# include "Animal.hpp"
# include "Brain.hpp"

# define D_NAME					"Dog"

class Dog : public Animal
{
	private:
		Brain					*_b;

	public:
		const Brain				*getBrain(void) const;
		void					makeSound(void) const;

		Dog&					operator=(const Dog& d);
		Dog(void);
		Dog(const Dog& d);
		virtual ~Dog(void);
};

#endif
