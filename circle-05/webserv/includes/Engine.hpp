// Copyright @bigpel66

// Header for the main engine of webserv
#ifndef CIRCLE_05_WEBSERV_INCLUDES_ENGINE_HPP_
#define CIRCLE_05_WEBSERV_INCLUDES_ENGINE_HPP_

// Standard Library Inclusion
#include <string>
#include <iostream>

// Class Headers Inclusion
#include "./Parser.hpp"

// Engine of Webserv
class Engine {
 private:
  // Holds the server configuration fields and values
  Parser _parser;

  // Coplien, but prevent to call below functions
  Engine(void);
  Engine(const Engine& e);
  Engine& operator=(const Engine& e);

 public:
  // Construct only with configuration file
  explicit Engine(const std::string& config);
  // Engine instance will not provide the polymorphism instances
  ~Engine(void);
};

#endif  // CIRCLE_05_WEBSERV_INCLUDES_ENGINE_HPP_
