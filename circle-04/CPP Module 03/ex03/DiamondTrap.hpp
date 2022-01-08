// Copyright @bigpel66

#ifndef CIRCLE_04_CPP_MODULE_03_EX03_DIAMONDTRAP_HPP_
#define CIRCLE_04_CPP_MODULE_03_EX03_DIAMONDTRAP_HPP_

#include <string>

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#define D_NAME             "DiamondTrap"

class DiamondTrap : public FragTrap, public ScavTrap {
 private:
  std::string _name;

 public:
  void attack(const std::string& target);
  std::string getName(void) const;

  void whoAmI(void) const;

  DiamondTrap& operator=(const DiamondTrap& d);
  DiamondTrap(void);
  explicit DiamondTrap(const std::string& name);
  DiamondTrap(const DiamondTrap& d);
  virtual ~DiamondTrap(void);
};

#endif  // CIRCLE_04_CPP_MODULE_03_EX03_DIAMONDTRAP_HPP_
