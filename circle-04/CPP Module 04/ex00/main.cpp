// Copyright @bigpel66

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

void test_animal(void) {
  const Animal* meta = new Animal();
  const Animal* i = new Cat();
  const Animal* j = new Dog();

  std::cout << std::endl;
  meta->makeSound();
  i->makeSound();
  j->makeSound();
  std::cout << std::endl;

  std::cout << std::endl;
  std::cout << *meta << *i << *j;
  std::cout << std::endl;

  std::cout << std::endl;
  delete j;
  delete i;
  delete meta;
}

void test_wrong(void) {
  const WrongAnimal* meta = new WrongAnimal();
  const WrongAnimal* i = new WrongCat();

  std::cout << std::endl;
  meta->makeSound();
  i->makeSound();
  std::cout << std::endl;

  std::cout << std::endl;
  std::cout << *meta << *i;
  std::cout << std::endl;

  std::cout << std::endl;
  delete i;
  delete meta;
}

int main(void) {
  std::cout << std::setfill('=') << std::setw(50) << "\n" << std::setfill(' ');
  test_animal();
  std::cout << std::setfill('=') << std::setw(50) << "\n" << std::setfill(' ');
  test_wrong();
  std::cout << std::setfill('=') << std::setw(50) << "\n" << std::setfill(' ');
  return 0;
}
