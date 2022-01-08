// Copyright @bigpel66

#include "Fixed.hpp"

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return _fixed_point;
}

void Fixed::setRawBits(const int raw) {
  std::cout << "setRawBits member function called" << std::endl;
  _fixed_point = raw;
}

Fixed& Fixed::operator=(const Fixed& f) {
  std::cout << "Assignation operator called" << std::endl;
  if (this != &f)
    _fixed_point = f.getRawBits();
  return *this;
}

Fixed::Fixed(void)
  : _fixed_point(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& f) {
  std::cout << "Copy constructor called" << std::endl;
  *this = f;
}

Fixed::~Fixed(void) {
  std::cout << "Destructor called" << std::endl;
}
