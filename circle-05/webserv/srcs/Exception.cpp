// Copyright @bigpel66

#include "../includes/Exception.hpp"

WebservException::WebservException(const std::string& error_message,
                                  const int error_number)
  : _error_message(error_message), _error_number(error_number) {
  size_t pos = _error_message.find_last_of('.');
  std::string separator = " ";
  if (pos == _error_message.size() - 1) {
    separator = ". ";
  }
  if (error_number != 0) {
    _error_message = _error_message + separator + get_error_message();
  }
}

WebservException::~WebservException(void) throw() {}

int WebservException::get_error_number(void) const {
  return _error_number;
}

const char *WebservException::get_error_message(void) const {
  return strerror(get_error_number());
}

const char *WebservException::what(void) const throw() {
  return _error_message.c_str();
}

MutexException::MutexException(const std::string& message)
  : WebservException(message, 0) {}

MutexException::MutexException(const std::string& message, const int number)
  : WebservException(message, number) {}

ThreadException::ThreadException(const std::string& message)
  : WebservException(message, 0) {}

ThreadException::ThreadException(const std::string& message, const int number)
  : WebservException(message, number) {}

ServerException::ServerException(const std::string& message)
  : WebservException(message, 0) {}

ServerException::ServerException(const std::string& message, const int number)
  : WebservException(message, number) {}

ParserException::ParserException(const std::string& message)
  : WebservException(message, 0) {}

ParserException::ParserException(const std::string& message, const int number)
  : WebservException(message, number) {}
