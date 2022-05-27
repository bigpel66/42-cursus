// Copyright @bigpel66

#include "../includes/Response.hpp"

StatusCodes Response::_status_codes;

Mimes Response::_mimes;

Mutex Response::_mutex;

Response::Response(int worker_id,
                  int code,
                  ReqContext& req_context)
  : _worker_id(worker_id),
    _code(code),
    _status_code(0),
    _redirect_code(0),
    _total_sent(0),
    _header_size(0),
    _body_size(0),
    _is_redirected(false),
    _req_context(req_context) {
  init_method_converter();
}

Response::~Response(void) {}

bool Response::is_connection_close_specified(void) const {
  return _headers.find("Connection") != _headers.end() &&
          _headers.at("Connection") == "close";
}

bool Response::is_redirected(void) const {
  return _is_redirected;
}

bool Response::is_body_size_constrained(void) const {
  return _req_context.get_client_max_body_size() > 0 &&
          _req_context.get_body().length() >
          _req_context.get_client_max_body_size();
}

bool Response::is_authenticated(void) const {
  if (_req_context.get_header("Authorization").empty()) {
    return false;
  }
  const std::string& cred = _req_context.get_header("Authorization");
  std::string token = ft::base64_decode(cred.substr(cred.find(' ') + 1));
  return token == _req_context.get_auth();
}

bool Response::is_something_wrong_on_redirect(void) const {
  return _status_code >= 300 && !_body.length();
}

bool Response::is_redirectable(void) const {
  return _status_code < 400 && _redirect_code;
}

void Response::case_on_methods(void) {

}

void Response::init_method_converter(void) {
  _mux["GET"] = &Response::GET;
  _mux["POST"] = &Response::POST;
  _mux["HEAD"] = &Response::GET;
  _mux["PUT"] = &Response::PUT;
  _mux["DELETE"] = &Response::DELETE;
}

void Response::init_error_page(void) {
  if (!_req_context.get_error_pages()[_status_code].empty()) {
    std::string err = ft::get_current_resource(
                        _req_context.get_error_pages()[_status_code]);
    std::string cur = ft::get_current_resource(
                        "/" + _req_context.get_target());
    if (err != cur) {
      _req_context.get_method() = "GET";
      _is_redirected = true;
      _redirect_code = _status_code;
      _redirected_target = err;
      _status_code = 0;
    }
  }
  _body += "<html>\r\n";
  _body += "<head><title>" + std::to_string(_status_code) + " " + _status_codes[_status_code];
  _body += "</title></head>\r\n";
  _body += "<body>\r\n";
  _body += "<center><h1>" + std::to_string(_status_code) + " " + _status_codes[_status_code];
  _body += "</h1></center>\r\n";
  _body += "<hr><center>" + _headers["Server"] + "</center>\r\n";
  _body += "</body>\r\n";
  _body += "</html>\r\n";
  _headers["Content-Type"] = _mimes.get_content_type(".html");
  _headers["Content-Length"] = std::to_string(_body.length());
  if (_status_code == 401)
    _headers["WWW-Authenticate"] = "Basic realm=\"Access to restricted area\"";
  if (_status_code == 408 || _status_code == 503)
    _headers["Connection"] = "close";
  if (_status_code == 503)
    _headers["Retry-After"] = "30";
}

void Response::init_response(void) {
  _headers["Server"] = "webserv/1.0";
  if (_req_context.get_method() == "HEAD") {
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
    status_code = std::to_string(_status_code) + " " + _status_codes[_status_code];
  }
  _response = _response + _req_context.get_protocol() + " " + status_code + "\r\n";
  _headers["Date"] = ft::get_http_date();
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

std::string Response::init_allowed_methods(void) {
  std::string methods;
  Methods::const_iterator it = _req_context.get_methods().begin();
  while (it != _req_context.get_methods().end()) {
    methods += *it;
    it++;
    if (it != _req_context.get_methods().end()) {
      methods += ", ";
    }
  }
  return methods;
}

void Response::build(void) {
  _file.set_path(_req_context.get_root() + "/" + _req_context.get_target());
  if (_code > 1) {
    _status_code = _code;
  } else if (!_req_context.is_method_acceptable(_req_context.get_method())) {
    _status_code = 405;
    _headers["Allow"] = init_allowed_methods();
  } else if (is_body_size_constrained()) {
    _status_code = 413;
  } else if (_req_context.get_auth() != "off" && !is_authenticated()) {
    _status_code = 401;
  } else {
    case_on_methods();
  }
  if (is_something_wrong_on_redirect()) {
    init_error_page();
  }
  if (!is_redirected()) {
    init_response();
  }
}

void Response::clear(void) {
  _code = 0;
  _status_code = 0;
  _total_sent = 0;
  _header_size = 0;
  _body_size = 0;
  _is_redirected = false;
  _body.clear();
  _response.clear();
  _headers.clear();
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

int Response::GET(void) {
  if (_req_context.get_autoindex() && _file.is_directory()) {
    _headers["Content-Type"] = _mimes.get_content_type(".html");
    _body = _file.autoindex(_req_context.get_target());
  } else {
    _headers["Content-Type"] = _mimes.get_content_type(_file.get_extension());
    if (!_accepted_charset.empty()) {
      _headers["Content-Type"] += "; charset=" + _accepted_charset;
    }
    _body = _file.get_content();
  }
  _headers["Content-Length"] = std::to_string(_body.length());
  return 200;
}

int Response::POST(void) {
  LockGuard<Mutex> _lg(&Response::_mutex);
  int status_code = 200;
  _body = _req_context.get_body();
  if (!_file.is_exist()) {
    _file.create(_body);
    status_code = 201;
  } else {
    _file.append(_body);
    status_code = 200;
  }
  _headers["Content-Length"] = std::to_string(_body.length());
  return status_code;
}

int Response::PUT(void) {
  LockGuard<Mutex> _lg(&Response::_mutex);
  int status_code = 200;
  if (!_file.is_exist()) {
    _file.create(_req_context.get_body());
    _headers["Content-Length"] = "0";
    status_code = 201;
  } else if (_req_context.get_body() == _file.get_content()) {
    status_code = 204;
  } else {
    _file.create(_req_context.get_body());
  }
  return status_code;
}

int Response::DELETE(void) {
  LockGuard<Mutex> _log(&Response::_mutex);
  if (!_file.is_exist()) {
    return 404;
  }
  _file.unlink();
  _body += "<!DOCTYPE html>\n"
  _body += "<html>\n"
  _body += "<body>\n"
  _body += "  <h1>File deleted</h1>\n"
  _body += "</body>\n"
  _body += "</html>";
  _headers["Content-Type"] = _mimes.get_content_type(".html");
  _headers["Content-Length"] = std::to_string(_body.length());
  return 200;
}

const std::string& Response::get_redirected_target(void) const {
  return _redirected_target;
}

std::string Response::get_log(void) {
  std::ostringstream stream;
  stream << "\n\t\t[       status_code]\t" << std::to_string(_status_code)
          << " " << status_codes[_status_code];
  if (_headers.count("Content-Length")) {
    stream << "\n\t\t[    content_length]\t" << _headers["Content-Length"];
  }
  stream << "\n\t\t[            header]\n"
          << _response.substr(0, _header_size - 4);
  if (_body_size) {
    if (_body_size < 200) {
      stream << "\n\t\t[          response]\n"
              << _response.substr(_header_size);
    } else {
      stream << "\n\t\t[          response]\n"
              << _response.substr(_header_size, 200) << " ... ";
    }
  }
  return stream.str();
}
