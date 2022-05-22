// Copyright @bigpel66

#include "../includes/ServerConfig.hpp"
#include "../includes/Parser.hpp"

ServerConfig::ServerConfig(int id,
                          const Lines& lines,
                          const Tokens& tokens,
                          const std::string& config)
  : _id(id),
    _lines(lines),
    _tokens(tokens),
    _config(config),
    _is_auto_index_on(false),
    _location_match(none_match),
    _client_max_body_size(0),
    _cgi_bin("cgi-bin"),
    _credentials("off") {
  init_directive_converter();
}

ServerConfig::~ServerConfig(void) {}

std::size_t ServerConfig::get_line_of_token(Tokens::iterator it) const {
  return _lines.at(it - _tokens.begin());
}

std::string ServerConfig::get_current_parsing_line(std::size_t line) const {
  return " on " + _config + ":" + std::to_string(line);
}

bool ServerConfig::is_demultiplexable(Tokens::iterator it) {
  if (_mux.find(*it) != _mux.end()) {
    return true;
  }
  return false;
}

bool ServerConfig::is_directive_value_ends_with_semi(Tokens::iterator it) const {
  return it->at(it->size() - 1) == ';';
}

void ServerConfig::init_directive_converter(void) {
  _mux["autoindex"] = &ServerConfig::parse_autoindex;
  _mux["client_max_body_size"] = &ServerConfig::parse_client_max_body_size;
  _mux["root"] = &ServerConfig::parse_root;
  _mux["upload"] = &ServerConfig::parse_upload;
  _mux["cgi_bin"] = &ServerConfig::parse_cgi_bin;
  _mux["auth"] = &ServerConfig::parse_auth;
  _mux["cgi"] = &ServerConfig::parse_cgi;
  _mux["listen"] = &ServerConfig::parse_listen;
  _mux["index"] = &ServerConfig::parse_index;
  _mux["limit_except"] = &ServerConfig::parse_limit_except;
  _mux["location"] = &ServerConfig::parse_location;
  _mux["error_page"] = &ServerConfig::parse_error_page;
  _mux["server_name"] = &ServerConfig::parse_server_name;
}

void ServerConfig::set_internal_directives(Tokens::iterator *it) {
  if (!Parser::is_left_brace(**it)) {
    throw ConfigException("missing left brace"
                          + get_current_parsing_line(get_line_of_token(*it)));
  }
  while (!Parser::is_right_brace(*(++(*it)))) {
    std::cout << **it << std::endl;
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

void ServerConfig::parse_autoindex(Tokens::iterator *it) {
  (void)it;
}

void ServerConfig::parse_client_max_body_size(Tokens::iterator *it) {
  (void)it;
}

void ServerConfig::parse_root(Tokens::iterator *it) {
  (void)it;
}

void ServerConfig::parse_upload(Tokens::iterator *it) {
  (void)it;
}

void ServerConfig::parse_cgi_bin(Tokens::iterator *it) {
  (void)it;
}

void ServerConfig::parse_auth(Tokens::iterator *it) {
  (void)it;
}

void ServerConfig::parse_cgi(Tokens::iterator *it) {
  (void)it;
}

void ServerConfig::parse_listen(Tokens::iterator *it) {
  std::string after_ip = **it;
  std::string ip = "0.0.0.0";
  uint32_t port = 4242;
  if (!Parser::is_npos(((++(*it))->find(":")))) {
    ip = (*it)->substr(0, (*it)->find(":"));
    after_ip = (*it)->substr((*it)->find(":") + 1);
  }
  if (!Parser::is_only_digit(after_ip)) {
    throw ConfigException("port is not a valid number"
                          + get_current_parsing_line(get_line_of_token(*it)));
  }
  port = static_cast<uint32_t>(std::strtod(after_ip.c_str(), ft::nullptr_t));
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

void ServerConfig::parse_index(Tokens::iterator *it) {
  (void)it;
}

void ServerConfig::parse_limit_except(Tokens::iterator *it) {
  (void)it;
}

void ServerConfig::parse_location(Tokens::iterator *it) {
  (void)it;
}

void ServerConfig::parse_error_page(Tokens::iterator *it) {
  (void)it;
}

void ServerConfig::parse_server_name(Tokens::iterator *it) {
  while (!Parser::is_total_semi(*(++(*it)))) {
      _server_names.push_back(**it);
  }
  for (ServerNames::iterator it = _server_names.begin(); it != _server_names.end(); it++) {
    std::cout << *it << std::endl;
  }
}
