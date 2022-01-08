// Copyright @bigpel66

#ifndef CIRCLE_04_CPP_MODULE_04_EX03_ICE_HPP_
#define CIRCLE_04_CPP_MODULE_04_EX03_ICE_HPP_

#include <string>

#include "AMateria.hpp"

#define I_NAME            "ice"

class Ice : public AMateria {
 public:
  AMateria* clone(void) const;
  void use(const ICharacter& ic);

  // Does Not Make Sense
  Ice& operator=(const Ice& i);

  Ice(void);
  explicit Ice(const std::string& type);
  Ice(const Ice& i);
  virtual ~Ice(void);
};

#endif  // CIRCLE_04_CPP_MODULE_04_EX03_ICE_HPP_
