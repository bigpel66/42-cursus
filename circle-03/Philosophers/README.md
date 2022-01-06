# 0. Subject & Guide Link

* [Subject](https://github.com/bigpel66/42-cursus/blob/main/circle-03/circle03%20-%20Philosophers.pdf)
* [Guide Link](https://bigpel66.oopy.io/library/42/inner-circle/9)

# 1. What is Philosophers?

This program is the implementation of Dininig Philosophers which can show the deadlock and starvation problems in synchronization. The part of the mandaotry should be with mutex and threads, and the part of the bonus should be with semaphore and processes.

# 2. How to compile the implemented program?

There is a `Makefile` which provides the common rules (all, clean, fclean, re) in each folder. After compiling all of the source codes, the program file will be generated.
* For the Mandatory and the Bonus (should enter the command in the appropriate path)
> make all

# 3. How to execute the implemented program?

`philo` and `philo_bonus` will print the message about the status of each philosophers by timelines. To see that, these programs takes the several numeric arguments. The given arguments below must consist of numeric value. The last arguement is optional.
> ./philo \<number-of-philosophers> \<time-to-die> \<time-to-eat> \<time-to-sleep> [\<number-of-times-each-philosophers-eat]
<p/>

> ./philo_bonus \<number-of-philosophers> \<time-to-die> \<time-to-eat> \<time-to-sleep> [\<number-of-times-each-philosophers-eat]

# 4. Which are the allowed external functions?

* For the Mandatory
1. `memset` on \<string.h>
2. `printf` on \<stdio.h>
3. `malloc` on \<stdlib.h>
4. `free` on \<stdlib.h>
5. `write` on \<unistd.h>
6. `usleep` on \<unistd.h>
7. `gettimeofday` on \<sys/time.h>
8. `pthread_create` on \<pthread.h>
9. `pthread_detach` on \<pthread.h>
10. `pthread_join` on \<pthread.h>
11. `pthread_mutex_init` on \<pthread.h>
12. `pthread_mutex_destroy` on \<pthread.h>
13. `pthread_mutex_lock` on \<pthread.h>
14. `pthread_mutex_unlock` on \<pthread.h>

* For the Bonus
1. `memset` on \<string.h>
2. `printf` on \<stdio.h>
3. `malloc` on \<stdlib.h>
4. `free` on \<stdlib.h>
5. `exit` on \<stdlib.h>
6. `write` on \<unistd.h>
7. `fork` on \<unistd.h>
8. `kill` on \<unistd.h>
9. `usleep` on \<unistd.h>
10. `pthread_create` on \<pthread.h>
11. `pthread_detach` on \<pthread.h>
12. `pthread_join` on \<pthread.h>
13. `gettimeofday` on \<sys/time.h>
14. `waitpid` on \<sys/wait.h>
15. `sem_open` on \<semaphore.h>
16. `sem_close` on \<semaphore.h>
17. `sem_post` on \<semaphore.h>
18. `sem_wait` on \<semaphore.h>
19. `sem_unlink` on \<semaphore.h>

# 5. Features

1. Each program is separated into the several branches by `pthread_create` or `fork`. The main stream of execution waits the branches by `Mutex` or `Semaphore`.
2. When the branches separated, each branch makes another execution stream to monitor whether the branch dead or not.
3. After making monitoring thread, each branch iterates `Taking Fork`, `Eating`, `Putting Fork`, `Sleeping`, `Thinking`.
4. sem_post or pthread_mutex_unlock will be called to resume the main stream of execution when the error occurs, philosopher eaten enough, philosopher dead.
5. These programs influenced by the time that user typed, exact time measure is important that not to make philosopher dead. `usleep` function does not make the process or thread sleep with the exact time compare to the argument. When the process or thread has to sleep the `x`ms, `usleep` function iterates the fraction of the `x`ms inside of the custom made function. This is so called as `elapse` in the project.
6. To share the beginning time, the main stream of execution measure the time before the branch separation.
7. When the action should be printed, each branch should lock the printing resource by `pthread_mutex_lock` or `sem_wait`.

# 6. Demo

<div style="display:flex" align="center">
    <img src="images/1.png" alt="1" width="800"/>
    <img src="images/2.png" alt="2" width="800"/>
    <img src="images/3.png" alt="3" width="800"/>
    <img src="images/4.png" alt="4" width="800"/>
</div>
