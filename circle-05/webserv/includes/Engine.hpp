// Copyright @bigpel66

// Header for the main engine of webserv
#ifndef CIRCLE_05_WEBSERV_INCLUDES_ENGINE_HPP_
#define CIRCLE_05_WEBSERV_INCLUDES_ENGINE_HPP_

// Class Headers
#include "./Utilizer.hpp" // Utilizer to resolve header dependency on standard things
#include "./Parser.hpp" // Parser to parse configuration file
#include "./Server.hpp" // Worker to accept the HTTP Request and serve the HTTP Response
#include "./Worker.hpp" // Worker to process the HTTP Request into the HTTP Response

// Engine of Webserv
class Engine {
 private:
  // Holds the server configuration fields and values
  Parser _parser;
  // Below servers and workers are acting like Producer-Consumer pattern
  std::vector<Server*> _servers; // Producer
  std::vector<Worker*> _workers; // Consumer

  // Coplien, but prevent to call below functions
  Engine(void);
  Engine(const Engine& e);
  Engine& operator=(const Engine& e);

 public:
  // Construct only with configuration file
  Engine(const std::string& config);
  // Engine instance will not provide the polymorphism instances
  ~Engine(void);
};

#endif  // CIRCLE_05_WEBSERV_INCLUDES_ENGINE_HPP_
