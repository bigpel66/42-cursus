// Copyright @bigpel66

#include "../includes/File.hpp"
#include "../includes/Parser.hpp"
#include "../includes/Engine.hpp"

File::File(void) : _fd(-1) {}

File::File(const std::string& path) : _fd(-1) {
  set_path(path);
}

File::~File(void) {
  close();
}

std::string File::set_width(std::size_t width, const std::string& str) {
  std::size_t len = str.length();
  std::string w;
  if (len > width) {
    width = 0;
  }
  for (std::size_t i = 0; i < width - len; i++) {
    w += " ";
  }
  w += str;
  return w;
}

bool File::is_entry_matched(const std::string& name) const {
  return _fullname != name &&
          name.find(_name) == 0 &&
          !Parser::is_npos(name.find(_extension));
}

bool File::is_negotiated(void) const {
  return !Engine::mimes.get_type(_extension)
                        .compare("application/octet-stream");
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

void File::close() {
  if (_fd < 0) {
    return;
  }
  ::close(_fd);
  _fd = -1;
}

void File::unlink() {
  if (!is_exist())
    return;
  ::unlink(_path.c_str());
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
  if (_fd < 0)
    return;
  if (body.length()) {
    write(_fd, body.c_str(), body.length());
  }
}

void File::set_path(std::string path, bool is_negotiation) {
  _path = ft::get_sole_slash(path);
  parse_path(is_negotiation);
}

void File::set_file_name(void) {
  _fullname = _path.substr(_path.find_last_of("/") + 1);
  if (_fullname.empty()) {
    return;
  }
  _name = _fullname.substr(0, _fullname.find("."));
}

void File::set_file_extension_on_negotiation(std::size_t dot_position) {
  while (is_negotiated()) {
    std::size_t backup_position = dot_position;
    dot_position = _fullname.find_last_of(".", dot_position - 1);
    if (Parser::is_npos(dot_position)) {
      break;
    } else {
      _extension = _fullname.substr(dot_position,
                                    backup_position - dot_position);
    }
  }
}

void File::set_file_extension(bool is_negotiation) {
  std::size_t dot_position = _fullname.find_last_of(".");
  if (!Parser::is_npos(dot_position)) {
    _extension = _fullname.substr(dot_position);
    if (is_negotiation) {
      set_file_extension_on_negotiation(dot_position);
    }
  }
}

void File::parse_path(bool is_negotiation) {
  set_file_name();
  set_file_extension(is_negotiation);
}

const std::string& File::get_path(void) const {
  return _path;
}

const std::string& File::get_extension(void) const {
  return _extension;
}

std::string File::get_content(void) const {
  ssize_t read_size;
  std::string content;
  char buf[DEFAULT_BUFFER_SIZE + 1];
  lseek(_fd, 0, SEEK_SET);
  while (true) {
    read_size = read(_fd, buf, DEFAULT_BUFFER_SIZE);
    if (!read_size) {
      return content;
    } else if (read_size == -1) {
      return "";
    } else {
      buf[read_size] = '\0';
      content.insert(content.length(), buf, read_size);
    }
  }
}

void File::init_sorted_auto_listings(DIR *dir, AutoListings *als) {
  struct dirent *ent;
  struct stat statbuf;
  char buf[32];
  struct tm *tm;
  while (true) {
    ent = readdir(dir);
    if (!ent) {
      break;
    }
    AutoListing al;
    al.name = ent->d_name;
    if (al.name.length() > 50) {
      al.name.erase(47);
      al.name += "..>";
    }
    std::string path = _path + "/" + ent->d_name;
    stat(path.c_str(), &statbuf);
    if (File::is_directory(path)) {
      al.is_directory = true;
      al.name += "/";
    }
    tm = gmtime(&statbuf.st_mtime);
    std::size_t write_size = strftime(buf, 32, "%d-%b-%Y %H:%M", tm);
    al.date = std::string(buf, write_size);
    al.size = statbuf.st_size;
    als->push_back(al);
  }
  std::sort(als->begin(), als->end(), sort_auto_listing);
}

void File::set_body_before_listing(std::string *body,
                                  const std::string& target) {
  (*body) += "<html>\r\n";
  (*body) += "<head><title>Index of " + target + "</title></head>\r\n";
  (*body) += "<body>\r\n";
  (*body) += "<h1>Index of " + target + "</h1><hr><pre>";
}

void File::set_body_after_listing(std::string *body) {
  (*body) += "</pre><hr></body>\r\n";
  (*body) += "</html>\r\n";
}

void File::set_body_listing(std::string *body,
                            const std::string& target,
                            AutoListings *als) {
  for (AutoListings::const_iterator it = als->begin()
      ; it != als->end()
      ; it++) {
    (*body) += "<a href=\"";
    (*body) += ft::get_sole_slash(target + + "/" + it->name) + "\">";
    (*body) += it->name + "</a>";
    if (it != als->begin()) {
      (*body) += set_width(68 - it->name.length(), it->date);
      if (it->is_directory)
        (*body) += set_width(20, "-");
      else
        (*body) += set_width(20, std::to_string(it->size));
    }
    (*body) += "\r\n";
  }
}

std::string File::get_autoindex(const std::string& target) {
  DIR *dir;
  std::string body;
  dir = opendir(_path.c_str());
  if (!dir) {
    return body;
  }
  set_body_before_listing(&body, target);
  AutoListings als;
  init_sorted_auto_listings(dir, &als);
  set_body_listing(&body, target, &als);
  set_body_after_listing(&body);
  closedir(dir);
  return body;
}

int File::get_fd(void) const {
  return _fd;
}

std::string File::get_last_modified(void) {
  char buf[32];
  struct tm *tm;
  struct stat statbuf;
  stat(_path.c_str(), &statbuf);
  tm = gmtime(&statbuf.st_mtime);
  int code = strftime(buf, 32, "%a, %d %b %Y %T GMT", tm);
  return std::string(buf, code);
}

std::string File::find_index(const Indexes& indexes) {
  DIR *dir;
  struct dirent *ent;
  std::string index;
  dir = opendir(_path.c_str());
  if (!dir) {
    return index;
  }
  while (true) {
    ent = readdir(dir);
    if (!ent) {
      break;
    }
    std::string name = ent->d_name;
    for (Indexes::const_iterator it = indexes.begin()
        ; it != indexes.end()
        ; it++) {
      if (*it == name) {
        index = "/" + name;
        break;
      }
    }
  }
  closedir(dir);
  return index;
}
