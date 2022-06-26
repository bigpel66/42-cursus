// Copyright @nesvoboda
// Modified by @bigpel66

#ifdef STD
# include <set>
# define NS std
#else
# define NS ft
# include "../../includes/set.hpp"
#endif

#include <iostream>
#include <string>
#include <cstdio>

// Read integer n, then insert n space-separated key-value pairs into __set
void insert(NS::set<int> &__set) {
  int input_numbers = 0;
  scanf("%d", &input_numbers);
  for (int i = 0 ; i < input_numbers ; i++) {
    int key;
    scanf("%d", &key);
    NS::pair<NS::set<int>::iterator, bool> ret = __set.insert(key);
    printf("%d %d\n", *ret.first, ret.second);
  }
}

// Read integer n, then delete n keys from __set
void del(NS::set<int> &__set) {
  int input_numbers = 0;
  scanf("%d", &input_numbers);
  for (int i = 0 ; i < input_numbers ; i++) {
    int key;
    scanf("%d", &key);
    printf("%lu\n", __set.erase(key));
  }
}

// Read integer n, then search n keys in __set
void search(NS::set<int> &__set) {
  int input_numbers = 0;
  scanf("%d", &input_numbers);
  for (int i = 0 ; i < input_numbers ; i++) {
    int key;
    scanf("%d", &key);
    NS::set<int>::iterator ret = __set.find(key);
    if (ret == __set.end()) {
      printf("miss\n");
    } else {
      printf("hit\n");
    }
  }
}

int main(void) {
  NS::set<int> __set;
  // Main operations
  insert(__set);
  del(__set);
  search(__set);
  // Copy construction and destruction
  {
    NS::set<int> tmp(__set);
  }
  printf("Size: %lu\n", __set.size());
  for (NS::set<int>::const_iterator it = __set.begin(); it != __set.end(); it++) {
    printf("Key: %d\n", *it);
  }
  return 0;
}
