// Copyright @bigpel66

#ifndef CIRCLE_04_CPP_MODULE_04_EX03_AMATERIA_HPP_
#define CIRCLE_04_CPP_MODULE_04_EX03_AMATERIA_HPP_

#include <string>
#include <iomanip>
#include <iostream>

#define W_SIZE              40
#define AM_SIZE             4

class ICharacter;

class AMateria {
 protected:
  std::string _type;

 public:
  const std::string& getType(void) const;

  virtual AMateria* clone(void) const = 0;
  virtual void use(const ICharacter& ic);

  // Does Not Make Sense
  AMateria& operator=(const AMateria& am);

  AMateria(void);
  explicit AMateria(const std::string& type);
  AMateria(const AMateria& am);
  virtual ~AMateria(void);
};

#endif  // CIRCLE_04_CPP_MODULE_04_EX03_AMATERIA_HPP_
