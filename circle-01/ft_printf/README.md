# 1. What is ft_printf?

This project is the implementation of a function which can perform like a real printf.

# 2. How to use the implemented function on the ouside of the module?

The ft_printf is served as a static library like Libft. There is a `Makefile` which provides the common rules (all, clean, fclean, re) including bonus rule in the folder.
* For the Mandatory
> make all
* For the Bonus
> make bonus

# 3. Which are the allowed external functions?

1. `va_start` on \<stdarg.h>
2. `va_arg` on \<stdarg.h>
3. `va_copy` on \<stdarg.h>
4. `va_end` on \<stdarg.h>
5. `write` on \<unistd.h>
6. `malloc` on \<stdlib.h>
7. `free` on \<stdlib.h>

# 4. What is the function prototype of the ft_printf?

| Name | Parameters | Return |
| - | - | - |
| ft_printf | const char *format, ... | int |

# 5. Possible Options

| Flag | Width | Precision | Length | Type |
| - | - | - | - | - |
| `-` </br> `+` </br> `(space)` </br> `0` </br> `#` | `<numbers>` </br> `*` | `.<numbers>` </br> `.*` | `l` </br> `ll` </br> `h` </br> `hh` | `c` </br> `s` </br> `p` </br> `d` </br> `i` </br> `o` </br> `u` </br> `x` </br> `X` </br> `n` </br> `%`

# 6. Features

1. Due to this function is implemented as same as the printf in \<stdio.h>, it can deal with the several Format Placeholders by using Variable Arguments. To call the function, it is as same as the printf function in \<stdio.h>.

2. This function does not use memory dynamic allocation to print the given strings. Actions like managing Buffer are not allowed. Thus, only with the padding strings which are given by options are using memory dynamic allocation.

3. On the part of the Bonus, this function provides printing Unicode through converting utf-8.

4. This is not supporting following types f, F, e, E, g, G. If you want to implement, it is recommended to look up the dtoa algorithm.


# 7. How does this function deal with the Undefiend Behaviors?

The ft_printf deals with `Undefunded Behaviors` as similar as printf on the Mac OS X.

# 8. How to include the static library into the other project?

When you are compiling the project, type the command below appropriately.
> gcc -Wall -Werror -Wextra -L \<directory-name> -l \<library-name>

The name of the static library should be started with `lib` and ends with `.a`. Also, \<library-name> should be typed except `lib` and `.a`. When we set the static library name as `libftprintf.a`, \<library-name> should be `ftprintf`.

* main.c in the folder does not included in the static library.
* main.c is the testing script to call the ft_printf function.
