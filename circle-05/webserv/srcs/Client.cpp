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

bool Client::is_header_timeout(void) const {

}

bool Client::is_body_timeout(void) const {

}

bool Client::is_timeout(void) const {
  struct timeval currnet_timeval;
  time_t current_time = gettimeofday(&currnet_timeval, ft::nil);

}

bool Client::is_connectable(void) const {
  return _is_connectable;
}
