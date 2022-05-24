// Copyright  @bigpel66

#ifndef CIRCLE_05_WEBSERV_INCLUDES_CLIENT_HPP_
#define CIRCLE_05_WEBSERV_INCLUDES_CLIENT_HPP_

// Standard Library Inclusion
#include <string>

// Class Headers Inclusion
#include "./Utilizer.hpp"

class Request;
class RequestConfig;
class Response;

class Client {
 private:
  int _fd;
  int _worker_id;
  bool _is_connectable;
  std::string _addr;
  const Listen& _listen;

  Request *_req;
  RequestConfig *_req_config;
  Response *_res;

  Client(void);
  Client(const Client& c);
  const Client& operator=(const Client& c);

 public:
  Client(int client_fd,
        int worker_id,
        bool is_connectable,
        std::string addr,
        const Listen& listen);
  ~Client(void);

  bool is_timeout(void) const;
  bool is_connectable(void) const;

  void set_request_config(const Options& options,
                          const ServerConfigs& server_configs);
  void set_reponse(const Options& options,
                  const ServerConfigs& server_configs,
                   int code);
  void clear(void);
};

#endif  // CIRCLE_05_WEBSERV_INCLUDES_CLIENT_HPP_
