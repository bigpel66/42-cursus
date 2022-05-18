// Copyright @bigpel66

// Header for the parser of configuration file
#ifndef CIRCLE_05_WEBSERV_INCLUDES_PARSER_HPP_
#define CIRCLE_05_WEBSERV_INCLUDES_PARSER_HPP_

// Standard Library Inclusion
#include <string>

class Parser {
 private:
  std::string _config;

  Parser(void);
  Parser(const Parser& p);
  Parser& operator=(const Parser& p);

 public:
  explicit Parser(const std::string& config);
  ~Parser(void);
};

#endif  // CIRCLE_05_WEBSERV_INCLUDES_PARSER_HPP_
