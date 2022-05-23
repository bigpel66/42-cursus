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
  ServerConfigs& _server_configs;
  Options& _options;

  Clients _clients;
  Servers _servers;

  Server(void);

 public:
  Server(const Server& s);
  Server& operator=(const Server& s);
  ~Server(void);
};

#endif  // CIRCLE_05_WEBSERV_INCLUDES_SERVER_HPP_
