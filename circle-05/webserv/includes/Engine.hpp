// Copyright @bigpel66

// Header for the main engine of webserv
#ifndef CIRCLE_05_WEBSERV_INCLUDES_ENGINE_HPP_
#define CIRCLE_05_WEBSERV_INCLUDES_ENGINE_HPP_

// Standard Library Inclusion
#include <vector>
#include <string>
#include <fstream>

// Class Headers Inclusion
#include "./Parser.hpp"  // Parser to parse configuration file
#include "./Server.hpp"  // Worker to accept the HTTP Request and serve the HTTP Response
#include "./Worker.hpp"  // Worker to process the HTTP Request into the HTTP Response

// Engine of Webserv
class Engine {
 private:
  // Holds the server configuration fields and values
  Parser _parser;
  // Below servers and workers are acting like Producer-Consumer pattern
  Servers _servers;  // Producer
  Workers _workers;  // Consumer

  // Coplien, but prevent to call below functions
  Engine(void);
  Engine(const Engine& e);
  Engine& operator=(const Engine& e);

  int _id;
  Mutex _logger;
  Mimes _mimes;

  void init_mimes(void);
  void push_server_as_parser(void);
  void push_worker_as_parser(void);
  void clear_servers(void);
  void clear_workers(void);

 public:
  // Construct only with configuration file
  explicit Engine(const std::string& config);
  // Engine instance will not provide the polymorphism instances
  ~Engine(void);

  Server *get_server_at(int index);
  void set_id_from_server(int id) const;
  int get_id_from_server(void) const;

  Servers get_servers(void) const;
  Workers get_workers(void) const;
  std::size_t get_server_size(void) const;
  std::size_t get_worker_size(void) const;
};

#endif  // CIRCLE_05_WEBSERV_INCLUDES_ENGINE_HPP_
