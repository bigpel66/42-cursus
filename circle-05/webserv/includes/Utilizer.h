// Copyright @bigpel66

// Header for the dependency on standard things
#ifndef CIRCLE_05_WEBSERV_INCLUDES_UTILIZER_HPP_
#define CIRCLE_05_WEBSERV_INCLUDES_UTILIZER_HPP_

// Standard Library Inclusion
#include <vector>
#include <map>
#include <list>
#include <string>
#include <iostream>
#include <exception>
#include <netinet/in.h>

// Class Headers Inclusion
#include "./Client.hpp"

#define DEFAULT_STACK_SIZE 8388608
#define DEFAULT_BUFFER_SIZE 100000
#define DEFAULT_SERVER_PORT 8080
#define DEFAULT_PENDING_QUEUE_SIZE 4096
#define MAX_WORKERS 50

class Worker;
struct s_location;

typedef struct sockaddr_in sock_addr;

typedef std::map<std::string, std::string> Header;

typedef std::map<std::string, std::string> Mimes;

typedef std::map<std::string, std::string> Params;

typedef std::vector<std::string> Methods;

typedef std::map<int, std::string> ErrorPages;

typedef std::vector<Server *> Servers;

typedef std::vector<Worker *> Workers;

typedef std::list<s_location *> Locations;

typedef std::list<Client> Clients;

typedef struct s_options {
  Methods methods;
  Params params;
} t_options;

typedef struct s_location {
  std::string path;
  t_options options;
  s_location *parent_location;
  Locations child_locations;
} t_location;

typedef struct s_server {
  int id;
  int port;
  std::string name;
  bool is_auto_index_on;
  ErrorPages error_pages;
  t_location *root_location;
} t_server;

namespace ft {
  const class nullptr_t {
   private:
    // Not allowed to get the address
    void operator&(void) const;

   public:
    // Return 0 for any class pointer
    template<typename T>
    operator T*(void) const {
      return 0;
    }

    // Return 0 for any member pointer
    template<typename T, typename U>
    operator T U::*(void) const {
      return 0;
    }

    // Safe boolean conversion
    operator void*(void) const {
      return 0;
    }
  } nullptr_t = {};
}  // namespace ft



#endif  // CIRCLE_05_WEBSERV_INCLUDES_UTILIZER_HPP_
