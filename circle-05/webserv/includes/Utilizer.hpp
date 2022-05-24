// Copyright @bigpel66

// Header for the dependency on standard things
#ifndef CIRCLE_05_WEBSERV_INCLUDES_UTILIZER_HPP_
#define CIRCLE_05_WEBSERV_INCLUDES_UTILIZER_HPP_

// Standard Library Inclusion
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <netinet/in.h>

class ServerConfig;
class Client;

// Constant Definition
#define DEFAULT_DELAY         1
#define DEFAULT_BUFFER_SIZE   131071
#define MINIMUM_WORKER_COUNT  1
#define MAXIMUM_WORKER_COUNT  8
#define MAXIMUM_PORT_NUMBER   65535
#define MAXIMUM_CLIENT_NUMBER 1024

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

struct lower_comp {
  bool operator()(const std::string& lhs, const std::string& rhs) const {
    std::string lhs_transformed = lhs;
    std::string rhs_transformed = rhs;
    int (*lower)(int) = std::tolower;
    std::transform(lhs_transformed.begin(),
                  lhs_transformed.end(),
                  lhs_transformed.begin(),
                  lower);
    std::transform(rhs_transformed.begin(),
                  rhs_transformed.end(),
                  rhs_transformed.begin(),
                  lower);
    return lhs_transformed < rhs_transformed;
  }
};

std::string inet_ntop(void *addr) {
  std::ostringstream stream;
  stream << std::to_string(reinterpret_cast<u_char *>(addr)[0]) << "."
          << std::to_string(reinterpret_cast<u_char *>(addr)[1]) << "."
          << std::to_string(reinterpret_cast<u_char *>(addr)[2]) << "."
          << std::to_string(reinterpret_cast<u_char *>(addr)[3]);
  return stream.str();
}

void *sockaddr_to_void_ptr_sockaddr_in(struct sockaddr *addr) {
  return &(reinterpret_cast<struct sockaddr_in *>(addr)->sin_addr);
}

}  // namespace ft

class Listen {
 private:
  std::string _ip;
  uint32_t _port;

  Listen(void);

 public:
  Listen(const std::string& ip, uint32_t port);
  Listen(const Listen& l);
  Listen& operator=(const Listen& l);
  ~Listen(void);

  friend std::ostream& operator<<(std::ostream& o, const Listen& l);
  friend bool operator==(const Listen& lhs, const Listen& rhs);
};

std::ostream& operator<<(std::ostream& o, const Listen& l);
bool operator==(const Listen& lhs, const Listen& rhs);

// Type Definition
typedef std::stack<bool> BraceChecker;
typedef std::stack<bool> DirectiveChecker;

typedef std::vector<std::size_t> Lines;
typedef std::vector<std::string> Tokens;

typedef void (ServerConfig::*DirectiveConverter)(Tokens::iterator *it);

typedef std::vector<int> ErrorCodes;
typedef std::vector<Listen> Listens;
typedef std::vector<std::string> Indexes;
typedef std::vector<std::string> Methods;
typedef std::vector<std::string> ServerNames;
typedef std::vector<ServerConfig *> Locations;
typedef std::vector<ServerConfig *> ServerConfigs;
typedef std::map<std::string, bool> Options;
typedef std::map<int, std::string> ErrorPages;
typedef std::map<std::string, std::string> CGIs;
typedef std::map<std::string, DirectiveConverter> DirectiveConverters;

typedef std::map<int, std::string> StatusCodeMapper;
typedef std::map<std::string, std::string, ft::lower_comp> MimeMapper;

typedef std::set<int> FDs;
typedef std::map<int, Listen> Servers;
typedef std::map<int, Client *> Clients;

#endif  // CIRCLE_05_WEBSERV_INCLUDES_UTILIZER_HPP_
