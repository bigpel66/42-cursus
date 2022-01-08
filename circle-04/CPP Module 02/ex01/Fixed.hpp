// Copyright @bigpel66

#ifndef CIRCLE_04_CPP_MODULE_02_EX01_FIXED_HPP_
#define CIRCLE_04_CPP_MODULE_02_EX01_FIXED_HPP_

#include <cmath>
#include <iostream>

class Fixed {
 private:
  int _fixed_point;
  static const int _frac_bits = 8;

 public:
  int getRawBits(void) const;
  void setRawBits(int const raw);
  float toFloat(void) const;
  int toInt(void) const;

  Fixed& operator=(const Fixed& f);
  Fixed(void);
  explicit Fixed(const int v);
  explicit Fixed(const float v);
  Fixed(const Fixed& f);
  ~Fixed(void);
};

std::ostream& operator<<(std::ostream& o, const Fixed& f);

#endif  // CIRCLE_04_CPP_MODULE_02_EX01_FIXED_HPP_
