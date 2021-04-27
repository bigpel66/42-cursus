/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 15:08:37 by jseo              #+#    #+#             */
/*   Updated: 2021/04/26 01:28:24 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	cam_mov(int key, t_mlx *m)
{
	if (key == KEY_W)
		(m->rt.c)[m->i].p.y += 0.5;
	if (key == KEY_A)
		(m->rt.c)[m->i].p.x -= 0.5;
	if (key == KEY_S)
		(m->rt.c)[m->i].p.y -= 0.5;
	if (key == KEY_D)
		(m->rt.c)[m->i].p.x += 0.5;
	if (key == KEY_Q)
		(m->rt.c)[m->i].p.z -= 0.5;
	if (key == KEY_E)
		(m->rt.c)[m->i].p.z += 0.5;
	to_string_c(&((m->rt.c)[m->i]), m->i + 1);
}

void	cam_rot(int key, t_mlx *m)
{
	double	*tmp;

	if (key == KEY_UP || key == KEY_DOWN)
		tmp = &((m->rt.c)[m->i].o.y);
	if (key == KEY_LEFT || key == KEY_RIGHT)
		tmp = &((m->rt.c)[m->i].o.x);
	if (key == KEY_CMA || key == KEY_SLH)
		tmp = &((m->rt.c)[m->i].o.z);
	if (key == KEY_LEFT || key == KEY_DOWN || key == KEY_CMA)
		*tmp = clamp(*tmp - 0.1, 0.0, 1.0);
	else
		*tmp = clamp(*tmp + 0.1, 0.0, 1.0);
	to_string_c(&((m->rt.c)[m->i]), m->i + 1);
}

void	cam_snap(int key, t_mlx *m)
{
	int	idx;

	idx = m->i;
	if (key == KEY_N)
	{
		m->i = (--idx) % m->rt.cnt.c;
		if (m->i < 0)
			m->i += m->rt.cnt.c;
	}
	if (key == KEY_M)
		m->i = (++idx) % m->rt.cnt.c;
	ostream_title("Viewport", (m->i) + 1);
	printf("Viewport has been turned into the No.%d Camera\n", (m->i) + 1);
	printf("\n");
}

void	cam_init(t_camera *c, t_vec3 up, double ar, double fd)
{
	double	theta;
	double	height;
	double	viewport_height;
	double	viewport_width;

	theta = degrees_to_radians(c->fov);
	height = tan(theta / 2.0);
	viewport_height = 2.0 * height;
	viewport_width = ar * viewport_height;
	c->w = v_unit(v_sub(c->p, c->o));
	c->u = v_unit(v_cross(up, c->w));
	c->v = v_cross(c->w, c->u);
	c->hor = v_scale(c->u, fd * viewport_width);
	c->ver = v_scale(c->v, fd * viewport_height);
	c->llc = v_sub(v_sub(v_sub(c->p,
					v_scale(c->hor, 1.0 / 2.0)),
				v_scale(c->ver, 1.0 / 2.0)),
			v_scale(c->w, fd));
	c->r = 0.05;
	c->spp = 100;
	c->md = 10;
}
