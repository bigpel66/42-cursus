#!/bin/bash
# Copyright @nesvoboda
# Modified by @bigpel66

python3 generate_input_map.py > input_map
python3 generate_input_set.py > input_set
python3 generate_input_stack.py > input_stack
python3 generate_input_vector.py > input_vector

clang++ benchmark_map.cpp -D STD && cat input_map | ./a.out > std_output_map && rm a.out
clang++ benchmark_set.cpp -D STD && cat input_set | ./a.out > std_output_set && rm a.out
clang++ benchmark_stack.cpp -D STD && cat input_stack | ./a.out > std_output_stack && rm a.out
clang++ benchmark_vector.cpp -D STD && cat input_vector | ./a.out > std_output_vector && rm a.out

clang++ benchmark_map.cpp -o ft_benchmark_map
clang++ benchmark_set.cpp -o ft_benchmark_set
clang++ benchmark_stack.cpp -o ft_benchmark_stack
clang++ benchmark_vector.cpp -o ft_benchmark_vector
