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
  Headers _headers;
  std::string _method;
  std::string _body;
  std::string _query_string;
  std::string _target;
  std::string _protocol;

  std::size_t _body_offset;
  std::size_t _chunk_size;
  std::size_t _content_length;

  struct timeval _header_timer;
  struct timeval _body_timer;

  chunk_status _chunk_status;
  request_status _request_status;

  Request(const Request& r);
  Request& operator=(const Request& r);

 public:
  Request(void);
  ~Request(void);

  bool is_timeout(void);
  bool is_header_validated(void) const;

  int parse_request_line(void);
  int parse_headers(void);
  int validate_headers(void);
  int parse_body(void);
  int validate_chunk_trailer(void);
  int parse_chunk(void);
  int parse(const std::string& data);

  time_t get_header_time(void) const;
  time_t get_body_time(void) const;

  friend class ReqContext;
};
#endif  // CIRCLE_05_WEBSERV_INCLUDES_REQUEST_HPP_
