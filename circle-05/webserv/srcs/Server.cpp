// Copyright @bigpel66

#include "../includes/Server.hpp"
#include "../includes/Exception.hpp"

bool Server::_is_alive = false;

Mutex Server::_status_controller;

Mutex Server::_connection_controller;

Mutex Server::_response_controller;

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

bool Server::is_connection_requested_on(int fd) const {
  return FD_ISSET(fd, &_read_fds);
}

bool Server::is_data_readable_from_client_on(int fd) const {
  return FD_ISSET(fd, &_read_fds);
}

bool Server::is_data_writable_to_client_on(int fd) const {
  return FD_ISSET(fd, &_write_fds);
}

bool Server::is_connection_closable_on_recv(int client_fd) {

}

bool Server::is_connection_closable_on_send(int client_fd) {

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

void Server::monitor_connections(void) {
  int code = select(_max_fd + 1,
                    &_read_fds,
                    &_write_fds,
                    ft::nullptr_t,
                    &_timeout);
  if (code < 0) {
    kill_server(_current_title + " select() failed");
  }
}

void Server::init_connection(int fd) {

}

void Server::accept_connections(void) {
  for (Servers::iterator it = _servers.begin()
      ; it != _servers.end()
      ; it++) {
    if (is_connection_requested_on(it->first)) {
      LockGuard<Mutex> _lg(&_connection_controller);
      init_connection(it->first);
    }
  }
}

void Server::close_client_connection(int client_fd) {

}

void Server::init_response_if_possible(Client *client) {

}

void Server::iterate_clients(void) {
  Clients::iterator back_up_it_on_erase = _clients.begin();
  for (Clients::iterator it = _clients.begin()
      ; it != _clients.end()
      ; it = back_up_it_on_erase) {
    back_up_it_on_erase++;
    if (!is_connection_closable_on_recv(it->first)) {
      close_client_connection(it->first);
      continue;
    }
    init_response_if_possible(it->second);
    if (!is_connection_closable_on_send(it->first)) {
      close_client_connection(it->first);
      continue;
    }
  }
}

void Server::io_multiplexing(void) {
  monitor_connections();
  accept_connections();
  iterate_clients();
}

void Server::delay_a_second(void) {
  usleep(DEFAULT_DELAY);
}

void Server::loop(void) {
  while (Server::_is_alive) {
    init_fds_for_select();
    io_multiplexing();
    delay_a_second();
  }
}

void Server::clear_clients(void) {
  Clients::iterator back_up_it_on_erase = _clients.begin();
  for (Clients::iterator it = _clients.begin()
      ; it != _clients.end()
      ; it = back_up_it_on_erase) {
    back_up_it_on_erase++;
    close_client_connection(it->first);
  }
}

void Server::run(int worker_id) {
  set_signal_handlers();
  set_default_timeout();
  set_current_title(worker_id);
  set_alive_status(true);
  _logger->info(_current_title + " Booting Up Server ...");
  loop();
  clear_clients();
  _logger->info(_current_title + " Shutting Down Server ...");
}

void server_signal_handler(int sig) {
  (void)sig;
  write(STDOUT_FILENO, "\b\bserver interrupted by signal", 30);
  Server::set_alive_status(false);
}
