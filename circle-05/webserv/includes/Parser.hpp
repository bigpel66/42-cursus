// Copyright @bigpel66

// Header for the parser of configuration file
#ifndef CIRCLE_05_WEBSERV_INCLUDES_PARSER_HPP_
#define CIRCLE_05_WEBSERV_INCLUDES_PARSER_HPP_

// Standard Library Inclusion
#include <string>
#include <fcntl.h>
#include <unistd.h>

// Class Headers Inclusion
#include "./Utilizer.h"

class Parser {
 private:
  int _fd;
  std::string _config;
  ServerInfos _server_infos;

  Parser(void);
  Parser(const Parser& p);
  Parser& operator=(const Parser& p);

  void is_directory(void);
  void is_openable(void);
  void close_config(void) const;

 public:
  explicit Parser(const std::string& config);
  ~Parser(void);

  std::size_t get_server_size(void) const;
  std::size_t get_worker_size(void) const;
  t_server_info get_server_info_at(std::size_t index) const;
};

#endif  // CIRCLE_05_WEBSERV_INCLUDES_PARSER_HPP_
