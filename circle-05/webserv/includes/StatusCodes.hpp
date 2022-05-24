// Copyright @bigple66

// Header for the status code of http response
#ifndef CIRCLE_05_WEBSERV_INCLUDES_STATUSCODES_HPP_
#define CIRCLE_05_WEBSERV_INCLUDES_STATUSCODES_HPP_

// Standard Library Inclusion
#include <string>

// Class Headers Inclusion
#include "./Utilizer.hpp"

class StatusCodes {
 private:
  StatusCodeMapper _mapper;

  StatusCodes(const StatusCodes& s);
  StatusCodes& operator=(const StatusCodes& s);

 public:
  StatusCodes(void);
  ~StatusCodes(void);

  const std::string& operator[](int code);
};

#endif  // CIRCLE_05_WEBSERV_INCLUDES_STATUSCODES_HPP_
