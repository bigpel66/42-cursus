// Copyright @bigpel66

#ifndef CIRCLE_04_CPP_MODULE_01_EX03_HUMANA_HPP_
#define CIRCLE_04_CPP_MODULE_01_EX03_HUMANA_HPP_

#include <string>

#include "Weapon.hpp"

class HumanA {
 private:
  std::string _name;
  Weapon &_w;

 public:
  void attack(void) const;

  HumanA(const std::string& name, Weapon &w);
  ~HumanA(void);
};

#endif  // CIRCLE_04_CPP_MODULE_01_EX03_HUMANA_HPP_
