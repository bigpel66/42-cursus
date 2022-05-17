// Copyright @bigpel66

#include "../includes/Thread.hpp"
#include "../includes/Exception.hpp"
#include "../includes/Null.hpp"

namespace current_thread {
  pthread_t get_id(void) {
    return pthread_self();
  }
}  // namespace current_thread

bool Thread::is_this_thread_running_on_current_thread(void) const {
  return _thread == current_thread::get_id();
}

bool Thread::is_invalid_thread(void) const {
  return _status == invalid_thread;
}

void Thread::set_invalid_thread(void) {
  _status = invalid_thread;
  _thread = 0;
}

void Thread::set_detach_state(void) {
  int code = pthread_attr_setdetachstate(_attr_ptr, PTHREAD_CREATE_JOINABLE);
  if (code != 0) {
    throw ThreadException("pthread_attr_setdetachstate failed.", code);
  }
}

void Thread::set_stack_size(std::size_t stack_size) {
  if (stack_size > PTHREAD_STACK_MIN) {
    int code = pthread_attr_setstacksize(_attr_ptr, stack_size);
    if (code != 0) {
      throw ThreadException("pthread_attr_setstacksize failed.", code);
    }
  } else {
    throw ThreadException
    (std::string("minimum stack size is ")
        + std::to_string(PTHREAD_STACK_MIN)
        + std::string(" bytes, but passed size is ")
        + std::to_string(stack_size));
  }
}

void Thread::pthread_not_joined_throw(int code) const {
  switch (code) {
  case EDEADLK:
    throw ThreadException("join failed, deadlock condition occured.", code);
  case EINVAL:
    throw ThreadException("join failed, this is not joinable thread.", code);
  case ESRCH:
    break;
  default:
    throw ThreadException("join failed, unexpected code returned.", code);
  }
}

void Thread::create_thread_with_runnable(const Runnable *runner) {
  void *non_const_runner = reinterpret_cast<void *>(const_cast<Runnable *>(runner));
  int code = pthread_create(&_thread, _attr_ptr,
                            start_thread_with_runnable,
                            non_const_runner);
  if (code != 0) {
    throw ThreadException("pthread_create failed.", code);
  } else {
    _status = valid_thread;
  }
}

void Thread::init(const Runnable *runner, std::size_t stack_size) {
  set_detach_state();
  set_stack_size(stack_size);
  create_thread_with_runnable(runner);
}

Thread::Thread(void)
  : _thread(0), _attr_ptr(ft::nullptr_t), _status(invalid_thread) {
  int code = pthread_attr_init(&_attr);
  if (code != 0) {
    throw ThreadException("pthread_attr_init failed.", code);
  } else {
    _attr_ptr = &_attr;
  }
}

Thread::Thread(const Runnable *runner)
  : Thread() {
  init(runner, 0);
}

Thread::Thread(const Runnable *runner, std::size_t stack_size)
  : Thread() {
  init(runner, stack_size);
}

Thread::~Thread(void) {
  if (_attr_ptr != ft::nullptr_t) {
    int code = pthread_attr_destroy(&_attr);
    if (code != 0) {
      throw ThreadException("pthread_attr_destroy failed.", code);
    }
  }
}

void Thread::join(void) {
  if (_thread) {
    if (is_this_thread_running_on_current_thread()) {
      throw ThreadException("join failed, joining itself cause deadlock.");
    }
    if (is_invalid_thread()) {
      throw ThreadException("join failed, invalid thread.");
    }
    int code = pthread_join(_thread, ft::nullptr_t);
    if (code == 0) {
      set_invalid_thread();
    } else {
      pthread_not_joined_throw(code);
    }
  }
}

bool Thread::joinable(void) const {
  return _thread != 0;
}

pthread_t Thread::get_id(void) const throw() {
  return _thread;
}

thread_status Thread::get_status(void) const {
  return _status;
}

std::size_t Thread::stack_size(void) {
  size_t size = -1;
  int code = pthread_attr_getstacksize(_attr_ptr, &size);
  if (code != 0) {
    throw ThreadException("get stack size failed.", code);
  }
  return size;
}

void *start_thread_with_runnable(void *runner) {
  try {
    reinterpret_cast<Runnable *>(runner)->run();
  } catch (...) {
    // Though this thread is able to throw exception, main thread cannot know it
    // But, this is the intention to be sure that exception situation happend
    // To make thread safe, printf has been used
    printf("start_thread_with_runnable failed.");
  }
  return ft::nullptr_t;
}
