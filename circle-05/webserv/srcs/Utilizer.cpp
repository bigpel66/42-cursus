// Copyright @bigpel66

#include "../includes/Utilizer.hpp"

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

bool operator==(const Listen& lhs, const Listen& rhs) {
  return lhs._ip == rhs._ip && lhs._port == rhs._port;
}
