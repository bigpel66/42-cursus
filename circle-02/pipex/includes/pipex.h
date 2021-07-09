/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 16:16:14 by jseo              #+#    #+#             */
/*   Updated: 2021/07/09 18:42:05 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/*
** =============================================================================
** Dependencies
** =============================================================================
*/

# include <stdbool.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <stdlib.h>
# include <sys/wait.h>

/* mod */
#include <stdio.h>

/*
** =============================================================================
** Enum Type Definitions
** =============================================================================
*/

typedef enum e_file
{
	READ,
	WRITE,
}				t_file;

typedef enum e_stat
{
	ERROR = -1,
	END,
	SUCCESS,
}				t_stat;

typedef enum e_mode
{
	SQ,
	DQ,
	ESQ,
	EDQ,
}				t_mode;

typedef enum e_exit
{
	VALID,
	INVALID,
}				t_exit;

/*
** =============================================================================
** Struct Type Definitions
** =============================================================================
*/

typedef struct s_fd
{
	char		*file;
	int			flag;
	int			mode;
	int			fd;
}				t_fd;

typedef struct s_arg
{
	int			a[2];
	int			b[2];
	int			fd;
	int			pipe;
	bool		heredoc;
	char		*limiter;
	char		*in;
	char		*out;
	char		**path;
	char		**file;
	char		***vec;
}				t_arg;

/*
** =============================================================================
** Macros
** =============================================================================
*/

# ifndef OPEN_MAX
#  define OPEN_MAX		4096
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 	4096
# endif

/*
** =============================================================================
** Context Functions
** =============================================================================
*/

void		free_arg(t_arg *x);
void		init(int argc, char **argv, char **envp, t_arg *x);
void		exit_child(t_arg *x, int code);
void		exit_parent(t_arg *x, int code, int i);
void		exit_invalid(t_arg *x, bool custom, const char *s1, const char *s2);
void		exit_valid(t_arg *x);

/*
** =============================================================================
** Debug Functions
** =============================================================================
*/

void		debug(t_arg *x);
void		print_args(t_arg *x);
void		print_path(t_arg *x);
void		print_vec(t_arg *x);

/*
** =============================================================================
** J Functions
** =============================================================================
*/

bool		jcalloc(void **ptr, size_t cnt, size_t n);
void		jfree(void **ptr);
int			jgnl(int fd, char **line);
bool		jisspace(int c);
void		*jmemset(void *s, int c, size_t n);
void		jputchar(char c, int fd);
void		jputendl(char *s, int fd);
void		jputnbr(int n, int fd);
void		jputstr(char *s, int fd);
char		**jsplit(const char *s, bool (*cmp)(int));
bool		jstrappend(char **s, char *s2);
char		*jstrdup(const char *s);
char		*jstrjoin(const char *s1, const char *s2);
size_t		jstrlcpy(char *dst, const char *src, size_t dstsize);
size_t		jstrlen(const char *s);
int			jstrncmp(const char *s1, const char *s2, size_t n);
char		*jsubstr(const char *s, unsigned int start, size_t len);

/*
** =============================================================================
** Parsing Functions
** =============================================================================
*/

bool		s_quote(int c);
bool		d_quote(int c);
bool		es_quote(int c1, int c2);
bool		ed_quote(int c1, int c2);
bool		command(t_arg *x, const char *cmd, int i);
bool		path(char **envp, t_arg *x);
char		**qsplit(const char *s);

/*
** =============================================================================
** Pipe Functions
** =============================================================================
*/

void		init_fd(t_fd *f, char *file, int flag, int mode);
void		none_fd(t_arg *x);
void		get_fd(t_arg *x, t_fd *f);
void		dup_fd(t_arg *x, int dst, int src);
void		call(char **envp, t_arg *x, int i);
void		exec(char **envp, t_arg *x);

#endif
