// Copyright @bigpel66

#include "../includes/Engine.hpp"

Engine::Engine(const std::string& config) : _parser(config) {
  std::ifstream file("config/mime_types");
  std::string line;
  std::string key;
  std::size_t pos;
  Mimes mimes;
  while (std::getline(file, line)) {
    while ((pos = line.find(" ")) != std::string::npos) {
      key = "." + line.substr(0, pos);
      line.erase(0, pos + 1);
    }
    mimes.insert(std::make_pair(key, line));
  }
  for (std::size_t i = 0 ; i < _parser.get_server_size() ; i++) {
    Server *server = new Server(locations, &_logger, mimes);
    _servers.push_back(server);
  }
  for (std::size_t i = 0 ; i < _parser.get_worker_size() ; i++) {
    Worker *worker = new Worker(i);
    _workers.push_back(worker);
  }
}

void Engine::clear_server(void) {
  Servers::iterator begin_iter = _servers.begin();
  Servers::iterator end_iter = _servers.end();
  while (begin_iter != end_iter) {
    delete *begin_iter;
    begin_iter++;
  }
  _servers.clear();
}

void Engine::clear_worker(void) {
  Workers::iterator begin_iter = _workers.begin();
  Workers::iterator end_iter = _workers.end();
  while (begin_iter != end_iter) {
    delete *begin_iter;
    begin_iter++;
  }
  _workers.clear();
}

Engine::~Engine(void) {
  clear_server();
  clear_worker();
}
