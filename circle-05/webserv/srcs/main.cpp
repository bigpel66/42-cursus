// Copyright @bigpel66

#include "../includes/Engine.hpp"

int main(int argc, char **argv) {
  try {
    Engine engine(argc, argv);
    engine.launch();
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  exit(1);
}
