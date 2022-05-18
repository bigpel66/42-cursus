// Copyright @bigpel66

// Header for the client to request task
#ifndef CIRCLE_05_WEBSERV_INCLUDES_CLIENT_HPP_
#define CIRCLE_05_WEBSERV_INCLUDES_CLIENT_HPP_

// Standard Library Inclusion
#include <string>

class Client {
 private:
  int _id;
  int _socket;
  std::string _path;
  std::string _content;

  Client(void);
  Client(const Client& c);
  Client& operator=(const Client& c);

 public:
  Client(int id, int socket);
  ~Client(void);

  int get_id(void) const;
  int get_socket(void) const;
  const std::string& get_path(void) const;
  const std::string& get_content(void) const;

  void set_id(int id);
  void set_socket(int socket);
  void set_path(const std::string& path);
  void set_content(const std::string& content);
};

#endif  // CIRCLE_05_WEBSERV_INCLUDES_CLIENT_HPP_
