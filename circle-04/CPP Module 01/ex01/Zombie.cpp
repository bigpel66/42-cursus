// Copyright @bigpel66

#include "Zombie.hpp"

void Zombie::announce(void) const {
  std::cout << "<" << _name << "> BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(const std::string& name) {
  _name = name;
  announce();
}

std::string Zombie::randomName(void) {
  static std::string ch = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  std::string temp(10, '\0');
  std::string::iterator iter = temp.begin();
  std::string::iterator end = temp.end();

  while (iter != end)
    *iter++ = ch.at(static_cast<int>(Random::randr(0.0, 25.0)));
  return temp;
}

Zombie::Zombie(void) {
  std::cout << "For the Horde!!!" << std::endl;
}

Zombie::Zombie(const std::string& name)
  : _name(name) {
  announce();
}

Zombie::~Zombie(void) {
  std::cout << "<" << _name << "> Buried..." << std::endl;
}
