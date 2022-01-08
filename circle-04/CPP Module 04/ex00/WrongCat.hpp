// Copyright @bigpel66

#ifndef CIRCLE_04_CPP_MODULE_04_EX00_WRONGCAT_HPP_
#define CIRCLE_04_CPP_MODULE_04_EX00_WRONGCAT_HPP_

#include "WrongAnimal.hpp"

#define WC_NAME           "WrongCat"

class WrongCat : public WrongAnimal {
 public:
  void makeSound(void) const;

  WrongCat& operator=(const WrongCat& wc);
  WrongCat(void);
  WrongCat(const WrongCat& wc);
  virtual ~WrongCat(void);
};

#endif  // CIRCLE_04_CPP_MODULE_04_EX00_WRONGCAT_HPP_
