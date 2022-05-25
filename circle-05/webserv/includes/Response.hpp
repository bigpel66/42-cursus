// Copyright @bigpel66

// Header for the response to the client
#ifndef CIRCLE_05_WEBSERV_INCLUDES_RESPONSE_HPP_
#define CIRCLE_05_WEBSERV_INCLUDES_RESPONSE_HPP_

// Standard Library Inclusion
#include <string>

// Class Headers Inclusion
#include "./File.hpp"
#include "./Client.hpp"
#include "./Logger.hpp"
#include "./Utilizer.hpp"
#include "./ReqContext.hpp"

class Response {
 private:
  int _worker_id;
  int _code;
  int _status_code;

  std::size_t _total_sent;
  std::size_t _header_size;
  std::size_t _body_size;

  bool _is_redirected;

  std::string _redirected_target;
  std::string _accepted_charset;
  std::string _response;
  std::string _body;

  File _file;
  Headers _headers;
  MethodConverters _mux;

  const ReqContext& _req_context;

  Response(void);
  Response(const Response& r);
  Response& operator=(const Response& r);

 public:
  Response(int worker_id, int code, const ReqContext& req_context);
  ~Response(void);

  void build(void);
  void clear(void);

  int send(int fd);
  int GET(void);
  int POST(void);
  int PUT(void);
  int DELETE(void);

  bool is_redirected(void) const;
  bool is_connection_close_specified(void) const;

  const std::string& get_redirected_target(void) const;
  std::string get_log(void);
};

#endif  // CIRCLE_05_WEBSERV_INCLUDES_RESPONSE_HPP_
