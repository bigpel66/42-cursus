// Copyright @bigpel66

#include "../includes/Mutex.hpp"
#include "../includes/Exception.hpp"

Mutex::Mutex(void) {
  int code = pthread_mutex_init(&_mutex, NULL);
  if (code) {
    throw MutexException("pthread_mutex_init failed.", code);
  }
}

Mutex::~Mutex(void) {
  pthread_mutex_destroy(&_mutex);
}

void Mutex::lock(void) {
  int code = pthread_mutex_lock(&_mutex);
  if (code) {
    throw MutexException("pthread_mutex_lock failed.", code);
  }
}

void Mutex::unlock(void) {
  int code = pthread_mutex_unlock(&_mutex);
  if (code) {
    throw MutexException("pthread_mutex_unlock failed.", code);
  }
}

bool Mutex::try_lock(void) {
  bool status = false;
  int code = pthread_mutex_trylock(&_mutex);
  if (code == 0) {
    status = true;
  } else if (code == EBUSY) {
    status = false;
  } else {
    throw MutexException("pthread_mutex_trylock failed.", code);
  }
  return status;
}
