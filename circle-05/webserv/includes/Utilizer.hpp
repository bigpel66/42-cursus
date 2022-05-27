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
class Response;
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
#define MAXIMUM_URI_LENGTH        100000
#define MAXIMUM_HEADER_KEY_LENGTH 1000
#define MAXIMUM_HEADER_VAL_LENGTH 4000
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

void safe_free(void **ptr) {
  if (*ptr) {
    free(*ptr);
    *ptr = nil;
  }
}

void safe_free_all(void ***ptr) {
  if (*ptr) {
    int i = 0;
    while ((*ptr)[i]) {
      safe_free(&((*ptr)[i]));
      i++;
    }
    safe_free(reinterpret_cast<void **>(ptr));
  }
}

std::string tolower(std::string s);

std::string toupper(std::string s);

std::string get_http_date(void);

std::string get_sole_slash_target(std::string str);

std::string inet_ntop(void *addr);

struct lower_comp {
  bool operator()(const std::string& lhs, const std::string& rhs) const {
    std::string lhs_transformed = ft::tolower(lhs);
    std::string rhs_transformed = ft::tolower(rhs);
    return lhs_transformed < rhs_transformed;
  }
};

void *sockaddr_to_void_ptr_sockaddr_in(struct sockaddr *addr);

std::size_t length_on_hex(const std::string& str);

static const int base64[256] = {
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  62, 63, 62, 62, 63,
  52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 0,  0,  0,  0,  0,  0,
  0,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14,
  15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 0,  0,  0,  0,  63,
  0,  26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
  41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51
};

std::string base64_decode(const std::string& str);

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
typedef int (Response::*MethodConverter)(void);

typedef ServContext Location;
typedef std::vector<int> ErrorCodes;
typedef std::vector<Listen> Listens;
typedef std::vector<std::string> Indexes;
typedef std::vector<std::string> Methods;
typedef std::vector<std::string> ServerNames;
typedef std::vector<std::string> Matches;
typedef std::vector<Location *> Locations;
typedef std::vector<ServContext *> ServContexts;
typedef std::map<std::string, bool> Options;
typedef std::map<int, std::string> ErrorPages;
typedef std::map<std::string, std::string> CGIs;
typedef std::map<std::string, std::string> Envs;
typedef std::map<std::string, DirectiveConverter> DirectiveConverters;
typedef std::map<std::string, MethodConverter> MethodConverters;
typedef std::map<std::string, std::string, ft::lower_comp> Headers;

typedef std::map<int, std::string> StatusCodeMapper;
typedef std::map<std::string, std::string, ft::lower_comp> MimeMapper;

typedef std::set<int> FDs;
typedef std::map<int, Listen> Servers;
typedef std::map<int, Client *> Clients;

#endif  // CIRCLE_05_WEBSERV_INCLUDES_UTILIZER_HPP_
