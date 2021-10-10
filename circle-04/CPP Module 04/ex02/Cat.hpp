/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:32:33 by jseo              #+#    #+#             */
/*   Updated: 2021/10/10 20:24:01 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CAT_H__
# define __CAT_H__

# include "Animal.hpp"
# include "Brain.hpp"

# define C_NAME					"Cat"

class Cat : public Animal
{
	private:
		Brain					*_b;

	public:
		const Brain				*getBrain(void) const;
		void					makeSound(void) const;

		Cat&					operator=(const Cat& c);
		Cat(void);
		Cat(const Cat& c);
		virtual ~Cat(void);
};

#endif
