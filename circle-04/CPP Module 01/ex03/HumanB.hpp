// Copyright @bigpel66

#ifndef CIRCLE_04_CPP_MODULE_01_EX03_HUMANB_HPP_
#define CIRCLE_04_CPP_MODULE_01_EX03_HUMANB_HPP_

#include <string>

#include "Weapon.hpp"

class HumanB {
 private:
  std::string _name;
  Weapon *_w;

  HumanB(void);

 public:
  void setWeapon(Weapon &w);
  void attack(void) const;

  HumanB(const std::string& name);
  ~HumanB(void);
};

#endif  // CIRCLE_04_CPP_MODULE_01_EX03_HUMANB_HPP_
