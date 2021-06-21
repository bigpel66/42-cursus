# 0. Guide Link

(will be added soon)
https://bigpel66.oopy.io/library/42/inner-circle/6

# 1. What is push_swap?

This project is the implementation of Quick Sort program which is made of Stack Sort algorithm. Only 2 stacks and 11 rules enabled to make elements ascending orders.

# 2. How to compile the implemented program?

There is a `Makefile` which provides the common rules (all, clean, fclean, re) including bonus rule in the folder. After compiling all of the source codes, the program file will be generated.
*For the Mandatory
> make all
* For the Bonus
> make bonus

Also, this project does not use given `checker` source code on the intra. `checker` is already implemented with the `push_swap`, so compiling with the mandatory rule will produce `checker` and `push_swap`. There are test scripts which can be run on the shell. These can grade the program while taking a peer-evaluation. To take a test, type the commande listed below.
> make test

# 3. What kind of tests are included?
1. checker Error
To validate `checker` that returns the "Error" properly when it is on the exception.

2. checker False
To validate `checker` that returns the "KO" properly when the result after the given instruction is not sorted.

3. checker True
To validate `checker` that returns the "OK" properly when the result after the given instruction is sorted.

4. push_swap Identity
To validate `push_swap` that does not spend any instructions to sort when it gets the already sorted arguments.

5. push_swap Simple Version
To validate `push_swap` that complies with the instruction guideline. Instructions should be returned under 3 when it gets the 3 numeric arguments, under 12 when it gets the 5 numeric arguments.

6. push_swap Middle Version
Check the average instructions when it gets the 100 numeric arguments with the status of the sorting result. They recommened to be under 700 to get a full grade.

7. push_swap Advanced Version
Check the average instructions when it gets the 500 numeric arguments with the status of the sorting result. They recommened to be under 5500 to get a full grade.

# 4. How to execute the implemented program?
`push_swap` will generate the instructions to make the elements ascending orders, so this program takes the several numeric arguments which has to be ordered properly.
> ./push_swap \<numeric-arguments>

`checker` will grade the given instructions to sort the numeric arguments, so this program takes the several numeric arguments which has been used on `push_swap`. Instead of giving the instructions as `string`, these will be given with the `standard input`. Instructions can be transmitted by the `pipe`, or only manual input should be followed. When the instructions sent by manual way, `CTRL + D` is the signal of `End of Transmission`.
> ./checker \<numeric-arguments>
<p/>

> ./push_swap \<numeric_arguments> | ./checker \<numeric-arguments>
<p/>

> ARG=\<numeric-arguments> ; ./push_swap $ARG | ./checker $ARG

`checker` is able to show the status of 2 Stacks by the visualization option. `checker` supports the `--debug` option, this should be placed only at the end of the phrase which executes `checker`.
> ./checker \<numeric-arguments> --debug
<p/>

> ./push_swap \<numeric_arguments> | ./checker \<numeric-arguments> --debug
<p/>

> ARG=\<numeric-arguments> ; ./push_swap $ARG | ./checker $ARG --debug

# 5. Which are the allowed external functions?

1. `write` on \<unistd.h>
2. `read` on \<unistd.h>
3. `malloc` on \<stdlib.h>
4. `free` on \<stdlib.h>
5. `exit` on \<stdlib.h>

# 6. Features

1. No duplicated arguments, non-numeric arguments are allowed. Including failure of dynamic memory allocation, `push_swap` and `checker` will return "Error" on these situation.

2. Though implemented sorting algorithm is `n * n` on the Big-O notation, this is not fully `n * n`. Like `Quick Sort` this sorting alorithm ensures the average performance as `n * log n`. To be ensured the average performance, checking duplication should not be `n * n`. Thus not to check the duplication on the brute force, both program use the `Red-Black Tree` which ensures the `n * log n`.

3. Only 11 instructions are allowed.
<p/>

		pb : Pushing top of the 1 element from A to B
<p/>

		pa : Pushing top of the 1 element from B to A
<p/>

		ra : Rotating A with ccw
<p/>

		rb : Rotating B with ccw
<p/>

		rr : Rotating both with ccw
<p/>

		rra : Rotating A with cw
<p/>

		rrb : Rotating B with cw
<p/>

		rrr : Rotating both with cw
<p/>


		sa : Swapping top of the 2 elements on A
<p/>

		sb : Swapping top of the 2 elements on B
<p/>

		ss : Swapping top of the 2 elements on both
<p/>


4. Not to mess up the instructions, `push_swap` is orienting the lowest call of push and swap instructions.

5. To see the result of the insturctions while running `checker`, execute the `checker` with the `--debug` option.

# 7. What is the key algorithm to solve the project?

(will be added soon)

# 8. Demo

<div style="display:flex" align="center">
    <img src="images/1.png" alt="1" width="800"/>
    <img src="images/2.png" alt="2" width="800"/>
    <img src="images/3.png" alt="3" width="800"/>
</div>
