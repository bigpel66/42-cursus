// Copyright @bigpel66

#include "../includes/Utilizer.hpp"

Listen::Listen(const std::string& ip, uint32_t port)
  : _ip(ip), _port(port) {}

Listen::~Listen(void) {}

bool operator==(const Listen& lhs, const Listen& rhs) {
  return lhs._ip == rhs._ip && lhs._port == rhs._port;
}
