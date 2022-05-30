// Copyright @bigpel66

#include "../includes/Client.hpp"

Client::Client(int fd,
              int worker_id,
              bool is_connectable,
              const std::string& addr,
              Listen &listen)
  : _fd(fd),
    _worker_id(worker_id),
    _is_connectable(is_connectable),
    _addr(addr),
    _listen(listen),
    _req_context(ft::nil),
    _req(ft::nil),
    _res(ft::nil) {}

Client::~Client(void) {
  ::close(_fd);
  clear();
}

void Client::clear() {
  ft::safe_delete(&_req_context);
  ft::safe_delete(&_req);
  ft::safe_delete(&_res);
}

void Client::init_req_context(ServContexts *servers) {
  if (_req_context) {
    return;
  }
  _req_context = new ReqContext(_req, this, servers);
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
      _res = new Response(500, _worker_id, *_req_context);
      _res->build();
      break;
    }
    retry_count++;
  } while (is_redirected);
  ft::safe_delete(&_req);
}

void Client::init_response(int code, ServContexts *servers) {
  _req = get_request();
  init_req_context(servers);
  _res = new Response(code, _worker_id, *_req_context);
  build_response_and_check_redirection();
}

bool Client::is_timeout(void) {
  if (_req) {
    time_t current_time = ft::get_current_timestamp();
    if (current_time - _req->get_header_time() > HEADER_TIMEOUT
      || current_time - _req->get_body_time() > BODY_TIMEOUT) {
      if (_req->is_timeout())
        return true;
    }
  }
  return false;
}

bool Client::is_connectable(void) const {
  return _is_connectable;
}

Listen *Client::get_listen(void) {
  return &_listen;
}

const std::string& Client::get_addr(void) const {
  return _addr;
}

ReqContext *Client::get_req_context(void) const {
  return _req_context;
}

Request *Client::get_request(void) {
  if (!_req) {
    _req = new Request();
  }
  return _req;
}

Response *Client::get_response(void) const {
  return _res;
}
