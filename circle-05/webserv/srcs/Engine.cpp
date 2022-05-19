// Copyright @bigpel66

#include "../includes/Engine.hpp"

Engine::Engine(const std::string& config) : _parser(config) {
  init_mimes();
  push_server_as_parser();
  push_worker_as_parser();
}

void Engine::clear_servers(void) {
  Servers::iterator begin_iter = _servers.begin();
  Servers::iterator end_iter = _servers.end();
  while (begin_iter != end_iter) {
    delete *begin_iter;
    begin_iter++;
  }
  _servers.clear();
}

void Engine::clear_workers(void) {
  Workers::iterator begin_iter = _workers.begin();
  Workers::iterator end_iter = _workers.end();
  while (begin_iter != end_iter) {
    delete *begin_iter;
    begin_iter++;
  }
  _workers.clear();
}

Engine::~Engine(void) {
  clear_servers();
  clear_workers();
}

void Engine::init_mimes(void) {
  std::ifstream file("config/mime_types");
  std::string line;
  std::string key;
  std::size_t pos;
  while (std::getline(file, line)) {
    while ((pos = line.find(" ")) != std::string::npos) {
      key = "." + line.substr(0, pos);
      line.erase(0, pos + 1);
    }
    _mimes.insert(std::make_pair(key, line));
  }
}

void Engine::push_server_as_parser(void) {
  for (std::size_t i = 0 ; i < _parser.get_server_size() ; i++) {
    Server *server = new Server(_parser.get_server_info(i), &_logger, _mimes);
    _servers.push_back(server);
  }
}

void Engine::push_worker_as_parser(void) {
  for (std::size_t i = 0 ; i < _parser.get_worker_size() ; i++) {
    Worker *worker = new Worker(i);
    _workers.push_back(worker);
  }
}
Servers Engine::get_servers(void) const {
  return _servers;
}

Workers Engine::get_workers(void) const {
  return _workers;
}

std::size_t Engine::get_server_size(void) const {
  return _parser.get_server_size();
}

std::size_t Engine::get_worker_size(void) const {
  return _parser.get_worker_size();
}
