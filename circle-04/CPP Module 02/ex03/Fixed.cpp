/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 13:33:41 by jseo              #+#    #+#             */
/*   Updated: 2021/10/08 22:14:41 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

bool							operator>(const Fixed& lhs, const Fixed& rhs)
{
	return (lhs.getRawBits() > rhs.getRawBits());
}

bool							operator<(const Fixed& lhs, const Fixed& rhs)
{
	return (lhs.getRawBits() < rhs.getRawBits());
}

bool							operator>=(const Fixed& lhs, const Fixed& rhs)
{
	return (lhs.getRawBits() >= rhs.getRawBits());
}

bool							operator<=(const Fixed& lhs, const Fixed& rhs)
{
	return (lhs.getRawBits() <= rhs.getRawBits());
}

bool							operator==(const Fixed& lhs, const Fixed& rhs)
{
	return (lhs.getRawBits() == rhs.getRawBits());
}

bool							operator!=(const Fixed& lhs, const Fixed& rhs)
{
	return (lhs.getRawBits() != rhs.getRawBits());
}

Fixed							operator+(const Fixed& lhs, const Fixed& rhs)
{
	Fixed						temp(lhs.toFloat() + rhs.toFloat());

	return (temp);
}

Fixed							operator-(const Fixed& lhs, const Fixed& rhs)
{
	Fixed						temp(lhs.toFloat() - rhs.toFloat());

	return (temp);
}

Fixed							operator*(const Fixed& lhs, const Fixed& rhs)
{
	Fixed						temp(lhs.toFloat() * rhs.toFloat());

	return (temp);
}

Fixed							operator/(const Fixed& lhs, const Fixed& rhs)
{
	Fixed						temp(lhs.toFloat() / rhs.toFloat());

	return (temp);
}

std::ostream&					operator<<(std::ostream& o, const Fixed& f)
{
	return (o << f.toFloat());
}

int								Fixed::getRawBits(void) const
{
	return (_fixed_point);
}

void							Fixed::setRawBits(const int raw)
{
	_fixed_point = raw;
}

float							Fixed::toFloat(void) const
{
	return (static_cast<float>(_fixed_point) / (1 << Fixed::_frac_bits));
}

int								Fixed::toInt(void) const
{
	return (_fixed_point >> Fixed::_frac_bits);
}

Fixed&							Fixed::operator++(void)
{
	++_fixed_point;
	return (*this);
}

Fixed&							Fixed::operator--(void)
{
	--_fixed_point;
	return (*this);
}

Fixed							Fixed::operator++(int)
{
	Fixed						temp = *this;

	++_fixed_point;
	return (temp);
}

Fixed							Fixed::operator--(int)
{
	Fixed						temp = *this;

	--_fixed_point;
	return (temp);
}

Fixed&							Fixed::operator=(const Fixed& f)
{
	if (this != &f)
		_fixed_point = f.getRawBits();
	return (*this);
}

Fixed::Fixed(void)
	: _fixed_point(0) {}

Fixed::Fixed(const int v)
	: _fixed_point(v << Fixed::_frac_bits) {}

Fixed::Fixed(const float v)
	: _fixed_point(static_cast<int>(roundf(v * (1 << Fixed::_frac_bits)))) {}

Fixed::Fixed(const Fixed& f)
{
	*this = f;
}

Fixed::~Fixed(void) {}

Fixed&							Fixed::min(Fixed& lhs, Fixed& rhs)
{
	if (lhs.getRawBits() < rhs.getRawBits())
		return (lhs);
	return (rhs);
}

Fixed&							Fixed::max(Fixed& lhs, Fixed& rhs)
{
	if (lhs.getRawBits() > rhs.getRawBits())
		return (lhs);
	return (rhs);
}

const Fixed&					Fixed::min(const Fixed& lhs, const Fixed& rhs)
{
	if (lhs.getRawBits() < rhs.getRawBits())
		return (lhs);
	return (rhs);
}

const Fixed&					Fixed::max(const Fixed& lhs, const Fixed& rhs)
{
	if (lhs.getRawBits() > rhs.getRawBits())
		return (lhs);
	return (rhs);
}
