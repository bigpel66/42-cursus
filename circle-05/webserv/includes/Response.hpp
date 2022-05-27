// Copyright @bigpel66

// Header for the response to the client
#ifndef CIRCLE_05_WEBSERV_INCLUDES_RESPONSE_HPP_
#define CIRCLE_05_WEBSERV_INCLUDES_RESPONSE_HPP_

// Standard Library Inclusion
#include <string>

// Class Headers Inclusion
#include "./CGI.hpp"
#include "./File.hpp"
#include "./Mimes.hpp"
#include "./Client.hpp"
#include "./Logger.hpp"
#include "./Utilizer.hpp"
#include "./LockGuard.hpp"
#include "./ReqContext.hpp"
#include "./StatusCodes.hpp"

class Response {
 private:
  int _worker_id;
  int _code;
  int _status_code;
  int _redirect_code;

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

  ReqContext& _req_context;

  static StatusCodes _status_codes;
  static Mimes _mimes;
  static Mutex _mutex;

  bool is_body_size_constrained(void) const;
  bool is_authenticated(void) const;
  bool is_something_wrong_on_redirect(void) const;
  bool is_redirectable(void) const;
  bool is_CGI(void) const;
  bool is_method_GET_or_HEAD(void) const;
  bool is_method_POST_or_PUT(void) const;

  void case_on_CGI(void);
  void case_on_GET_or_HEAD(void);
  void case_on_POST_or_PUT(void);
  void case_on_methods(void);
  void init_method_converter(void);
  void init_error_page(void);
  void init_response(void);
  std::string init_allowed_methods(void);

  Response(void);
  Response(const Response& r);
  Response& operator=(const Response& r);

 public:
  Response(int worker_id, int code, ReqContext *req_context);
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
