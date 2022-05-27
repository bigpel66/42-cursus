// Copyright @bigpel66

// Header for the handling file
#ifndef CIRCLE_05_WEBSERV_INCLUDES_FILE_HPP_
#define CIRCLE_05_WEBSERV_INCLUDES_FILE_HPP_

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
  File(void);
  ~File(void);

  bool open(bool is_file_needs_to_be_created);
  bool is_exist(void) const;
  bool is_directory(void) const;
  void create(const std::string& body);
  void append(const std::string& body);
  void close(void);
  void unlink(void);
  void parse_match(void);
  void parse_extension(void);
  void parse_extension_with_negotiation(void);
  void set_path(const std::string& path, bool is_negotiation);

  const std::string& get_path(void) const;
  const std::string& get_extension(void) const;
  std::string get_content(void) const;
  std::string get_autoindex(void) const;
  Matches& get_matches(void) const;
  int get_fd(void) const;
  std::string get_last_modified(void);
  std::string find_index(const Indexes& indexes);
};

#endif  // CIRCLE_05_WEBSERV_INCLUDES_FILE_HPP_
