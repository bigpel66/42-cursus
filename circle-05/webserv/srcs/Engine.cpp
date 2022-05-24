// Copyright @bigpel66

#include "../includes/Engine.hpp"

Engine::Engine(int argc, char **argv)
  : _argc(argc),
    _argv(argv),
    _logger(ft::nullptr_t),
    _parser(ft::nullptr_t) {
  init_options();
  parse_argument();
  if (is_help_option_on()) {
    print_guide_and_exit();
  }
  if (is_logger_not_ready()) {
    init_logger("DEBUG");
  }
}

Engine::~Engine(void) {
  if (_logger) {
    delete _logger;
  }
  if (_parser) {
    delete _parser;
  }
}

std::string Engine::guide(void) {
  std::string s;
  s += "Usage: ./webserv [options] [file.conf]\n\n";
  s += "  -h, --help         : see the guide to launch webserv\n";
  s += "  -l, --log [LEVEL]  : set the log level (DEBUG, INFO, ERROR, FATAL)\n";
  s += "  -t, --test         : test file.conf and exit";
  return s;
}

void Engine::increase_index(void) {
  _i++;
}

void Engine::init_logger(const std::string& arg) {
  if (arg == "DEBUG") {
    _logger = new Logger(DEBUG);
  } else if (arg == "INFO") {
    _logger = new Logger(INFO);
  } else if (arg == "ERROR") {
    _logger = new Logger(ERROR);
  } else if (arg == "FATAL") {
    _logger = new Logger(FATAL);
  } else {
    throw EngineException("[Invalid Log Option " + arg + "]\n" + guide());
  }
}

void Engine::init_options(void) {
  _options["h"];
  _options["-help"];
  _options["t"];
  _options["-test"];
  _options["l"];
  _options["-log"];
}

void Engine::parse_other_option(void) {
  std::string arg = _argv[_i];
  std::string option = arg.substr(arg.find('-') + 1);
  if (is_option_available(option)) {
    _options[option] = true;
  } else {
    throw EngineException("[Invalid Option -" + option + "]\n" + guide());
  }
}

void Engine::parse_argument(void) {
  for (_i =  1 ; _i < _argc ; _i++) {
    if (is_log_option()) {
      increase_index();
      init_logger(_argv[_i]);
    } else if (is_other_option()) {
      parse_other_option();
    } else if (is_too_many_argument()) {
      throw EngineException("[Too Many Arguments]\n" + guide());
    } else {
      _parser = new Parser(_argv[_i]);
    }
  }
}

void Engine::print_guide_and_exit(void) {
  std::cout << guide();
  exit(0);
}

bool Engine::is_log_option(void) {
  std::string arg = _argv[_i];
  return (arg == "-l" || arg == "--log") && (_i < _argc - 1);
}

bool Engine::is_other_option(void) {
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

bool Engine::is_logger_not_ready(void) const {
  return _logger == ft::nullptr_t;
}

void Engine::launch(void) {
  // TODO(@bigpel66)
  Server serv(_logger, _options, _parser->get_serv_contexts());
}
