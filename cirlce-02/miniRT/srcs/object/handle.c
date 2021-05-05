/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 17:21:14 by jseo              #+#    #+#             */
/*   Updated: 2021/05/04 17:21:16 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
