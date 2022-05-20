// Copyright @bigpel66

#include "../includes/Utilizer.hpp"
#include "../includes/Engine.hpp"
#include "../includes/Logger.hpp"

void print_guide(void) {
  std::cout << "to launch server, give an exact configuration file\n"
            << "e.g.) "
            << YELLOW
            << "./webserv "
            << BLACK
            << "[file.conf]\n"
            << RESET;
}

void argument_too_many(void) {
  std::cout << RED
            << "[No Configuration File]\n"
            << RESET;
  print_guide();
}

void argument_too_less(void) {
  std::cout << RED
            << "[Too Many Arguments]\n"
            << RESET;
  print_guide();
}

void run_server(const std::string& config) {
  try {
    Engine engine(config);
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
}

int main(int argc, char **argv) {
  if (argc < 2) {
    argument_too_less();
  } else if (argc > 2) {
    argument_too_many();
  } else {
    run_server(argv[1]);
  }
}
