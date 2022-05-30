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

class ReqContext;

class CGI {
 private:
  int _worker_id;
  char **_envp;
  char *_argv[3];

  const File &_file;
  ReqContext &_req_context;

  std::string _cwd;
  std::string _extension;
  std::string _file_path;
  std::string _req_body;
  std::string _cgi_body;
  std::string _cgi_exec;
  std::string _cgi_path;
  File _tmp;
  Envs _env;

  void init(void);
  void set_env_on_POST(void);
  void set_env_on_auth(void);
  void set_env_on_redirect(void);
  void set_env_on_others(void);
  void convert_key_value_to_cgi_header_form(void);
  bool set_env(void);

  bool is_envp_ready_to_exec(void);
  bool is_request_not_sendable(int pipe_read_fd) const;
  bool is_supported_extensions(void) const;
  bool is_body_separatable(void) const;
  bool is_valid_pair_on_colon_separated(void) const;
  std::size_t get_crlf_position_from_body(void) const;
  std::size_t get_colon_position_from_body(void) const;
  void remove_crlf_from_body(std::size_t crlf_position);

  void case_on_exec_child(int cgi_pipe[2]);
  int case_on_exec_parent(int cgi_pipe[2], pid_t pid);

  CGI(void);
  CGI(const CGI& c);
  CGI& operator=(const CGI& c);

 public:
  CGI(int worker_id, const File& file, ReqContext *config);
  ~CGI(void);

  const std::string& get_body(void) const;
  int exec(void);
  void parse_headers(Headers *headers);
};

#endif  // CIRCLE_05_WEBSERV_INCLUDES_CGI_HPP_
