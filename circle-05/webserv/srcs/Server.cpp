// Copyright @bigpel66

#include "../includes/Server.hpp"
#include "../includes/Engine.hpp"
#include "../includes/Exception.hpp"

bool Server::Server::_is_alive = false;

const bool Server::_reuse_addr = true;

Server::Server(const Server &s)
  :  _serv_contexts(s._serv_contexts) {
  *this = s;
}

Server::Server(ServContexts *servers)
  : _max_fd(0),
    _serv_contexts(*servers) {
  FD_ZERO(&_master_fds);
  FD_ZERO(&_read_fds);
  FD_ZERO(&_write_fds);
}

Server &Server::operator=(const Server &copy) {
  _fds = copy._fds;
  _max_fd = copy._max_fd;
  _master_fds = copy._master_fds;
  _serv_contexts = copy._serv_contexts;
  _servers = copy._servers;
  _clients = copy._clients;
  return (*this);
}

Server::~Server(void) {}

bool Server::is_listen_duplicated(const Listens& binded,
                                  const Listen& l) const {
  return std::find(binded.begin(), binded.end(), l) != binded.end();
}

bool Server::is_nothing_received(ssize_t buffer_read_size) const {
  return buffer_read_size <= 0;
}

bool Server::is_client_response_settable(int code) const {
  return code >= 1;
}

bool Server::recv(int fd) {
  Request *req = _clients[fd]->get_request();
  char buf[DEFAULT_BUFFER_SIZE];
  FD_CLR(fd, &_read_fds);
  ssize_t read_size = ::recv(fd, buf, DEFAULT_BUFFER_SIZE, 0);
  if (is_nothing_received(read_size)) {
    return false;
  }
  std::string data(buf, read_size);
  int code = req->parse(data);
  if (is_client_response_settable(code)) {
    _clients[fd]->init_response(code, &_serv_contexts);
  }
  return true;
}

bool Server::is_nothing_sent(int code) const {
  return code < 0;
}

bool Server::is_data_full_sent(int code) const {
  return code == 0;
}

bool Server::send(int fd) {
  FD_CLR(fd, &_write_fds);
  Response *res = _clients[fd]->get_response();
  if (!res) {
    return true;
  }
  int code = res->send(fd);
  if (is_nothing_sent(code)) {
    return false;
  } else if (is_data_full_sent(code)) {
    bool is_connectable = res->is_connectable() &&
                          _clients[fd]->is_connectable();
    _clients[fd]->clear();
    if (!is_connectable)
      return false;
  }
  return true;
}

void Server::interrupt_handler(int sig) {
  LockGuard<Mutex> _lg(&Engine::server_controller);
  (void)sig;
  std::cout << "\b\b \b\b";
  Server::_is_alive = false;
}

