/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 15:08:37 by jseo              #+#    #+#             */
/*   Updated: 2021/04/30 12:35:48 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	cam_mov(int key, t_mlx *m)
{
	double	*tmp;

	if (key == KEY_W || key == KEY_S)
		tmp = &((m->rt.c)[m->i].p.y);
	if (key == KEY_A || key == KEY_D)
		tmp = &((m->rt.c)[m->i].p.x);
	if (key == KEY_Q || key == KEY_E)
		tmp = &((m->rt.c)[m->i].p.z);
	if (key == KEY_W || key == KEY_D || key == KEY_E)
		*tmp = *tmp + 0.5 * 6;
	else
		*tmp = *tmp - 0.5 * 6;
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
		*tmp = clamp(*tmp - 0.1 * 2, -1.0, 1.0);
	else
		*tmp = clamp(*tmp + 0.1 * 2, -1.0, 1.0);
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

void	cam_handle(int key, t_mlx *m)
{
	if ((key >= 0 && key <= 2) || (key >= 12 && key <= 14))
		cam_mov(key, m);
	else if ((key >= 123 && key <= 126) || (key >= 43 && key <= 44))
		cam_rot(key, m);
	else if (key >= 45 && key <= 46)
		cam_snap(key, m);
}

void	cam_init(t_camera *c, t_vec3 up, double ar)
{
	double	theta;
	double	height;
	double	viewport_height;
	double	viewport_width;

	if (c->o.x == 0 && c->o.y != 0 && c->o.z == 0)
		up = v_init(0.0, c->o.y, 0.001);
	theta = degrees_to_radians(c->fov);
	height = tan(theta / 2.0);
	viewport_height = 2.0 * height;
	viewport_width = ar * viewport_height;
	c->w = v_unit(v_flip(c->o));
	c->u = v_unit(v_cross(up, c->w));
	c->v = v_cross(c->w, c->u);
	c->hor = v_scale(c->u, viewport_width);
	c->ver = v_scale(c->v, viewport_height);
	c->llc = v_init(c->p.x - c->hor.x / 2 - c->ver.x / 2 - c->w.x,
					c->p.y - c->hor.y / 2 - c->ver.y / 2 - c->w.y,
					c->p.z - c->hor.z / 2 - c->ver.z / 2 - c->w.z);
}
