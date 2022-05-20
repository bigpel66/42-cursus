// Copyright @bigpel66

#include "../includes/Parser.hpp"
#include "../includes/Exception.hpp"


Parser::Parser(const std::string& config)
  : _newline_count(0),
    _config(config),
    _is_brace_started(false),
    _is_loop_continuable(true) {
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

bool Parser::is_readable_then_read(char *ch) {
  return read(_fd, ch, 1) > 0;
}

bool Parser::is_empty_line(const std::string& line) const {
  for (std::string::const_iterator it = line.begin() ; it < line.end() ; it++) {
    if ((*it >= 9 && *it <= 13) || (*it == ' ')) {
      continue;
    } else {
      return false;
    }
  }
  return true;
}

std::string& Parser::trim_whitespace(std::string *line) {
  (*line).erase((*line).find_last_not_of("\t\n\v\f\r ") + 1);
  (*line).erase(0, (*line).find_first_not_of("\t\n\v\f\r "));
  return (*line);
}

std::string Parser::get_key(const std::string& line) {
  std::size_t pos = line.find(':');
  std::string key = line.substr(0, pos);
  return trim_whitespace(&key);
}

std::string Parser::get_val(const std::string& line) {
  std::size_t pos = line.find(':');
  std::string val = line.substr(pos + 1);
  return trim_whitespace(&val);
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
      break;
    }
  }
}

std::string Parser::get_current_parsing_line(void) const {
  return " on " + _config + ":" + std::to_string(_newline_count);
}

void Parser::set_worker_count(const std::string& val) {
  char *rest = ft::nullptr_t;
  _worker_count = static_cast<int>(std::strtod(val.c_str(), &rest));
  if (*rest) {
    throw ParserException("set_worker_count"
                          + get_current_parsing_line()
                          + " failed.");
  }
}

void Parser::increase_newline_count(void) {
  _newline_count++;
}

bool Parser::is_brace_openable(std::string line) {
  std::size_t pos = line.find_first_of('{');
  if (pos == std::string::npos) {
    return false;
  } else if (trim_whitespace(&line) == "{") {
    return true;
  } else {
    throw ParserException("is_brace_openable"
                          + get_current_parsing_line()
                          + " failed.");
  }
}

bool Parser::is_brace_closable(std::string line) {
  std::size_t pos = line.find_first_of('}');
  if (pos == std::string::npos) {
    return false;
  } else if (trim_whitespace(&line) == "}") {
    return true;
  } else {
    throw ParserException("is_brace_closable"
                          + get_current_parsing_line()
                          + " failed.");
  }
}

void Parser::parse_server_internal_directive(const std::string& line) {
  (void)line;
}

void Parser::parse_server_block_directive(const std::string& line) {
  if (!_is_brace_started && is_brace_openable(line)) {
    _is_brace_started = true;
  } else if (_is_brace_started && is_brace_closable(line)) {
    _is_brace_started = false;
    _is_loop_continuable = false;
  } else {
    if (!_is_brace_started) {
      throw ParserException("missing {"
                            + get_current_parsing_line());
    }
  }
}

void Parser::parse_top_directive(const std::string& line) {
  std::string key = get_key(line);
  if (key == "server") {
    parse_line(&Parser::parse_server_block_directive);
    _is_loop_continuable = true;
  } else if (key == "workers") {
    set_worker_count(get_val(line));
  } else {
    throw ParserException(key
                          + get_current_parsing_line()
                          + " is a unknown directive.");
  }
}

void Parser::case_newline(std::string *line,
                          void (Parser::*f)(const std::string& line)) {
  increase_newline_count();
  if (is_empty_line(*line)) {
    return;
  } else {
    (this->*f)(*line);
  }
  (*line).clear();
}

void Parser::parse_line(void (Parser::*f)(const std::string& line)) {
  char ch;
  std::string line;
  while (_is_loop_continuable && is_readable_then_read(&ch)) {
    std::cout << _newline_count << " ";
    if (is_comment(ch)) {
      skip_comment();
    } else if (!is_newline(ch)) {
      line.push_back(ch);
    } else {
      std::cout << line << std::endl;
      case_newline(&line, f);
    }
  }
}

void Parser::parse_config(void) {
  parse_line(&Parser::parse_top_directive);
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

