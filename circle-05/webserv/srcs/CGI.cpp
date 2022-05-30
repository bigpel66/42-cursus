// Copyright @bigpel66

#include "../includes/CGI.hpp"
#include "../includes/Parser.hpp"

CGI::CGI(int worker_id, const File& file, ReqContext *req_context)
  : _worker_id(worker_id),
    _envp(ft::nil),
    _file(file),
    _req_context(*req_context) {
  if (_req_context.get_body().empty() && _req_context.get_method() != "POST") {
    _req_body = _file.get_content();
  } else {
    _req_body = _req_context.get_body();
  }
  init();
}

CGI::~CGI() {
  ft::safe_free(reinterpret_cast<void **>(&(_argv[0])));
  ft::safe_free(reinterpret_cast<void **>(&(_argv[1])));
  ft::safe_free_all(reinterpret_cast<void ***>(&_envp));
  _tmp.close();
  _tmp.unlink();
}

void CGI::init() {
  _argv[0] = ft::nil;
  _argv[1] = ft::nil;
  _argv[2] = ft::nil;
  char *cwd = getcwd(ft::nil, 0);
  if (!cwd) {
    return;
  }
  _cwd = cwd;
  ft::safe_free(reinterpret_cast<void **>(&cwd));
  _extension = _file.get_extension();
  _cgi_exec = _req_context.get_cgi(_extension);
  if (_req_context.get_cgi_bin()[0] == '/') {
    _cgi_path = _req_context.get_cgi_bin() + "/" + _cgi_exec;
  } else {
    _cgi_path = _cwd + "/" + _req_context.get_cgi_bin() + "/" + _cgi_exec;
  }
  _file_path = _cwd + "/" + _file.get_path();
  _tmp.set_path("/tmp/webserv_cgi_tmp_" + ft::to_string(_worker_id));
  _tmp.open(true);
}

void CGI::set_env_on_POST(void) {
  if (_req_context.get_method() == "POST") {
    _env["CONTENT_TYPE"] = _req_context.get_header("Content-Type");
    _env["CONTENT_LENGTH"] = std::to_string(_req_body.length());
  }
}

void CGI::set_env_on_auth(void) {
  if (_req_context.get_auth() != "off") {
    _env["AUTH_TYPE"] = "BASIC";
    _env["REMOTE_IDENT"] = _req_context.get_auth()
                                  .substr(0, _req_context.get_auth().find(':'));
    _env["REMOTE_USER"] = _req_context.get_auth()
                                  .substr(0, _req_context.get_auth().find(':'));
  }
}

void CGI::set_env_on_redirect(void) {
  if (is_supported_extensions()) {
    _env["REDIRECT_STATUS"] = "200";
  }
}

void CGI::set_env_on_others(void) {
  _env["GATEWAY_INTERFACE"] = "CGI/1.1";
  _env["PATH_INFO"] = _file_path;
  _env["PATH_TRANSLATED"] = _file_path;
  _env["QUERY_STRING"] = _req_context.get_query_string();
  _env["REMOTE_ADDR"] = _req_context.get_client().get_addr();
  _env["REQUEST_METHOD"] = _req_context.get_method();
  _env["REQUEST_URI"] = _file_path;
  _env["SCRIPT_NAME"] = _cgi_path;
  _env["SERVER_SOFTWARE"] = "WEBSERV/1.0";
  _env["SERVER_NAME"] = _req_context.get_host();
  _env["SERVER_PROTOCOL"] = _req_context.get_protocol();
  _env["SERVER_PORT"] = std::to_string(_req_context.get_port());
}

void CGI::convert_key_value_to_cgi_header_form(void) {
  for (Headers::const_iterator it = _req_context.get_headers().begin()
      ; it != _req_context.get_headers().end()
      ; it++) {
    if (!it->second.empty()) {
      std::string header = "HTTP_" + ft::toupper(it->first);
      std::replace(header.begin(), header.end(), '-', '_');
      _env[header] = it->second;
    }
  }
}

bool CGI::set_env(void) {
  set_env_on_POST();
  set_env_on_auth();
  set_env_on_redirect();
  set_env_on_others();
  convert_key_value_to_cgi_header_form();
  return is_envp_ready_to_exec();
}

