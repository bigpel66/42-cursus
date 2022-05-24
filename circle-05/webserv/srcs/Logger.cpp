// Copyright @bigpel66

#include "../includes/Logger.hpp"

Logger::Logger(log_level level) : _level(level) {
  _logger = new Mutex();
}

Logger::~Logger(void) {
  ft::safe_delete(_logger);
}

void Logger::print(const std::string& color, const std::string& message) const {
  std::cout << CYAN << _time_format_buffer << RESET
            << color << message << RESET
            << "\n";
}

void Logger::log(const std::string& color, const std::string& message) {
  LockGuard<Mutex> _lg(_logger);
  gettimeofday(&_time_val, ft::nil);
  _time = _time_val.tv_sec;
  localtime_r(&_time, &_time_info);
  strftime(_time_format_buffer,
          sizeof(_time_format_buffer),
          "[%Y-%m-%d %T %a] ",
          &_time_info);
  print(color, message);
}

bool Logger::log_available(log_level level) const {
  return _level <= level;
}

void Logger::debug(const std::string& message) {
  if (log_available(DEBUG)) {
    log(BLACK, message);
  }
}

void Logger::info(const std::string& message) {
  if (log_available(INFO)) {
    log(GREEN, message);
  }
}

void Logger::error(const std::string& message) {
  if (log_available(ERROR)) {
    log(YELLOW, message);
  }
}

void Logger::fatal(const std::string& message) {
  if (log_available(FATAL)) {
    log(RED, message);
  }
}

log_level Logger::get_level(void) const {
  return _level;
}
