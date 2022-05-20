// Copyright @bigpel66

// Header for the Logger to write everything in server
#ifndef CIRCLE_05_WEBSERV_INCLUDES_LOGGER_HPP_
#define CIRCLE_05_WEBSERV_INCLUDES_LOGGER_HPP_

// Standard Library Inclusion
#include <string>
#include <iostream>

// Class Headers Inclusion
#include "./Mutex.hpp"
#include "./Utilizer.hpp"

// Constant Definition
# define RESET   "\033[0m"
# define BLACK   "\033[30m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define CYAN    "\033[36m"

// Enum Log Level
enum log_level {
  DEBUG,
  INFO,
  ERROR,
  FATAL
};

class Logger {
 private:
  Mutex *_logger;
  log_level _level;

  Logger(void);
  Logger(const Logger& l);
  Logger& operator=(const Logger& l);

  bool log_available(log_level level) const;
  void log(const std::string& color, const std::string& message) const;

 public:
  explicit Logger(log_level level);
  ~Logger(void);

  void debug(const std::string& message) const;
  void info(const std::string& message) const;
  void error(const std::string& message) const;
  void fatal(const std::string& message) const;
};

#endif  // CIRCLE_05_WEBSERV_INCLUDES_LOGGER_HPP_
