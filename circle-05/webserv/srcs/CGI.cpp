// Copyright @bigpel66

#include "../includes/CGI.hpp"
#include "../includes/Client.hpp"
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

CGI::~CGI(void) {
  ft::safe_free(reinterpret_cast<void **>(&(_argv[0])));
  ft::safe_free(reinterpret_cast<void **>(&(_argv[1])));
  ft::safe_free_all(reinterpret_cast<void ***>(&_envp));
  _tmp.close();
  _tmp.unlink();
}

void CGI::init(void) {
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
  _tmp.set_path("/tmp/webserv_tmp_cgi_" + std::to_string(_worker_id), false);
  _tmp.open(true);
}

void CGI::set_env(void) {
  if (_req_context.get_method() == "POST") {
    _env["CONTENT_TYPE"] = _req_context.get_header("Content-Type");
    _env["CONTENT_LENGTH"] = std::to_string(_req_body.length());
  }
  _env["GATEWAY_INTERFACE"] = "CGI/1.1";
  _env["PATH_INFO"] = _file_path;
  _env["PATH_TRANSLATED"] = _file_path;
  _env["QUERY_STRING"] = _req_context.get_query_string();
  _env["REMOTE_ADDR"] = _req_context.get_client().get_addr();
  if (_req_context.get_auth() != "off") {
    _env["AUTH_TYPE"] = "BASIC";
    _env["REMOTE_IDENT"] = _req_context.get_auth()
                                  .substr(0, _req_context.get_auth().find(':'));
    _env["REMOTE_USER"] = _req_context.get_auth()
                                  .substr(0, _req_context.get_auth().find(':'));
  }
  _env["REQUEST_METHOD"] = _req_context.get_method();
  _env["REQUEST_URI"] = _file_path;
  _env["SCRIPT_NAME"] = _cgi_path;
  _env["SERVER_NAME"] = _req_context.get_host();
  _env["SERVER_PROTOCOL"] = _req_context.get_protocol();
  _env["SERVER_PORT"] = std::to_string(_req_context.get_port());
  _env["SERVER_ SOFTWARE"] = "WEBSERV/1.0";
  if (_extension == ".php") {
    _env["REDIRECT_STATUS"] = "200";
  }
  for (Headers::const_iterator it = _req_context.get_headers().begin()
      ; it != _req_context.get_headers().end()
      ; it++) {
    if (!it->second.empty()) {
      std::string header = "HTTP_" + ft::toupper(it->first);
      std::replace(header.begin(), header.end(), '-', '_');
      _env[header] = it->second;
    }
  }
  _envp = reinterpret_cast<char **>(malloc(sizeof(char *) * (_env.size() + 1)));
  if (!_envp) {
    return;
  }
  int i = 0;
  for (Envs::const_iterator it = _env.begin()
      ; it != _env.end()
      ; it++) {
    std::string tmp = it->first + "=" + it->second;
    _envp[i] = ::strdup(tmp.c_str());
    if (!_envp[i]) {
      return;
    }
    i++;
  }
  _envp[i] = ft::nil;
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

int CGI::exec(void) {

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
    std::size_t content_length = std::strtod((*headers)["Content-Length"].c_str(), ft::nil);
    _cgi_body.erase(content_length);
  }
}
