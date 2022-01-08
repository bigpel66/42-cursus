// Copyright @bigpel66

#ifndef CIRCLE_04_CPP_MODULE_04_EX01_CAT_HPP_
#define CIRCLE_04_CPP_MODULE_04_EX01_CAT_HPP_

#include "Animal.hpp"
#include "Brain.hpp"

#define C_NAME            "Cat"

class Cat : public Animal {
 private:
  Brain *_b;

 public:
  const Brain *getBrain(void) const;
  void makeSound(void) const;

  Cat& operator=(const Cat& c);
  Cat(void);
  Cat(const Cat& c);
  virtual ~Cat(void);
};

#endif  // CIRCLE_04_CPP_MODULE_04_EX01_CAT_HPP_
