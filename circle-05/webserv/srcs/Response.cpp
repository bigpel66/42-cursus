// Copyright @bigpel66

#include "../includes/Response.hpp"

Response::Response(int worker_id,
                  int code,
                  const ReqContext& req_context)
  : _worker_id(worker_id),
    _code(code),
    _status_code(0),
    _redirect_code(0),
    _total_sent(0),
    _header_size(0),
    _body_size(0),
    _is_redirected(false),
    _req_context(req_context) {
  init_method_converter();
}

Response::~Response(void) {}

void Response::clear(void) {
  _code = 0;
  _status_code = 0;
  _total_sent = 0;
  _header_size = 0;
  _body_size = 0;
  _is_redirected = false;
  _body.clear();
  _response.clear();
  _headers.clear();
}

void Response::init_method_converter(void) {
  _mux["GET"] = &Response::GET;
  _mux["POST"] = &Response::POST;
  _mux["HEAD"] = &Response::GET;
  _mux["PUT"] = &Response::PUT;
  _mux["DELETE"] = &Response::DELETE;
}

bool Response::is_connection_close_specified(void) const {
  return _headers.find("Connection") != _headers.end() &&
          _headers.at("Connection") == "close";
}

bool Response::is_redirected(void) const {
  return _is_redirected;
}
