// Copyright @bigpel66

#include "../includes/Server.hpp"
#include <sys/time.h>

Server::Server(t_server server_info, Mutex *logger, Mimes mimes)
  : AbstractThread(DEFAULT_STACK_SIZE) {
  _id = server_info.id;
  _port = server_info.port;
  _server_name = server_info.name;
  _logger = logger;
  _socket = socket(AF_INET, SOCK_STREAM, 0);
}

Server::~Server(void) {}

void Server::log(const std::string& message) const {
  time_t time;
  struct timeval tv;
  struct tm *time_info;
  char buffer[100];
  _logger->lock();
  gettimeofday(&tv, ft::nullptr_t);
  time = tv.tv_sec;
  time_info = localtime(&time);
  strftime(buffer, sizeof(buffer), "[%c]", time_info);
  std::cout << "\e[1;" << std::to_string(93 + _id) << "m["
            << _server_name << "::" << _port << "]\e[0m"
            << message
            << " \e[1;90m" << buffer << "\e[0m" << std::endl;
  _logger->unlock();
}

void Server::error(const std::string& message) const {
  perror(message.c_str());
  exit(1);
}
