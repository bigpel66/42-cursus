// Copyright @bigpel66

#ifndef CIRCLE_04_CPP_MODULE_03_EX02_SCAVTRAP_HPP_
#define CIRCLE_04_CPP_MODULE_03_EX02_SCAVTRAP_HPP_

#include <string>

#include "ClapTrap.hpp"

#define S_NAME            "ScavTrap"
#define S_HP              100
#define S_EP              50
#define S_AD              20

class ScavTrap : public ClapTrap {
 public:
  void attack(const std::string& target);

  void guardGate(void) const;

  ScavTrap& operator=(const ScavTrap& s);
  ScavTrap(void);
  explicit ScavTrap(const std::string& name);
  ScavTrap(const ScavTrap& s);
  virtual ~ScavTrap(void);
};

#endif  // CIRCLE_04_CPP_MODULE_03_EX02_SCAVTRAP_HPP_
