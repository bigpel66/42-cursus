// Copyright @bigpel66

#include "../includes/ServContext.hpp"
#include "../includes/Parser.hpp"
#include "../includes/Logger.hpp"

ServContext::ServContext(int id,
                          const Lines& lines,
                          const Tokens& tokens,
                          const std::string& config)
  : _id(id),
    _lines(lines),
    _tokens(tokens),
    _config(config),
    _is_location_started(false),
    _modifier(none_match),
    _is_autoindex_on(false),
    _cgi_bin("cgi-bin"),
    _credentials("off"),
    _client_max_body_size(0) {
  init_directive_converter();
}

ServContext& ServContext::operator=(const ServContext& s) {
  if (this != &s) {
    _id = s._id;
    _is_autoindex_on = s._is_autoindex_on;
    _client_max_body_size = s._client_max_body_size;
    _root = s._root;
    _cgi_bin = s._cgi_bin;
    _credentials = s._credentials;
    _cgis =  s._cgis;
    _indexes = s._indexes;
    _error_pages = s._error_pages;
  }
  return *this;
}

ServContext::~ServContext(void) {}

std::size_t ServContext::get_line_of_token(Tokens::iterator it) const {
  return _lines.at(it - _tokens.begin());
}

std::string ServContext::get_current_parsing_line(std::size_t line) const {
  return " on " + _config + ":" + std::to_string(line);
}

bool ServContext::is_demultiplexable(Tokens::iterator it) {
  if (_mux.find(*it) != _mux.end()) {
    return true;
  }
  return false;
}

bool ServContext::is_location_modifier(const std::string& str) const {
  return str == "=" ||
          str == "~" ||
          str == "~*" ||
          str == "^~";
}

void ServContext::init_directive_converter(void) {
  _mux["autoindex"] = &ServContext::parse_autoindex;
  _mux["client_max_body_size"] = &ServContext::parse_client_max_body_size;
  _mux["root"] = &ServContext::parse_root;
  _mux["upload"] = &ServContext::parse_upload;
  _mux["cgi_bin"] = &ServContext::parse_cgi_bin;
  _mux["auth"] = &ServContext::parse_auth;
  _mux["cgi"] = &ServContext::parse_cgi;
  _mux["listen"] = &ServContext::parse_listen;
  _mux["index"] = &ServContext::parse_index;
  _mux["limit_except"] = &ServContext::parse_limit_except;
  _mux["location"] = &ServContext::parse_location;
  _mux["error_page"] = &ServContext::parse_error_page;
  _mux["server_name"] = &ServContext::parse_server_name;
}

void ServContext::set_internal_directives(Tokens::iterator *it) {
  if (!Parser::is_left_brace(**it)) {
    throw ConfigException("missing left brace"
                          + get_current_parsing_line(get_line_of_token(*it)));
  }
  while (!Parser::is_right_brace(*(++(*it)))) {
    if (is_demultiplexable(*it)) {
      (this->*(_mux[**it]))(it);
    } else {
      throw ConfigException("invalid directive "
                            + **it
                            + " detected"
                            + get_current_parsing_line(get_line_of_token(*it)));
    }
  }
}

Listens& ServContext::get_listens(void) {
  return _listens;
}

const ServerNames& ServContext::get_server_names(void) const {
  return _server_names;
}

void ServContext::parse_autoindex(Tokens::iterator *it) {
  if (_is_location_started) {
    throw ConfigException("autoindex cannot be set after location"
                          + get_current_parsing_line(get_line_of_token(*it)));
  }
  if (*(++(*it)) == "on") {
    _is_autoindex_on = true;
  } else if (**it == "off") {
    _is_autoindex_on = false;
  } else {
    throw ConfigException("autoindex unknown value"
                          + get_current_parsing_line(get_line_of_token(*it)));
  }
  if (!Parser::is_total_semi(*(++(*it)))) {
    throw ConfigException("autoindex has sevaral values"
                          + get_current_parsing_line(get_line_of_token(*it)));
  }
}

void ServContext::parse_client_max_body_size(Tokens::iterator *it) {
  if (_is_location_started) {
    throw ConfigException("client_max_body_size cannot be set after location"
                          + get_current_parsing_line(get_line_of_token(*it)));
  }
  if (!Parser::is_only_digit(*(++(*it)))) {
    throw ConfigException("client_max_body_size unknown value"
                          + get_current_parsing_line(get_line_of_token(*it)));
  }
  _client_max_body_size = static_cast<std::uint32_t>(std::strtod((*it)->c_str(),
                                                            ft::nil));
  if (!Parser::is_total_semi(*(++(*it)))) {
    throw ConfigException("client_max_body_size has sevaral values"
                          + get_current_parsing_line(get_line_of_token(*it)));
  }
}

