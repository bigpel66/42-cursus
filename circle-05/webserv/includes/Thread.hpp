// Copyright @bigpel66

// Header for the thread to support concurrency
#ifndef CIRCLE_05_WEBSERV_INCLUDES_THREAD_HPP_
#define CIRCLE_05_WEBSERV_INCLUDES_THREAD_HPP_

// Standard Library Inclusion
#include <pthread.h>
#include <cstddef>

// Enum Thread Status
enum thread_status {
  invalid_thread,
  valid_thread
};

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
  thread_status _status;
  pthread_t _thread;
  pthread_attr_t _attr;
  pthread_attr_t *_attr_ptr;

  Thread& operator=(const Thread& t);
  Thread(const Thread& t);

  bool is_this_thread_running_on_current_thread(void) const;
  bool is_invalid_thread(void) const;
  void set_invalid_thread(void);
  void set_detach_state(void);
  void set_stack_size(std::size_t stack_size);
  void init_attr(void);
  void destroy_attr(void);
  void pthread_not_joined_throw(int code) const;
  void create_thread_with_runnable(const Runnable& runner);
  void init(const Runnable& runner, std::size_t stack_size);

 public:
  Thread(void);
  explicit Thread(const Runnable& runner);
  Thread(const Runnable& runner, std::size_t stack_size);
  ~Thread(void);

  void join(void);
  bool joinable(void) const;
  pthread_t get_id(void) const throw();
  thread_status get_status(void) const;
  std::size_t stack_size(void);
};

// Rallable Possessing Thread Interface
class AbstractThread : public Runnable {
 private:
  Thread *_thread;
  std::size_t _stack_size;

  AbstractThread(void);
  AbstractThread(const AbstractThread& t);
  AbstractThread& operator=(const AbstractThread& t);

 public:
  explicit AbstractThread(const std::size_t stack_size);
  virtual ~AbstractThread(void);

  void join(void);
  bool joinable(void) const;
  void start(void);
};

void *start_thread_with_runnable(void *runner);

#endif  // CIRCLE_05_WEBSERV_INCLUDES_THREAD_HPP_
