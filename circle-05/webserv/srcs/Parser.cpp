// Copyright @bigpel66

#include "../includes/Parser.hpp"
#include "../includes/Exception.hpp"


Parser::Parser(const std::string& config) : _config(config) {
  is_directory();
  close_config();
  is_openable();

}

Parser::~Parser(void) {}

void Parser::close_config(void) const {
  close(_fd);
}

void Parser::is_directory(void) {
  _fd = open(_config.c_str(), O_RDONLY | O_DIRECTORY | O_NONBLOCK);
  if (_fd != -1) {
    throw ParserException(_config + " is a directory.");
  }
}

void Parser::is_openable(void) {
  _fd = open(_config.c_str(), O_RDONLY | O_NONBLOCK);
  if (_fd < 3) {
    throw ParserException(_config + " cannot open file.");
  }
}

t_server_info Parser::get_server_info_at(std::size_t index) const {
  (void)index;
  return t_server_info();
}

std::size_t Parser::get_server_size(void) const {
  return 0;
}

std::size_t Parser::get_worker_size(void) const {
  return 0;
}

