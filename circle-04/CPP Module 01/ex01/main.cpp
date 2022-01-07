// Copyright @bigpel66

#include "Zombie.hpp"

int main(void) {
  std::cout << "Creating a Horde of " << NB_ZOMBIE << " Zombies"
        << std::endl << std::endl;
  Zombie *z = Zombie::zombieHorde(NB_ZOMBIE, Zombie::randomName());
  std::cout << std::endl << "Burying a Horde of " << NB_ZOMBIE << " Zombies"
        << std::endl << std::endl;
  delete[] z;
  return 0;
}
