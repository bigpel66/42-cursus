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
  std::size_t _server_count;
  std::size_t _newline_count;
  std::string _config;
  std::string _content;
  std::ifstream _ifstream;

  Lines _lines;
  Tokens _tokens;
  BraceChecker _brace_checker;
  DirectiveChecker _directive_checker;
  ServerConfigs _server_configs;

  Parser(void);
  Parser(const Parser& p);
  Parser& operator=(const Parser& p);

  std::size_t get_line_of_token(Tokens::iterator it) const;
  std::string get_current_parsing_line(std::size_t line) const;
  std::string& trim_whitespace(std::string *line);
  std::string& trim_comment(std::string *line);
  Tokens tokenize(const std::string& line, const std::string& delimiter);

  bool is_semi(const std::string& str) const;
  bool is_config_exist(struct stat *buffer);
  bool is_config_directory(const struct stat& buffer);
  bool is_empty_line(Tokens::iterator it) const;
  bool is_left_brace(Tokens::iterator it) const;
  bool is_right_brace(Tokens::iterator it) const;
  bool is_containing_delimiter(Tokens::iterator it) const;
  bool is_brace_checker_empty(void) const;
  bool is_brace_checker_not_empty(void) const;
  bool is_directive_checker_empty(void) const;
  bool is_directive_checker_not_empty(void) const;
  bool is_valid_directive_end_with_semi(Tokens::iterator it) const;
  bool is_server_config_empty(void) const;
  bool is_server_directive(Tokens::iterator it) const;
  bool is_workers_in_range(void) const;
  bool is_workers_directive(Tokens::iterator it) const;

  void check_brace_matchable(bool (Parser::*f)(void) const);
  void check_directive_matchable(bool (Parser::*f)(void) const);
  void check_config_openable(void);
  void check_server_config_empty(void) const;

  void increase_newline_count(void);
  void append_tokens(Tokens tokens);
  void tokenize_config(void);
  void open_ifstream(void);
  void close_ifstream(void);
  void tokenize(void);
  void parse_workers_directive(Tokens::iterator it);
  void parse_top_directives(void);
  void parse_config(void);

 public:
  explicit Parser(const std::string& config);
  ~Parser(void);
};

#endif  // CIRCLE_05_WEBSERV_INCLUDES_PARSER_HPP_
