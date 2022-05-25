// Copyright @bigpel66

#include "../includes/Parser.hpp"
#include "../includes/Exception.hpp"
#include "../includes/ServContext.hpp"

Parser::Parser(const std::string& config)
  : _worker_count(1),
    _server_count(0),
    _newline_count(0),
    _config(config) {
  parse_config();
  for (ServContexts::iterator it = _serv_contexts.begin()
      ; it != _serv_contexts.end()
      ; it++) {
    std::cout << **it << std::endl;
  }
}

Parser::~Parser(void) {
  close_ifstream();
  clear_serv_contexts();
}

std::size_t Parser::get_line_of_token(Tokens::iterator it) const {
  return _lines.at(it - _tokens.begin());
}

std::string Parser::get_current_parsing_line(std::size_t line) const {
  return " on " + _config + ":" + std::to_string(line);
}

std::size_t Parser::trim_left(std::string *line) {
  std::size_t pos = (*line).find_last_not_of("\t\n\v\f\r ");
  if (pos != std::string::npos) {
    (*line).erase(pos + 1);
  }
  return pos;
}

std::size_t Parser::trim_right(std::string *line) {
  std::size_t pos = (*line).find_first_not_of("\t\n\v\f\r ");
  if (pos != std::string::npos) {
    (*line).erase(0, pos);
  }
  return pos;
}

std::string& Parser::trim_whitespace(std::string *line) {
  std::size_t left_result = trim_left(line);
  std::size_t right_result = trim_right(line);
  if (is_npos(left_result) && is_npos(right_result)) {
    *line = "";
  }
  return (*line);
}

std::string& Parser::trim_comment(std::string *line) {
  std::size_t pos = (*line).find_first_of("#");
  if (!is_npos(pos)) {
    (*line).erase(pos);
  }
  return (*line);
}

Tokens Parser::split(const std::string& line, const std::string& delimiter) {
  Tokens tokens;
  std::size_t pos;
  std::size_t offset = 0;
  while (true) {
    pos = line.find_first_of(delimiter, offset);
    if (is_npos(pos)) {
      break;
    }
    tokens.push_back(line.substr(offset, pos - offset));
    offset = line.find_first_not_of(delimiter, pos);
  }
  std::string last = line.substr(offset);
  if (is_semi_needs_split(last)) {
    last = line.substr(offset, line.find_last_not_of(";") - offset + 1);
    tokens.push_back(last);
    tokens.push_back(";");
  } else {
    tokens.push_back(last);
  }
  return tokens;
}

bool Parser::is_empty_line(const std::string& str) {
  return str == "";
}

bool Parser::is_total_semi(const std::string& str) {
  return str == ";";
}

bool Parser::is_ends_with_semi(const std::string& str) {
  return str.at(str.size() - 1) == ';';
}

bool Parser::is_left_brace(const std::string& str) {
  return str == "{";
}

bool Parser::is_right_brace(const std::string& str) {
  return str == "}";
}

bool Parser::is_only_digit(const std::string& str) {
  return Parser::is_npos(str.find_first_not_of("0123456789"));
}

bool Parser::is_npos(std::size_t pos) {
  return pos == std::string::npos;
}

bool Parser::is_config_exist(struct stat *buffer) {
  return stat(_config.c_str(), buffer) == 0;
}

bool Parser::is_config_directory(const struct stat& buffer) {
  return buffer.st_mode & S_IFDIR;
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

bool Parser::is_semi_needs_split(const std::string& str) {
  return !Parser::is_empty_line(str) &&
          !Parser::is_total_semi(str) &&
          Parser::is_ends_with_semi(str);
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

bool Parser::is_serv_context_empty(void) const {
  return _serv_contexts.empty();
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

void Parser::check_serv_context_empty(void) const {
  if (is_serv_context_empty()) {
    throw ParserException(_config + " no server config detected");
  }
}

void Parser::increase_newline_count(void) {
  _newline_count++;
}

void Parser::append_tokens(Tokens tokens) {
  for (Tokens::iterator it = tokens.begin() ; it != tokens.end() ; it++) {
    if (is_empty_line(*it)) {
      continue;
    } else if (is_left_brace(*it)) {
      _brace_checker.push(true);
    } else if (is_right_brace(*it)) {
      check_brace_matchable(&Parser::is_brace_checker_empty);
      _brace_checker.pop();
    } else if (is_valid_directive_end_with_semi(it)) {
      _directive_checker.push(true);
    } else if (is_ends_with_semi(*it)) {
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
    append_tokens(split(_content, "\t "));
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
  if (!Parser::is_only_digit(*it)) {
    throw ParserException("workers not a valid number"
                          + get_current_parsing_line(get_line_of_token(it)));
  }
  _worker_count = static_cast<std::size_t>(std::strtod(it->c_str(), ft::nil));
  if (!is_workers_in_range()) {
    throw ParserException("workers not in a valid range [1 - 8]"
                          + get_current_parsing_line(get_line_of_token(it)));
  }
}

void Parser::parse_top_directives(void) {
  for (Tokens::iterator it = _tokens.begin() ; it < _tokens.end() ; it++) {
    if (is_server_directive(it)) {
      ServContext *ptr = new ServContext(_server_count++,
                                          _lines,
                                          _tokens,
                                          _config);
      ptr->set_internal_directives(&(++it));
      _serv_contexts.push_back(ptr);
    } else if (is_workers_directive(it)) {
      parse_workers_directive(++it);
    } else if (is_total_semi(*it)) {
      continue;
    } else {
      throw ParserException("unknown directive "
                            + *it
                            + " detected"
                            + get_current_parsing_line(get_line_of_token(it)));
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
  check_serv_context_empty();
}

void Parser::clear_serv_contexts(void) {
  for (ServContexts::iterator it = _serv_contexts.begin()
      ; it != _serv_contexts.end()
      ; it++) {
    ft::safe_delete(&*it);
  }
}

const ServContexts& Parser::get_serv_contexts(void) const {
  return _serv_contexts;
}
