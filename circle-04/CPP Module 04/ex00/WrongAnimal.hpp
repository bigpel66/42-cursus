/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:20:52 by jseo              #+#    #+#             */
/*   Updated: 2021/10/10 19:25:13 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WRONG_ANIMAL_H__
# define __WRONG_ANIMAL_H__

# include <iomanip>
# include <iostream>
# include <string>

# define W_SIZE					12
# define WA_NAME				"WrongAnimal"

class WrongAnimal
{
	protected:
		std::string				_type;

	public:
		void					setType(const std::string& type);
		std::string				getType(void) const;
		void					makeSound(void) const;

		WrongAnimal&			operator=(const WrongAnimal& wa);
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal& wa);
		virtual ~WrongAnimal(void);
};

std::ostream&					operator<<(std::ostream& o, const WrongAnimal& wa);

#endif
