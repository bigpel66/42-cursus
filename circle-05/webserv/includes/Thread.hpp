// Copyright @bigpel66

// Header for the thread to support concurrency
#ifndef CIRCLE_05_WEBSERV_INCLUDES_THREAD_HPP_
#define CIRCLE_05_WEBSERV_INCLUDES_THREAD_HPP_

// Standard Library Inclusion
#include <pthread.h>
#include <cstddef>

// Function Runnable Interface
class Runnable {
 private:
  Runnable(const Runnable& runner);
  Runnable& operator=(const Runnable& runner);

 public:
  Runnable(void);
  virtual ~Runnable(void);

  virtual void run(void) throw() = 0;
};

// Pthread Wrapping Thread
class Thread {
 private:
  pthread_t _thread;
  pthread_attr_t _attr;
  pthread_attr_t *_attr;

  Thread& operator=(const Thread& t);
  Thread(const Thread& t);

 public:
  Thread(void);
  explicit Thread(const Runnable* runner);
  Thread(const Runnable* runner, std::size_t stack_size);
  ~Thread(void);

  void join(void);
  bool joinable(void) const;
  pthread_t get_id(void) const throw();
  std::size_t stack_size(void);
};

// Rallable Possessing Thread Interface
class AbstractThread : public Runnable {
 private:
  Thread *_thread;
  std::size_t _stack_size;

  AbstractThread(const AbstractThread& t);
  AbstractThread& operator=(const AbstractThread& t);

 public:
  AbstractThread(void);
  explicit AbstractThread(const std::size_t stack_size);
  virtual ~AbstractThread(void);

  void join(void);
  bool joinable(void) const;
  void start(void);
};

#endif  // CIRCLE_05_WEBSERV_INCLUDES_THREAD_HPP_
