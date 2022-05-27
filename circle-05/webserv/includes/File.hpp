// Copyright @bigpel66

// Header for the handling file
#ifndef CIRCLE_05_WEBSERV_INCLUDES_FILE_HPP_
#define CIRCLE_05_WEBSERV_INCLUDES_FILE_HPP_

// Standard Library Inclusion
#include <string>

// Class Headers Inclusion
#include "./Utilizer.hpp"

class File {
 private:
  int _fd;
  std::string _name;
  std::string _extension;
  std::string _fullname;
  std::string _path;
  Matches _matches;

  File(const File& f);
  File& operator=(const File& f);

 public:
  explicit File(const std::string& path);
  File(void);
  ~File(void);

  bool is_exist(void) const;
  bool is_directory(void) const;
  bool open(bool is_file_needs_to_be_created);
  void close(void);
  void unlink(void);
  void create(const std::string& body);
  void append(const std::string& body);
  void parse_match(void);
  void parse_extension(void);
  void parse_extension_with_negotiation(void);
  void set_path(const std::string& path, bool is_negotiation);

  const std::string& get_path(void) const;
  const std::string& get_extension(void) const;
  std::string get_content(void) const;
  std::string get_autoindex(const std::string& target) const;
  Matches& get_matches(void);
  int get_fd(void) const;
  std::string get_last_modified(void);
  std::string find_index(const Indexes& indexes);

  static bool is_exist(const std::string& path);
  static bool is_directory(const std::string& path);
};

#endif  // CIRCLE_05_WEBSERV_INCLUDES_FILE_HPP_
