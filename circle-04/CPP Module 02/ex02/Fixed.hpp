/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 13:29:06 by jseo              #+#    #+#             */
/*   Updated: 2021/10/08 19:48:33 by jseo             ###   ########.fr       */
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

		bool					operator>(const Fixed& f);
		bool					operator<(const Fixed& f);
		bool					operator>=(const Fixed& f);
		bool					operator<=(const Fixed& f);
		bool					operator==(const Fixed& f);
		bool					operator!=(const Fixed& f);

		Fixed					operator+(const Fixed& f);
		Fixed					operator-(const Fixed& f);
		Fixed					operator*(const Fixed& f);
		Fixed					operator/(const Fixed& f);

		Fixed&					operator++(void);
		Fixed&					operator--(void);
		Fixed					operator++(int);
		Fixed					operator--(int);

		Fixed&					operator=(const Fixed& f);
		Fixed(void);
		Fixed(const int v);
		Fixed(const float v);
		Fixed(const Fixed& f);
		~Fixed(void);

		static Fixed&			min(Fixed& lhs, Fixed& rhs);
		static Fixed&			max(Fixed& lhs, Fixed& rhs);
		static const Fixed&		min(const Fixed& lhs, const Fixed& rhs);
		static const Fixed&		max(const Fixed& lhs, const Fixed& rhs);
};

std::ostream&					operator<<(std::ostream& o, const Fixed& f);

#endif
