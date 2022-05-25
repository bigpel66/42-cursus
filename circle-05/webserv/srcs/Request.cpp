// Copyright @bigpel66

#include "../includes/Request.hpp"

Request::Request(void) {}

Request::~Request(void) {}

bool Request::is_header_validated(void) const {
  return _request_status > on_validating_headers;
}

const std::string& Request::get_target(void) const {
  return _target;
}
