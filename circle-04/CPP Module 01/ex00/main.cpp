// Copyright @bigpel66

#include "Zombie.hpp"

int main(void) {
  Zombie *z[NB_ZOMBIE];

  std::cout << "Creating " << NB_ZOMBIE << " Random Heap Zombies"
    << std::endl << std::endl;
  for (int i = 0 ; i < NB_ZOMBIE ; ++i)
    z[i] = Zombie::newZombie(Zombie::randomName());
  std::cout << std::endl << "Creating " << NB_ZOMBIE << " Random Stack Zombies"
    << std::endl << std::endl;
  for (int i = 0 ; i < NB_ZOMBIE ; ++i)
    Zombie::randomChump(Zombie::randomName());
  std::cout << std::endl << "Burying " << NB_ZOMBIE << " Random Heap Zombies"
    << std::endl << std::endl;
  for (int i = 0 ; i < NB_ZOMBIE ; ++i)
    delete z[i];
  return 0;
}
