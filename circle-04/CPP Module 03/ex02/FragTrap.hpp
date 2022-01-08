// Copyright @bigpel66

#ifndef CIRCLE_04_CPP_MODULE_03_EX02_FRAGTRAP_HPP_
#define CIRCLE_04_CPP_MODULE_03_EX02_FRAGTRAP_HPP_

#include <string>

#include "ClapTrap.hpp"

#define F_NAME            "FragTrap"
#define F_HP              100
#define F_EP              100
#define F_AD              30

class FragTrap : public ClapTrap {
 public:
  void hiFivesGuys(void) const;

  FragTrap& operator=(const FragTrap& f);
  FragTrap(void);
  explicit FragTrap(const std::string& name);
  FragTrap(const FragTrap& f);
  virtual ~FragTrap(void);
};

#endif  // CIRCLE_04_CPP_MODULE_03_EX02_FRAGTRAP_HPP_
