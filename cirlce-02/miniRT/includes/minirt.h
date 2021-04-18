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

/*
** =============================================================================
** Dependencies
** =============================================================================
*/

# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/*
** =============================================================================
** Macros
** =============================================================================
*/

# define TRUE 			1
# define FALSE 			0
# define VALID			0
# define INVALID		1
# define SUCCESS		1
# define END			0
# define ERROR 			-1

# ifndef OPEN_MAX
#  define OPEN_MAX		4096
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 	4096
# endif

/*
** =============================================================================
** Type Definitions
** =============================================================================
*/

typedef int			t_bool;

typedef struct		s_vec3
{
	double			x;
	double			y;
	double			z;
}					t_vec3;

typedef struct		s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;

typedef struct		s_camera
{
	t_vec3			pos;
	t_vec3			dir;
	t_vec3			horizontal;
	t_vec3			vertical;
	t_vec3			basis_u;
	t_vec3			basis_v;
	t_vec3			basis_w;
	t_vec3			lower_left_corner;
	double			fov;
	double			lens_radius;
}					t_camera;

typedef struct		s_ambient
{
	t_color			color;
	double			val;
}					t_ambient;

typedef struct		s_light
{
	t_vec3			pos;
	t_color			color;
	double			val;
}					t_light;

typedef	struct		s_sphere
{
	t_vec3			pos;
	t_color			color;
	double			radius;
}					t_sphere;

typedef struct		s_plane
{
	t_vec3			pos;
	t_vec3			dir;
	t_color			color;
}					t_plane;

typedef	struct		s_square
{
	t_vec3			pos;
	t_vec3			dir;
	t_color			color;
	double			side;
}					t_square;

typedef struct		s_cylinder
{
	t_vec3			pos;
	t_vec3			dir;
	t_color			color;
	double			radius;
	double			height;
}					t_cylinder;

typedef struct		s_triangle
{
	t_vec3			pos1;
	t_vec3			pos2;
	t_vec3			pos3;
	t_color			color;
}					t_triangle;

typedef struct		s_scene
{
	int				r_width;
	int				r_height;
	t_camera		cam;
	t_ambient		a;
	t_light			l;
	t_sphere		sp;
	t_plane			pl;
	t_square		sq;
	t_cylinder		cy;
	t_triangle		tr;
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

/*
** =============================================================================
** Memory Functions
** =============================================================================
*/

t_bool				dalloc(void **ptr, size_t cnt, size_t n);
void				free_ptr(void **ptr);

/*
** =============================================================================
** Error Handling Functions
** =============================================================================
*/

void				print_error_list(void);
void				e_argument(void);
void				e_file_extname(void);
void				e_file_open(void);
void				e_file_parsing(void);
void				e_file_read(void);
void				e_screen_connection(void);
void				e_window(void);

/*
** =============================================================================
** FT Functions
** =============================================================================
*/

void				*ft_memset(void *s, int c, size_t n);
char				*ft_strappend(char *s1, char *s2);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *s);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlen(const char *s);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

/*
** =============================================================================
** Checking Functions
** =============================================================================
*/

t_bool				is_blank(int c);
t_bool				is_newline(int c);

/*
** =============================================================================
** Parsing Functions
** =============================================================================
*/

int					get_next_line(int fd, char **line);

/*
** =============================================================================
** MiniLibX Functions
** =============================================================================
*/

void				mlx_ready(t_mlx *m);

/*
** =============================================================================
** Entry Point
** =============================================================================
*/

int					main(int argc, char **argv);

#endif
