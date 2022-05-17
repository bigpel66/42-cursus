// Copyright @bigpel66

// Header for the mutex to control the concurrency
#ifndef CIRCLE_O5_WEBSERV_INCLUDES_MUTEX_HPP_
#define CIRCLE_O5_WEBSERV_INCLUDES_MUTEX_HPP_

// Standard Library Inclusion
#include <pthread.h>

class Mutex {
 private:
  pthread_mutex_t _mutex;

  // Prevent to call directly
  Mutex(const Mutex& m);
  Mutex& operator=(const Mutex& m);

 public:
  Mutex(void);
  ~Mutex(void);

  void lock(void);
  void unlock(void);
  bool try_lock(void);
};

#endif  // CIRCLE_O5_WEBSERV_INCLUDES_MUTEX_HPP_
