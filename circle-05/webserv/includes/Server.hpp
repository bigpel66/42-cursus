// Copyright @bigpel66

// Header for the producer of requested tasks
#ifndef CIRCLE_05_WEBSERV_INCLUDES_SERVER_HPP_
#define CIRCLE_05_WEBSERV_INCLUDES_SERVER_HPP_

// Standard Library Inclusion
#include <map>
#include <string>

// Class Headers Inclusion
#include "./Logger.hpp"
#include "./Client.hpp"
#include "./Request.hpp"
#include "./Utilizer.hpp"
#include "./Response.hpp"
#include "./LockGuard.hpp"

class Server {
 private:
  FDs _fds;
  int _max_fd;
  std::string _current_title;

  int _worker_id;

  // This is for the unchangable value on setting socket
  static const bool _reuse_addr = true;

  // This is for tracking the signal exit on multi-threading
  static bool _is_alive;
  // This is for controlling the server status on multi-threading
  static Mutex _status_controller;
  // This is for controlling the server connection on multi-threading
  static Mutex _connection_controller;
  // This is for controlling the server response on multi-threading
  static Mutex _response_controller;
  // Measure timeval to timeout the select i/o multiplexing
  struct timeval _timeout;

  Logger *_logger;

  fd_set _master_fds;
  fd_set _read_fds;
  fd_set _write_fds;

  const Options& _options;
  const ServerConfigs& _server_configs;

  Clients _clients;
  Servers _servers;

  void set_signal_handlers(void) const;
  void set_default_timeout(void);
  void set_worker_id(int worker_id);
  void set_current_title(int worker_id);

  bool is_connection_requested_on(int fd) const;
  bool is_data_readable_from_client_on(int fd) const;
  bool is_data_writable_to_client_on(int fd) const;
  bool is_connection_closable_on_recv(int client_fd);
  bool is_connection_closable_on_send(int client_fd);
  bool is_nothing_received(ssize_t buffer_read_size) const;
  bool is_nothing_sent(int code) const;
  bool is_data_fully_sent(int code) const;
  bool is_client_response_settable(int code) const;
  bool is_conneciton_needs_to_be_closed(Response *res, Client *client) const;
  bool is_binded_includes_given_listen(const Listens& binded,
                                      const Listen& listen) const;

  void init(void);
  void init_socket_binding(Listens *binded, const Listen& listen);

  void insert_default_listen(Listens *binded,
                            const ServerConfig& server_config);
  void iterate_listens_of_server_config(Listens *binded,
                                        const ServerConfig& server_config);
  void check_nothing_binded(const Listens& binded);

  void init_connection(int server_fd);
  void init_response_by_status_code(Client *client, int status_code);
  void init_response_by_timeout_or_disconnect(Client *client);

  std::string combine_title(const std::string& msg) const;
  bool recv_data_on(int clienet_fd);
  bool send_data_on(int clienet_fd);

  void kill_server(const std::string& msg);
  void insert_fd(int fd);
  void erase_fd(int fd);
  void erase_client(int fd);
  void copy_read_fds_before_select(void);
  void copy_write_fds_before_select(void);
  void init_fds_for_select(void);
  void monitor_connections(void);
  void accept_connections(void);
  void close_client_connection(int client_fd);
  void iterate_clients(void);
  void io_multiplexing(void);
  void delay_a_second(void);
  void loop(void);
  void clear_clients(void);
  void run(int worker_id);

  Server(void);

 public:
  Server(Logger *logger,
        const Options& options,
        const ServerConfigs& server_configs);
  Server(const Server& s);
  Server& operator=(const Server& s);
  ~Server(void);

  // Static due to the non-member function signal handler
  static void set_alive_status(bool is_alive);
};

void server_signal_handler(int sig);

#endif  // CIRCLE_05_WEBSERV_INCLUDES_SERVER_HPP_
