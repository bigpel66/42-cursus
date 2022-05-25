// Copyright @bigpel66

#include "../includes/Engine.hpp"
#include "../includes/Server.hpp"
#include "../includes/Exception.hpp"
#include "../includes/ServContext.hpp"

const bool Server::_reuse_addr = true;

bool Server::_is_alive = false;

Mutex Server::_status_controller;

Mutex Server::_connection_controller;

Mutex Server::_response_controller;

Server::Server(const Options& options,
              const ServContexts& serv_contexts)
  : _max_fd(0),
    _options(options),
    _serv_contexts(serv_contexts) {
  FD_ZERO(&_master_fds);
  FD_ZERO(&_read_fds);
  FD_ZERO(&_write_fds);
  init();

  // TODO(@bigpel66)
  run(0);
}

Server::Server(const Server& s)
  : _options(s._options),
    _serv_contexts(s._serv_contexts) {
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

void Server::set_worker_id(int worker_id) {
  _worker_id = worker_id;
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
  if (is_data_readable_from_client_on(client_fd)) {
    if (!recv_data_on(client_fd)) {
      return true;
    }
  }
  return false;
}

bool Server::is_connection_closable_on_send(int client_fd) {
  if (is_data_writable_to_client_on(client_fd)) {
    if (!send_data_on(client_fd)) {
      return true;
    }
  }
  return false;
}

bool Server::is_nothing_received(ssize_t buffer_read_size) const {
  return buffer_read_size <= 0;
}

bool Server::is_nothing_sent(int code) const {
  return code < 0;
}

bool Server::is_data_fully_sent(int code) const {
  return code == 0;
}

bool Server::is_client_response_settable(int code) const {
  return code >= 1;
}

bool Server::is_conneciton_needs_to_be_closed(Response *res,
                                              Client *client) const {
                                                (void)res;
                                                (void)client;
                                                return false;
  // return res->is_connection_close_specified() ||
  //         client->is_connection_close_specified();
}

bool Server::is_binded_includes_given_listen(const Listens& binded,
                                            const Listen& l) const {
  return std::find(binded.begin(), binded.end(), l) != binded.end();
}

void Server::insert_default_listen_if_empty(Listens *binded,
                                            const ServContext& serv_context) {
  if (serv_context.get_listens().empty()) {
    binded->push_back(Listen("0.0.0.0", 80));
  }
}

void Server::iterate_listens_of_serv_context(Listens *binded,
                                              const ServContext& serv_context) {
  for (Listens::const_iterator it = serv_context.get_listens().begin()
      ; it != serv_context.get_listens().end()
      ; it++) {
      if (is_binded_includes_given_listen(*binded, *it)) {
        continue;
      }
      init_socket_binding(binded, *it);
  }
}

void Server::check_server_socket_opened(int server_fd) {
  if (server_fd < 0) {
    kill_server("socket() failed");
  }
}

void Server::check_server_socket_binded(int code) {
  if (code < 0) {
    kill_server("bind() failed");
  }
}

void Server::check_server_socket_listening(int code) {
  if (code < 0) {
    kill_server("listen() failed");
  }
}

void Server::check_nothing_binded(const Listens& binded) {
  if (binded.empty()) {
    kill_server("nothing binded on server");
  }
}

void Server::init(void) {
  Listens binded;
  for (ServContexts::const_iterator it = _serv_contexts.begin()
      ; it != _serv_contexts.end()
      ; it++) {
      insert_default_listen_if_empty(&binded, **it);
      iterate_listens_of_serv_context(&binded, **it);
  }
  check_nothing_binded(binded);
}

void Server::init_socket_binding(Listens *binded, const Listen& l) {
  int server_fd = socket(PF_INET, SOCK_STREAM, 0);
  check_server_socket_opened(server_fd);
  fcntl(server_fd, F_SETFL, O_NONBLOCK);
  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(l.get_port());
  addr.sin_addr.s_addr = inet_addr(l.get_ip().c_str());
  setsockopt(server_fd,
            SOL_SOCKET,
            SO_REUSEADDR,
            &Server::_reuse_addr,
            sizeof(_reuse_addr));
  int code = bind(server_fd,
                  reinterpret_cast<struct sockaddr *>(&addr),
                  sizeof(addr));
  check_server_socket_binded(code);
  code = listen(server_fd, MAXIMUM_CONNECTION);
  check_server_socket_listening(code);
  _servers[server_fd] = l;
  insert_fd(server_fd);
  binded->push_back(l);
  Engine::Engine::logger->info("listening on "
        + l.get_ip() + ":" + std::to_string(l.get_port()));
}

void Server::init_connection(int server_fd) {
  // (void)server_fd;
  struct sockaddr_storage addr_storage;
  socklen_t addr_len = sizeof(addr_storage);
  struct sockaddr *addr = reinterpret_cast<struct sockaddr *>(&addr_storage);
  FD_CLR(server_fd, &_read_fds);
  int client_fd =  accept(server_fd, addr, &addr_len);
  if (client_fd < 0) {
    return;
  }
  Engine::logger->info(combine_title("connection accepted on "
        + std::to_string(client_fd)));
  fcntl(client_fd, F_SETFL, O_NONBLOCK);
  insert_fd(client_fd);
  _clients[client_fd] = new Client(client_fd,
                      _worker_id,
                      _clients.size() < MAXIMUM_CLIENT_NUMBER,
                      ft::inet_ntop(ft::sockaddr_to_void_ptr_sockaddr_in(addr)),
                      _servers[server_fd]);
}

void Server::init_response_by_status_code(Client *client, int status_code) {
  // (void)client;
  // (void)status_code;
  client->set_response(status_code, _options, _serv_contexts);
  Engine::logger->info(combine_title("<< "
        + client->get_req_context()->get_log(Engine::logger->get_level())));
}

void Server::init_response_by_timeout_or_disconnect(Client *client) {
  // (void)client;
  if (client->is_timeout()) {
    client->set_response(408, _options, _serv_contexts);
    Engine::logger->info(combine_title("<< "
          + client->get_req_context()->get_log(Engine::logger->get_level())));
  }
  if (!client->is_connectable()) {
    client->set_response(503, _options, _serv_contexts);
    Engine::logger->info(combine_title("<< "
          + client->get_req_context()->get_log(Engine::logger->get_level())));
  }
}

std::string Server::combine_title(const std::string& msg) const {
  return _current_title + msg;
}

bool Server::recv_data_on(int client_fd) {
  // (void)client_fd;
  // return false;
  FD_CLR(client_fd, &_read_fds);
  Request *req = _clients[client_fd]->get_request();
  char buf[DEFAULT_BUFFER_SIZE];
  ssize_t buffer_read_size = recv(client_fd, buf, DEFAULT_BUFFER_SIZE, 0);
  if (is_nothing_received(buffer_read_size)) {
    return false;
  }
  std::string data(buf, buffer_read_size);
  int code = req->parse(data);
  if (is_client_response_settable(code)) {
    init_response_by_status_code(_clients[client_fd], code);
  }
  return true;
}

bool Server::send_data_on(int client_fd) {
  // (void)client_fd;
  // return false;
  FD_CLR(client_fd, &_write_fds);
  Response *res = _clients[client_fd]->get_response();
  if (!res) {
    return true;
  }
  int code = res->send(client_fd);
  if (is_nothing_sent(code)) {
    return false;
  } else if (is_data_fully_sent(code)) {
    _clients[client_fd]->clear();
    Engine::logger->info(combine_title(">> "
          + res->get_log(Engine::logger->get_level())));
    if (is_conneciton_needs_to_be_closed(res, _clients[client_fd])) {
      return false;
    }
  }
  return true;
}

void Server::kill_server(const std::string& msg) {
  set_alive_status(false);
  Engine::logger->fatal(combine_title(msg));
  exit(0);
}

void Server::insert_fd(int fd) {
  std::pair<FDs::iterator, bool> result = _fds.insert(fd);
  if (!result.second) {
    kill_server("duplicated fd detected, " + std::to_string(fd));
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

void Server::erase_client(int fd) {
  if (_clients.find(fd) != _clients.end()) {
    ft::safe_delete(&_clients[fd]);
    _clients.erase(fd);
    Engine::logger->info(combine_title("connection closed on "
          + std::to_string(fd)));
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
                    ft::nil,
                    &_timeout);
  if (code < 0 && _is_alive) {
    kill_server("select() failed");
  }
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

// Watch out for calling this function, back up iterator is necessary
void Server::close_client_connection(int client_fd) {
  erase_fd(client_fd);
  erase_client(client_fd);
}

void Server::iterate_clients(void) {
  Clients::iterator back_up_it_on_erase = _clients.begin();
  for (Clients::iterator it = _clients.begin()
      ; it != _clients.end()
      ; it = back_up_it_on_erase) {
    back_up_it_on_erase++;
    if (is_connection_closable_on_recv(it->first)) {
      close_client_connection(it->first);
      continue;
    }
    init_response_by_timeout_or_disconnect(it->second);
    if (is_connection_closable_on_send(it->first)) {
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
  Engine::logger->info(combine_title("Booting Up Server ..."));
  set_signal_handlers();
  set_default_timeout();
  set_worker_id(worker_id);
  set_current_title(worker_id);
  set_alive_status(true);
  loop();
  clear_clients();
  Engine::logger->info(combine_title("Shutting Down Server ..."));
}

void server_signal_handler(int sig) {
  (void)sig;
  write(STDOUT_FILENO, "\b\bserver interrupted by signal", 30);
  Server::set_alive_status(false);
  exit(0);
}
