// Copyright @bigpel66

#include "../includes/Server.hpp"
#include "../includes/Exception.hpp"

bool Server::_is_server_alive = false;

Server::Server(const Options& options, const ServerConfigs& server_configs)
  : _options(options),
    _server_configs(server_configs) {
  FD_ZERO(&_master_fds);
  FD_ZERO(&_read_fds);
  FD_ZERO(&_write_fds);


  // TODO
  run(0);
}

Server::Server(const Server& s)
  : _options(s._options),
    _server_configs(s._server_configs) {
  *this = s;
}

Server& Server::operator=(const Server& s) {
  if (this != &s) {
    _fds = s._fds;
    _max_fd = s._max_fd;
    _master_fds = s._master_fds;
    _servers = s._servers;
    _clients = s._clients;
  }
  return *this;
}

Server::~Server(void) {}

void Server::set_server_alive_status(bool is_alive) {
  _is_server_alive = is_alive;
}

void Server::insert_fd(int fd) {
  std::pair<FDs::iterator, bool> result = _fds.insert(fd);
  if (!result.second) {
    throw ServerException("Duplicated FD detected " + std::to_string(fd));
  }
  FD_SET(fd, &_master_fds);
  if (fd > _max_fd) {
    _max_fd = fd;
  }
}

void Server::erase_fd(int fd) {
  _fds.erase(fd);
  FD_CLR(fd, &_master_fds);
  if (fd == _max_fd) {
    _max_fd = *_fds.rbegin();
  }
}

void Server::run(int worker_id) {
  set_server_alive_status(true);
  _current_title = "worker [" + std::to_string(worker_id) + "] : ";
  signal(SIGINT, signal_handler);
  signal(SIGQUIT, signal_handler);
  while(_is_server_alive);
}
