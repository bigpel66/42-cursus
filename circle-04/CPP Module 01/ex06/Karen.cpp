// Copyright @bigpel66

#include "Karen.hpp"

void Karen::censored(void) {
  std::cout
    << "[ Probably complaining about insignificant problems ]"
    << std::endl << std::endl;
}
void Karen::debug(void) {
  std::cout << "[ DEBUG ]" << std::endl;
  std::cout
    << "I love to get extra bacon for my "
    << "7XL-double-cheese-triple-pickle-special-ketchup burger."
    << std::endl << "I just love it!"
    << std::endl << std::endl;
}

void Karen::info(void) {
  std::cout << "[ INFO ]" << std::endl;
  std::cout
    << "I cannot believe adding extra bacon cost more money."
    << std::endl << "You don’t put enough!"
    << std::endl << "If you did I would not have to ask for it!"
    << std::endl << std::endl;
}

void Karen::warning(void) {
  std::cout << "[ WARNING ]" << std::endl;
  std::cout
    << "I think I deserve to have some extra bacon for free."
    << std::endl << "I’ve been coming here for years and "
    << "you just started working here last month."
    << std::endl << std::endl;
}

void Karen::error(void) {
  std::cout << "[ ERROR ]" << std::endl;
  std::cout
    << "This is unacceptable, I want to speak to the manager now."
    << std::endl << std::endl;
}

void Karen::complain(std::string level) {
  int opt = 0;
  void (Karen::*f[5])(void) = { &Karen::censored,
                                &Karen::debug,
                                &Karen::info,
                                &Karen::warning,
                                &Karen::error };
  std::string message[5] = { "CENSORED", "DEBUG", "INFO", "WARNING", "ERROR" };

  for (int i = 1 ; i < 5 ; ++i)
    if (level == message[i])
      opt = i;
  switch (opt) {
    case 0:
      (this->*(f[0]))();
      break;
    case 1:
      (this->*(f[1]))();
    case 2:
      (this->*(f[2]))();
    case 3:
      (this->*(f[3]))();
    case 4:
      (this->*(f[4]))();
      break;
  }
}

Karen::Karen(void) {}

Karen::~Karen(void) {}
