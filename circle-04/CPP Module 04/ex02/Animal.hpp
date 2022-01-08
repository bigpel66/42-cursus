// Copyright @bigpel66

#ifndef CIRCLE_04_CPP_MODULE_04_EX02_ANIMAL_HPP_
#define CIRCLE_04_CPP_MODULE_04_EX02_ANIMAL_HPP_

#include <iomanip>
#include <iostream>
#include <string>

#define W_SIZE            12
#define A_NAME            "Animal"

class Animal {
 protected:
  std::string _type;

 public:
  void setType(const std::string& type);
  std::string getType(void) const;
  virtual void makeSound(void) const = 0;

  Animal& operator=(const Animal& a);
  Animal(void);
  Animal(const Animal& a);
  virtual ~Animal(void);
};

std::ostream& operator<<(std::ostream& o, const Animal& a);

#endif  // CIRCLE_04_CPP_MODULE_04_EX02_ANIMAL_HPP_
