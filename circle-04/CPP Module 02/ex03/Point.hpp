/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 19:52:51 by jseo              #+#    #+#             */
/*   Updated: 2021/10/08 22:23:52 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __POINT_H__
# define __POINT_H__

# include "Fixed.hpp"

# define Vec					Point

class Point
{
	private:
		Fixed const				_x;
		Fixed const				_y;

	public:
		const Fixed&			getX(void) const;
		const Fixed&			getY(void) const;

		Point&					operator=(const Point& p);
		Point(void);
		Point(const float x, const float y);
		Point(const Point& p);
		~Point(void);
};

Vec								operator-(const Point& p1, const Point& p2);
Fixed							operator*(const Vec& v1, const Vec& v2);
bool							operator~(const Fixed& f);
bool							bsp(Point const a, Point const b, Point const c, Point const point);
std::ostream&					operator<<(std::ostream& o, const Point& p);

#endif
