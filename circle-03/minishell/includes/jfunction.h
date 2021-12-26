/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jfunction.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 19:06:48 by jseo              #+#    #+#             */
/*   Updated: 2021/12/26 23:15:17 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JFUNCTION_H
# define JFUNCTION_H

/*
** =============================================================================
** Dependencies
** =============================================================================
*/

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

/*
** =============================================================================
** Macros
** =============================================================================
*/

# ifndef OPEN_MAX
#  define OPEN_MAX		4096
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	4096
# endif

/*
** =============================================================================
** Enum Type Definitions
** =============================================================================
*/

typedef enum e_stat
{
	ERROR = -1,
	END,
	SUCCESS,
}						t_stat;

/*
** =============================================================================
** Struct Type Definitions
** =============================================================================
*/

typedef struct s_list
{
	void				*content;
	struct s_list		*next;
}						t_list;

/*
** =============================================================================
** J Functions
** =============================================================================
*/

size_t	jabs(int n);
bool	jatoi(char **s, int *v);
bool	jcalloc(void **ptr, size_t cnt, size_t n);
void	jfree(void **ptr);
int		jgnl(int fd, char **line);
bool	jisalnum(int c);
int		jisalpha(int c);
bool	jisascii(int c);
bool	jisdigit(int c);
bool	jisprint(int c);
bool	jisspace(int c);
char	*jitoa(int n);
void	jlstadd_back(t_list **lst, t_list *new);
void	jlstadd_front(t_list **lst, t_list *new);
void	jlstclear(t_list **lst, void (*del)(void *));
void	jlstdelone(t_list *lst, void (*del)(void *));
void	jlstiter(t_list *lst, void (*f)(void *));
t_list	*jlstlast(t_list *lst);
t_list	*jlstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*jlstnew(void *content);
void	jlstshow(t_list *lst);
size_t	jlstsize(t_list *lst);
void	*jmemset(void *s, int c, size_t n);
size_t	jnumlen(int v);
void	jputchar(char c, int fd);
void	jputendl(char *s, int fd);
void	jputnbr(int n, int fd);
void	jputstr(char *s, int fd);
char	**jsplit(const char *s, bool (*cmp)(int));
bool	jstrappend(char **s, char *s2);
char	*jstrchr(const char *s, int c);
char	*jstrdup(const char *s);
char	*jstrjoin(const char *s1, const char *s2);
size_t	jstrlcpy(char *dst, const char *src, size_t dstsize);
size_t	jstrlen(const char *s);
int		jstrncmp(const char *s1, const char *s2, size_t n);
void	jstrtrim(char **s);
char	*jsubstr(const char *s, unsigned int start, size_t len);
int		jtolower(int c);
int		jtoupper(int c);
size_t	jwordlen(const char *s, bool (*cmp)(int));

#endif
