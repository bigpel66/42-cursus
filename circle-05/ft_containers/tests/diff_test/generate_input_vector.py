# Copyright @nesvoboda
# Modified by @bigpel66

import random

INPUT_N = 100000

random.seed()

# Insert
print(INPUT_N)
for i in range(INPUT_N):
    print(random.randint(0, 42000))

# Delete
DELETE_N = INPUT_N // 2
print(DELETE_N)
for i in range(DELETE_N):
    print(random.randint(0, (INPUT_N - i) - 1 ))
