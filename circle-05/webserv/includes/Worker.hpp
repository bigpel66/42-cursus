// Copyright @bigpel66

// Header for the consumer of produced tasks
#ifndef CIRCLE_05_WEBSERV_INCLUDES_WORKER_HPP_
#define CIRCLE_05_WEBSERV_INCLUDES_WORKER_HPP_

// Class Headers Inclusion
#include "./Thread.hpp"  // Wokrer runs as thread
#include "./Server.hpp"  // Worker holds a server who made worker run

// Enum Worker Status
enum worker_status {
  invalid_worker,
  valid_worker
};

class Worker : public AbstractThread {
 private:
  int _id;
  int _it;
  int _socket;
  worker_status _status;
  Server *_server;

  Worker(void);
  Worker(const Worker& w);
  Worker& operator=(const Worker& w);

 public:
  explicit Worker(int id);
  virtual ~Worker(void);

  int get_id(void) const;
  int get_it(void) const;
  int get_socket(void) const;
  worker_status get_status(void) const;
  Server *get_server(void) const;

  void set_it(int it);
  void set_socket(int socket);
  void set_status(worker_status status);
  void set_server(Server *server);

  virtual void run(void) throw();
};

#endif  // CIRCLE_05_WEBSERV_INCLUDES_WORKER_HPP_
