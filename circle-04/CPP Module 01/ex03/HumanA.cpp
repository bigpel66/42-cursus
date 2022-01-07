// Copyright @bigpel66

#include "HumanA.hpp"

void HumanA::attack(void) const {
  std::cout << "[ " << YELLOW << _name << EOC << " ]\t\t\t"
    << YELLOW << "attacks" << EOC << " with his " << _w.getType()
    << std::endl;
}

HumanA::HumanA(const std::string& name, Weapon& w)
  : _name(name), _w(w) {
  std::cout << "[ " << YELLOW << _name << EOC << " ]\t\t\t"
    << "is " << GREEN << "respawned" << EOC << " with " << _w.getType()
    << std::endl;
}

HumanA::~HumanA(void) {
  std::cout << "[ " << YELLOW << _name << EOC << " ]\t\t\t"
    << "is " << RED << "dead" << EOC
    << std::endl;
}
