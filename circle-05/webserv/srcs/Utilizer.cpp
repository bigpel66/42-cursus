#include "../includes/Utilizer.hpp"

void ft::safe_free(void **ptr) {
  if (*ptr) {
    free(*ptr);
    *ptr = nil;
  }
}

void ft::safe_free_all(void ***ptr) {
  if (*ptr) {
    int i = 0;
    while ((*ptr)[i]) {
      ft::safe_free(&((*ptr)[i]));
      i++;
    }
    ft::safe_free(reinterpret_cast<void **>(ptr));
  }
}

std::string ft::base64_decode(const std::string& str) {
  if (str.length() == 0) {
    return "";
  }
  char *p = const_cast<char *>(str.c_str());
  unsigned char *str_ptr = reinterpret_cast<unsigned char *>(p);
  std::size_t j = 0;
  std::size_t pad1 = str.length() % 4 || str_ptr[str.length() - 1] == '=';
  std::size_t pad2 = pad1 &&
                    (str.length() % 4 > 2 || str_ptr[str.length() - 2] != '=');
  const std::size_t last = (str.length() - pad1) / 4 << 2;
  std::string result(last / 4 * 3 + pad1 + pad2, '\0');
  unsigned char *res_ptr = reinterpret_cast<unsigned char *>(&result[0]);
  for (std::size_t i = 0; i < last; i += 4) {
    int n = ft::base64[str_ptr[i]] << 18 |
            ft::base64[str_ptr[i + 1]] << 12 |
            ft::base64[str_ptr[i + 2]] << 6 |
            ft::base64[str_ptr[i + 3]];
    res_ptr[j++] = n >> 16;
    res_ptr[j++] = n >> 8 & 0xFF;
    res_ptr[j++] = n & 0xFF;
  }
  if (pad1) {
    int n = ft::base64[str_ptr[last]] << 18 |
            ft::base64[str_ptr[last + 1]] << 12;
    res_ptr[j++] = n >> 16;
    if (pad2) {
      n |= ft::base64[str_ptr[last + 2]] << 6;
      res_ptr[j++] = n >> 8 & 0xFF;
    }
  }
  return result;
}

std::string ft::tolower(std::string s) {
  std::transform(s.begin(), s.end(), s.begin(), ::tolower);
  return s;
}

std::string ft::toupper(std::string s) {
  std::transform(s.begin(), s.end(), s.begin(), ::toupper);
  return s;
}

std::string ft::trim_left(std::string str, char c) {
  std::size_t startpos = str.find_first_not_of(c);
  if (startpos != std::string::npos)
    str.erase(0, startpos);
  return str;
}

std::string ft::trim_right(std::string str, char c) {
  std::size_t lastpos = str.find_last_not_of(c);
  if (lastpos == std::string::npos)
    return "";
  str.erase(lastpos + 1, str.length());
  return str;
}

std::string ft::get_sole_slash_target(std::string str) {
  std::string::iterator it = str.begin();
  while (it != str.end()) {
    if (*it == '/') {
      it++;
      while (it != str.end() && *it == '/') {
        it = str.erase(it);
      }
    } else {
      it++;
    }
  }
  return str;
}

std::string ft::get_current_datetime() {
  char buf[32];
  struct tm	*tm;
  struct timeval tv;
  gettimeofday(&tv, ft::nil);
  tm = gmtime(&tv.tv_sec);
  std::size_t size = strftime(buf, 32, "%a, %d %b %Y %T GMT", tm);
  return std::string(buf, size);
}

time_t ft::get_current_timestamp() {
  struct timeval cur;
  gettimeofday(&cur, ft::nil);
  return (cur.tv_sec);
}

std::size_t ft::length_on_hex(const std::string& str) {
  std::stringstream ss;
  std::size_t hex_length;
  ss << std::hex << str;
  ss >> hex_length;
  return hex_length;
}

std::string ft::inet_ntop(void *addr) {
  std::ostringstream stream;
  stream << to_string(reinterpret_cast<u_char *>(addr)[0]) << "."
          << to_string(reinterpret_cast<u_char *>(addr)[1]) << "."
          << to_string(reinterpret_cast<u_char *>(addr)[2]) << "."
          << to_string(reinterpret_cast<u_char *>(addr)[3]);
  return stream.str();
}

void *ft::sockaddr_to_void_ptr_sockaddr_in(struct sockaddr *addr) {
  return &(reinterpret_cast<struct sockaddr_in *>(addr)->sin_addr);
}

int ft::stoi(const std::string &str) {
  int num;
  std::stringstream ss;
  ss << str;
  ss >> num;
  return num;
}

Listen::Listen(void)
  : ip(""), port(0) {}

Listen::Listen(const std::string& ip, std::uint32_t port)
  : ip(ip), port(port) {}

Listen::Listen(const Listen& l) {
  *this = l;
}

Listen& Listen::operator=(const Listen& l) {
  if (this != &l) {
    ip = l.ip;
    port = l.port;
  }
  return *this;
}

Listen::~Listen(void) {}

std::ostream& operator<<(std::ostream& o, const Listen& l) {
  o << "\n\t\t\t" << l.ip << " : " << l.port;
  return o;
}

bool operator==(const Listen& lhs, const Listen& rhs) {
  return lhs.ip == rhs.ip && lhs.port == rhs.port;
}

AutoListing::AutoListing(void)
  : is_directory(false) {}

AutoListing::AutoListing(const AutoListing& a) {
  *this = a;
}

AutoListing& AutoListing::operator=(const AutoListing& a) {
  if (this != &a) {
    name = a.name;
    date = a.date;
    size = a.size;
    is_directory = a.is_directory;
  }
  return *this;
}

AutoListing::~AutoListing(void) {}

bool sort_auto_listing(const AutoListing& lhs, const AutoListing& rhs) {
  if (lhs.is_directory && rhs.is_directory) {
    return lhs.name < rhs.name;
  } else if (!lhs.is_directory && !rhs.is_directory) {
    return lhs.name < rhs.name;
  } else {
    return lhs.is_directory > rhs.is_directory;
  }
}
