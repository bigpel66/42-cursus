// Copyright @bigpel66

#include "../includes/Client.hpp"

Client::Client(int client_fd,
              int worker_id,
              bool is_connectable,
              const std::string& addr,
              const Listen& listen)
  : _fd(client_fd),
    _worker_id(worker_id),
    _is_connectable(is_connectable),
    _addr(addr),
    _listen(listen),
    _req(ft::nil),
    _req_context(ft::nil),
    _res(ft::nil) {}

Client::~Client(void) {
  ::close(_fd);
  clear();
}

void Client::clear(void) {
  ft::safe_delete(&_req);
  ft::safe_delete(&_req_context);
  ft::safe_delete(&_res);
}

bool Client::is_header_timeout(time_t current_time) const {
  return current_time - _req->get_header_time() > HEADER_TIMEOUT;
}

bool Client::is_body_timeout(time_t current_time) const {
  return current_time - _req->get_body_time() > BODY_TIMEOUT;
}

bool Client::is_timeout(void) const {
  struct timeval currnet_timeval;
  time_t current_time = gettimeofday(&currnet_timeval, ft::nil);
  if (is_header_timeout(current_time) || is_body_timeout(current_time)) {
    if (_req->is_timeout()) {
      return true;
    }
  }
  return false;
}

bool Client::is_connection_close_specified(void) const {
  return !_is_connectable;
}

const Listen& Client::get_listen(void) const {
  return _listen;
}

const std::string& Client::get_addr(void) const {
  return _addr;
}

Request *Client::get_request(void) {
  set_request();
  return _req;
}

ReqContext *Client::get_req_context(void) const {
  return _req_context;
}

Response *Client::get_response(void) const {
  return _res;
}

void Client::set_request(void) {
  if (!_req) {
    _req = new Request();
  }
}

void Client::set_req_context(const ServContexts& serv_contexts) {
  if (!_req_context) {
    _req_context = new ReqContext(*_req, *this, serv_contexts);
  }
}

void Client::build_response_and_check_redirection(void) {
  bool is_redirected;
  int retry_count = 0;
  do {
    _res->build();
    is_redirected = _res->is_redirected();
    if (is_redirected) {
      _req_context->reset_to_redirected_location(_res->get_redirected_target());
      _res->clear();
    }
    if (retry_count > MAXIMUM_REDIRECT_NUMBER) {
      ft::safe_delete(&_res);
      _res = new Response(_worker_id, 500, _req_context);
      _res->build();
      break;
    }
    retry_count++;
  } while (is_redirected);
  ft::safe_delete(&_req);
}

void Client::set_response(int code, const ServContexts& serv_contexts) {
  set_request();
  set_req_context(serv_contexts);
  _res = new Response(_worker_id, code, _req_context);
  build_response_and_check_redirection();
}
