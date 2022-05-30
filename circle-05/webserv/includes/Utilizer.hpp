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
#include <iostream>
#include <exception>
#include <sstream>

#include <cstring>
#include <ctime>

#include <fcntl.h>
#include <regex.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <dirent.h>
#include <pthread.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

// Foward Declaration
class ServContext;
class Response;
class Server;
class Client;

// Constant Definition
#define DEFAULT_PORT              4242
#define DEFAULT_STACK_SIZE        524288
#define DEFAULT_DELAY             500
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
std::string to_string(T number) {
  std::stringstream ss;
  ss << number;
  return ss.str();
}

template<typename T>
void safe_delete(T **ptr) {
  if (*ptr) {
    delete *ptr;
    *ptr = nil;
  }
}

void safe_free(void **ptr);

void safe_free_all(void ***ptr);

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

std::string base64_decode(const std::string &str);

std::string tolower(std::string str);

std::string toupper(std::string str);

std::string trim_left(std::string str, char c);

std::string trim_right(std::string str, char c);

std::string get_sole_slash(std::string str);

std::string get_current_datetime(void);

time_t get_current_timestamp(void);

std::size_t length_on_hex(const std::string& str);

std::string inet_ntop(void *addr);

void *sockaddr_to_void_ptr_sockaddr_in(struct sockaddr *addr);

int stoi(const std::string &str);

struct lower_comp {
  bool operator()(const std::string& lhs, const std::string& rhs) const {
    std::string lhs_transformed = ft::tolower(lhs);
    std::string rhs_transformed = ft::tolower(rhs);
    return lhs_transformed < rhs_transformed;
  }
};

}  // namespace ft

struct Listen {
 public:
  std::string ip;
  std::uint32_t port;

  Listen(void);
  Listen(const std::string& ip, std::uint32_t port);
  Listen(const Listen& l);
  Listen& operator=(const Listen& l);
  ~Listen(void);

  friend std::ostream& operator<<(std::ostream& o, const Listen& l);
  friend bool operator==(const Listen& lhs, const Listen& rhs);
};

std::ostream& operator<<(std::ostream& o, const Listen& l);
bool operator==(const Listen& lhs, const Listen& rhs);

class AutoListing {
 public:
  std::string name;
  std::string date;
  std::size_t size;
  bool is_directory;

  AutoListing(void);
  AutoListing(const AutoListing& a);
  AutoListing& operator=(const AutoListing& a);
  ~AutoListing(void);

  friend bool sort_auto_listing(const AutoListing& lhs, const AutoListing& rhs);
};

bool sort_auto_listing(const AutoListing& lhs, const AutoListing& rhs);

class Worker {
 public:
  int id;
  pthread_t t;
  Server *serv;
};

typedef struct sockaddr SockAddr;

typedef ServContext Location;
typedef std::set<int> FDs;
typedef std::vector<int> ErrorCodes;
typedef std::vector<std::size_t> Lines;
typedef std::vector<std::string> Tokens;
typedef std::vector<std::string> Methods;
typedef std::vector<std::string> Indexes;
typedef std::vector<std::string> Matches;
typedef std::vector<Listen> Listens;
typedef std::vector<Location> Locations;
typedef std::vector<Location *> LocationPtrs;
typedef std::vector<std::string> ServerNames;
typedef std::vector<ServContext> ServContexts;
typedef std::vector<ServContext *> ServContextPtrs;
typedef std::vector<AutoListing> AutoListings;
typedef std::vector<Worker> Workers;

typedef std::map<std::string, bool> Options;
typedef std::map<int, std::string> ErrorPages;
typedef std::map<std::string, std::string> CGIs;
typedef std::map<std::string, std::string> Envs;
typedef std::map<std::string, std::string> Headers;
typedef std::map<int, Listen> Servers;
typedef std::map<int, Client *> Clients;
typedef std::map<int, std::string> StatusCodeMapper;
typedef std::map<std::string, std::string, ft::lower_comp> MimeMapper;

typedef std::stack<bool> BraceChecker;
typedef std::stack<bool> DirectiveChecker;
typedef void (ServContext::*DirectiveConverter)(Tokens::iterator *it);
typedef std::map<std::string, DirectiveConverter> DirectiveConverters;
typedef int (Response::*MethodConverter)(void);
typedef std::map<std::string, MethodConverter> MethodConverters;

#endif  // CIRCLE_05_WEBSERV_INCLUDES_UTILIZER_HPP_
