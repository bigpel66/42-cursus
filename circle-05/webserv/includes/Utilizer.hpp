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
#include <regex.h>
#include <signal.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

class ServContext;
class Client;

// Constant Definition
#define DEFAULT_DELAY             1
#define DEFAULT_BUFFER_SIZE       131071
#define MINIMUM_WORKER_COUNT      1
#define MAXIMUM_WORKER_COUNT      8
#define MAXIMUM_CONNECTION        1024
#define MAXIMUM_PORT_NUMBER       65535
#define MAXIMUM_CLIENT_NUMBER     1024
#define MAXIMUM_REDIRECT_NUMBER   5
#define HEADER_TIMEOUT            60
#define BODY_TIMEOUT              60

namespace ft {

const class nil {
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
} nil = {};

template<typename T>
void safe_delete(T **ptr) {
  if (*ptr) {
    delete *ptr;
    *ptr = nil;
  }
}

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

std::string inet_ntop(void *addr);

void *sockaddr_to_void_ptr_sockaddr_in(struct sockaddr *addr);

}  // namespace ft

class Listen {
 private:
  std::string _ip;
  uint32_t _port;


 public:
  Listen(void);
  Listen(const std::string& ip, std::uint32_t port);
  Listen(const Listen& l);
  Listen& operator=(const Listen& l);
  ~Listen(void);

  const std::string& get_ip(void) const;
  std::uint32_t get_port(void) const;

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

typedef void (ServContext::*DirectiveConverter)(Tokens::iterator *it);

typedef ServContext Location;
typedef std::vector<int> ErrorCodes;
typedef std::vector<Listen> Listens;
typedef std::vector<std::string> Indexes;
typedef std::vector<std::string> Methods;
typedef std::vector<std::string> ServerNames;
typedef std::vector<Location *> Locations;
typedef std::vector<ServContext *> ServContexts;
typedef std::map<std::string, bool> Options;
typedef std::map<int, std::string> ErrorPages;
typedef std::map<std::string, std::string> CGIs;
typedef std::map<std::string, DirectiveConverter> DirectiveConverters;
typedef std::map<std::string, std::string, ft::lower_comp> Headers;

typedef std::map<int, std::string> StatusCodeMapper;
typedef std::map<std::string, std::string, ft::lower_comp> MimeMapper;

typedef std::set<int> FDs;
typedef std::map<int, Listen> Servers;
typedef std::map<int, Client *> Clients;

#endif  // CIRCLE_05_WEBSERV_INCLUDES_UTILIZER_HPP_
