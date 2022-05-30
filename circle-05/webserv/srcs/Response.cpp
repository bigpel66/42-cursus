// Copyright @bigpel66

#include "../includes/Response.hpp"
#include "../includes/Engine.hpp"

Response::Response(int code, int worker_id, ReqContext *config)
  : _code(code),
    _worker_id(worker_id),
    _status_code(0),
    _redirect_code(0),
    _total_sent(0),
    _header_size(0),
    _body_size(0),
    _is_redirected(false),
    _req_ctx(*config) {
  init_method_converter();
}

Response::~Response(void) {}

void Response::clear() {
  _code = 0;
  _status_code = 0;
  _total_sent = 0;
  _header_size = 0;
  _body_size = 0;
  _is_redirected = false;
  _response.clear();
  _body.clear();
  _headers.clear();
}

void Response::case_on_cgi(void) {
  CGI cgi(_worker_id, _file, &_req_ctx);
  _status_code = cgi.exec();
  if (_status_code > 400) {
    return;
  }
  cgi.parse_headers(&_headers);
  _body = cgi.get_body();
  _headers["Content-Length"] = ft::to_string(_body.length());
}

bool Response::case_on_GET_or_HEAD_with_return_possible(void) {
  if (_file.is_directory()) {
    std::string index = _file.find_index(_req_ctx.get_indexes());
    if (index.length()) {
      _is_redirected = true;
      _redirected_target = ft::get_sole_slash("/"
                            + _req_ctx.get_target()
                            + "/"
                            + index);
      _status_code = 200;
      return true;
    } else if (!_req_ctx.get_autoindex()) {
      _status_code = 404;
      return true;
    }
  }
  std::string path = _file.get_path();
  if (!_file.is_directory()) {
    if (!_file.is_exist()) {
      _status_code = 404;
      return true;
    }
    if (!_file.open()) {
      _status_code = 403;
      return true;
    }
    _headers["Last-Modified"] = _file.get_last_modified();
  }
  return false;
}

void Response::case_on_POST_or_PUT(void) {
  std::string path = _req_ctx.get_uri() + "/" + _req_ctx.get_resource();
  if (!_req_ctx.get_upload().empty()) {
    File dir(_req_ctx.get_root() + "/" + _req_ctx.get_upload());
    path = _req_ctx.get_uri()
            + "/"
            + _req_ctx.get_upload()
            + "/"
            + _req_ctx.get_resource();
    if (dir.is_exist() && !dir.is_directory()) {
      dir.unlink();
    }
    if (!dir.is_exist()) {
      mkdir(dir.get_path().c_str(), 0755);
    }
    _file.set_path(dir.get_path() + "/" + _req_ctx.get_resource());
  }
  _headers["Location"] = ft::get_sole_slash(path);
}

void Response::case_on_methods(void) {
  const std::string &method = _req_ctx.get_method();
  std::string path;

  if (is_method_GET_or_HEAD()) {
    if (case_on_GET_or_HEAD_with_return_possible()) {
      return;
    }
  }
  if (is_cgi()) {
    case_on_cgi();
    return;
  }
  if (is_method_POST_or_PUT()) {
    case_on_POST_or_PUT();
  }
  _status_code = (this->*(Response::_mux[method]))();
}

std::string Response::init_allowed_methods(void) {
  std::vector<std::string> methods = _req_ctx.get_methods();
  std::string list;

  std::vector<std::string>::iterator it = methods.begin();

  while (it != methods.end()) {
    list += *it;
    it++;
    if (it != methods.end())
      list += ", ";
  }
  return list;
}

void Response::init_response(void) {
  _headers["Server"] = "webserv/1.0";
  if (_req_ctx.get_method() == "HEAD") {
    _body.clear();
  }
  if (is_redirectable()) {
    _status_code = _redirect_code;
  }
  std::string status_code;
  if (_headers.count("Status")) {
    status_code = _headers["Status"];
    _headers.erase("Status");
  } else {
    status_code = ft::to_string(_status_code)
                  + " "
                  + Engine::status_codes[_status_code];
  }
  _response += _req_ctx.get_protocol() + " " + status_code + "\r\n";
  _headers["Date"] = ft::get_current_datetime();
  for (Headers::iterator it = _headers.begin(); it != _headers.end(); it++) {
    _response += it->first + ": " + it->second + "\r\n";
  }
  _response += "\r\n";
  _header_size = _response.size();
  if (!_body.empty()) {
    _body_size = _body.size();
    _response += _body;
    _body.clear();
  }
}

void Response::init_error_page(void) {
  if (!_req_ctx.get_error_page(_status_code).empty()) {
    std::string e = ft::get_sole_slash(_req_ctx.get_error_page(_status_code));
    std::string c = ft::get_sole_slash("/" + _req_ctx.get_resource());
    if (e != c) {
      _req_ctx.set_method("GET");
      _is_redirected = true;
      _redirect_code = _status_code;
      _redirected_target = e;
      _status_code = 0;
      return;
    }
  }
  _body += "<html>\r\n";
  _body += "<head><title>"
            + ft::to_string(_status_code)
            + " "
            + Engine::status_codes[_status_code]
            + "</title></head>\r\n";
  _body += "<body>\r\n";
  _body += "<center><h1>"
            + ft::to_string(_status_code)
            + " "
            + Engine::status_codes[_status_code]
            + "</h1></center>\r\n";
  _body += "<hr><center>" + _headers["Server"] + "</center>\r\n";
  _body += _file.get_autoindex(_req_ctx.get_target());
  _body += "</body>\r\n";
  _body += "</html>\r\n";
  _headers["Content-Type"] = Engine::mimes.get_type(".html");
  _headers["Content-Length"] = ft::to_string(_body.length());
  if (_status_code == 401) {
    _headers["WWW-Authenticate"] = "Basic realm=\"Access to restricted area\"";
  }
  if (_status_code == 408 || _status_code == 503) {
    _headers["Connection"] = "close";
  }
  if (_status_code == 503) {
    _headers["Retry-After"] = "30";
  }
}

