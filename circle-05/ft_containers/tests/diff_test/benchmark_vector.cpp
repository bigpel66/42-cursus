// Copyright @nesvoboda
// Modified by @bigpel66

#ifdef STD
# include <vector>
# define NS std
#else
# define NS ft
# include "../../includes/vector.hpp"
#endif

#include <iostream>
#include <string>
#include <cstdio>

// Read integer n, then insert n values into __vector
void insert(NS::vector<int> &__vector) {
  int input_numbers = 0;
  scanf("%d", &input_numbers);
  for (int i = 0 ; i < input_numbers ; i++) {
    int value;
    scanf("%d", &value);
    __vector.push_back(value);
    printf("Size: %lu, capacity: %lu\n", __vector.size(), __vector.capacity());
  }
}

// Read integer n, then delete n indexes from __vector
void del(NS::vector<int> &__vector) {
  int input_numbers = 0;
  scanf("%d", &input_numbers);
  for (int i = 0 ; i < input_numbers ; i++) {
    std::size_t index;
    scanf("%lu", &index);
    NS::vector<int>::iterator ret = __vector.erase(__vector.begin() + index);
    if (ret == __vector.end()) {
      printf("end");
    } else {
      printf("%d\n", *ret);
    }
  }
}

int main(void) {
  NS::vector<int> __vector;
  // Main operations
  insert(__vector);
  del(__vector);
  // Copy construction and destruction
  {
    NS::vector<int> vec2(__vector);
  }
  printf("Size: %lu\n", __vector.size());
  for (NS::vector<int>::const_iterator it = __vector.begin() ; it != __vector.end() ; it++) {
    printf("%d\n", *it);
  }
  return 0;
}
