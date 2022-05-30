// Copyright @bigpel66

#include "../includes/Engine.hpp"

Logger Engine::logger;

Mimes Engine::mimes;

StatusCodes Engine::status_codes;

Mutex Engine::server_controller;

Mutex Engine::connection_controller;

Mutex Engine::response_controller;

Engine::Engine(int argc, char **argv)
  : _argc(argc),
    _argv(argv),
    _parser(ft::nil) {
  init_options();
  parse_argument();
  if (is_help_option_on()) {
    print_guide_and_exit();
  }
  _parser = new Parser(argv[_i - 1]);
}

Engine::~Engine(void) {
  ft::safe_delete(&_parser);
}

std::string Engine::guide(void) {
  std::string s;
  s += "Usage: ./webserv [options] [file.conf]\n\n";
  s += "  -h, --help         : see the guide to launch webserv\n";
  return s;
}

void Engine::init_options(void) {
  _options["h"];
  _options["-help"];
}

void Engine::parse_option(void) {
  std::string arg = _argv[_i];
  std::string option = arg.substr(arg.find('-') + 1);
  if (is_option_available(option)) {
    _options[option] = true;
  } else {
    throw EngineException("[Invalid Option -" + option + "]\n" + guide());
  }
}

void Engine::parse_argument(void) {
  if (_argc < 2) {
    throw EngineException("[Too Less Arguments]\n" + guide());
  }
  for (_i =  1 ; _i < _argc ; _i++) {
    if (is_option()) {
      parse_option();
    } else if (is_too_many_argument()) {
      throw EngineException("[Too Many Arguments]\n" + guide());
    }
  }
}

void Engine::print_guide_and_exit(void) {
  std::cout << guide();
  exit(0);
}

bool Engine::is_option(void) {
  std::string arg = _argv[_i];
  return arg.at(0) == '-';
}

bool Engine::is_option_available(const std::string& option) const {
  return _options.find(option) != _options.end();
}

bool Engine::is_too_many_argument(void) const {
  return _i != _argc - 1;
}

bool Engine::is_help_option_on(void) const {
  return _options.at("h") || _options.at("-help");
}

Parser *Engine::get_parser(void) {
  return _parser;
}
