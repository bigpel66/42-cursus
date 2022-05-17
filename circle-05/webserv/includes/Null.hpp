// Copyright @bigpel66

// Header for the Null Pointer Implementation for safety
#ifndef CIRCLE_05_WEBSERV_INCLUDES_NULL_HPP_
#define CIRCLE_05_WEBSERV_INCLUDES_NULL_HPP_

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

#endif  // CIRCLE_05_WEBSERV_INCLUDES_NULL_HPP_
