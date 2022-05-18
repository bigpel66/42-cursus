// Copyright @bigpel66

// Header for the exceptions to throw and stack unwind
#ifndef CIRCLE_05_WEBSERV_INCLUDES_EXCEPTION_HPP_
#define CIRCLE_05_WEBSERV_INCLUDES_EXCEPTION_HPP_

// Standard Library Inclusion
#include <exception>
#include <string>
#include <cstring>

// PthreadException is the base Exception class for Pthread
class PthreadException : public std::exception {
 private:
  std::string _error_message;
  int _error_number;

  // Prevent to call directly
  PthreadException(void);
  PthreadException& operator=(const PthreadException& t);

 public:
  PthreadException(const std::string& error_message, const int error_number);
  PthreadException(const PthreadException& t);
  virtual ~PthreadException(void) throw();

  int get_error_number(void) const;
  const char *get_error_message(void) const;
  virtual const char* what(void) const throw();
};

// MutexException is the Exception regarding Mutex class
class MutexException : public PthreadException {
 public:
  explicit MutexException(const std::string& message);
  MutexException(const std::string& message, const int number);
};

// MutexException is the Exception regarding Thread class
class ThreadException : public PthreadException {
 public:
  explicit ThreadException(const std::string& message);
  ThreadException(const std::string& message, const int number);
};

#endif  // CIRCLE_05_WEBSERV_INCLUDES_EXCEPTION_HPP_
