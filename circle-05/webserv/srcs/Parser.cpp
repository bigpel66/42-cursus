// Copyright @bigpel66

#include "../includes/Parser.hpp"
#include "../includes/Exception.hpp"

Parser::Parser(const std::string& config)
  : _worker_count(0),
    _newline_count(0),
    _config(config) {
  check_config_openable();
  parse_config();
  check_brace_matchable(&Parser::is_brace_checker_not_empty);
}

Parser::~Parser(void) {
  close_ifstream();
}

std::string Parser::get_current_parsing_line(void) const {
  return " on " + _config + ":" + std::to_string(_newline_count);
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

bool Parser::is_config_exist(struct stat *buffer) {
  return stat(_config.c_str(), buffer) == 0;
}

bool Parser::is_config_directory(const struct stat& buffer) {
  return buffer.st_mode & S_IFDIR;
}

bool Parser::is_left_brace(Tokens::iterator it) const {
  return *it == "{";
}

bool Parser::is_right_brace(Tokens::iterator it) const {
  return *it == "}";
}

bool Parser::is_brace_checker_empty(void) const {
  return _brace_checker.empty();
}

bool Parser::is_brace_checker_not_empty(void) const {
  return !_brace_checker.empty();
}

void Parser::check_brace_matchable(bool (Parser::*f)(void) const) {
  if ((this->*f)()) {
    throw ParserException("brace not matched" + get_current_parsing_line());
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

void Parser::append_tokens(Tokens tokens) {
  Tokens::iterator bit = tokens.begin();
  Tokens::iterator eit = tokens.end();
  while (bit != eit) {
    if (is_left_brace(bit)) {
      _brace_checker.push(true);
    } else if (is_right_brace(bit)) {
      check_brace_matchable(&Parser::is_brace_checker_empty);
      std::cout << "as1111111" << std::endl;
      _brace_checker.pop();
    }
    std::cout << *bit << std::endl;
    _tokens.push_back(*bit++);
  }
}

void Parser::tokenize_config(void) {
  while (std::getline(_ifstream, _content)) {
    increase_newline_count();
    trim_comment(&_content);
    trim_whitespace(&_content);
    append_tokens(tokenize(_content, "\t "));
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

void Parser::parse_config(void) {
  open_ifstream();
  tokenize_config();
  close_ifstream();
}

void Parser::increase_newline_count(void) {
  _newline_count++;
}
