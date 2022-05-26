// Copyright @bigpel66

#include "../includes/Utilizer.hpp"
#include "../includes/Server.hpp"

std::string ft::inet_ntop(void *addr) {
  std::ostringstream stream;
  stream << std::to_string(reinterpret_cast<u_char *>(addr)[0]) << "."
          << std::to_string(reinterpret_cast<u_char *>(addr)[1]) << "."
          << std::to_string(reinterpret_cast<u_char *>(addr)[2]) << "."
          << std::to_string(reinterpret_cast<u_char *>(addr)[3]);
  return stream.str();
}

void *ft::sockaddr_to_void_ptr_sockaddr_in(struct sockaddr *addr) {
  return &(reinterpret_cast<struct sockaddr_in *>(addr)->sin_addr);
}

std::size_t ft::length_on_hex(const std::string& str) {
  std::stringstream ss;
  std::size_t hex_length;
  ss << std::hex << str;
  ss >> hex_length;
  return hex_length;
}

Listen::Listen(void)
  : _ip(""), _port(0) {}

Listen::Listen(const std::string& ip, std::uint32_t port)
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

const std::string& Listen::get_ip(void) const {
  return _ip;
}

std::uint32_t Listen::get_port(void) const {
  return _port;
}

std::ostream& operator<<(std::ostream& o, const Listen& l) {
  o << "\n\t\t\t" << l._ip << " : " << l._port;
  return o;
}

bool operator==(const Listen& lhs, const Listen& rhs) {
  return lhs._ip == rhs._ip && lhs._port == rhs._port;
}
