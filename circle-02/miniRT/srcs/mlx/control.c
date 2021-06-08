/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 15:08:37 by jseo              #+#    #+#             */
/*   Updated: 2021/05/07 17:45:59 by jseo             ###   ########.fr       */
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
	ostream_endl();
}

void	obj_mov(int key, t_mlx *m)
{
	double	*tmp;

	if (key == KEY_3 || key == KEY_4)
		tmp = &((m->rt.c)[m->i].p.y);
	if (key == KEY_1 || key == KEY_2)
		tmp = &((m->rt.c)[m->i].p.x);
	if (key == KEY_I || key == KEY_P)
		tmp = &((m->rt.c)[m->i].p.z);
	if (key == KEY_2 || key == KEY_4 || key == KEY_P)
		*tmp = *tmp - 0.5 * 6;
	else
		*tmp = *tmp + 0.5 * 6;
	to_string_c(&((m->rt.c)[m->i]), m->i + 1);
}

void	obj_rot(int key, t_mlx *m)
{
	double	*tmp;

	if (key == KEY_C || key == KEY_V)
		tmp = &((m->rt.c)[m->i].o.y);
	if (key == KEY_Z || key == KEY_X)
		tmp = &((m->rt.c)[m->i].o.x);
	if (key == KEY_K || key == KEY_SEMI)
		tmp = &((m->rt.c)[m->i].o.z);
	if (key == KEY_C || key == KEY_Z || key == KEY_K)
		*tmp = clamp(*tmp + 0.1 * 2, -1.0, 1.0);
	else
		*tmp = clamp(*tmp - 0.1 * 2, -1.0, 1.0);
	to_string_c(&((m->rt.c)[m->i]), m->i + 1);
}
