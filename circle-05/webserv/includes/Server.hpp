// Copyright @bigpel66

// Header for the producer of requested tasks
#ifndef CIRCLE_05_WEBSERV_INCLUDES_SERVER_HPP_
#define CIRCLE_05_WEBSERV_INCLUDES_SERVER_HPP_

// Standard Library Inclusion
#include <string>
#include <map>

// Class Headers Inclusion
#include "./Utilizer.h"  // For the using type definition
#include "./Worker.hpp"  // Server holds workers to delegate task
#include "./Thread.hpp"  // Server runs as thread
#include "./Client.hpp"  // Client to get request
#include "./Mutex.hpp"  // Mutext to control concurrency like log things

class Worker;

// Enum Server Descriptor Status
enum server_desc_status {
  busy_server_desc,
  idle_server_desc
};

class Server : public AbstractThread {
 private:
  int _id;
  int _port;
  int _socket;
  int _max_sd;
  bool _is_auto_index_on;
  server_desc_status _desc_status;

  std::string _server_name;
  sock_addr _server_addr;
  sock_addr _client_addr;

  std::map<int, Worker *> _workers;
  std::map<int, std::string> error_pages;
  std::map<std::string, std::string> _mimes;

  fd_set _client_fd;
  fd_set _temp_fd;

  Mutex _logger;

  Server(void);
  Server(const Server& s);
  Server& operator=(const Server& s);

 public:
  explicit Server(int port);
  virtual ~Server(void);

  int get_id(void) const;
  int get_port(void) const;
  int get_socket(void) const;
  int get_max_sd(void) const;
  server_desc_status get_desc_status(void) const;
  const std::string& get_server_name(void) const;
  const sock_addr& get_server_addr(void) const;
  const sock_addr& get_client_addr(void) const;

  void set_id(int id);
  void set_max_sd(void);
  void set_temp_fd(void);
  void set_desc_status(server_desc_status desc_status);

  fd_set *get_client_fd(void) const;
  fd_set *get_temp_fd(void) const;

  const Mutex& get_logger(void) const;

  virtual void run(void) throw();

  void error(const std::string& s) const;
  void log(const std::string& s) const;

  void GET(Header *header, const Client& client, std::string *response);
  void POST(Header *header, const Client& client, std::string *response);
  void PUT(Header *header, const Client& client, std::string *response);
  void DELETE(Header *header, const Client& client, std::string *response);
};

#endif  // CIRCLE_05_WEBSERV_INCLUDES_SERVER_HPP_
