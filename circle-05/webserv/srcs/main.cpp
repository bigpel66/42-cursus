// Copyright @bigpel66

#include "../includes/Utilizer.h"
#include "../includes/Engine.hpp"

void print_usage_guide(void) {
  std::cout << "[No Configuration File] "
            << "to launch server, give an exact configuration file\n"
            << "e.g.) ./webserv [file.conf]\n";
}

void print_argument_error(void) {
  std::cout << "[Too Many Arguments] "
            << "to launch server, give an configuration file\n"
            << "e.g.) ./webserv [file.conf]\n";
}

void run_server(const std::string& config) {
  std::cout << config;
}

int main(int argc, char **argv) {
  if (argc < 2) {
    print_usage_guide();
  } else if (argc > 2) {
    print_argument_error();
  } else {
    run_server(argv[1]);
  }
  return 0;
}
