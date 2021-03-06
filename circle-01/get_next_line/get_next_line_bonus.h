/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 11:23:21 by jseo              #+#    #+#             */
/*   Updated: 2021/05/11 23:07:05 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# define ERROR			-1
# define END			0
# define SUCCESS		1
# define TRUE			1
# define FALSE			0

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	4096
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX		4096
# endif

typedef int				t_bool;

int						get_next_line(int fd, char **line);
size_t					ft_strlen(const char *s);
size_t					ft_strlcpy(char *dst, const char *src, size_t dstsize);
char					*ft_strdup(const char *s);
t_bool					dalloc(void **ptr, size_t cnt, size_t n);
void					free_ptr(void **ptr);

#endif
