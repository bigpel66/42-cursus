// Copyright @bigpel66

#include "../includes/Exception.hpp"

PthreadException::PthreadException(const std::string& error_message,
                                  const int error_number)
  : _error_message(error_message), _error_number(error_number) {
  if (error_number != 0) {
    size_t pos = _error_message.find_last_of('.');
    std::string separator = " ";
    if (pos == _error_message.size() - 1) {
      separator = ". ";
    }
    _error_message = _error_message + separator + get_error_message();
  }
}

PthreadException::~PthreadException(void) {}

int PthreadException::get_error_number(void) const {
  return _error_number;
}

const char *PthreadException::get_error_message(void) const {
  return strerror(get_error_number());
}

const char *PthreadException::what(void) const throw() {
  return _error_message.c_str();
}

MutexException::MutexException(const std::string& message)
  : PthreadException(message, 0) {}

MutexException::MutexException(const std::string& message, const int number)
  : PthreadException(message, number) {}

ThreadException::ThreadException(const std::string& message)
  : PthreadException(message, -1) {}

ThreadException::ThreadException(const std::string& message, const int number)
  : PthreadException(message, number) {}
