// Copyright @bigpel66

#ifndef CIRCLE_04_CPP_MODULE_01_EX01_ZOMBIE_HPP_
#define CIRCLE_04_CPP_MODULE_01_EX01_ZOMBIE_HPP_

#include <iostream>
#include <string>

#include "Random.hpp"

#define NB_ZOMBIE       10

class Zombie {
 private:
  std::string _name;

 public:
  static Zombie *zombieHorde(int N, std::string name);

  void announce(void) const;
  void setName(const std::string& name);
  static std::string randomName(void);

  Zombie(void);
  Zombie(const std::string& name);
  ~Zombie(void);
};

#endif  // CIRCLE_04_CPP_MODULE_01_EX01_ZOMBIE_HPP_
