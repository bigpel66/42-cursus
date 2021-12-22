/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:43:10 by jseo              #+#    #+#             */
/*   Updated: 2021/12/22 18:37:19 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*
** =============================================================================
** Dependencies from System
** =============================================================================
*/

# include <dirent.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/history.h>
# include <readline/readline.h>

/*
** =============================================================================
** Dependencies from User
** =============================================================================
*/

# include "ast.h"
# include "redblack.h"

/*
** =============================================================================
** Enum Type Definitions
** =============================================================================
*/

typedef enum e_exit
{
    VALID,
    INVALID,
}			t_exit;

/*
** =============================================================================
** Struct Type Definitions
** =============================================================================
*/

// ...

/*
** =============================================================================
** J Functions
** =============================================================================
*/

bool	jcalloc(void **ptr, size_t cnt, size_t n);
void	jfree(void **ptr);
bool	jisspace(int c);
void	*jmemset(void *s, int c, size_t n);
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
char	*jsubstr(const char *s, unsigned int start, size_t len);

#endif
