/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 17:02:29 by jseo              #+#    #+#             */
/*   Updated: 2021/02/10 22:57:18 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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
