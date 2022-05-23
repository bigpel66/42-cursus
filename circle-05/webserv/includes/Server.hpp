// Copyright @bigpel66

// Header for the producer of requested tasks
#ifndef CIRCLE_05_WEBSERV_INCLUDES_SERVER_HPP_
#define CIRCLE_05_WEBSERV_INCLUDES_SERVER_HPP_

// Standard Library Inclusion
#include <map>
#include <string>

// Class Headers Inclusion
#include "./Utilizer.hpp"

class Server {
 private:
  FDs _fds;
  int _max_fd;
  std::string _current_title;

  // This is for tracking the signal exit on multi-threading
  static bool _is_server_alive;

  fd_set _master_fds;
  fd_set _read_fds;
  fd_set _write_fds;

  const Options& _options;
  const ServerConfigs& _server_configs;

  Clients _clients;
  Servers _servers;

  Server(void);

 public:
  Server(const Options& options, const ServerConfigs& server_configs);
  Server(const Server& s);
  Server& operator=(const Server& s);
  ~Server(void);

  static void set_server_alive_status(bool is_alive);

  void insert_fd(int fd);
  void erase_fd(int fd);
  void run(int worker_id);
};

#endif  // CIRCLE_05_WEBSERV_INCLUDES_SERVER_HPP_
