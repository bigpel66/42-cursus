// Copyright @bigpel66

#include "../includes/Client.hpp"

Client::Client(int id, int socket) : _id(id), _socket(socket) {}

Client::~Client(void) {}

int Client::get_id(void) const {
  return _id;
}

int Client::get_socket(void) const {
  return _socket;
}

const std::string& Client::get_path(void) const {
  return _path;
}

const std::string& Client::get_content(void) const {
  return _content;
}

void Client::set_id(int id) {
  _id = id;
}

void Client::set_socket(int socket) {
  _socket = socket;
}

void Client::set_path(const std::string& path) {
  _path = path;
}

void Client::set_content(const std::string& content) {
  _content = content;
}
