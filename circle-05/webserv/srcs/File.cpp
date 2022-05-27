// Copyright @bigpel66

#include "../includes/File.hpp"

File::File(void) : _fd(-1) {}

File::File(const std::string& path) : _fd(-1) {
  set_path(path, false);
}

File::~File(void) {
  close();
}

bool File::is_directory(const std::string& path) {
  struct stat statbuf;
  stat(path.c_str(), &statbuf);
  return S_ISDIR(statbuf.st_mode);
}

bool File::is_exist(const std::string& path) {
  struct stat statbuf;
  return stat(path.c_str(), &statbuf) == 0;
}

bool File::is_directory(void) const {
  struct stat statbuf;
  stat(_path.c_str(), &statbuf);
  return S_ISDIR(statbuf.st_mode);
}

bool File::is_exist(void) const {
  struct stat statbuf;
  return stat(_path.c_str(), &statbuf) == 0;
}

bool File::open(bool is_file_needs_to_be_created) {
  close();
  if (is_file_needs_to_be_created) {
    _fd = ::open(_path.c_str(), O_CREAT | O_RDWR | O_TRUNC, 00755);
  } else {
    _fd = ::open(_path.c_str(), O_RDONLY);
  }
  return _fd >= 0;
}

void File::close(void) {
  if (_fd >= 0) {
    ::close(_fd);
    _fd = -1;
  }
}

void File::unlink(void) {
  if (is_exist(_path)) {
    ::unlink(_path.c_str());
  }
}

void File::create(const std::string& body) {
  if (!open(true)) {
    return;
  }
  if (body.length()) {
    write(_fd, body.c_str(), body.length());
  }
}

void File::append(const std::string& body) {
  close();
  _fd = ::open(_path.c_str(), O_RDWR | O_APPEND);
  if (_fd < 0) {
    return;
  }
  if (body.length()) {
    write(_fd, body.c_str(), body.length());
  }
}

void File::parse_match(void) {
  // TODO (@bigpel66)
}

void File::parse_extension(void) {
  // TODO (@bigpel66)
}

void File::parse_extension_with_negotiation(void) {
  // TODO (@bigpel66)
}

void File::set_path(const std::string& path, bool is_negotiation) {
  // TODO (@bigpel66)
  (void)path;
  (void)is_negotiation;
}

const std::string& File::get_path(void) const {
  return _path;
}

const std::string& File::get_extension(void) const {
  return _extension;
}

std::string File::get_content(void) const {
  // TODO (@bigpel66)
  return "";
}

std::string File::get_autoindex(const std::string& target) const {
  // TODO (@bigpel66)
  (void)target;
  return "";
}

Matches& File::get_matches(void) {
  return _matches;
}

int File::get_fd(void) const {
  return _fd;
}

std::string File::get_last_modified(void) {
  char buf[32];
  struct tm *tm;
  struct stat statbuf;
  stat(_path.c_str(), &statbuf);
  tm = gmtime_r(&statbuf.st_mtime, ft::nil);
  int code = strftime(buf, 32, "%a, %d %b %Y %T GMT", tm);
  return std::string(buf, code);
}

std::string File::find_index(const Indexes& indexes) {
  // TODO (@bigpel66)
  (void)indexes;
  return "";
}
