// Copyright @bigpel66

#ifndef CIRCLE_04_CPP_MODULE_01_EX00_ZOMBIE_HPP_
#define CIRCLE_04_CPP_MODULE_01_EX00_ZOMBIE_HPP_

#include <iostream>
#include <string>

#include "Random.hpp"

#define NB_ZOMBIE       10

class Zombie {
 private:
  std::string _name;

  Zombie(void);

 public:
  static Zombie *newZombie(std::string name);
  static void randomChump(std::string name);

  void announce(void) const;
  static std::string randomName(void);

  explicit Zombie(const std::string& name);
  ~Zombie(void);
};

#endif  // CIRCLE_04_CPP_MODULE_01_EX00_ZOMBIE_HPP_
