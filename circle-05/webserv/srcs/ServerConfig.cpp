// Copyright @bigpel66

#include "../includes/ServerConfig.hpp"
#include "../includes/Parser.hpp"

DirectiveConverters ServerConfig::_mux;

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
    _credentials("off") {}

ServerConfig::~ServerConfig(void) {}

std::size_t ServerConfig::get_line_of_token(Tokens::iterator it) const {
  return _lines.at(it - _tokens.begin());
}

std::string ServerConfig::get_current_parsing_line(std::size_t line) const {
  return " on " + _config + ":" + std::to_string(line);
}

void ServerConfig::set_internal_directives(Tokens::iterator *it) {
  if (!Parser::is_left_brace(*it)) {
    throw ConfigException("missing left brace"
                          + get_current_parsing_line(get_line_of_token(*it)));
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
  (void)it;
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
  (void)it;
}
