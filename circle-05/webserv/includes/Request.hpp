// Copyright @bigpel66

// Header for the request from the client
#ifndef CIRCLE_05_WEBSERV_INCLUDES_REQUEST_HPP_
#define CIRCLE_05_WEBSERV_INCLUDES_REQUEST_HPP_

// Standard Library Inclusion
#include <string>

// Class Headers Inclusion
#include "./Utilizer.hpp"

// Enum Request Status
enum request_status {
  on_request_line,
  on_headers,
  on_validating_headers,
  on_body,
  on_chunk,
  on_complete,
  on_error
};

// Enum Chunk Status
enum chunk_status {
  chunk_size,
  chunk_body
};

class Request {
 private:
  std::string _data;
  std::string _method;
  Headers _headers;
  std::string _body;
  std::string _query_string;
  std::string _resource;
  std::string _protocol;

  size_t _body_offset;
  size_t _chunk_size;
  size_t _content_length;

  struct timeval _header_timer;
  struct timeval _body_timer;

  chunk_status _chunk_status;
  request_status _request_status;

  Request(const Request& r);
  Request& operator=(const Request& r);

 public:
  Request(void);
  ~Request(void);

  bool is_timeout(void) const;
  int parse_request_line(void);
  int parse_headers(void);
  int validate_headers(void);
  int parse_body(void);
  int validate_chunk_trailer(void);
  int parse_chunk(void);
  int parse(const std::string& data);

  time_t get_header_time();
  time_t get_body_time();
};
#endif  // CIRCLE_05_WEBSERV_INCLUDES_REQUEST_HPP_
