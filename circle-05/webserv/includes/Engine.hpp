// Copyright @bigpel66

// Header for the main engine of webserv
#ifndef CIRCLE_05_WEBSERV_INCLUDES_ENGINE_HPP_
#define CIRCLE_05_WEBSERV_INCLUDES_ENGINE_HPP_

// Standard Library Inclusion
#include <string>
#include <iostream>

// Class Headers Inclusion
#include "./Mimes.hpp"
#include "./Logger.hpp"
#include "./Parser.hpp"
#include "./Utilizer.hpp"
#include "./Exception.hpp"
#include "./Server.hpp"

// Engine of Webserv
class Engine {
 private:
  int _i;
  int _argc;
  char **_argv;

  Mimes _mimes;

  Options _options;

  Parser *_parser;


  Engine(void);
  Engine(const Engine& e);
  Engine& operator=(const Engine& e);

  std::string guide(void);

  void increase_index(void);
  void init_logger(const std::string& arg);
  void init_options(void);
  void parse_other_option(void);
  void parse_argument(void);
  void print_guide_and_exit(void);

  bool is_log_option(void);
  bool is_other_option(void);
  bool is_option_available(const std::string& option) const;
  bool is_too_many_argument(void) const;
  bool is_help_option_on(void) const;
  bool is_logger_not_ready(void) const;

 public:
  Engine(int argc, char **argv);
  ~Engine(void);

  void launch(void);

  static Logger *logger;
  static Mimes mimes;
  static StatusCodes status_codes;
};

#endif  // CIRCLE_05_WEBSERV_INCLUDES_ENGINE_HPP_
