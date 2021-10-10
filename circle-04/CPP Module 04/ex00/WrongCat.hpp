/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:20:32 by jseo              #+#    #+#             */
/*   Updated: 2021/10/10 19:27:17 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WRONG_CAT_H__
# define __WRONG_CAT_H__

# include "WrongAnimal.hpp"

# define WC_NAME				"WrongCat"

class WrongCat : public WrongAnimal
{
	public:
		void					makeSound(void) const;

		WrongCat&				operator=(const WrongCat& wc);
		WrongCat(void);
		WrongCat(const WrongCat& wc);
		virtual ~WrongCat(void);
};

#endif
