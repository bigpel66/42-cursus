/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xmouse.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 00:16:17 by jseo              #+#    #+#             */
/*   Updated: 2021/05/05 01:13:24 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	cur_init(int key, double x, double y, t_cur *cur)
{
	if (key != PTR_LEFT)
		return (FALSE);
	cur->x = x;
	cur->y = y;
	return (TRUE);
}

t_bool	cam_cur_no_left(int key, t_mlx *m)
{
	t_camera *c;

	c = &((m->rt.c)[m->i]);
	if (key == PTR_RIGHT)
		c->o = flip(c->o);
	else if (key == PTR_UP_1 || key == PTR_UP_2)
		c->p = add(c->p, scale(c->o, 10));
	else if (key == PTR_DOWN_1 || key == PTR_DOWN_2)
		c->p = sub(c->p, scale(c->o, 10));
	else
		return (FALSE);
	to_string_c(&((m->rt.c)[m->i]), m->i + 1);
	return (TRUE);
}

t_bool	cam_cur_left(t_mlx *m)
{
	double	cosine;
	double	sine;

	cosine = cos(degrees_to_radians(30.0));
	sine = cosine_to_sine(cosine);
	(m->rt.c)[m->i].o =
		v_init(cosine * (m->rt.c)[m->i].o.x + sine * (m->rt.c)[m->i].o.z,
				(m->rt.c)[m->i].o.y,
				-sine * (m->rt.c)[m->i].o.x + cosine * (m->rt.c)[m->i].o.z);
	to_string_c(&((m->rt.c)[m->i]), m->i + 1);
	return (TRUE);
}
