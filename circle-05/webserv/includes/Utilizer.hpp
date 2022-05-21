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

// Type Definition
typedef std::stack<bool> BraceChecker;
typedef std::stack<bool> DirectiveChecker;
typedef std::vector<std::string> Tokens;
typedef std::map<std::string, bool> Options;
typedef std::vector<ServerConfig> ServerConfigs;

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