bool CGI::is_envp_ready_to_exec(void) {
  _envp = reinterpret_cast<char **>(malloc(sizeof(char *) * (_env.size() + 1)));
  if (!_envp) {
    return false;
  }
  int i = 0;
  for (Envs::const_iterator it = _env.begin()
      ; it != _env.end()
      ; it++) {
    std::string tmp = it->first + "=" + it->second;
    _envp[i] = ::strdup(tmp.c_str());
    if (!_envp[i]) {
      return false;
    }
    i++;
  }
  _envp[i] = ft::nil;
  return true;
}

bool CGI::is_request_not_sendable(int pipe_read_fd) const {
  return _req_body.length() &&
          write(pipe_read_fd, _req_body.c_str(), _req_body.length()) <= 0;
}

bool CGI::is_supported_extensions(void) const {
  return _extension == ".php";
}

bool CGI::is_body_separatable(void) const {
  return !Parser::is_npos(get_crlf_position_from_body());
}

bool CGI::is_valid_pair_on_colon_separated(void) const {
  return !Parser::is_npos(get_colon_position_from_body());
}

std::size_t CGI::get_crlf_position_from_body(void) const {
  return _cgi_body.find("\r\n");
}

std::size_t CGI::get_colon_position_from_body(void) const {
  return _cgi_body.find(':');
}

void CGI::remove_crlf_from_body(std::size_t crlf_position) {
  _cgi_body.erase(0, crlf_position + 2);
}

const std::string& CGI::get_body(void) const {
  return _cgi_body;
}

void CGI::case_on_exec_child(int cgi_pipe[2]) {
  if (chdir(_file_path.substr(0, _file_path.find_last_of('/')).c_str()) == -1) {
    exit(1);
  }
  close(cgi_pipe[1]);
  if (dup2(cgi_pipe[0], 0) == -1) {
    exit(1);
  }
  if (dup2(_tmp.get_fd(), 1) == -1) {
    exit(1);
  }
  close(cgi_pipe[0]);
  execve(_argv[0], _argv, _envp);
  exit(1);
}

int CGI::case_on_exec_parent(int cgi_pipe[2], pid_t pid) {
  close(cgi_pipe[0]);
  if (is_request_not_sendable(cgi_pipe[1])) {
    return 500;
  }
  close(cgi_pipe[1]);
  int status;
  if (waitpid(pid, &status, 0) == -1) {
    return 500;
  }
  if (WIFEXITED(status) && WEXITSTATUS(status)) {
    return 502;
  }
  _cgi_body = _tmp.get_content();
  return 200;
}

int CGI::exec(void) {
  if (!set_env()) {
    return 500;
  }
  _argv[0] = ::strdup(_cgi_path.c_str());
  _argv[1] = ::strdup(_file_path.c_str());
  _argv[2] = ft::nil;
  if (!_argv[0] || !_argv[1]) {
    return 500;
  }
    int cgi_pipe[2];
  if (pipe(cgi_pipe)) {
    return 500;
  }
  pid_t pid = fork();
  if (pid < 0) {
    return 502;
  } else if (!pid) {
    case_on_exec_child(cgi_pipe);
  }
  return case_on_exec_parent(cgi_pipe, pid);
}

void CGI::parse_headers(Headers *headers) {
  while (is_body_separatable()) {
    std::size_t crlf_position = get_crlf_position_from_body();
    if (crlf_position == 0) {
      remove_crlf_from_body(crlf_position);
      break;
    }
    if (is_valid_pair_on_colon_separated()) {
      std::size_t colon_position = get_colon_position_from_body();
      std::string key = _cgi_body.substr(0, colon_position);
      std::string val = _cgi_body.substr(colon_position + 1,
                                        crlf_position - colon_position - 1);
      (*headers)[key] = Parser::trim_whitespace(&val);
    }
    remove_crlf_from_body(crlf_position);
  }
  if (headers->count("Content-Length")) {
    std::size_t size = ft::stoi((*headers)["Content-Length"]);
    _cgi_body.erase(size);
  }
}
