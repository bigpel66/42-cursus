// Copyright @ bigpel66

#ifndef CIRCLE_05_WEBSERV_INCLUDES_SERVERCONFIG_HPP_
#define CIRCLE_05_WEBSERV_INCLUDES_SERVERCONFIG_HPP_

// Standard Library Inclusion
#include <string>

// Class Headers Inclusion
#include "./Utilizer.hpp"

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

  ServerConfig(void);
  ServerConfig(const ServerConfig& s);
  ServerConfig& operator=(const ServerConfig s);

 public:
  explicit ServerConfig(int id);
  ~ServerConfig(void);

  void set_internal_directives(Tokens::iterator *it);
};

#endif  // CIRCLE_05_WEBSERV_INCLUDES_SERVERCONFIG_HPP_
