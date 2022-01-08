// Copyright @bigpel66

#ifndef CIRCLE_04_CPP_MODULE_04_EX00_DOG_HPP_
#define CIRCLE_04_CPP_MODULE_04_EX00_DOG_HPP_

#include "Animal.hpp"

#define D_NAME            "Dog"

class Dog : public Animal {
 public:
  void makeSound(void) const;

  Dog& operator=(const Dog& d);
  Dog(void);
  Dog(const Dog& d);
  virtual ~Dog(void);
};

#endif  // CIRCLE_04_CPP_MODULE_04_EX00_DOG_HPP_
