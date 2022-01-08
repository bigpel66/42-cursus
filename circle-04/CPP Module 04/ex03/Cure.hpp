// Copyright @bigpel66

#ifndef CIRCLE_04_CPP_MODULE_04_EX03_CURE_HPP_
#define CIRCLE_04_CPP_MODULE_04_EX03_CURE_HPP_

#include <string>

#include "AMateria.hpp"

#define C_NAME            "cure"

class Cure : public AMateria {
 public:
  AMateria* clone(void) const;
  void use(const ICharacter& ic);

  // Does Not Make Sense
  Cure& operator=(const Cure& c);

  Cure(void);
  explicit Cure(const std::string& type);
  Cure(const Cure& c);
  virtual ~Cure(void);
};

#endif  // CIRCLE_04_CPP_MODULE_04_EX03_CURE_HPP_
