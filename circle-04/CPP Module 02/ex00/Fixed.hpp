/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 13:29:06 by jseo              #+#    #+#             */
/*   Updated: 2021/10/08 16:09:05 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_H__
# define __FIXED_H__

# include <iostream>

class Fixed
{
	private:
		int						_fixed_point;
		static const int		_frac_bits = 8;

	public:
		int						getRawBits(void) const;
		void					setRawBits(int const raw);

		Fixed&					operator=(const Fixed& f);
		Fixed(void);
		Fixed(const Fixed& f);
		~Fixed(void);
};

#endif
