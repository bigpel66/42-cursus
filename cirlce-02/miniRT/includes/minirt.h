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
# include <stdint.h>
# include <pthread.h>

/*
** =============================================================================
** Macros
** =============================================================================
*/

# define TRUE 			1
# define FALSE 			0
# define VALID			0
# define INVALID		1
# define CHECK			1
# define PARSE			0
# define SUCCESS		1
# define END			0
# define ERROR 			-1

# define NOTHING		0
# define RESOLUTION		1
# define AMBIENT		2
# define CAMERA			3
# define LIGHT			4
# define SPHERE			5
# define PLANE			6
# define SQUARE			7
# define CYLINDER		8
# define TRIANGLE		9

# define KEY_TERM		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_Q			12
# define KEY_E			14
# define KEY_UP			126
# define KEY_LEFT		123
# define KEY_DOWN		125
# define KEY_RIGHT		124
# define KEY_CMA		43
# define KEY_SLH		44
# define KEY_N			45
# define KEY_M			46

# ifndef OPEN_MAX
#  define OPEN_MAX		4096
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 	1024
# endif

# ifndef RES_X
#  define RES_X			1600
# endif

# ifndef RES_Y
#  define RES_Y			900
# endif

# define DECIMAL		"0123456789"
# define BMP_HEADER		14
# define DIB_HEADER		40

/*
** =============================================================================
** Type Definitions
** =============================================================================
*/

typedef int				t_bool;
typedef pthread_mutex_t	t_mux;

typedef struct			s_vec3
{
	double				x;
	double				y;
	double				z;
}						t_vec3;

typedef struct			s_color
{
	double				r;
	double				g;
	double				b;
}						t_color;

typedef struct			s_resolution
{
	int					w;
	int					h;
	double				ar;
}						t_resolution;

typedef struct			s_ambient
{
	double				s;
	t_color				c;
}						t_ambient;

typedef struct			s_camera
{
	t_vec3				p;
	t_vec3				o;
	double				fov;
	t_vec3				hor;
	t_vec3				ver;
	t_vec3				u;
	t_vec3				v;
	t_vec3				w;
	t_vec3				llc;
	double				r;
}						t_camera;

typedef struct			s_light
{
	t_vec3				p;
	double				s;
	t_color				c;
}						t_light;

typedef	struct			s_sphere
{
	t_vec3				p;
	double				d;
	t_color				c;
}						t_sphere;

typedef struct			s_plane
{
	t_vec3				p;
	t_vec3				o;
	t_color				c;
}						t_plane;

typedef	struct			s_square
{
	t_vec3				p;
	t_vec3				o;
	double				l;
	t_color				c;
}						t_square;

typedef struct			s_cylinder
{
	t_vec3				p;
	t_vec3				o;
	double				d;
	double				h;
	t_color				c;
}						t_cylinder;

typedef struct			s_triangle
{
	t_vec3				p1;
	t_vec3				p2;
	t_vec3				p3;
	t_color				c;
}						t_triangle;

typedef struct			s_cnt
{
	int					r;
	int					a;
	int					c;
	int					l;
	int					sp;
	int					pl;
	int					sq;
	int					cy;
	int					tr;
	int					obj;
}						t_cnt;

typedef struct			s_scene
{
	t_cnt				cnt;
	t_resolution		r;
	t_ambient			a;
	t_camera			*c;
	t_light				*l;
	t_sphere			*sp;
	t_plane				*pl;
	t_square			*sq;
	t_cylinder			*cy;
	t_triangle			*tr;
}						t_scene;

typedef struct			s_obj
{
	int					type;
	int					i;
	int					n;
	void				*data;
}						t_obj;

typedef struct			s_ray
{
	t_vec3				a;
	t_vec3				b;
	double				t;
	t_vec3				cur;
}						t_ray;

typedef struct			s_img
{
	void				*id;
	char				*addr;
	int					bpp;
	int					sl;
	int					endian;
}						t_img;

typedef struct			s_mlx
{
	void				*sid;
	void				*wid;
	t_scene				rt;
	int					i;
	t_img				*img;
	t_obj				*obj;
}						t_mlx;

typedef struct			s_p
{
	void				*ancestor;
	void				*t;
	void				*p;
	t_mlx				*m;
	t_mux				*l;
	int					i;
	int					x;
}						t_p;

/*
** =============================================================================
** Error Handling Functions
** =============================================================================
*/

void					e_element_dup(void **ptr, int fd);
void					e_element_parse(void **ptr, t_mlx *m, int fd);
void					e_element_identifier(void **ptr, t_mlx *m, int fd);
void					e_file_param(void);
void					e_file_option(void);
void					e_file_extname(void);
void					e_file_open(t_mlx *m);
void					e_file_read(void **ptr, t_mlx *m, int fd);
void					e_memory_alloc(t_mlx *m);
void					e_mlx_setup(t_mlx *m);
void					e_mlx_screen_connection(t_mlx *m);
void					e_mlx_window(t_mlx *m);
void					e_mlx_image(t_mlx *m);
void					e_thread_open(void **t, void **p, t_mlx *m);
void					e_thread_join(void **t, void **p, t_mlx *m);
void					e_thread_alloc(void **t, void **p, t_mlx *m);
void					e_thread_exec(t_p *p, void **t, void **x, t_mux *l);

/*
** =============================================================================
** FT String Functions
** =============================================================================
*/

int						ft_gnl(int fd, char **line);
void					*ft_memset(void *s, int c, size_t n);
char					*ft_strappend(char *s1, char *s2);
char					*ft_strchr(const char *s, int c);
char					*ft_strdup(const char *s);
size_t					ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t					ft_strlen(const char *s);
int						ft_strncmp(const char *s1, const char *s2, size_t n);

