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
  ServContexts _serv_contexts;

  Parser(void);
  Parser(const Parser& p);
  Parser& operator=(const Parser& p);

  std::size_t get_line_of_token(Tokens::iterator it) const;
  std::string get_current_parsing_line(std::size_t line) const;
  std::string& trim_comment(std::string *line);
  Tokens split(const std::string& line, const std::string& delimiter);

  bool is_brace_checker_empty(void) const;
  bool is_brace_checker_not_empty(void) const;
  bool is_directive_checker_empty(void) const;
  bool is_directive_checker_not_empty(void) const;
  bool is_semi_needs_split(const std::string& str);
  bool is_valid_directive_end_with_semi(Tokens::iterator it) const;
  bool is_serv_context_empty(void) const;
  bool is_server_directive(Tokens::iterator it) const;
  bool is_workers_in_range(void) const;
  bool is_workers_directive(Tokens::iterator it) const;

  void check_brace_matchable(bool (Parser::*f)(void) const);
  void check_directive_matchable(bool (Parser::*f)(void) const);
  void check_config_openable(void);
  void check_serv_context_empty(void) const;

  void increase_newline_count(void);
  void append_tokens(Tokens tokens);
  void tokenize_config(void);
  void open_ifstream(void);
  void close_ifstream(void);
  void tokenize(void);
  void parse_workers_directive(Tokens::iterator it);
  void parse_top_directives(void);
  void parse_config(void);

  void clear_serv_contexts(void);

 public:
  explicit Parser(const std::string& config);
  ~Parser(void);

  static bool is_empty_line(const std::string& str);
  static bool is_total_semi(const std::string& str);
  static bool is_ends_with_semi(const std::string& str);
  static bool is_left_brace(const std::string& str);
  static bool is_right_brace(const std::string& str);
  static bool is_only_digit(const std::string& str);
  static bool is_npos(std::size_t pos);
  static std::size_t trim_left(std::string *line);
  static std::size_t trim_right(std::string *line);
  static std::string& trim_whitespace(std::string *line);

  ServContexts *get_serv_contexts(void);
  std::size_t get_worker_count(void) const;
};

#endif  // CIRCLE_05_WEBSERV_INCLUDES_PARSER_HPP_
