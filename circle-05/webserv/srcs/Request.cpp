// Copyright @bigpel66

#include "../includes/Request.hpp"

Request::Request(void)
  : _protocol("HTTP/1.1"),
    _body_offset(0),
    _chunk_size(0),
    _request_status(on_request_line) {
  gettimeofday(&_header_timer, ft::nil);
}

Request::~Request(void) {}

bool Request::is_timeout(void) {
  if (_request_status != on_complete) {
    _request_status = on_error;
    return true;
  }
  return false;
}

bool Request::is_header_validated(void) const {
  return _request_status > on_validating_headers;
}

time_t Request::get_header_time(void) const {
  return _header_timer.tv_sec;
}

time_t Request::get_body_time(void) const {
  return _body_timer.tv_sec;
}

int Request::parse_request_line(void) {
  // TODO (@bigpel66)
  return 0;
}

int Request::parse_headers(void) {
  // TODO (@bigpel66)
  return 0;
}

int Request::parse_body(void) {
  // TODO (@bigpel66)
  return 0;
}

int Request::validate_chunk_trailer(void) {
  // TODO (@bigpel66)
  return 0;
}

int Request::parse_chunk(void) {
  // TODO (@bigpel66)
  return 0;
}

int Request::parse(const std::string& data) {
  // TODO (@bigpel66)
  (void)data;
  return 0;
}
