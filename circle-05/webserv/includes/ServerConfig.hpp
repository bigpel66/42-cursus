// Copyright @ bigpel66

#ifndef CIRCLE_05_WEBSERV_INCLUDES_SERVERCONFIG_HPP_
#define CIRCLE_05_WEBSERV_INCLUDES_SERVERCONFIG_HPP_

// Standard Library Inclusion
#include <string>

// Class Headers Inclusion
#include "./Utilizer.hpp"
#include "./Exception.hpp"

// Enum Location Match
enum location_match {
  none_match,
  exact_match,
  case_sensitive_match,
  case_insensitive_match,
  longest_match
};

class ServerConfig {
 private:
  int _id;
  const Lines& _lines;
  const Tokens& _tokens;
  std::string _config;

  bool _is_auto_index_on;

  location_match _location_match;

  std::size_t _client_max_body_size;
  std::string _uri;
  std::string _root;
  std::string _upload;
  std::string _cgi_bin;
  std::string _credentials;

  CGIs _cgis;
  Listens _listens;
  Indexes _indexes;
  Methods _methods;
  Locations _locations;
  ErrorCodes _error_codes;
  ServerNames _server_names;

  DirectiveConverters _mux;

  std::size_t get_line_of_token(Tokens::iterator it) const;
  std::string get_current_parsing_line(std::size_t line) const;

  void parse_autoindex(Tokens::iterator *it);
  void parse_client_max_body_size(Tokens::iterator *it);
  void parse_root(Tokens::iterator *it);
  void parse_upload(Tokens::iterator *it);
  void parse_cgi_bin(Tokens::iterator *it);
  void parse_auth(Tokens::iterator *it);
  void parse_cgi(Tokens::iterator *it);
  void parse_listen(Tokens::iterator *it);
  void parse_index(Tokens::iterator *it);
  void parse_limit_except(Tokens::iterator *it);
  void parse_location(Tokens::iterator *it);
  void parse_error_page(Tokens::iterator *it);
  void parse_server_name(Tokens::iterator *it);

  bool is_demultiplexable(Tokens::iterator it);
  bool is_directive_value_ends_with_semi(Tokens::iterator it) const;

  void init_directive_converter(void);

  ServerConfig(void);
  ServerConfig(const ServerConfig& s);
  ServerConfig& operator=(const ServerConfig s);

 public:
  ServerConfig(int id,
              const Lines& lines,
              const Tokens& tokens,
              const std::string& config);
  ~ServerConfig(void);

  void set_internal_directives(Tokens::iterator *it);
};

#endif  // CIRCLE_05_WEBSERV_INCLUDES_SERVERCONFIG_HPP_
