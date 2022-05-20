// Copyright @bigpel66

#include "../includes/Logger.hpp"

Logger::Logger(log_level level) : _level(level) {
  _logger = new Mutex();
}

Logger::~Logger(void) {
  delete _logger;
}

void Logger::log(const std::string& color, const std::string& message) const {
  time_t time;
  char buffer[100];
  struct timeval tv;
  struct tm time_info;
  _logger->lock();
  gettimeofday(&tv, ft::nullptr_t);
  time = tv.tv_sec;
  localtime_r(&time, &time_info);
  strftime(buffer, sizeof(buffer), "[%Y-%m-%d %T %a] ", &time_info);
  std::cout << CYAN << buffer << RESET
            << color << message << RESET
            << "\n";
  _logger->unlock();
}

bool Logger::log_available(log_level level) const {
  return _level <= level;
}

void Logger::debug(const std::string& message) const {
  if (log_available(DEBUG)) {
    log(BLACK, message);
  }
}

void Logger::info(const std::string& message) const {
  if (log_available(INFO)) {
    log(GREEN, message);
  }
}

void Logger::error(const std::string& message) const {
  if (log_available(ERROR)) {
    log(YELLOW, message);
  }
}

void Logger::fatal(const std::string& message) const {
  if (log_available(FATAL)) {
    log(RED, message);
  }
}
