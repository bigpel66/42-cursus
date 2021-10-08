/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 13:29:06 by jseo              #+#    #+#             */
/*   Updated: 2021/10/08 18:56:49 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_H__
# define __FIXED_H__

# include <cmath>
# include <iostream>

class Fixed
{
	private:
		int						_fixed_point;
		static const int		_frac_bits = 8;

	public:
		int						getRawBits(void) const;
		void					setRawBits(int const raw);
		float					toFloat(void) const;
		int						toInt(void) const;

		Fixed&					operator=(const Fixed& f);
		Fixed(void);
		Fixed(const int v);
		Fixed(const float v);
		Fixed(const Fixed& f);
		~Fixed(void);
};

std::ostream&					operator<<(std::ostream& o, const Fixed& f);

#endif
