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

# define RESOLUTION		1
# define AMBIENT		2
# define CAMERA			3
# define LIGHT			4
# define SPHERE			5
# define PLANE			6
# define SQUARE			7
# define CYLINDER		8
# define TRIANGLE		9

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

typedef struct		s_resolution
{
	t_bool			f;
	int				w;
	int				h;
}					t_resolution;

typedef struct		s_ambient
{
	t_bool			f;
	double			s;
	t_color			c;
}					t_ambient;

typedef struct		s_camera
{
	t_bool			f;
	t_vec3			p;
	t_vec3			d;
	t_vec3			hor;
	t_vec3			ver;
	t_vec3			u;
	t_vec3			v;
	t_vec3			w;
	t_vec3			llc;
	double			fov;
	double			r;
}					t_camera;

typedef struct		s_light
{
	t_bool			f;
	t_vec3			p;
	double			s;
	t_color			c;
}					t_light;

typedef	struct		s_sphere
{
	t_bool			f;
	t_vec3			p;
	double			r;
	t_color			c;
}					t_sphere;

typedef struct		s_plane
{
	t_bool			f;
	t_vec3			p;
	t_vec3			d;
	t_color			c;
}					t_plane;

typedef	struct		s_square
{
	t_bool			f;
	t_vec3			p;
	t_vec3			d;
	double			l;
	t_color			c;
}					t_square;

typedef struct		s_cylinder
{
	t_bool			f;
	t_vec3			p;
	t_vec3			d;
	double			r;
	double			h;
	t_color			c;
}					t_cylinder;

typedef struct		s_triangle
{
	t_bool			f;
	t_vec3			p1;
	t_vec3			p2;
	t_vec3			p3;
	t_color			c;
}					t_triangle;

typedef struct		s_scene
{
	t_resolution	r;
	t_ambient		a;
	t_camera		c;
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
	t_scene			i;
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
void				e_file_parsing(void **ptr);
void				e_file_read(void);
void				e_screen_connection(void);
void				e_window(void);

/*
** =============================================================================
** FT Functions
** =============================================================================
*/

int					ft_gnl(int fd, char **line);
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
t_bool				is_identifier(char **line);
t_bool				is_newline(int c);
t_bool				valid_color(t_color c);
t_bool				valid_vec3(t_vec3 v);

/*
** =============================================================================
** Value Functions
** =============================================================================
*/

t_bool				get_ambient(t_mlx *m, char *line);
t_bool				get_camera(t_mlx *m, char *line);
t_bool				get_cylinder(t_mlx *m, char *line);
t_bool				get_index(const char *s, int c);
t_bool				get_light(t_mlx *m, char *line);
t_bool				get_plane(t_mlx *m, char *line);
t_bool				get_resolution(t_mlx *m, char *line);
t_bool				get_sphere(t_mlx *m, char *line);
t_bool				get_square(t_mlx *m, char *line);
t_bool				get_triangle(t_mlx *m, char *line);
void				sdobule(char **line, double *v1, double *v2, double *v3);
void				sint(char **line, int *v1, int *v2, int *v3);
double				vdouble(char **line);
int					vint(char **line);

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
