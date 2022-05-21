// Copyright @bigpel66

// Header for the dependency on standard things
#ifndef CIRCLE_05_WEBSERV_INCLUDES_UTILIZER_HPP_
#define CIRCLE_05_WEBSERV_INCLUDES_UTILIZER_HPP_

// Standard Library Inclusion
#include <map>
#include <stack>
#include <vector>
#include <string>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/stat.h>

// Class Headers Inclusion
#include "./ServerConfig.hpp"

// Constant Definition
#define MINIMUM_WORKER_COUNT  1
#define MAXIMUM_WORKER_COUNT  8

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

class Listen {
 private:
  std::string _ip;
  uint32_t _port;

  Listen(void);
  Listen(const Listen& l);
  Listen& operator=(const Listen& l);

 public:
  Listen(const std::string& ip, uint32_t port);
  ~Listen(void);

  friend bool operator==(const Listen& lhs, const Listen& rhs);
};

bool operator==(const Listen& lhs, const Listen& rhs);

// Type Definition
typedef std::stack<bool> BraceChecker;
typedef std::stack<bool> DirectiveChecker;
typedef std::vector<std::size_t> Lines;
typedef std::vector<std::string> Tokens;
typedef std::vector<std::string> ServerNames;
typedef std::vector<Listen> Listens;
typedef std::vector<std::string> Indexes;
typedef std::vector<std::string> Methods;
typedef std::map<std::string, std::string> CGIs;
typedef std::map<int, std::string> ErrorCodes;
typedef std::map<std::string, bool> Options;
typedef std::vector<ServerConfig> Locations;
typedef std::vector<ServerConfig> ServerConfigs;

#endif  // CIRCLE_05_WEBSERV_INCLUDES_UTILIZER_HPP_
