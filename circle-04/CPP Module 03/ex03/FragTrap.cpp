// Copyright @bigpel66

#include "FragTrap.hpp"

void FragTrap::hiFivesGuys(void) const {
  std::cout << "[ " << F_NAME << " ] "
    << "[ " << GREEN << std::setw(W_SIZE) << "Buff Scream" << EOC << " ] "
    << _name << " ( Hi Fives !!! )" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &f) {
  if (this != &f) {
    _name = f.getName();
    _hp = f.getHP();
    _ep = f.getEP();
    _ad = f.getAD();
  }
  return *this;
}

FragTrap::FragTrap(void)
  : ClapTrap(F_NAME) {
  *(const_cast<std::string *>(&_class_name)) = F_NAME;
  *(const_cast<unsigned int *>(&_class_hp)) = F_HP;
  *(const_cast<unsigned int *>(&_class_ep)) = F_EP;
  *(const_cast<unsigned int *>(&_class_ad)) = F_AD;
  _hp = _class_hp;
  _ep = _class_ep;
  _ad = _class_ad;
  std::cout << "[ " << F_NAME << " ]"
    << " [ login ] " << _name << std::endl;
}

FragTrap::FragTrap(const std::string& name)
  : ClapTrap(name) {
  *(const_cast<std::string *>(&_class_name)) = F_NAME;
  *(const_cast<unsigned int *>(&_class_hp)) = F_HP;
  *(const_cast<unsigned int *>(&_class_ep)) = F_EP;
  *(const_cast<unsigned int *>(&_class_ad)) = F_AD;
  _hp = _class_hp;
  _ep = _class_ep;
  _ad = _class_ad;
  std::cout << "[ " << F_NAME << " ]"
    << " [ login ] " << _name << std::endl;
}

FragTrap::FragTrap(const FragTrap& f) {
  *(const_cast<std::string *>(&_class_name)) = F_NAME;
  *(const_cast<unsigned int *>(&_class_hp)) = F_HP;
  *(const_cast<unsigned int *>(&_class_ep)) = F_EP;
  *(const_cast<unsigned int *>(&_class_ad)) = F_AD;
  _name = f.getName();
  _hp = f.getHP();
  _ep = f.getEP();
  _ad = f.getAD();
  std::cout << "[ " << F_NAME << " ]"
    << " [ login ] " << _name << std::endl;
}

FragTrap::~FragTrap(void) {
  std::cout << "[ " << F_NAME << " ]"
    << " [ logout ] " << _name << std::endl;
  *(const_cast<std::string *>(&_class_name)) = C_NAME;
}
