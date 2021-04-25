/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 15:08:37 by jseo              #+#    #+#             */
/*   Updated: 2021/04/25 15:08:38 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	camera_translation(int key, t_mlx *m)
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

void	camera_rotation(int key, t_mlx *m)
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

void	camera_index(int key, t_mlx *m)
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
}
