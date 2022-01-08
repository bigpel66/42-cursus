// Copyright @bigpel66

#ifndef CIRCLE_04_CPP_MODULE_02_EX00_FIXED_HPP_
#define CIRCLE_04_CPP_MODULE_02_EX00_FIXED_HPP_

#include <iostream>

class Fixed {
 private:
  int _fixed_point;
  static const int _frac_bits = 8;

 public:
  int getRawBits(void) const;
  void setRawBits(int const raw);

  Fixed& operator=(const Fixed& f);
  Fixed(void);
  Fixed(const Fixed& f);
  ~Fixed(void);
};

#endif  // CIRCLE_04_CPP_MODULE_02_EX00_FIXED_HPP_
