// Copyright @bigpel66

#ifndef CIRCLE_04_CPP_MODULE_04_EX00_WRONGANIMAL_HPP_
#define CIRCLE_04_CPP_MODULE_04_EX00_WRONGANIMAL_HPP_

#include <iomanip>
#include <iostream>
#include <string>

#define W_SIZE            12
#define WA_NAME           "WrongAnimal"

class WrongAnimal {
 protected:
  std::string _type;

 public:
  void setType(const std::string& type);
  std::string getType(void) const;
  void makeSound(void) const;

  WrongAnimal& operator=(const WrongAnimal& wa);
  WrongAnimal(void);
  WrongAnimal(const WrongAnimal& wa);
  virtual ~WrongAnimal(void);
};

std::ostream& operator<<(std::ostream& o, const WrongAnimal& wa);

#endif  // CIRCLE_04_CPP_MODULE_04_EX00_WRONGANIMAL_HPP_
