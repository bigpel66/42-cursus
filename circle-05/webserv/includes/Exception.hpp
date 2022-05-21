// Copyright @bigpel66

// Header for the exceptions to throw and stack unwind
#ifndef CIRCLE_05_WEBSERV_INCLUDES_EXCEPTION_HPP_
#define CIRCLE_05_WEBSERV_INCLUDES_EXCEPTION_HPP_

// Standard Library Inclusion
#include <exception>
#include <string>
#include <cstring>

// WebservException is the base Exception class for Pthread
class WebservException : public std::exception {
 private:
  std::string _error_message;
  int _error_number;

  // Prevent to call directly
  WebservException(void);
  WebservException& operator=(const WebservException& t);

 public:
  WebservException(const std::string& error_message, const int error_number);
  WebservException(const WebservException& t);
  virtual ~WebservException(void) throw();

  int get_error_number(void) const;
  const char *get_error_message(void) const;
  virtual const char* what(void) const throw();
};

// MutexException is the Exception regarding Mutex class
class MutexException : public WebservException {
 public:
  explicit MutexException(const std::string& m);
  MutexException(const std::string& m, const int n);
};

// ThreadException is the Exception regarding Thread class
class ThreadException : public WebservException {
 public:
  explicit ThreadException(const std::string& m);
  ThreadException(const std::string& m, const int n);
};

// EngineException is the Exception regarding Engine class
class EngineException : public WebservException {
 public:
  explicit EngineException(const std::string& m);
  EngineException(const std::string& m, const int n);
};

// ParserException is the Exception regarding Parser class
class ParserException : public WebservException {
 public:
  explicit ParserException(const std::string& m);
  ParserException(const std::string& m, const int n);
};

// ConfigException is the Exception regarding Config class
class ConfigException : public WebservException {
 public:
  explicit ConfigException(const std::string& m);
  ConfigException(const std::string& m, const int n);
};

// ServerException is the Exception regarding Server class
class ServerException : public WebservException {
 public:
  explicit ServerException(const std::string& m);
  ServerException(const std::string& m, const int n);
};

#endif  // CIRCLE_05_WEBSERV_INCLUDES_EXCEPTION_HPP_