void Server::insert_fd(int fd) {
  _fds.insert(fd);
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

void Server::init_socket_binding(Listens *binded, const Listen& l) {
  int server_fd = socket(PF_INET, SOCK_STREAM, 0);
  if (server_fd < 0) {
    throw ServerException("socket() failed");
  }
  ::fcntl(server_fd, F_SETFL, O_NONBLOCK);
  struct sockaddr_in addr;
  ::memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(l.port);
  addr.sin_addr.s_addr = inet_addr(l.ip.c_str());
  ::setsockopt(server_fd,
              SOL_SOCKET,
              SO_REUSEADDR,
              &Server::_reuse_addr,
              sizeof(int));
  SockAddr *addr_ptr = reinterpret_cast<SockAddr *>(&addr);
  const SockAddr *const_addr_ptr = const_cast<const SockAddr *>(addr_ptr);
  int code = ::bind(server_fd, const_addr_ptr, sizeof(addr));
  if (code < 0) {
    throw ServerException("bind() failed");
  }
  code = ::listen(server_fd, MAXIMUM_CONNECTION);
  if (code < 0) {
    throw ServerException("listen() failed");
  }
  _servers[server_fd] = l;
  insert_fd(server_fd);
  binded->push_back(l);
  Engine::logger.info("listeing on " + l.ip + ":" + ft::to_string(l.port));
}

void Server::insert_default_listen_if_empty(ServContext *serv_context) {
  if (serv_context->get_listens().empty()) {
    serv_context->get_listens().push_back(Listen("0.0.0.0", 80));
  }
}

void Server::iterate_listens(Listens *binded, ServContext *serv_context) {
  for (Listens::iterator it = serv_context->get_listens().begin()
      ; it != serv_context->get_listens().end()
      ; it++) {
    if (is_listen_duplicated(*binded, *it)) {
      continue;
    }
    init_socket_binding(binded, *it);
  }
}

void Server::init(void) {
  Listens binded;
  for (ServContexts::iterator it = _serv_contexts.begin()
      ; it != _serv_contexts.end()
      ; it++) {
    insert_default_listen_if_empty(&(*it));
    iterate_listens(&binded, &(*it));
  }
  if (binded.empty()) {
    throw ServerException("nothing binded on server");
  }
}

void Server::set_worker_id(int worker_id) {
  _worker_id = worker_id;
}

void Server::set_current_title(int worker_id) {
  _current_title = "worker [" + std::to_string(worker_id) + "] : ";
}

void Server::set_default_timeout(void) {
  _timeout.tv_sec = 1;
  _timeout.tv_usec = 0;
}

void Server::set_signal_handlers(void) const {
  signal(SIGINT, interrupt_handler);
  signal(SIGQUIT, interrupt_handler);
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

int Server::monitor_connections(void) {
  int code = select(_max_fd + 1, &_read_fds, &_write_fds, ft::nil, &_timeout);
  if (code < 0 && Server::_is_alive) {
    throw ServerException("select() failed");
  }
  return code;
}

void Server::init_connection(int fd) {
  struct sockaddr_storage addr;
  socklen_t addr_size = sizeof(addr);
  struct sockaddr *addr_ptr = reinterpret_cast<struct sockaddr *>(&addr);
  FD_CLR(fd, &_read_fds);
  int client_fd = accept(fd, addr_ptr, &addr_size);
  if (client_fd < 0) {
    return;
  }
  Engine::logger.debug(combine_title("connection accepted on "
                      + ft::to_string(client_fd)));
  ::fcntl(client_fd, F_SETFL, O_NONBLOCK);
  insert_fd(client_fd);
  _clients[client_fd] = new Client(client_fd,
          _worker_id,
          _clients.size() < MAXIMUM_CLIENT_NUMBER,
          ft::inet_ntop(ft::sockaddr_to_void_ptr_sockaddr_in(addr_ptr)),
          &_servers[fd]);
}

void Server::accept_connections(void) {
  for (Servers::iterator it = _servers.begin()
      ; it != _servers.end()
      ; it++) {
    if (FD_ISSET(it->first, &_read_fds)) {
      LockGuard<Mutex> _lg(&Engine::connection_controller);
      init_connection(it->first);
    }
  }
}

void Server::erase_client(int fd) {
  if (_clients.find(fd) != _clients.end()) {
    ft::safe_delete(&_clients[fd]);
    _clients.erase(fd);
    Engine::logger.debug(combine_title("connection closed on "
                        + ft::to_string(fd)));
  }
}

void Server::close_client_connection(int fd) {
  erase_fd(fd);
  erase_client(fd);
}

void Server::check_timeout_disconnect(Client *client) {
  if (client->is_timeout()) {
    client->init_response(408, &_serv_contexts);
  }
  if (!client->is_connectable()) {
    client->init_response(503, &_serv_contexts);
  }
}

void Server::iterate_clients(void) {
  Clients::iterator back_up_it_on_erase = _clients.begin();
  for (Clients::iterator it = _clients.begin()
      ; it != _clients.end()
      ; it = back_up_it_on_erase) {
    int client_fd = it->first;
    back_up_it_on_erase++;
    if (FD_ISSET(client_fd, &_read_fds) && !recv(client_fd)) {
      close_client_connection(client_fd);
      continue;
    }
    check_timeout_disconnect(it->second);
    if (FD_ISSET(client_fd, &_write_fds) && !send(client_fd)) {
      close_client_connection(client_fd);
      continue;
    }
  }
}

void Server::io_multiplexing(void) {
  if (monitor_connections() < 0) {
    return;
  }
  accept_connections();
  iterate_clients();
}

void Server::delay_a_moment(void) {
  usleep(DEFAULT_DELAY);
}

void Server::loop(void) {
  Engine::logger.info(combine_title("Booting Up Server ..."));
  while (Server::_is_alive) {
    init_fds_for_select();
    io_multiplexing();
    delay_a_moment();
  }
  Engine::logger.info(combine_title("Shutting Down Server ..."));
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

std::string Server::combine_title(const std::string& msg) const {
  return _current_title + msg;
}

void Server::run(int worker_id) {
  Server::_is_alive = true;
  set_worker_id(worker_id);
  set_current_title(worker_id);
  set_default_timeout();
  set_signal_handlers();
  loop();
  clear_clients();
}
