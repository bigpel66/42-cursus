// Copyright @bigpel66

#include "../includes/Engine.hpp"
#include "../includes/Response.hpp"

Mutex Response::_mutex;

Response::Response(int worker_id,
                  int code,
                  ReqContext *req_context)
  : _worker_id(worker_id),
    _code(code),
    _status_code(0),
    _redirect_code(0),
    _total_sent(0),
    _header_size(0),
    _body_size(0),
    _is_redirected(false),
    _req_context(*req_context) {
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

bool Response::is_localized(Matches *matches) {
  (void)matches;
  return false;
  // std::string path = file_.getPath();
  // std::string all = config_.getHeader("Accept-Language");
  // int q = 10;
  // int max = 0;
  // std::vector<std::string> new_matches;
  // std::vector<std::string> select_matches;

  // headers_["Content-Language"] = "fr";
  // while (1) {
  //   std::string str = all.substr(0, all.find_first_of(" ,;\0"));
  //   new_matches.clear();
  //   if (str.find("*") == std::string::npos){
  //     for (std::vector<std::string>::iterator it = matches.begin() ; it != matches.end() ; it++)
  //       if (it->find("." + str) != std::string::npos)
  //         new_matches.push_back(*it);
  //   }
  //   else
  //     new_matches = matches;
  //   if (!new_matches.empty() && (q > max)) {
  //     select_matches = new_matches;
  //     if (str[0] != '*')
  //       headers_["Content-Language"] = str;
  //     max = q;
  //   }
  //   if (all.find(".") != std::string::npos)
  //     q = ft::stoi(all.substr(all.find_first_of(".") + 1, 1));
  //   if (all.find(",") == std::string::npos){
  //     if (!select_matches.empty()) {
  //       matches = select_matches;
  //       return (1);
  //     }
  //     return (0);
  //   }
  //   all = all.substr(all.find_first_of(" ,;"));
  //   all = all.substr(all.find_first_of("abcdefghijklmnoprstuvwxyz*"));
  // }
}

bool Response::is_wildcard_or_append(Matches *selected,
                                    Matches *on_wildcard,
                                    const std::string& str) {
  if (Parser::is_npos(str.find("*"))) {
    selected->push_back(str);
    on_wildcard->push_back(str);
    return false;
  }
  return true;
}

bool Response::is_breakable_on_charset_loop(std::string *val) {
  if (Parser::is_npos(val->find(","))) {
    return true;
  }
  *val = val->substr(val->find_first_of(" ,;"));
  if (Parser::is_npos(val->find_first_of("abcdefghijklmnoprstuvwxyz*"))) {
    return true;
  }
  *val = val->substr(val->find_first_of("abcdefghijklmnoprstuvwxyz*"));
  return false;
}

bool Response::is_CGI(void) const {
  CGIs cgis = _req_context.get_cgis();
  for (CGIs::const_iterator it = cgis.begin() ; it != cgis.end() ; it++) {
    if (it->first == _file.get_extension()) {
      return true;
    }
  }
  return false;
}

bool Response::is_method_GET_or_HEAD(void) const {
  return _req_context.get_method() == "GET" ||
          _req_context.get_method() == "HEAD";
}

bool Response::is_method_POST_or_PUT(void) const {
  return _req_context.get_method() == "POST" ||
          _req_context.get_method() == "PUT";
}

void Response::case_on_CGI(void) {
  CGI cgi(_worker_id, _file, &_req_context);
  _status_code = cgi.exec();
  if (_status_code > 400) {
    return;
  }
  cgi.parse_headers(&_headers);
  _body = cgi.get_body();
  _headers["Content-Length"] = std::to_string(_body.length());
}

void Response::case_on_GET_or_HEAD(void) {
  if (_file.is_directory()) {
    std::string index = _file.find_index(_req_context.get_indexes());
    if (index.length()) {
      _is_redirected = true;
      _redirected_target = ft::get_sole_slash_target("/"
                                                    + _req_context.get_target()
                                                    + "/"
                                                    + index);
      _status_code = 200;
      return;
    } else if (!_req_context.get_autoindex()) {
      _status_code = 404;
      return;
    }
  }
  std::string path = _file.get_path();
  if (!_file.is_directory()) {
    if (!_file.is_exist()) {
      _status_code = 404;
      return;
    }
    _file.parse_match();
    Matches& matches = _file.get_matches();
    if (!_req_context.get_header("Accept-Language").empty()) {
      if (is_localized(&matches)) {
          _file.set_path(path.substr(0, path.find_last_of("/") + 1)
                        + matches.front(),
                        true);
      }
    }
    if (!_req_context.get_header("Accept-Charset").empty()) {
      _accepted_charset = init_accept_charset(&matches);
      _file.set_path(path.substr(0, path.find_last_of("/") + 1)
                    + matches.front(),
                    true);
    }
    if (!_file.open(false)) {
      _status_code = 403;
      return;
    }
    _headers["Last-Modified"] = _file.get_last_modified();
  }
}

void Response::case_on_POST_or_PUT(void) {
  std::string path = _req_context.get_uri() + "/" + _req_context.get_resource();
  if (!_req_context.get_upload().empty()) {
    File dir(_req_context.get_root() + "/" + _req_context.get_upload());
    path = _req_context.get_uri()
            + "/"
            + _req_context.get_upload()
            + "/"
            + _req_context.get_resource();
    if (dir.is_exist() && !dir.is_directory()) {
      dir.unlink();
    }
    if (!dir.is_exist()) {
      mkdir(dir.get_path().c_str(), 0755);
    }
    _file.set_path(dir.get_path() + "/" + _req_context.get_resource(),
                  false);
  }
  _headers["Location"] = ft::get_sole_slash_target(path);
}

void Response::case_on_methods(void) {
  if (is_method_GET_or_HEAD()) {
    case_on_GET_or_HEAD();
  }
  if (is_CGI()) {
    case_on_CGI();
  }
  if (is_method_POST_or_PUT()) {
    case_on_POST_or_PUT();
  }
  (this->*(Response::_mux[_req_context.get_method()]))();
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
    std::string err = ft::get_sole_slash_target(
                        _req_context.get_error_pages()[_status_code]);
    std::string cur = ft::get_sole_slash_target(
                        "/" + _req_context.get_target());
    if (err != cur) {
      _req_context.set_method("GET");
      _is_redirected = true;
      _redirect_code = _status_code;
      _redirected_target = err;
      _status_code = 0;
    }
  }
  _body += "<html>\r\n";
  _body += "<head><title>" + std::to_string(_status_code);
  _body += " " + Engine::status_codes[_status_code];
  _body += "</title></head>\r\n";
  _body += "<body>\r\n";
  _body += "<center><h1>" + std::to_string(_status_code);
  _body += " " + Engine::status_codes[_status_code];
  _body += "</h1></center>\r\n";
  _body += "<hr><center>" + _headers["Server"] + "</center>\r\n";
  _body += "</body>\r\n";
  _body += "</html>\r\n";
  _headers["Content-Type"] = Engine::mimes.get_type(".html");
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
    status_code = std::to_string(_status_code)
                  + " "
                  + Engine::status_codes[_status_code];
  }
  _response += _req_context.get_protocol() + " " + status_code + "\r\n";
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