/*
** =============================================================================
** Element Checking Functions
** =============================================================================
*/

t_bool					chk_ambient(t_scene *rt);
t_bool					chk_camera(t_scene *rt);
t_bool					chk_cylinder(t_scene *rt);
t_bool					chk_light(t_scene *rt);
t_bool					chk_plane(t_scene *rt);
t_bool					chk_resolution(t_scene *rt);
t_bool					chk_sphere(t_scene *rt);
t_bool					chk_square(t_scene *rt);
t_bool					chk_triangle(t_scene *rt);

/*
** =============================================================================
** Element Getting Functions
** =============================================================================
*/

t_bool					get_ambient(t_scene *rt, char *line);
t_bool					get_camera(t_scene *rt, char *line);
t_bool					get_cylinder(t_scene *rt, char *line);
t_bool					get_light(t_scene *rt, char *line);
t_bool					get_plane(t_scene *rt, char *line);
t_bool					get_resolution(t_scene *rt, char *line);
t_bool					get_sphere(t_scene *rt, char *line);
t_bool					get_square(t_scene *rt, char *line);
t_bool					get_triangle(t_scene *rt, char *line);

/*
** =============================================================================
** MiniLibX Functions
** =============================================================================
*/

void					p_init(t_p *arg, void *t, void *p, t_mlx *m);
void					p_update(t_p *arg, int i, int x, t_mux *l);
void					*mlx_col_calc(void *p);
void					*mlx_img_calc(void *p);
void					mlx_calc(t_mlx *m);
void					mlx_free(t_mlx *m);
void					mlx_run(t_mlx *m);
void					mlx_save(t_mlx *m, char *f, int len);
void					mlx_setup(t_mlx *m, char *f);

/*
** =============================================================================
** Object Functions
** =============================================================================
*/

t_bool					obj_init(t_mlx *m);

/*
** =============================================================================
** Parsing Functions
** =============================================================================
*/

int						get_identifier(char **s);
int						get_index(const char *s, int c);
t_bool					udouble(char **s, double *v);
t_bool					sdouble(char **s, double *v1, double *v2, double *v3);
t_bool					uint(char **s, int *v);
t_bool					sint(char **s, int *v1, int *v2, int *v3);

/*
** =============================================================================
** Ray Tracing Math Functions
** =============================================================================
*/

double					randv(void);
double					randr(double min, double max);
double					clamp(double d, double min, double max);
double					degrees_to_radians(double degrees);

/*
** =============================================================================
** Scene Functions
** =============================================================================
*/

t_bool					scene_init(t_scene *rt);
void					scene_open(t_mlx *m, char *f, t_bool chk);

/*
** =============================================================================
** Vector Calculation Functions
** =============================================================================
*/

t_vec3					v_flip(t_vec3 v);
t_vec3					v_add(t_vec3 u, t_vec3 v);
t_vec3					v_sub(t_vec3 u, t_vec3 v);
t_vec3					v_mul(t_vec3 u, t_vec3 v);
t_vec3					v_scale(t_vec3 v, double s);

/*
** =============================================================================
** Vector Feature Functions
** =============================================================================
*/

t_vec3					v_init(double x, double y, double z);
t_vec3					v_unit(t_vec3 v);
t_vec3					v_reflect(t_vec3 v, t_vec3 n);
t_vec3					v_refract(t_vec3 uv, t_vec3 n, double etai_over_etat);

/*
** =============================================================================
** Vector Information Functions
** =============================================================================
*/

double					v_size_squared(t_vec3 v);
double					v_size(t_vec3 v);
t_bool					v_near_zero(t_vec3 v);
double					v_dot(t_vec3 u, t_vec3 v);
t_vec3					v_cross(t_vec3 u, t_vec3 v);

/*
** =============================================================================
** Vector Random Functions
** =============================================================================
*/

t_vec3					v_randr(double min, double max);
t_vec3					v_rand_in_unit_sphere(void);
t_vec3					v_rand_in_unit_hemisphere(t_vec3 n);
t_vec3					v_rand_in_unit_disk(void);
t_vec3					v_rand_unit(void);

/*
** =============================================================================
** BMP Functions
** =============================================================================
*/

t_bool					export_bmp(t_mlx *m, int fd, int idx);

/*
** =============================================================================
** Camera Functions
** =============================================================================
*/

void					cam_mov(int key, t_mlx *m);
void					cam_rot(int key, t_mlx *m);
void					cam_snap(int key, t_mlx *m);
void					cam_init(t_camera *c, t_vec3 up, double ar, double fd);

/*
** =============================================================================
** Color Functions
** =============================================================================
*/

void					c_init(t_color *c, double r, double g, double b);
t_color					c_gamma_correction(t_color c, int samples_per_pixel);

/*
** =============================================================================
** Memory Functions
** =============================================================================
*/

t_bool					dalloc(void **ptr, size_t cnt, size_t n);
void					free_ptr(void **ptr);
void					free_scene(t_scene *rt);
void					free_thread(void **t, void **p, t_mux *l);

/*
** =============================================================================
** Ostream Functions
** =============================================================================
*/

void					to_string_c(t_camera *c, int idx);
void					ostream_title(const char *s, int idx);
void					ostream_vector(const t_vec3 *v, const char *s);
void					ostream_color(const t_color *c, const char *s);
void					ostream_floating_point(double d, const char *s);

/*
** =============================================================================
** Checking Functions
** =============================================================================
*/

t_bool					is_blank(int c);
t_bool					is_digit(int c);
t_bool					is_endl(const char *s);
t_bool					valid_color(t_color c);
t_bool					valid_vec3(t_vec3 v);

/*
** =============================================================================
** Entry Point
** =============================================================================
*/

void					print_error_list(void);
int						main(int argc, char **argv);

#endif
