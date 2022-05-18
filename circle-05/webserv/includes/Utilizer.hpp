// Copyright @bigpel66

// Header for the dependency on standard things
#ifndef CIRCLE_O5_WEBSERV_INCLUDES_UTILIZER_HPP_
#define CIRCLE_O5_WEBSERV_INCLUDES_UTILIZER_HPP_

// STL on C++
#include <vector>
#include <map>

// String on C++
#include <string>

// Exception on C++
#include <exception>

// Socket to Connect TCP for HTTP on C
// Thread for Concurrency on C

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

#endif  // CIRCLE_O5_WEBSERV_INCLUDES_UTILIZER_HPP_
