/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_function.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 19:06:48 by jseo              #+#    #+#             */
/*   Updated: 2021/12/24 23:34:45 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef J_FUNCTION_H
# define J_FUNCTION_H

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

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

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