void Response::build() {
  _file.set_path(_req_ctx.get_root() + "/" + _req_ctx.get_resource());
  if (_code > 1) {
    _status_code = _code;
  } else if (!_req_ctx.is_method_acceptable(_req_ctx.get_method())) {
    _status_code = 405;
    _headers["Allow"] = init_allowed_methods();
  } else if (is_body_size_constrained()) {
    _status_code = 413;
  } else if (_req_ctx.get_auth() != "off" && !is_authenticated()) {
    _status_code = 401;
  } else {
    case_on_methods();
  }
  if (is_something_wrong_on_redirect()) {
    init_error_page();;
  }
  if (!_is_redirected) {
    init_response();
  }
}

bool Response::is_method_GET_or_HEAD(void) const {
  return _req_ctx.get_method() == "GET" ||
          _req_ctx.get_method() == "HEAD";
}

bool Response::is_method_POST_or_PUT(void) const {
  return _req_ctx.get_method() == "POST" ||
          _req_ctx.get_method() == "PUT";
}

bool Response::is_cgi(void) {
  const CGIs& cgi = _req_ctx.get_cgis();
  for (CGIs::const_iterator it = cgi.begin(); it != cgi.end(); it++) {
    if (it->first == _file.get_extension())
      return true;
  }
  return false;
}

bool Response::is_authenticated(void) const {
  if (_req_ctx.get_header("Authorization").empty()) {
    return false;
  }
  const std::string& cred = _req_ctx.get_header("Authorization");
  std::string token = ft::base64_decode(cred.substr(cred.find(' ') + 1));
  return token == _req_ctx.get_auth();
}

bool Response::is_body_size_constrained(void) const {
  return _req_ctx.get_client_max_body_size() > 0 &&
          _req_ctx.get_body().length() >
          _req_ctx.get_client_max_body_size();
}

bool Response::is_something_wrong_on_redirect(void) const {
  return _status_code >= 300 && !_body.length();
}

bool Response::is_redirectable(void) const {
  return _status_code < 400 && _redirect_code;
}

bool Response::is_connectable() {
  return !(_headers.find("Connection") != _headers.end() &&
          _headers["Connection"] == "close");
}

bool Response::is_redirected(void) const {
  return _is_redirected;
}

const std::string& Response::get_redirected_target(void) const {
  return _redirected_target;
}

int Response::GET() {
  LockGuard<Mutex> _lg(&Engine::response_controller);
  if (_req_ctx.get_autoindex() && _file.is_directory()) {
    _headers["Content-Type"] = Engine::mimes.get_type(".html");
    _body = _file.get_autoindex(_req_ctx.get_target());
    _headers["Content-Length"] = ft::to_string(_body.length());
  } else {
    _headers["Content-Type"] = Engine::mimes.get_type(_file.get_extension());
    _body = _file.get_content();
    _headers["Content-Length"] = ft::to_string(_body.length());
  }
  return 200;
}

int Response::POST() {
  LockGuard<Mutex> _lg(&Engine::response_controller);
  int status_code = 200;
  _body = _req_ctx.get_body();
  if (!_file.is_exist()) {
    _file.create(_body);
    status_code = 201;
  } else {
    _file.append(_body);
    status_code = 200;
  }
  _headers["Content-Length"] = ft::to_string(_body.length());
  return status_code;
}

int Response::PUT() {
  LockGuard<Mutex> _lg(&Engine::response_controller);
  int status_code = 204;
  if (!_file.is_exist()) {
    _file.create(_req_ctx.get_body());
    _headers["Content-Length"] = "0";
    status_code = 201;
  } else if (_req_ctx.get_body() == "" ||
            _req_ctx.get_body() == _file.get_content()) {
    status_code = 204;
  } else {
    _file.create(_req_ctx.get_body());
  }
  return status_code;
}

int Response::DELETE() {
  LockGuard<Mutex> _lg(&Engine::response_controller);
  if (!_file.is_exist()) {
    return 404;
  }
  _file.unlink();
  _body += "<!DOCTYPE html>\n";
  _body += "<html>\n";
  _body += "<body>\n";
  _body += "  <h1>File deleted</h1>\n";
  _body += "</body>\n";
  _body += "</html>";
  _headers["Content-Type"] = Engine::mimes.get_type(".html");
  _headers["Content-Length"] = ft::to_string(_body.length());
  return 200;
}

void Response::init_method_converter(void) {
  _mux["GET"] = &Response::GET;
  _mux["HEAD"] = &Response::GET;
  _mux["POST"] = &Response::POST;
  _mux["PUT"] = &Response::PUT;
  _mux["DELETE"] = &Response::DELETE;
}

int Response::send(int fd) {
  int code = ::send(fd,
                    _response.c_str() + _total_sent,
                    _response.length() - _total_sent,
                    0);
  if (code <= 0) {
    return -1;
  }
  _total_sent += code;
  if (_total_sent >= _response.length()) {
    return 0;
  }
  return 1;
}
