// Copyright @bigpel66

#include "../includes/Parser.hpp"
#include "../includes/Exception.hpp"


Parser::Parser(const std::string& config)
  : _newline_count(0), _config(config) {
  is_directory_then_open();
  close_config();
  is_openable_then_open();
  parse_config();
  close_config();
}

Parser::~Parser(void) {}

void Parser::close_config(void) const {
  close(_fd);
}

bool Parser::is_empty_line(const std::string& line) const {
  for (std::string::const_iterator it = line.begin() ; it < line.end() ; it++) {
    if ((*it >= 9 && *it <= 13) || (*it == ' ')) {
      continue ;
    } else {
      return false;
    }
  }
  return true;
}

std::string& Parser::trim_whitespace(std::string& line) {
  line.erase(line.find_last_not_of("\t\n\v\f\r ") + 1);
  line.erase(0, line.find_first_not_of("\t\n\v\f\r "));
  return line;
}

std::string Parser::get_key(const std::string& line) {
  std::string key;
  for (std::string::const_iterator it = line.begin() ; it != line.end() ; it++) {
    if (*it == ':') {
      break ;
    }
    key.push_back(*it);
  }
  return trim_whitespace(key);
}

bool Parser::is_comment(char ch) const {
  return ch == '#';
}

bool Parser::is_newline(char ch) const {
  return ch == '\n';
}

void Parser::skip_comment(void) const {
  int result;
  char ch;
  while ((result = read(_fd, &ch, 1)) > 0) {
    if (is_newline(ch)) {
      break ;
    }
  }
}

void Parser::increase_newline_count(void) {
  _newline_count++;
}

void Parser::parse_top_directive(const std::string& key) {
  if (key == "server") {
    std::cout << "this is server" << std::endl;
  } else if (key == "workers") {
    std::cout << "this is workers" << std::endl;
  } else {
    throw ParserException(key
                          + " on "
                          + _config
                          + ":"
                          + std::to_string(_newline_count)
                          + " is a unknown directive.");
  }
}

void Parser::case_newline(std::string& line) {
  std::string key = get_key(line);
  increase_newline_count();
  if (is_empty_line(line)) {
    return ;
  } else {
    parse_top_directive(key);
  }
  line.clear();
}

void Parser::parse_config(void) {
  char ch;
  int result;
  std::string line;
  while ((result = read(_fd, &ch, 1)) > 0) {
    if (is_comment(ch)) {
      skip_comment();
    } else if (!is_newline(ch)) {
      line.push_back(ch);
    } else {
      case_newline(line);
    }
  }
}

void Parser::is_directory_then_open(void) {
  _fd = open(_config.c_str(), O_RDONLY | O_DIRECTORY | O_NONBLOCK);
  if (_fd != -1) {
    throw ParserException(_config + " is a directory.");
  }
}

void Parser::is_openable_then_open(void) {
  _fd = open(_config.c_str(), O_RDONLY | O_NONBLOCK);
  if (_fd < 3) {
    throw ParserException(_config + " cannot open file.");
  }
}

t_server_info Parser::get_server_info_at(std::size_t index) const {
  return _server_infos.at(index);
}

std::size_t Parser::get_server_size(void) const {
  return _server_infos.size();
}

std::size_t Parser::get_worker_size(void) const {
  return _worker_count;
}

