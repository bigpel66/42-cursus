// Copyright @bigpel66

// Header for the producer of requested tasks
#ifndef CIRCLE_05_WEBSERV_INCLUDES_SERVER_HPP_
#define CIRCLE_05_WEBSERV_INCLUDES_SERVER_HPP_

// Standard Library Inclusion
#include <string>
#include <map>

// Class Headers Inclusion
#include "./Utilizer.hpp"
#include "./Thread.hpp"

class Server : public AbstractThread {
 private:
  Server(void);
  Server(const Server& s);
  Server& operator=(const Server& s);

 public:
  virtual ~Server(void);

  virtual void run(void) throw();
};

#endif  // CIRCLE_05_WEBSERV_INCLUDES_SERVER_HPP_
