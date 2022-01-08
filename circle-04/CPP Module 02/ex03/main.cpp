// Copyright @bigpel66

#include "Point.hpp"

int main(void) {
  Point a(0.0, 0.0);
  Point b(0.0, 4.0);
  Point c(5.0, 0.0);
  Point hit1(1.0, 1.0);
  Point hit2(10.0, 10.0);

  std::cout << "Point a is " << a << std::endl;
  std::cout << "Point b is " << b << std::endl;
  std::cout << "Point c is " << c << std::endl;
  std::cout << "Hit Point1 is " << hit1 << std::endl;
  std::cout << "Hit Point2 is " << hit2 << std::endl;
  std::cout << std::endl;
  std::cout << "Hit Point1 is " << (bsp(a, b, c, hit1) ? "inside " : "outside ")
    << "of the triangle!" << std::endl;
  std::cout << "Hit Point1 is " << (bsp(a, b, c, hit2) ? "inside " : "outside ")
    << "of the triangle!" << std::endl;
  return 0;
}
