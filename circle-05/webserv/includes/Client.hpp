// Copyright  @bigpel66

// Header for the client of the server
#ifndef CIRCLE_05_WEBSERV_INCLUDES_CLIENT_HPP_
#define CIRCLE_05_WEBSERV_INCLUDES_CLIENT_HPP_

// Standard Library Inclusion
#include <string>

// Class Headers Inclusion
#include "./Utilizer.hpp"
#include "./Request.hpp"
#include "./Response.hpp"
#include "./ReqContext.hpp"

class Request;
class ReqContext;
class Response;

class Client {
 private:
  int _fd;
  int _worker_id;
  bool _is_connectable;
  std::string _addr;
  Listen& _listen;

  ReqContext *_req_context;
  Request *_req;
  Response *_res;

  void init_req_context(ServContexts *servers);
  void build_response_and_check_redirection(void);

  Client(void);
  Client(const Client& c);
  const Client& operator=(const Client& c);

 public:
  Client(int fd,
        int worker_id,
        bool is_connectable,
        const std::string& addr,
        Listen& listen);
  ~Client(void);

  void clear(void);
  void init_response(int code, ServContexts *servers);

  bool is_timeout(void);
  bool is_connectable(void) const;
  Listen *get_listen(void);
  const std::string& get_addr(void) const;

  ReqContext *get_req_context(void) const;
  Request *get_request(void);
  Response *get_response(void) const;
};

#endif  // CIRCLE_05_WEBSERV_INCLUDES_CLIENT_HPP_
