// Copyright @bigpel66

#include "../includes/Worker.hpp"
#include "../includes/Utilizer.hpp"

Worker::Worker(int id)
  : AbstractThread(8388608),
    _id(id),
    _socket(0),
    _status(valid_worker),
    _server(ft::nullptr_t) {
}

int Worker::get_id(void) const {
  return _id;
}

int Worker::get_it(void) const {
  return _it;
}

int Worker::get_socket(void) const {
  return _socket;
}

worker_status Worker::get_status(void) const {
  return _status;
}

Server *Worker::get_server(void) const {
  return _server;
}

void Worker::set_it(int it) {
  _it = it;
}

void Worker::set_socket(int socket) {
  _socket = socket;
}

void Worker::set_status(worker_status status) {
  _status = status;
}

void Worker::set_server(Server *server) {
  _server = server;
}

void Worker::run(void) throw() {
}
