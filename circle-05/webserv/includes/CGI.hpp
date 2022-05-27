// Copyright @bigpel66

// Header for the handling requested cgi tasks
#ifndef CIRCLE_05_WEBSERV_INCLUDES_CGI_HPP_
#define CIRCLE_05_WEBSERV_INCLUDES_CGI_HPP_

// Standard Library Inclusion
#include <string>

// Class Headers Inclusion
#include "./File.hpp"
#include "./Utilizer.hpp"
#include "./ReqContext.hpp"

class CGI {
 private:
  int _worker_id;
  char **_envp;
  char *_argv[3];

  const File& _file;
  ReqContext& _req_context;

  std::string _cwd;
  std::string _extension;
  std::string _file_path;
  std::string _req_body;
  std::string _res_body;
  std::string _cgi_exec;
  std::string _cgi_path;
  File _tmp;
  Envs _env;

  void init(void);
  void set_env(void);

  CGI(void);
  CGI(const CGI& c);
  CGI& operator=(const CGI& c);

 public:
  CGI(int worker_id, const File& file, ReqContext *req_context);
  ~CGI(void);

  const std::string& get_body(void) const;
  int exec(void);
  void parse_headers(Headers *headers);
};

#endif  // CIRCLE_05_WEBSERV_INCLUDES_CGI_HPP_
