// Copyright @bigpel66

// Header for the HTTP header
#ifndef CIRCLE_05_WEBSERV_INCLUDES_HEADERS_HPP_
#define CIRCLE_05_WEBSERV_INCLUDES_HEADERS_HPP_

// Standard Library Inclusion
#include <string>
#include <map>

// Class Headers Inclusion
#include "./Utilizer.h"  // For the using type definition

class Headers {
 private:
  std::map<std::size_t, Header> _headers;

  Headers(const Headers& headers);
  Headers& operator=(const Headers& headers);

 public:
  Headers(void);
  ~Headers(void);

  void operator+=(const std::string& requested_string);
  Header& operator[](std::size_t index);
  std::size_t size(void) const;
  std::size_t last_index(void) const;
  Header& last_header(void);
};

#endif  // CIRCLE_05_WEBSERV_INCLUDES_HEADERS_HPP_
