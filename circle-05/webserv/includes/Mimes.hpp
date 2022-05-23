// Copyright @bigpel66

#ifndef CIRCLE_05_WEBSERV_INCLUDES_MIMES_HPP_
#define CIRCLE_05_WEBSERV_INCLUDES_MIMES_HPP_

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

  const std::string& get_content_type(const std::string& extension);
};

#endif  // CIRCLE_05_WEBSERV_INCLUDES_MIMES_HPP_
