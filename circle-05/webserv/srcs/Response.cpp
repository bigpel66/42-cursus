// Copyright @bigpel66

#include "../includes/Response.hpp"

StatusCodes Response::_status_codes = StatusCodes();

Mimes Response::_mimes = Mimes();

Mutex Response::_mutex = Mutex();

Response::Response(int worker_id,
                  int code,
                  const ReqContext& req_context)
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

void Response::init_method_converter(void) {
  _mux["GET"] = &Response::GET;
  _mux["POST"] = &Response::POST;
  _mux["HEAD"] = &Response::GET;
  _mux["PUT"] = &Response::PUT;
  _mux["DELETE"] = &Response::DELETE;
}

bool Response::is_connection_close_specified(void) const {
  return _headers.find("Connection") != _headers.end() &&
          _headers.at("Connection") == "close";
}

bool Response::is_redirected(void) const {
  return _is_redirected;
}

int Response::send(int fd) {
  int code = ::send(fd, _response.c_str() + _total_sent, _response.length() - _total_sent, 0);
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
  _body += "<!DOCTYPE html>\n\
            <html>\n\
            <body>\n\
              <h1>File deleted</h1>\n\
            </body>\n\
            </html>";
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
  stream << "\n\t\t[            header]\n" << _response.substr(0, _header_size - 4);
  if (_body_size) {
    if (_body_size < 200) {
      stream << "\n\t\t[          response]\n" << _response.substr(_header_size);
    } else {
      stream << "\n\t\t[          response]\n" << _response.substr(_header_size, 200) << " ... ";
    }
  }
  return stream.str();
}
