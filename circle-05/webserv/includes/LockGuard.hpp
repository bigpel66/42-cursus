// Copyright @bigpel66

// Header for the lock guard to automatically unlock based on RAII pattern
#ifndef CIRCLE_05_WEBSERV_INCLUDES_LOCKGUARD_HPP_
#define CIRCLE_05_WEBSERV_INCLUDES_LOCKGUARD_HPP_

// Class Headers Inclusion
#include "./Mutex.hpp"  // Lock Guard controls the mutex type

template<typename T>
class LockGuard {
 private:
  T *_mutex;

  LockGuard(void);
  LockGuard(const LockGuard& g);
  LockGuard& operator=(const LockGuard& g);

 public:
  explicit LockGuard(const T& mutex) {
    _mutex = &mutex;
    _mutex->lock();
  }

  ~LockGuard(void) {
    _mutex->unlock();
  }
};

#endif  // CIRCLE_05_WEBSERV_INCLUDES_LOCKGUARD_HPP_
