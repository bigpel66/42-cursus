// Copyright @bigpel66

// Header for the producer of requested tasks
#ifndef CIRCLE_05_WEBSERV_INCLUDES_SERVER_HPP_
#define CIRCLE_05_WEBSERV_INCLUDES_SERVER_HPP_

// Standard Library Inclusion
#include <map>
#include <string>

// Class Headers Inclusion
#include "./Utilizer.hpp"
#include "./Logger.hpp"
#include "./LockGuard.hpp"

class Server {
 private:
  FDs _fds;
  int _max_fd;
  std::string _current_title;

  // This is for tracking the signal exit on multi-threading
  static bool _is_alive;
  // This is for controlling the server status on multi-threading
  static Mutex _status_controller;
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
  void set_current_title(int worker_id);

  void kill_server(const std::string& msg);
  void insert_fd(int fd);
  void erase_fd(int fd);
  void copy_read_fds_before_select(void);
  void copy_write_fds_before_select(void);
  void init_fds_for_select(void);
  void io_multiplexing(void);
  void loop(void);
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