void Response::update_matches_by_charset(bool is_wildcard,
                                        Matches *matches,
                                        Matches *selected,
                                        Matches *on_wildcard) {
  if (is_wildcard) {
    *matches = *on_wildcard;
  } else {
    *matches = *selected;
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

std::string Response::init_accept_charset(Matches *matches) {
  int max = 0;
  bool is_init = true;
  bool is_wildcard = false;
  std::string charset;
  std::string val = _req_context.get_header("Accept-Charset");
  Matches selected_matches;
  Matches on_wildcard_matches;
  while (true) {
    std::string str = val.substr(0, val.find_first_of(" ,;\0"));
    if (is_wildcard_or_append(&selected_matches, &on_wildcard_matches, str)) {
      is_wildcard = true;
    }
    int q = get_quality(val);
    if (max < q) {
      max = q;
      if (Parser::is_npos(str.find("*"))) {
        charset = str;
        if (!is_init) {
          selected_matches.clear();
        }
      }
    }
    if (is_breakable_on_charset_loop(&val)) {
      break;
    }
    is_init = false;
  }
  update_matches_by_charset(is_wildcard,
                            matches,
                            &selected_matches,
                            &on_wildcard_matches);
  return charset;
}

int Response::get_quality(const std::string& val) {
  if (!Parser::is_npos(val.find("."))) {
    return std::strtod(val.substr(val.find_first_of(".") + 1, 1).c_str(),
                      ft::nil);
  }
  return 10;
}

void Response::build(void) {
  _file.set_path(_req_context.get_root() + "/" + _req_context.get_target(),
                false);
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
    _headers["Content-Type"] = Engine::mimes.get_type(".html");
    _body = _file.get_autoindex(_req_context.get_target());
  } else {
    _headers["Content-Type"] = Engine::mimes.get_type(_file.get_extension());
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
  _body += "<!DOCTYPE html>\n";
  _body += "<html>\n";
  _body += "<body>\n";
  _body += "  <h1>File deleted</h1>\n";
  _body += "</body>\n";
  _body += "</html>";
  _headers["Content-Type"] = Engine::mimes.get_type(".html");
  _headers["Content-Length"] = std::to_string(_body.length());
  return 200;
}

const std::string& Response::get_redirected_target(void) const {
  return _redirected_target;
}

std::string Response::get_log(void) {
  std::ostringstream stream;
  stream << "\n\t\t[       status_code]\t" << std::to_string(_status_code)
          << " " << Engine::status_codes[_status_code];
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
