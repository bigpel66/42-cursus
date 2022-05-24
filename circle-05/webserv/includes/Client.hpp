// Copyright  @bigpel66

// Header for the client of the server
#ifndef CIRCLE_05_WEBSERV_INCLUDES_CLIENT_HPP_
#define CIRCLE_05_WEBSERV_INCLUDES_CLIENT_HPP_

// Standard Library Inclusion
#include <string>

// Class Headers Inclusion
#include "./Utilizer.hpp"

class Request;
class ReqContext;
class Response;

class Client {
 private:
  int _fd;
  int _worker_id;
  bool _is_connectable;
  std::string _addr;
  const Listen& _listen;

  Request *_req;
  ReqContext *_req_context;
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

  void set_req_context(const Options& options,
                      const ServContexts& serv_contexts);
  void set_response(const Options& options,
                  const ServContexts& serv_contexts,
                  int code);

  Request *get_request(void) const;
  Request *must_get_request(void) const;
  ReqContext *get_req_context(void) const;
  Response *get_response(void) const;
  void clear(void);
};

#endif  // CIRCLE_05_WEBSERV_INCLUDES_CLIENT_HPP_
