/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:06:32 by jseo              #+#    #+#             */
/*   Updated: 2021/04/17 16:19:34 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define TRUE 			1
# define FALSE 			0
# define SUCCESS 		0
# define ERROR 			-1

# ifndef OPEN_MAX
#  define OPEN_MAX		4096
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 	4096
# endif

typedef int			t_bool;

typedef struct		s_scene
{
	int				x;
	int				y;
}					t_scene;

typedef struct		s_img
{
	void			*id;
	char			*addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
}					t_img;

typedef struct		s_mlx
{
	void			*sid;
	void			*wid;
	t_img			*img;
	t_scene			*data;
}					t_mlx;

t_bool				dalloc(void **ptr, size_t cnt, size_t n);
void				free_ptr(void **ptr);

void				*ft_memset(void *s, int c, size_t n);
char				*ft_strappend(char *s1, char *s2);
char				*ft_strdup(const char *s);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlen(const char *s);

int					get_next_line(int fd, char **line);

void				pre_setting(t_mlx *m);

int					main(int argc, char **argv);

#endif
