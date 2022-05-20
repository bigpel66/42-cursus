// Copyright @bigpel66

#include "../includes/Engine.hpp"

Engine::Engine(const std::string& config)
  : _logger(DEBUG), _parser(config) {
}

Engine::~Engine(void) {
}
