// Copyright @bigpel66

#ifndef CIRCLE_04_CPP_MODULE_04_EX03_IMATERIASOURCE_HPP_
#define CIRCLE_04_CPP_MODULE_04_EX03_IMATERIASOURCE_HPP_

#include <string>

#include "AMateria.hpp"

class IMateriaSource {
 public:
  virtual void learnMateria(AMateria* am) = 0;
  virtual AMateria* createMateria(const std::string& type) = 0;

  virtual ~IMateriaSource(void) {}
};

#endif  // CIRCLE_04_CPP_MODULE_04_EX03_IMATERIASOURCE_HPP_
