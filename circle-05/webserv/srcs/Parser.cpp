// Copyright @bigpel66

#include "../includes/Parser.hpp"
#include "../includes/Exception.hpp"
#include "../includes/ServerConfig.hpp"

Parser::Parser(const std::string& config)
  : _worker_count(0),
    _server_count(0),
    _newline_count(0),
    _config(config) {
  parse_config();
}

Parser::~Parser(void) {
  close_ifstream();
  clear_server_configs();
}

std::size_t Parser::get_line_of_token(Tokens::iterator it) const {
  return _lines.at(it - _tokens.begin());
}

std::string Parser::get_current_parsing_line(std::size_t line) const {
  return " on " + _config + ":" + std::to_string(line);
}

std::string& Parser::trim_whitespace(std::string *line) {
  std::size_t pos;
  pos = (*line).find_last_not_of("\t\n\v\f\r ");
  if (pos != std::string::npos) {
    (*line).erase(pos + 1);
  }
  pos = (*line).find_first_not_of("\t\n\v\f\r ");
  if (pos != std::string::npos) {
    (*line).erase(0, pos);
  }
  return (*line);
}

std::string& Parser::trim_comment(std::string *line) {
  std::size_t pos = (*line).find_first_of("#");
  if (pos != std::string::npos) {
    (*line).erase(pos);
  }
  return (*line);
}

Tokens Parser::tokenize(const std::string& line, const std::string& delimiter) {
  std::size_t pos;
  std::size_t offset = 0;
  Tokens tokens;
  while (true) {
    pos = line.find_first_of(delimiter, offset);
    if (pos == std::string::npos) {
      break;
    }
    tokens.push_back(line.substr(offset, pos - offset));
    offset = line.find_first_not_of(delimiter, pos);
  }
  tokens.push_back(line.substr(offset));
  return tokens;
}

bool Parser::is_semi(const std::string& str) const {
  return str == ";";
}

bool Parser::is_config_exist(struct stat *buffer) {
  return stat(_config.c_str(), buffer) == 0;
}

bool Parser::is_config_directory(const struct stat& buffer) {
  return buffer.st_mode & S_IFDIR;
}

bool Parser::is_empty_line(Tokens::iterator it) const {
  return *it == "";
}

bool Parser::is_left_brace(Tokens::iterator it) {
  return *it == "{";
}

bool Parser::is_right_brace(Tokens::iterator it) {
  return *it == "}";
}

bool Parser::is_containing_delimiter(Tokens::iterator it) const {
  return it->at(it->size() - 1) == ';';
}

bool Parser::is_brace_checker_empty(void) const {
  return _brace_checker.empty();
}

bool Parser::is_brace_checker_not_empty(void) const {
  return !_brace_checker.empty();
}

bool Parser::is_directive_checker_empty(void) const {
  return _directive_checker.empty();
}

bool Parser::is_directive_checker_not_empty(void) const {
  return !_directive_checker.empty();
}

bool Parser::is_valid_directive_end_with_semi(Tokens::iterator it) const {
  return *it == "listen" ||
          *it == "server_name" ||
          *it == "root" ||
          *it == "auth" ||
          *it == "error_page" ||
          *it == "upload" ||
          *it == "autoindex" ||
          *it == "index" ||
          *it == "cgi" ||
          *it == "cgi_bin" ||
          *it == "limit_except" ||
          *it == "workers" ||
          *it == "client_max_body_size";
}

bool Parser::is_server_config_empty(void) const {
  return _server_configs.empty();
}

bool Parser::is_server_directive(Tokens::iterator it) const {
  return *it == "server";
}

bool Parser::is_workers_in_range(void) const {
  return _worker_count >= MINIMUM_WORKER_COUNT &&
          _worker_count <= MAXIMUM_WORKER_COUNT;
}

bool Parser::is_workers_directive(Tokens::iterator it) const {
  return *it == "workers";
}