void ServContext::parse_root(Tokens::iterator *it) {
  if (_is_location_started) {
    throw ConfigException("root cannot be set after location"
                          + get_current_parsing_line(get_line_of_token(*it)));
  }
  _root = *(++(*it));
  if (!Parser::is_total_semi(*(++(*it)))) {
    throw ConfigException("root has sevaral values"
                          + get_current_parsing_line(get_line_of_token(*it)));
  }
}

void ServContext::parse_upload(Tokens::iterator *it) {
  if (_is_location_started) {
    throw ConfigException("upload cannot be set after location"
                          + get_current_parsing_line(get_line_of_token(*it)));
  }
  _upload = *(++(*it));
  if (!Parser::is_total_semi(*(++(*it)))) {
    throw ConfigException("upload has sevaral values"
                          + get_current_parsing_line(get_line_of_token(*it)));
  }
}

void ServContext::parse_cgi_bin(Tokens::iterator *it) {
  if (_is_location_started) {
    throw ConfigException("cgi_bin cannot be set after location"
                          + get_current_parsing_line(get_line_of_token(*it)));
  }
  _cgi_bin = *(++(*it));
  if (!Parser::is_total_semi(*(++(*it)))) {
    throw ConfigException("cgi_bin has sevaral values"
                          + get_current_parsing_line(get_line_of_token(*it)));
  }
}

void ServContext::parse_auth(Tokens::iterator *it) {
  if (_is_location_started) {
    throw ConfigException("auth cannot be set after location"
                          + get_current_parsing_line(get_line_of_token(*it)));
  }
  _credentials = *(++(*it));
  if (!Parser::is_total_semi(*(++(*it)))) {
    throw ConfigException("auth has sevaral values"
                          + get_current_parsing_line(get_line_of_token(*it)));
  }
}

void ServContext::parse_cgi(Tokens::iterator *it) {
  if (_is_location_started) {
    throw ConfigException("cgi cannot be set after location"
                          + get_current_parsing_line(get_line_of_token(*it)));
  }
  std::vector<std::string> cgi_arguments;
  while (!Parser::is_total_semi(*(++(*it)))) {
    cgi_arguments.push_back(**it);
  }
  if (cgi_arguments.size() != 2) {
    throw ConfigException("cgi has not 2 values for extension and executable"
                            + get_current_parsing_line(get_line_of_token(*it)));
  }
  _cgis[cgi_arguments[0]] = cgi_arguments[1];
}

void ServContext::parse_listen(Tokens::iterator *it) {
  if (_is_location_started) {
    throw ConfigException("listen cannot be set after location"
                          + get_current_parsing_line(get_line_of_token(*it)));
  }
  std::string after_ip = *(++(*it));
  std::string ip = "0.0.0.0";
  std::uint32_t port = 4242;
  if (!Parser::is_npos(((*it)->find(":")))) {
    ip = (*it)->substr(0, (*it)->find(":"));
    after_ip = (*it)->substr((*it)->find(":") + 1);
  }
  if (!Parser::is_only_digit(after_ip)) {
    throw ConfigException("port is not a valid number"
                          + get_current_parsing_line(get_line_of_token(*it)));
  }
  port = static_cast<std::uint32_t>(std::strtod(after_ip.c_str(), ft::nil));
  if (port > MAXIMUM_PORT_NUMBER) {
    throw ConfigException("port is not in range [1 - 65535]"
                          + get_current_parsing_line(get_line_of_token(*it)));
  }
  Listen listen(ip, port);
  if (std::find(_listens.begin(), _listens.end(), listen) != _listens.end()) {
    throw ConfigException("listen is duplicated"
                          + get_current_parsing_line(get_line_of_token(*it)));
  }
  _listens.push_back(listen);
  if (!Parser::is_total_semi(*(++(*it)))) {
    throw ConfigException("listen has sevaral values"
                          + get_current_parsing_line(get_line_of_token(*it)));
  }
}

void ServContext::parse_index(Tokens::iterator *it) {
  if (_is_location_started) {
    throw ConfigException("index cannot be set after location"
                          + get_current_parsing_line(get_line_of_token(*it)));
  }
  while (!Parser::is_total_semi(*(++(*it)))) {
    _indexes.push_back(**it);
  }
}

void ServContext::parse_limit_except(Tokens::iterator *it) {
  if (_is_location_started) {
    throw ConfigException("limit_except cannot be set after location"
                          + get_current_parsing_line(get_line_of_token(*it)));
  }
  while (!Parser::is_total_semi(*(++(*it)))) {
    _methods.push_back(**it);
  }
}

void ServContext::parse_location_internal(Tokens::iterator *it,
                                          Locations *locations) {
  if (is_location_modifier(*(++(*it)))) {
    if ((**it) == "=") {
      _modifier = exact_match;
    } else if ((**it) == "~") {
      _modifier = case_sensitive_match;
    } else if ((**it) == "~*") {
      _modifier = case_insensitive_match;
    } else if ((**it) == "^~") {
      _modifier = longest_match;
    } else {
      throw ConfigException("unknown location modifier"
                            + get_current_parsing_line(get_line_of_token(*it)));
    }
    ++(*it);
  } else {
    _modifier = none_match;
  }
  _uri = **it;
  set_internal_directives(&(++(*it)));
  locations->push_back(*this);
}

