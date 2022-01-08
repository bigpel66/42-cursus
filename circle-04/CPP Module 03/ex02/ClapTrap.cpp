// Copyright @bigpel66

#include "ClapTrap.hpp"

void ClapTrap::print(std::ostream& o) const {
  o << std::setw(W_SIZE + 2) << "Class Name : " << getClassName() << std::endl
  << std::setw(W_SIZE + 2) << "Class HP : " << getClassHP() << std::endl
  << std::setw(W_SIZE + 2) << "Class EP : " << getClassEP() << std::endl
  << std::setw(W_SIZE + 2) << "Class AD : " << getClassAD() << std::endl
  << std::setw(W_SIZE + 2) << "Name : " << getName() << std::endl
  << std::setw(W_SIZE + 2) << "HP : " << getHP() << std::endl
  << std::setw(W_SIZE + 2) << "EP : " << getEP() << std::endl
  << std::setw(W_SIZE + 2) << "AD : " << getAD() <<std::endl
  << std::endl;
}

void ClapTrap::attack(const std::string& target) {
  if (!_hp) {
  std::cout << "[ " << C_NAME << " ] "
    << "[ " << YELLOW << std::setw(W_SIZE) << "Not Attacked" << EOC << " ] "
    << _name << " ( Already Dead )" << std::endl;
  return;
  }
  if (!_ep) {
    std::cout << "[ " << C_NAME << " ] "
      << "[ " << YELLOW << std::setw(W_SIZE) << "Not Attacked" << EOC << " ] "
      << _name << " ( Not Enough Energy )" << std::endl;
  } else {
    --_ep;
    std::cout << "[ " << C_NAME << " ] "
      << "[ " << GREEN << std::setw(W_SIZE) << "Attacked" << EOC << " ] "
      << _name << " to " << target << std::endl;
  }
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (!_hp) {
    std::cout << "[ " << C_NAME << " ] "
      << "[ " << YELLOW << std::setw(W_SIZE) << "Not Damaged" << EOC << " ] "
      << _name << " ( Already Dead )" << std::endl;
    return;
  }
  if (_hp <= amount) {
    _hp = 0;
    std::cout << "[ " << C_NAME << " ] "
      << "[ " << RED << std::setw(W_SIZE) << "Died" << EOC << " ] ";
  } else {
    _hp -= amount;
    std::cout << "[ " << C_NAME << " ] "
      << "[ " << RED << std::setw(W_SIZE) << "Damaged" << EOC << " ] ";
  }
  std::cout << _name << " ( -" << std::setw(2) << amount << " --> "
    << std::setw(2) << _hp << " )" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (!_hp) {
    std::cout << "[ " << C_NAME << " ] "
      << "[ " << YELLOW << std::setw(W_SIZE) << "Not Reapired" << EOC << " ] "
      << _name << " ( Already Dead )" << std::endl;
    return;
  }
  if (_hp + amount > getClassHP()) {
    _hp = getClassHP();
  } else {
    _hp += amount;
  }
  std::cout << "[ " << C_NAME << " ] "
  << "[ " << GREEN << std::setw(W_SIZE) << "Repaired" << EOC << " ] "
  << _name << " ( +" << std::setw(2) << amount << " --> "
  << std::setw(2) << _hp << " )" << std::endl;
}

void ClapTrap::setName(const std::string& name) {
  _name = name;
}

void ClapTrap::setHP(unsigned int* hp) {
  _hp = *hp;
}

void ClapTrap::setEP(unsigned int* ep) {
  _ep = *ep;
}

void ClapTrap::setAD(unsigned int* ad) {
  _ad = *ad;
}

std::string ClapTrap::getName(void) const {
  return _name;
}

unsigned int ClapTrap::getHP(void) const {
  return _hp;
}

unsigned int ClapTrap::getEP(void) const {
  return _ep;
}

unsigned int ClapTrap::getAD(void) const {
  return _ad;
}

void ClapTrap::setClassName(const std::string& name) {
  *(const_cast<std::string *>(&_class_name)) = name;
}

void ClapTrap::setClassHP(const unsigned int* hp) {
  *(const_cast<unsigned int *>(&_class_hp)) = *hp;
}

void ClapTrap::setClassEP(const unsigned int* ep) {
  *(const_cast<unsigned int *>(&_class_ep)) = *ep;
}

void ClapTrap::setClassAD(const unsigned int* ad) {
  *(const_cast<unsigned int *>(&_class_ad)) = *ad;
}

std::string ClapTrap::getClassName(void) const {
  return _class_name;
}

unsigned int ClapTrap::getClassHP(void) const {
  return _class_hp;
}

unsigned int ClapTrap::getClassEP(void) const {
  return _class_ep;
}

unsigned int ClapTrap::getClassAD(void) const {
  return _class_ad;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& c) {
  if (this != &c) {
  _name = c.getName();
  _hp = c.getHP();
  _ep = c.getEP();
  _ad = c.getAD();
  }
  return *this;
}

ClapTrap::ClapTrap(void)
  : _name(C_NAME), _hp(C_HP), _ep(C_EP), _ad(C_AD),
    _class_name(C_NAME), _class_hp(C_HP), _class_ep(C_EP), _class_ad(C_AD) {
  std::cout << "[ " << C_NAME << " ]"
    << " [ login ] " << _name << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
  : _name(name), _hp(C_HP), _ep(C_EP), _ad(C_AD),
    _class_name(C_NAME), _class_hp(C_HP), _class_ep(C_EP), _class_ad(C_AD) {
  std::cout << "[ " << C_NAME << " ]"
    << " [ login ] " << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& c)
  : _name(c.getName()), _hp(c.getHP()), _ep(c.getEP()), _ad(c.getAD()),
    _class_name(C_NAME), _class_hp(C_HP), _class_ep(C_EP), _class_ad(C_AD) {
  std::cout << "[ " << C_NAME << " ]"
    << " [ login ] " << _name << std::endl;
}

ClapTrap::~ClapTrap(void) {
  std::cout << "[ " << C_NAME << " ]"
    << " [ logout ] " << _name << std::endl;
}
