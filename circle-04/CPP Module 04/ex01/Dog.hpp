// Copyright @bigpel66

#ifndef CIRCLE_04_CPP_MODULE_04_EX01_DOG_HPP_
#define CIRCLE_04_CPP_MODULE_04_EX01_DOG_HPP_

#include "Animal.hpp"
#include "Brain.hpp"

#define D_NAME            "Dog"

class Dog : public Animal {
 private:
  Brain *_b;

 public:
  const Brain *getBrain(void) const;
  void makeSound(void) const;

  Dog& operator=(const Dog& d);
  Dog(void);
  Dog(const Dog& d);
  virtual ~Dog(void);
};

#endif  // CIRCLE_04_CPP_MODULE_04_EX01_DOG_HPP_
