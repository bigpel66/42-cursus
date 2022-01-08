// Copyright @bigpel66

#ifndef CIRCLE_04_CPP_MODULE_02_EX03_POINT_HPP_
#define CIRCLE_04_CPP_MODULE_02_EX03_POINT_HPP_

#include "Fixed.hpp"

#define Vec               Point

class Point {
 private:
  Fixed const _x;
  Fixed const _y;

 public:
  const Fixed& getX(void) const;
  const Fixed& getY(void) const;

  Point& operator=(const Point& p);
  Point(void);
  Point(const float x, const float y);
  Point(const Point& p);
  ~Point(void);
};

Vec operator-(const Point& p1, const Point& p2);
Fixed operator*(const Vec& v1, const Vec& v2);
bool operator~(const Fixed& f);
bool bsp(Point const a, Point const b, Point const c, Point const point);
std::ostream& operator<<(std::ostream& o, const Point& p);

#endif  // CIRCLE_04_CPP_MODULE_02_EX03_POINT_HPP_
