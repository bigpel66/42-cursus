// Copyright @bigpel66

// Header for the dependency on standard things
#ifndef CIRCLE_05_WEBSERV_INCLUDES_UTILIZER_HPP_
#define CIRCLE_05_WEBSERV_INCLUDES_UTILIZER_HPP_

// Standard Library Inclusion
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <exception>
#include <netinet/in.h>

#define DEFAULT_STACK_SIZE 8388608
#define DEFAULT_BUFFER_SIZE 100000
#define DEFAULT_SERVER_PORT 8080
#define MAX_WORKERS 50

typedef struct sockaddr_in sock_addr;

typedef std::map<std::string, std::string> Header;

typedef std::map<std::string, std::string> Mimes;

typedef struct s_options {
  std::vector<std::string> methods;
  std::map<std::string, std::string> params;
} t_options;

typedef struct s_location {
  std::string path;
  t_options options;
  s_location *parent;
  std::vector<s_location *> children;
} t_location;

typedef struct s_server {
  int id;
  int port;
  std::string name;
  bool is_auto_index_on;
  std::map<int, std::string> error_pages;
  t_location *root;
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
