# Copyright @nesvoboda
# Modified by @bigpel66

import random

INPUT_N = 25000
DELETE_N = 5000
SEARCH_N = 5000

random.seed()

# Insert
print(INPUT_N)
acc = 0
for i in range(INPUT_N):
    acc += random.randint(0, 10)
    print(str(acc))

# Delete
print(DELETE_N)
for i in range(DELETE_N):
    print(random.randint(0, acc))

# Search
print(SEARCH_N)
for i in range(SEARCH_N):
    print(random.randint(0, acc))
