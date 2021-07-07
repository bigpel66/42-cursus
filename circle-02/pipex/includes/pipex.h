/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 16:16:14 by jseo              #+#    #+#             */
/*   Updated: 2021/07/07 16:56:13 by jseo             ###   ########.fr       */
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

typedef struct s_arg
{
	int			p[2];
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

# define VALID		0
# define INVALID	1
# define ERROR		-1
# define EMPTY		-1
# define CHILD		0
# define P_READ		0
# define P_WRITE	1

/*
** =============================================================================
** Context Functions
** =============================================================================
*/

void		exec(t_arg *x, char **envp);
void		free_arg(t_arg *x);
void		init(int argc, char **argv, t_arg *x);
bool		path(char **envp, t_arg *x);
bool		check_command(t_arg *x, int i);
bool		parse_command(t_arg *x, const char *cmd, int i);
bool		check_infile(t_arg *x);
bool		parse_stdin(t_arg *x);
void		exit_invalid(t_arg *x, bool custom, const char *s1, const char *s2);
void		exit_valid(t_arg *x);

/*
** =============================================================================
** J Functions
** =============================================================================
*/

bool		jcalloc(void **ptr, size_t cnt, size_t n);
void		jfree(void **ptr);
bool		jisspace(int c);
void		*jmemset(void *s, int c, size_t n);
char		**jsplit(const char *s, bool (*cmp)(int));
char		*jstrdup(const char *s);
char		*jstrjoin(const char *s1, const char *s2);
size_t		jstrlcpy(char *dst, const char *src, size_t dstsize);
size_t		jstrlen(const char *s);
int			jstrncmp(const char *s1, const char *s2, size_t n);
char		*jsubstr(const char *s, unsigned int start, size_t len);

#endif
