// Copyright @bigpel66

#include "Zombie.hpp"

Zombie *Zombie::zombieHorde(int N, std::string name) {
  Zombie *z = new Zombie[N];

  for (int i = 0 ; i < N ; ++i)
    z[i].setName(name);
  return z;
}
