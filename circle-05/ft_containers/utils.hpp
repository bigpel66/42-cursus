// Copyright @bigpel66

#ifndef CIRCLE_05_FT_CONTAINERS_UTILS_HPP_
#define CIRCLE_05_FT_CONTAINERS_UTILS_HPP_

#include <cstdint>

namespace ft {

/* nullptr_t */
const class nullptr_t {
 private:
  void operator&(void) const;

 public:
  template <typename T>
    operator T*(void) const { return 0; }

  template <typename T, typename U>
    operator T U::*(void) const { return 0; }
} nil = {};

/* enable_if */
template <bool cond, typename T = void>
struct enable_if {};

template <typename T>
struct enable_if <true, T> {
  typedef T type;
};

/* is_integral_base */
template <bool is_integral, typename T>
struct is_integral_base {
typedef T type;
static const bool value = is_integral;
};

/* is_integral */
template <typename>
struct is_integral
  : public is_integral_base<false, void> {};

template <>
struct is_integral<bool>
  : public is_integral_base<true, bool> {};

template <>
struct is_integral<char>
  : public is_integral_base<true, char> {};

template <>
struct is_integral<unsigned char>
  : public is_integral_base<true, unsigned char> {};

template <>
struct is_integral<short>
  : public is_integral_base<true, short> {};

template <>
struct is_integral<unsigned short>
  : public is_integral_base<true, unsigned short> {};

template <>
struct is_integral<int>
  : public is_integral_base<true, int> {};

template <>
struct is_integral<unsigned int>
  : public is_integral_base<true, unsigned int> {};

template <>
struct is_integral<long>
  : public is_integral_base<true, long> {};

template <>
struct is_integral<unsigned long>
  : public is_integral_base<true, unsigned long> {};

template <>
struct is_integral<long long>
  : public is_integral_base<true, long long> {};

template <>
struct is_integral<unsigned long long>
  : public is_integral_base<true, unsigned long long> {};

}  // namespace ft

#endif  // CIRCLE_05_FT_CONTAINERS_UTILS_HPP_
