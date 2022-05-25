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
    _listen(listen) {
  _req = ft::nil;
  _req_context = ft::nil;
  _res = ft::nil;
}

Client::~Client(void) {
  close(_fd);
  clear();
}

void Client::clear(void) {
  ft::safe_delete(_req);
  ft::safe_delete(_req_context);
  ft::safe_delete(_res);
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

bool Client::is_connectable(void) const {
  return _is_connectable;
}

Request *Client::get_request(void) {
  if (!_req) {
    _req = new Request();
  }
  return _req;
}

ReqContext *Client::get_req_context(void) const {
  return _req_context;
}

Response *Client::get_response(void) const {
  return _res;
}
