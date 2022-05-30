// Copyright @bigpel66

// Header for the producer of requested tasks
#ifndef CIRCLE_05_WEBSERV_INCLUDES_SERVER_HPP_
#define CIRCLE_05_WEBSERV_INCLUDES_SERVER_HPP_

// Standard Library Inclusion
#include <map>
#include <string>

// Class Headers Inclusion
#include "./Client.hpp"
#include "./Request.hpp"
#include "./Utilizer.hpp"
#include "./Response.hpp"
#include "./LockGuard.hpp"
#include "./ServContext.hpp"

class Server {
 private:
  FDs _fds;
  int _max_fd;
  int _worker_id;
  std::string _current_title;

  fd_set _master_fds;
  fd_set _read_fds;
  fd_set _write_fds;

  ServContexts& _serv_contexts;
  Servers _servers;
  Clients _clients;

  struct timeval _timeout;

  static bool _is_alive;
  static const bool _reuse_addr;
  static void interrupt_handler(int sig);

  bool is_listen_duplicated(const Listens& binded, const Listen& l) const;
  bool is_nothing_received(ssize_t read_size) const;
  bool is_client_response_settable(int code) const;
  bool recv(int fd);
  bool is_nothing_sent(int code) const;
  bool is_data_full_sent(int code) const;
  bool send(int fd);

  void insert_fd(int fd);
  void erase_fd(int fd);

  void init_socket_binding(Listens *binded, const Listen& l);
  void insert_default_listen_if_empty(ServContext *serv_context);
  void iterate_listens(Listens *binded, ServContext *serv_context);

  void set_worker_id(int worker_id);
  void set_current_title(int worker_id);
  void set_default_timeout(void);
  void set_signal_handlers(void) const;
  void copy_read_fds_before_select(void);
  void copy_write_fds_before_select(void);
  void init_fds_for_select(void);
  int monitor_connections(void);
  void init_connection(int fd);
  void accept_connections(void);
  void erase_client(int fd);
  void close_client_connection(int fd);
  void check_timeout_disconnect(Client *client);
  void iterate_clients(void);
  void io_multiplexing(void);
  void delay_a_moment(void);
  void loop(void);
  void clear_clients(void);

  std::string combine_title(const std::string& msg) const;

  Server(void);

 public:
  Server(const Server& s);
  Server(ServContexts *servers);
  ~Server(void);
  Server &operator=(const Server &copy);

  void init(void);
  void run(int worker_id = 0);
};

#endif  // CIRCLE_05_WEBSERV_INCLUDES_SERVER_HPP_
