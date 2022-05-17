// Copyright @bigpel66

#include "../includes/Utilizer.hpp"
#include "../includes/Engine.hpp"
#include <iostream>

const class my_nullptr_t
{
    public:

        /* Return 0 for any class pointer */
        template<typename T>
        operator T*() const
        {
            return 0;
        }

        /* Return 0 for any member pointer */
        template<typename T, typename U>
        operator T U::*() const
        {
            return 0;
        }

        /* Safe boolean conversion */
        operator void*() const
        {
            return 0;
        }

    private:

        /* Not allowed to get the address */
        void operator&() const;

} my_nullptr = {};

namespace this_thread {
  pthread_t get_id(void) {
    return pthread_self();
  }
}

class A {
  public:
  // pthread_t pthread;
  pthread_t get_id(void) {
    return pthread_self();
  }
};

void hi(void) {

}

int main(int argc, char **argv) {
  A a;

  (void)argc, (void)argv;
  std::cout << a.get_id() << std::endl;
  std::cout << this_thread::get_id() << std::endl;
  const char *s = nullptr;
  const char *s2 = my_nullptr;

  std::cout << (s == s2) << std::endl;
  std::cout << sizeof(my_nullptr) << std::endl;
  std::cout << sizeof(A) << std::endl;
  std::cout << (my_nullptr == 0) << std::endl;
  return 0;
}
