// Copyright @bigpel66

#ifndef CIRCLE_04_CPP_MODULE_04_EX03_MATERIASOURCE_HPP_
#define CIRCLE_04_CPP_MODULE_04_EX03_MATERIASOURCE_HPP_

#include <string>

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
 private:
  AMateria* _am[AM_SIZE];

 public:
  const AMateria* getAMateria(int idx) const;
  void learnMateria(AMateria* am);
  AMateria* createMateria(const std::string& type);

  MateriaSource& operator=(const MateriaSource& ms);
  MateriaSource(void);
  MateriaSource(const MateriaSource& ms);
  virtual ~MateriaSource(void);
};

#endif  // CIRCLE_04_CPP_MODULE_04_EX03_MATERIASOURCE_HPP_
