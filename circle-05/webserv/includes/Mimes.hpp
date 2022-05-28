// Copyright @bigpel66

// Header for the content type according to the extension
#ifndef CIRCLE_05_WEBSERV_INCLUDES_MIMES_HPP_
#define CIRCLE_05_WEBSERV_INCLUDES_MIMES_HPP_

// Standard Library Inclusion
#include <string>

// Class Headers Inclusion
#include "./Utilizer.hpp"

class Mimes {
 private:
  MimeMapper _mapper;

  Mimes(const Mimes& m);
  Mimes& operator=(const Mimes& m);

 public:
  Mimes(void);
  ~Mimes(void);

  const std::string& get_type(const std::string& extension);
};

#endif  // CIRCLE_05_WEBSERV_INCLUDES_MIMES_HPP_
