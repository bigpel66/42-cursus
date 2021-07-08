/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 16:16:14 by jseo              #+#    #+#             */
/*   Updated: 2021/07/08 14:52:24 by jseo             ###   ########.fr       */
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
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <stdlib.h>
# include <sys/wait.h>

/*
** =============================================================================
** Type Definitions
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

# define VALID			0
# define INVALID		1
# define SUCCESS		1
# define END			0
# define ERROR			-1
# define EMPTY			-1
# define CHILD			0

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

void		exec(char **envp, t_arg *x);
void		free_arg(t_arg *x);
void		init(int argc, char **argv, char **envp, t_arg *x);
void		exit_invalid(t_arg *x, bool custom, const char *s1, const char *s2);
void		exit_valid(t_arg *x);

/*
** =============================================================================
** Parsing Functions
** =============================================================================
*/

bool		check_infile(char **argv, t_arg *x);
bool		parse_command(t_arg *x, const char *cmd, int i);
void		process(char **envp, t_arg *x, int i);
void		block(t_arg *x, pid_t pid);

/*
** =============================================================================
** Pipe Functions
** =============================================================================
*/

void		init_fd(t_fd *f, char *file, int flag, int mode);
void		none_fd(t_arg *x);
void		get_fd(t_arg *x, t_fd *f);
void		dup_fd(t_arg *x, int dst, int src);

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
char		**jsplit(const char *s, bool (*cmp)(int));
bool		jstrappend(char **s, char *s2);
char		*jstrdup(const char *s);
char		*jstrjoin(const char *s1, const char *s2);
size_t		jstrlcpy(char *dst, const char *src, size_t dstsize);
size_t		jstrlen(const char *s);
int			jstrncmp(const char *s1, const char *s2, size_t n);
char		*jsubstr(const char *s, unsigned int start, size_t len);

#endif
