# 1. What is Libft?

This project is the implementation of Libc. There is a restriction of using library on carrying out the projects in 42. This is the first library that the Cadets can use.
<br/>

# 2. How to archive as static library?

Libft is the static library. There is a `Makefile` which provides the common rules (all, clean, fclean, re) with bonus rule in the folder.
* For the Mandatory
> make all
* For the Bonus
> make bonus

# 3. What kind of functions in Libft?
## 1) Mandatory
| Name | Parameters| Return |
| - | - | - |
| ft_atoi | const char *s| int |
| ft_itoa | int n | char * |
| ft_bzero | void *s, size_t n | void |
| ft_calloc | size_t cnt, size_t n | void *|
| ft_isalnum | int c | int |
| ft_isalpha | int c | int |
| ft_isascii | int c | int |
| ft_isdigit | int c | int |
| ft_isprint | int c | int |
| ft_memccpy | void *dst, const void *src, int c, size_t n | void * |
| ft_memcpy | void *dst, const void *src, size_t n | void * |
| ft_memmove | void *dst, const void *src, size_t n | void * |
| ft_memset | void *s, int c, size_t n | void * |
| ft_memchr | const void *s, int c, size_t n | void * |
| ft_memcmp | const void *s1, const void *s2, size_t n | int |
| ft_putchar_fd | char c, int fd | void |
| ft_put_endl | char *s, int fd | void |
| ft_putnbr_fd | int n, int fd | void |
| ft_putstr_fd | char *s, int fd | void |
| ft_split | char const *s, char c | char ** |
| ft_strchr | const char *s, int c | char * |
| ft_strrchr | const char *s, int c | char * |
| ft_strdup | const char *s | char * |
| ft_strjoin | char const *s1, char const *s2 | char * |
| ft_strlcat |  char *dst, const char *src, size_t dstsize | size_t |
| ft_strlcpy | char *dst, const  char *src, size_t dstsize | size_t |
| ft_strlen | const char *s | size_t |
| ft_strmapi | char const *s, char (*f)(unsigned int, char) | char * |
| ft_strncmp | const char *s1, const char *s2, size_t n | int |
| ft_strnstr | const char *s1, const char *set, size_t n | char * |
| ft_strtrim | char const *s1, char const *set | char * |
| ft_substr | char const *s, unsigned int start, size_t len | char * |
| ft_tolower | int c | int |
| ft_toupper | int c | int |

## 2) Bonus
| Name | Parameters | Return |
| - | - | - |
| ft_lstadd_back | t_list **lst, t_list *new | void |
| ft_lstadd_front | t_list **lst, t_list *new | void |
| ft_lstclear | t_list **lst, void (*del)(void *) | void |
| ft_lstdelone | t_list *lst, void (*del)(void *) | void |
| ft_lstiter | t_list *lst, void  (*f)(void *) | void |
| ft_lstmap | t_list *lst, void *(*f)(void *), void (*del)(void *) | t_list * |
| ft_lstlast | t_list *lst| t_list * |
| ft_lstnew | void *content | t_list * |
| ft_lstsize | t_list *lst | int |

# 4. How does every functions deal with the Undefiend Behaviors?
Every functions in Libft deals with `Undefunded Behaviors` as similar as How the Mac OS X does.

# 5. How to include the static library into the other project?
When you are compiling the project, type the command below appropriately.
> gcc -Wall -Werror -Wextra -L \<directory-name> -l \<library-name>
