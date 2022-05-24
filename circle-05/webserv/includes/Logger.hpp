// Copyright @bigpel66

// Header for the Logger to write everything in server
#ifndef CIRCLE_05_WEBSERV_INCLUDES_LOGGER_HPP_
#define CIRCLE_05_WEBSERV_INCLUDES_LOGGER_HPP_

// Standard Library Inclusion
#include <string>
#include <iostream>

// Class Headers Inclusion
#include "./Utilizer.hpp"
#include "./LockGuard.hpp"

// Constant Definition
#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"

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

  time_t _time;
  struct tm _time_info;
  struct timeval _time_val;
  char _time_format_buffer[100];

  Logger(void);
  Logger(const Logger& l);
  Logger& operator=(const Logger& l);

  void print(const std::string& color, const std::string& message) const;
  void log(const std::string& color, const std::string& message);
  bool log_available(log_level level) const;

 public:
  explicit Logger(log_level level);
  ~Logger(void);

  void debug(const std::string& message);
  void info(const std::string& message);
  void error(const std::string& message);
  void fatal(const std::string& message);

  log_level get_level(void) const;
};

#endif  // CIRCLE_05_WEBSERV_INCLUDES_LOGGER_HPP_
