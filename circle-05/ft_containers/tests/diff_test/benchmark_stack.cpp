// Copyright @nesvoboda
// Modified by @bigpel66

#ifdef STD
# include <stack>
# define NS std
#else
# define NS ft
# include "../../includes/stack.hpp"
#endif

#include <iostream>
#include <string>
#include <cstdio>

// Read integer n, then push n values on __stack
void insert(NS::stack<int> &__stack) {
  int input_numbers = 0;
  scanf("%d", &input_numbers);
  for (int i = 0 ; i < input_numbers ; i++) {
    int value;
    scanf("%d", &value);
    __stack.push(value);
    printf("Size: %lu, top: %d\n", __stack.size(), __stack.top());
  }
}

int main(void) {
  NS::stack<int> __stack;
  // Main operations
  insert(__stack);
  // Copy construction and destruction
  {
    NS::stack<int> stk2(__stack);
  }
  printf("Size: %lu\n", __stack.size());
  while (__stack.size() != 0) {
    printf("%d\n", __stack.top());
    __stack.pop();
  }
  return 0;
}
