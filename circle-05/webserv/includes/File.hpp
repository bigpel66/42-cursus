// Copyright @bigpel66

// Header for the handling file
#ifndef CIRCLE_05_WEBSERV_INCLUDES_FILE_HPP_
#define CIRCLE_05_WEBSERV_INCLUDES_FILE_HPP_

// Standard Library Inclusion
#include <string>

// Class Headers Inclusion
#include "./Utilizer.hpp"
#include "./Mimes.hpp"
#include "./Logger.hpp"

class File {
 private:
  int _fd;
  std::string _name;
  std::string _fullname;
  std::string _extension;
  Matches _matches;
  std::string _path;

  std::string set_width(std::size_t width, const std::string& str);

  bool is_entry_matched(const std::string& name) const;
  bool is_negotiated(void) const;

  void set_file_name();
  void set_file_extension(bool is_negotiation);
  void set_file_extension_on_negotiation(std::size_t dot_position);
  void parse_path(bool is_negotiation);

  void init_sorted_auto_listings(DIR *dir, AutoListings *auto_listings);
  void set_body_before_listing(std::string *body, const std::string& target);
  void set_body_after_listing(std::string *body);
  void set_body_listing(std::string *body,
                        const std::string& target,
                        AutoListings *als);

  File(const File& f);
  File& operator=(const File& f);

 public:
  File(void);
  explicit File(const std::string& path);
  ~File(void);

  bool open(bool is_file_needs_to_be_created = false);
  void close();
  void unlink();
  void create(const std::string& body);
  void append(const std::string& body);
  void set_path(std::string path, bool is_negotiation = false);

  const std::string& get_path(void) const;
  const std::string& get_extension(void) const;
  std::string get_content(void) const;
  std::string get_autoindex(const std::string& target);
  int get_fd(void) const;
  std::string get_last_modified(void);
  std::string find_index(const Indexes& indexes);

  bool is_exist(void) const;
  bool is_directory(void) const;
  static bool is_exist(const std::string& path);
  static bool is_directory(const std::string& path);
};

#endif  // CIRCLE_05_WEBSERV_INCLUDES_FILE_HPP_
