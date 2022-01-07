// Copyright @bigpel66

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void) {
  {
    Weapon club = Weapon("Crude Spiked Club");
    HumanA bob("Bob", &club);

    bob.attack();
    club.setType("Some other type of Club");
    bob.attack();
  }
  {
    Weapon club = Weapon("Crude Spiked Club");
    HumanB jim("Jim");

    jim.setWeapon(&club);
    jim.attack();
    club.setType("Some other type of Club");
    jim.attack();
  }
  return 0;
}
