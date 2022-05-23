// Copyright @bigpel66

#include "../includes/Utilizer.hpp"
#include "../includes/Server.hpp"

Listen::Listen(const std::string& ip, uint32_t port)
  : _ip(ip), _port(port) {}

Listen::Listen(const Listen& l) {
  *this = l;
}

Listen& Listen::operator=(const Listen& l) {
  if (this != &l) {
    _ip = l._ip;
    _port = l._port;
  }
  return *this;
}

Listen::~Listen(void) {}

std::ostream& operator<<(std::ostream& o, const Listen& l) {
  o << "\n\t\t\t" << l._ip << " : " << l._port;
  return o;
}

bool operator==(const Listen& lhs, const Listen& rhs) {
  return lhs._ip == rhs._ip && lhs._port == rhs._port;
}

void signal_handler(int sig) {
  (void)sig;
  write(STDOUT_FILENO, "\b\bserver interrupted by signal", 30);
  Server::set_server_alive_status(false);
}
