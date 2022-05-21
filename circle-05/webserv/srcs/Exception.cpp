// Copyright @bigpel66

#include "../includes/Exception.hpp"

WebservException::WebservException(const std::string& error_message,
                                  const int error_number)
  : _error_message(error_message), _error_number(error_number) {
  if (error_number != 0) {
    _error_message = _error_message + " (" + get_error_message() + ")";
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

MutexException::MutexException(const std::string& m)
  : WebservException(m, 0) {}

MutexException::MutexException(const std::string& m, const int n)
  : WebservException(m, n) {}

ThreadException::ThreadException(const std::string& m)
  : WebservException(m, 0) {}

ThreadException::ThreadException(const std::string& m, const int n)
  : WebservException(m, n) {}

EngineException::EngineException(const std::string& m)
  : WebservException(m, 0) {}

EngineException::EngineException(const std::string& m, const int n)
  : WebservException(m, n) {}

ParserException::ParserException(const std::string& m)
  : WebservException(m, 0) {}

ParserException::ParserException(const std::string& m, const int n)
  : WebservException(m, n) {}

ConfigException::ConfigException(const std::string& m)
  : WebservException(m, 0) {}

ConfigException::ConfigException(const std::string& m, const int n)
  : WebservException(m, n) {}

ServerException::ServerException(const std::string& m)
  : WebservException(m, 0) {}

ServerException::ServerException(const std::string& m, const int n)
  : WebservException(m, n) {}
