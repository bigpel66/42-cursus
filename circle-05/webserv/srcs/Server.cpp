// Copyright @bigpel66

#include "../includes/Server.hpp"
#include "../includes/Exception.hpp"

bool Server::_is_alive = false;

Mutex Server::_status_controller;

Server::Server(Logger *logger,
              const Options& options,
              const ServerConfigs& server_configs)
  : _logger(logger),
    _options(options),
    _server_configs(server_configs) {
  FD_ZERO(&_master_fds);
  FD_ZERO(&_read_fds);
  FD_ZERO(&_write_fds);


  // TODO(@bigpel66)
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

void Server::set_alive_status(bool is_alive) {
  LockGuard<Mutex> _lg(&_status_controller);
  Server::_is_alive = is_alive;
}

void Server::set_signal_handlers(void) const {
  signal(SIGINT, server_signal_handler);
  signal(SIGQUIT, server_signal_handler);
}

void Server::set_default_timeout(void) {
  _timeout.tv_sec = 1;
  _timeout.tv_usec = 0;
}

void Server::set_current_title(int worker_id) {
  _current_title = "worker [" + std::to_string(worker_id) + "] : ";
}

void Server::kill_server(const std::string& msg) {
  set_alive_status(false);
  _logger->fatal(msg);
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

void Server::copy_read_fds_before_select(void) {
  _read_fds = _master_fds;
}

void Server::copy_write_fds_before_select(void) {
  _write_fds = _master_fds;
}

void Server::init_fds_for_select(void) {
    copy_read_fds_before_select();
    copy_write_fds_before_select();
}

void Server::io_multiplexing(void) {
  int code = select(_max_fd + 1,
                    &_read_fds,
                    &_write_fds,
                    ft::nullptr_t,
                    &_timeout);
  if (code < 0) {
    kill_server(_current_title + " select() failed");
  }
}

void Server::loop(void) {
  while (Server::_is_alive) {
    init_fds_for_select();
    io_multiplexing();
  }
}

void Server::run(int worker_id) {
  set_signal_handlers();
  set_default_timeout();
  set_current_title(worker_id);
  set_alive_status(true);
  _logger->info(_current_title + " Starting Server ...");
  loop();
}

void server_signal_handler(int sig) {
  (void)sig;
  write(STDOUT_FILENO, "\b\bserver interrupted by signal", 30);
  Server::set_alive_status(false);
}
