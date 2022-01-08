// Copyright @bigpel66

#include "Point.hpp"

Vec operator-(const Point& p1, const Point& p2) {
  return Vec(((p1.getX()) - (p2.getX())).toFloat(),
              (p1.getY() - p2.getY()).toFloat());
}

Fixed operator*(const Vec& v1, const Vec& v2) {
  return Fixed((v1.getX() * v2.getY()) - v1.getY() * v2.getX());
}

bool operator~(const Fixed& f) {
  return f > Fixed(0);
}

bool bsp(const Point a, const Point b, const Point c, const Point point) {
  Vec ab = a - b;
  Vec bp = b - point;

  Vec bc = b - c;
  Vec cp = c - point;

  Vec ca = c - a;
  Vec ap = a - point;

  if ((~(ab * bp) && ~(bc * cp) && ~(ca * ap))
    || (!(~(ab * bp)) && !(~(bc * cp)) && !(~(ca * ap))))
    return true;
  return false;
}
