// Copyright @bigpel66

// Header for the parser of configuration file
#ifndef CIRCLE_05_WEBSERV_INCLUDES_PARSER_HPP_
#define CIRCLE_05_WEBSERV_INCLUDES_PARSER_HPP_

// Standard Library Inclusion
#include <string>
#include <fstream>
#include <iostream>

// Class Headers Inclusion
#include "./Utilizer.hpp"

class Parser {
 private:
  std::size_t _worker_count;
  std::size_t _newline_count;
  std::string _config;
  std::string _content;
  std::ifstream _ifstream;

  Tokens _tokens;
  BraceChecker _brace_checker;
  ServerConfigs _server_configs;

  Parser(void);
  Parser(const Parser& p);
  Parser& operator=(const Parser& p);

  std::string get_current_parsing_line(void) const;
  std::string& trim_whitespace(std::string *line);
  std::string& trim_comment(std::string *line);
  Tokens tokenize(const std::string& line, const std::string& delimiter);

  bool is_config_exist(struct stat *buffer);
  bool is_config_directory(const struct stat& buffer);
  bool is_left_brace(Tokens::iterator it) const;
  bool is_right_brace(Tokens::iterator it) const;
  bool is_brace_checker_empty(void) const;
  bool is_brace_checker_not_empty(void) const;

  void check_brace_matchable(bool (Parser::*f)(void) const);
  void check_config_openable(void);
  void append_tokens(Tokens tokens);
  void tokenize_config(void);
  void open_ifstream(void);
  void close_ifstream(void);
  void parse_config(void);
  void increase_newline_count(void);

 public:
  explicit Parser(const std::string& config);
  ~Parser(void);
};

#endif  // CIRCLE_05_WEBSERV_INCLUDES_PARSER_HPP_
