// Copyright @bigpel66

#include "PhoneBook.hpp"

int main(void) {
  PhoneBook pb;

  while (true) {
    pb.panel_cmd();
    pb.cmd_input();
    switch (pb.cmd_type()) {
      case CMD_EXIT:
        return 0;
      case CMD_ADD:
        std::cout << YELLOW
          << "Adding Contact to Phone Book..." << EOC << std::endl;
        pb.contact_add();
        break;
      case CMD_SEARCH:
        std::cout << BLUE
          << "Searching Contact to Phone Book..." << EOC << std::endl;
        pb.contact_search();
        break;
      default:
        std::cout << RED
          << "Wrong Command : " << pb.cmd_output() << EOC << std::endl;
        continue;
    }
  }
  return 0;
}