void Parser::check_brace_matchable(bool (Parser::*f)(void) const) {
  if ((this->*f)()) {
    throw ParserException("brace not matched"
                          + get_current_parsing_line(_newline_count));
  }
}

void Parser::check_directive_matchable(bool (Parser::*f)(void) const) {
  if ((this->*f)()) {
    throw ParserException("directive not matched"
                          + get_current_parsing_line(_newline_count));
  }
}

void Parser::check_config_openable(void) {
  struct stat buffer;
  if (!is_config_exist(&buffer)) {
    throw ParserException(_config + " cannot open file");
  } else if (is_config_directory(buffer)) {
    throw ParserException(_config + " is a directory");
  }
}

void Parser::check_server_config_empty(void) const {
  if (is_server_config_empty()) {
    throw ParserException(_config + " no server config detected");
  }
}

void Parser::increase_newline_count(void) {
  _newline_count++;
}

void Parser::append_tokens(Tokens tokens) {
  for (Tokens::iterator it = tokens.begin() ; it != tokens.end() ; it++) {
    if (is_empty_line(it)) {
      continue;
    } else if (is_left_brace(it)) {
      _brace_checker.push(true);
    } else if (is_right_brace(it)) {
      check_brace_matchable(&Parser::is_brace_checker_empty);
      _brace_checker.pop();
    } else if (is_valid_directive_end_with_semi(it)) {
      _directive_checker.push(true);
    } else if (is_containing_delimiter(it)) {
      check_directive_matchable(&Parser::is_directive_checker_empty);
      _directive_checker.pop();
    }
    _tokens.push_back(*it);
    _lines.push_back(_newline_count);
  }
}

void Parser::tokenize_config(void) {
  while (std::getline(_ifstream, _content)) {
    increase_newline_count();
    trim_comment(&_content);
    trim_whitespace(&_content);
    append_tokens(tokenize(_content, "\t "));
    check_directive_matchable(&Parser::is_directive_checker_not_empty);
  }
}

void Parser::open_ifstream(void) {
  _ifstream.open(_config, std::ifstream::in);
  if (!_ifstream.good()) {
    throw ParserException(_config + " failed to open");
  }
}

void Parser::close_ifstream(void) {
  _ifstream.close();
}

void Parser::parse_workers_directive(Tokens::iterator it) {
  char *rest = ft::nullptr_t;
  _worker_count = static_cast<std::size_t>(std::strtod(it->c_str(), &rest));
  if (!is_semi(rest)) {
    throw ParserException("workers not a valid number"
                          + get_current_parsing_line(get_line_of_token(it)));
  }
  if (!is_workers_in_range()) {
    throw ParserException("workers not in a valid range [1 - 8]"
                          + get_current_parsing_line(get_line_of_token(it)));
  }
}

void Parser::parse_top_directives(void) {
  for (Tokens::iterator it = _tokens.begin() ; it < _tokens.end() ; it++) {
    if (is_server_directive(it)) {
      ServerConfig *ptr = new ServerConfig(_server_count++,
                                          _lines,
                                          _tokens,
                                          _config);
      ptr->set_internal_directives(&(++it));
      _server_configs.push_back(ptr);
    } else if (is_workers_directive(it)) {
      parse_workers_directive(++it);
    } else {
      throw ParserException(_config
                            + " unknown directive "
                            + *it
                            + " detected");
    }
  }
}

void Parser::tokenize(void) {
  check_config_openable();
  open_ifstream();
  tokenize_config();
  close_ifstream();
  check_brace_matchable(&Parser::is_brace_checker_not_empty);
}

void Parser::parse_config(void) {
  tokenize();
  parse_top_directives();
  check_server_config_empty();
}

void Parser::clear_server_configs(void) {
  for (ServerConfigs::iterator it = _server_configs.begin()
      ; it != _server_configs.end()
      ; it++) {
    if (*it) {
      delete *it;
    }
  }
}
