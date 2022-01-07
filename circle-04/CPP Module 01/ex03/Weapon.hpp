// Copyright @bigpel66

#ifndef CIRCLE_04_CPP_MODULE_01_EX03_WEAPON_HPP_
#define CIRCLE_04_CPP_MODULE_01_EX03_WEAPON_HPP_

#include <iostream>
#include <string>

#define RED           "\033[0;31m"
#define YELLOW        "\033[1;33m"
#define GREEN         "\033[0;32m"
#define BLUE          "\033[0;34m"
#define EOC           "\033[0;0m"

class Weapon {
 private:
  std::string _type;

  Weapon(void);

 public:
  const std::string &getType(void) const;
  void setType(const std::string& type);

  explicit Weapon(const std::string& type);
  ~Weapon(void);
};

#endif  // CIRCLE_04_CPP_MODULE_01_EX03_WEAPON_HPP_
