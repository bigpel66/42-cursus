/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 11:23:21 by jseo              #+#    #+#             */
/*   Updated: 2021/02/10 22:55:00 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 4096
# endif

int		get_next_line(int fd, char **line);
ssize_t	check_newline(char *mem);
int		split_line(char **mem, char **line, ssize_t idx);
int		exception_line(char **mem, char **line, ssize_t size);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *s);
char	*ft_strappend(char *s1, char *s2);

#endif
