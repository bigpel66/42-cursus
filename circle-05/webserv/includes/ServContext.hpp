// Copyright @ bigpel66

// Header for the context of the server
#ifndef CIRCLE_05_WEBSERV_INCLUDES_SERVCONTEXT_HPP_
#define CIRCLE_05_WEBSERV_INCLUDES_SERVCONTEXT_HPP_

// Standard Library Inclusion
#include <map>
#include <string>
#include <vector>

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

class ServContext {
 private:
  int _id;
  const Lines& _lines;
  const Tokens& _tokens;
  std::string _config;
  bool _is_location_started;

  std::string _match_uri;
  location_match _modifier;

  bool _is_auto_index_on;

  std::string _root;
  std::string _upload;
  std::string _cgi_bin;
  std::string _credentials;
  std::size_t _client_max_body_size;

  CGIs _cgis;
  Listens _listens;
  Indexes _indexes;
  Methods _methods;
  Locations _locations;
  ErrorPages _error_pages;
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
  void parse_location_internal(Tokens::iterator *it, Locations *locations);
  void parse_location(Tokens::iterator *it);
  void parse_error_page(Tokens::iterator *it);
  void parse_server_name(Tokens::iterator *it);

  bool is_demultiplexable(Tokens::iterator it);
  bool is_location_modifier(const std::string& str) const;

  void init_directive_converter(void);

  ServContext(void);
  ServContext(const ServContext& s);

 public:
  ServContext(int id,
              const Lines& lines,
              const Tokens& tokens,
              const std::string& config);
  ServContext& operator=(const ServContext& s);
  ~ServContext(void);

  void set_internal_directives(Tokens::iterator *it);

  const Listens& get_listens(void) const;

  friend class ReqContext;
  friend std::ostream& operator<<(std::ostream& o,
                              const std::vector<std::string>& vs);
  friend std::ostream& operator<<(std::ostream& o,
                              const std::map<int, std::string>& mis);
  friend std::ostream& operator<<(std::ostream& o,
                              const std::map<std::string, std::string>& mss);
  friend std::ostream& operator<<(std::ostream& o,
                              const Listens& l);
  friend std::ostream& operator<<(std::ostream& o,
                              const location_match& l);
  friend std::ostream& operator<<(std::ostream& o,
                              const Locations& l);
  friend std::ostream& operator<<(std::ostream& o,
                              const ServContext& s);
};

std::ostream& operator<<(std::ostream& o,
                      const std::vector<std::string>& vs);
std::ostream& operator<<(std::ostream& o,
                      const std::map<int, std::string>& mis);
std::ostream& operator<<(std::ostream& o,
                      const std::map<std::string, std::string>& mss);
std::ostream& operator<<(std::ostream& o,
                      const Listens& l);
std::ostream& operator<<(std::ostream& o,
                      const location_match& l);
std::ostream& operator<<(std::ostream& o,
                      const Locations& l);
std::ostream& operator<<(std::ostream& o,
                      const ServContext& s);

#endif  // CIRCLE_05_WEBSERV_INCLUDES_SERVCONTEXT_HPP_
