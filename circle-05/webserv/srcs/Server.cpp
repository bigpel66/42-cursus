// Copyright @bigpel66

#include "../includes/Server.hpp"
#include "../includes/Exception.hpp"
#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <sys/socket.h>

Server::Server(t_server server_info, Mutex *logger, Mimes mimes)
  : AbstractThread(DEFAULT_STACK_SIZE) {
  _id = server_info.id;
  _port = server_info.port;
  _server_name = server_info.name;
  _logger = logger;
  log("Starting...");
  set_socket();
  set_ioctl();
  bind_socket();
  listen_socket();
  group_client();
  _error_pages = server_info.error_pages;
  _root_location = server_info.root_location;
  _is_auto_index_on = server_info.is_auto_index_on;
  _mimes = mimes;
}

void Server::set_socket(void) {
  _socket = socket(AF_INET, SOCK_STREAM, 0);
  if (socket < 0) {
    throw ServerException("socket opening failed.", _socket);
  }
}

void Server::set_ioctl(void) {
  int option = 1;
  int code = setsockopt(_socket,
                        SOL_SOCKET,
                        SO_REUSEADDR,
                        reinterpret_cast<char *>(&option),
                        sizeof(option));
  if (code < 0) {
    throw ServerException("setsockopt failed.", code);
  }
  code = fcntl(_socket, F_SETFL, O_NONBLOCK);
  if (code < 0) {
    throw ServerException("fcntl failed.", code);
  }
}

void Server::bind_socket(void) {
  memset(reinterpret_cast<void *>(&_server_addr), 0, sizeof(_server_addr));
  _server_addr.sin_family = AF_INET;
  _server_addr.sin_addr.s_addr = INADDR_ANY;
  _server_addr.sin_port = htons(_port);
  int code = bind(_socket, (struct sockaddr *)&_server_addr, sizeof(_server_addr));
  if (code < 0) {
    throw ServerException("socket binding failed.", code);
  }
}

void Server::listen_socket(void) {
  int code = listen(_socket, DEFAULT_PENDING_QUEUE_SIZE);
  if (code < 0) {
    throw ServerException("socket listening failed.", code);
  }
}

void Server::group_client(void) {
  FD_ZERO(&_client_fd);
  _max_sd = _socket;
  FD_SET(_socket, &_client_fd);
}

Server::~Server(void) {
  close(_socket);
}

void Server::log(const std::string& message) const {
  time_t time;
  struct timeval tv;
  struct tm *time_info;
  char buffer[100];
  _logger->lock();
  gettimeofday(&tv, ft::nullptr_t);
  time = tv.tv_sec;
  time_info = localtime_r(&time, ft::nullptr_t);
  strftime(buffer, sizeof(buffer), "[%c]", time_info);
  std::cout << "\e[1;" << std::to_string(93 + _id) << "m["
            << _server_name << "::" << _port << "]\e[0m"
            << message
            << " \e[1;90m" << buffer << "\e[0m" << std::endl;
  _logger->unlock();
}

void Server::log_level_1(const std::string& message) const {
  log(std::string("\e[33;1m[") + message + std::string("]"));
}

void Server::log_level_2(const std::string& message) const {
  log(std::string("\e[32;1m[") + message + std::string("]"));
}

void Server::log_level_3(const std::string& message) const {
  log(std::string("\e[96;1m[") + message + std::string("]"));
}

void Server::log_level_4(const std::string& message) const {
  log(std::string("\e[93;1m[") + message + std::string("]"));
}

void Server::log_level_5(const std::string& message) const {
  log(std::string("\e[31;1m[") + message + std::string("]"));
}
