// Copyright @bigpel66

#include "../includes/Logger.hpp"

Logger::Logger(void) {
  _logger = new Mutex();
}

Logger::~Logger(void) {
  ft::safe_delete(&_logger);
}

void Logger::print(const std::string& color, const std::string& message) const {
  std::cout << CYAN << _time_format_buffer << RESET
            << color << message << RESET
            << "\n";
}

void Logger::log(const std::string& color, const std::string& message) {
  LockGuard<Mutex> _lg(_logger);
  time(&_time);
  _time_info = localtime(&_time);
  strftime(_time_format_buffer,
          sizeof(_time_format_buffer),
          "[%Y-%m-%d %T %a] ",
          _time_info);
  print(color, message);
}


void Logger::debug(const std::string& message) {
  log(BLACK, message);
}

void Logger::info(const std::string& message) {
  log(GREEN, message);
}

void Logger::error(const std::string& message) {
  log(YELLOW, message);
}

void Logger::fatal(const std::string& message) {
  log(RED, message);
}