void ServContext::parse_location(Tokens::iterator *it) {
  _is_location_started = true;
  Location location(-1, _lines, _tokens, _config);
  location = *this;
  location.parse_location_internal(it, &_locations);
}

void ServContext::parse_error_page(Tokens::iterator *it) {
  if (_is_location_started) {
    throw ConfigException("error_page cannot be set after location"
                          + get_current_parsing_line(get_line_of_token(*it)));
  }
  int code;
  ErrorCodes codes;
  while (Parser::is_only_digit(*(++(*it)))) {
    code = static_cast<std::uint32_t>(std::strtod((*it)->c_str(), ft::nil));
    codes.push_back(code);
  }
  for (ErrorCodes::iterator et = codes.begin() ; et != codes.end() ; et++) {
    _error_pages[*et] = **it;
  }
  if (!Parser::is_total_semi(*(++(*it)))) {
    throw ConfigException("error_page has sevaral values"
                          + get_current_parsing_line(get_line_of_token(*it)));
  }
}

void ServContext::parse_server_name(Tokens::iterator *it) {
  if (_is_location_started) {
    throw ConfigException("server_name cannot be set after location"
                          + get_current_parsing_line(get_line_of_token(*it)));
  }
  while (!Parser::is_total_semi(*(++(*it)))) {
    _server_names.push_back(**it);
  }
}

std::ostream& operator<<(std::ostream& o,
                        const std::vector<std::string>& vs) {
  std::vector<std::string>::const_iterator it;
  for (it = vs.begin() ; it !=  vs.end() ; it++) {
    o << "\n\t\t\t" << *it << "\t";
  }
  return o;
}

std::ostream& operator<<(std::ostream& o,
                        const std::map<int, std::string>& mis) {
  std::map<int, std::string>::const_iterator it;
  for (it = mis.begin() ; it !=  mis.end() ; it++) {
    o << "\n\t\t\t" << it->first << " -> " << it->second;
  }
  return o;
}

std::ostream& operator<<(std::ostream& o,
                        const std::map<std::string, std::string>& mss) {
  std::map<std::string, std::string>::const_iterator it;
  for (it = mss.begin() ; it !=  mss.end() ; it++) {
    o << "\n\t\t\t" << it->first << " -> " << it->second;
  }
  return o;
}

std::ostream& operator<<(std::ostream& o,
                        const Listens& l) {
  for (Listens::const_iterator it = l.begin() ; it !=  l.end() ; it++) {
    o << *it;
  }
  return o;
}

std::ostream& operator<<(std::ostream& o,
                        const location_match& l) {
  if (l == none_match) {
    o << "none match";
  } else if (l == exact_match) {
    o << "exact match";
  } else if (l == case_sensitive_match) {
    o << "case sensitive match";
  } else if (l == case_insensitive_match) {
    o << "case insensitive match";
  } else if (l == longest_match) {
    o << "longest match";
  }
  return o;
}

std::ostream& operator<<(std::ostream& o,
                        const Locations& s) {
  std::vector<ServContext>::const_iterator it;
  for (it = s.begin() ; it != s.end() ; it++) {
    o << "\n\t\t\t"
      << "[\t"
      << it->_modifier
      << "\t] "
      << it->_uri;
  }
  return o;
}

std::ostream& operator<<(std::ostream& o,
                        const ServContext& s) {
  o << CYAN
    << "[Server Config       :\t_id " << std::to_string(s._id) << "]\n"
    << RESET
    << YELLOW << "config               :\t" << RESET
    << s._config << "\n"
    << YELLOW << "server_name          :\t" << RESET
    << s._server_names << "\n"
    << YELLOW << "autoindex            :\t" << RESET
    << s._is_autoindex_on << "\n"
    << YELLOW << "root                 :\t" << RESET
    << s._root << "\n"
    << YELLOW << "upload               :\t" << RESET
    << s._upload << "\n"
    << YELLOW << "auth                 :\t" << RESET
    << s._credentials << "\n"
    << YELLOW << "client_max_body_size :\t" << RESET
    << std::to_string(s._client_max_body_size) << "\n"
    << YELLOW << "cgi_bin              :\t" << RESET
    << s._cgi_bin << "\n"
    << YELLOW << "cgi                  :\t" << RESET
    << s._cgis << "\n"
    << YELLOW << "listen               :\t" << RESET
    << s._listens << "\n"
    << YELLOW << "index                :\t" << RESET
    << s._indexes << "\n"
    << YELLOW << "limit_except         :\t" << RESET
    << s._methods << "\n"
    << YELLOW << "error_page           :\t" << RESET
    << s._error_pages << "\n"
    << YELLOW << "location             :\t" << RESET
    << s._locations << "\n";
  return o;
}

