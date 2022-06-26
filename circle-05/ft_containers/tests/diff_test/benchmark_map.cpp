// Copyright @nesvoboda
// Modified by @bigpel66

#ifdef STD
# include <map>
# define NS std
#else
# define NS ft
# include "../../includes/map.hpp"
#endif

#include <iostream>
#include <string>
#include <cstdio>

// Read integer n, then insert n space-separated key-value pairs into __map
void insert(NS::map<int, int> &__map) {
  int input_numbers = 0;
  scanf("%d", &input_numbers);
  for (int i = 0 ; i < input_numbers ; i++) {
    int key;
    int value;
    scanf("%d %d", &key, &value);
    const int c_key = key;
    NS::pair<NS::map<int, int>::iterator, bool> ret = __map.insert(NS::make_pair(c_key, value));
    printf("%d %d %d\n", ret.first->first, ret.first->second, ret.second);
  }
}

// Read integer n, then delete n keys from __map
void del(NS::map<int, int> &__map) {
  int input_numbers = 0;
  scanf("%d", &input_numbers);
  for (int i = 0 ; i < input_numbers ; i++) {
    int key;
    scanf("%d", &key);
    printf("%lu\n", __map.erase(key));
  }
}

// Read integer n, then search n keys in __map
void search(NS::map<int, int> &__map) {
  int input_numbers = 0;
  scanf("%d", &input_numbers);
  for (int i = 0 ; i < input_numbers ; i++) {
    int key;
    scanf("%d", &key);
    NS::map<int, int>::iterator ret = __map.find(key);
    if (ret == __map.end()) {
      printf("miss\n");
    } else {
      printf("hit\n");
    }
  }
}

int main(void) {
  NS::map<int, int> __map;
  // Main operations
  insert(__map);
  del(__map);
  search(__map);
  // Copy construction and destruction
  {
    NS::map<int, int> tmp(__map);
  }
  printf("Size: %lu\n", __map.size());
  for (NS::map<int, int>::const_iterator it = __map.begin(); it != __map.end(); it++) {
    printf("Key: %d, value: %d\n", it->first, it->second);
  }
  return 0;
}
