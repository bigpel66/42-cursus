/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 00:16:11 by jseo              #+#    #+#             */
/*   Updated: 2021/05/05 20:54:39 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	cam_key(int key, t_mlx *m)
{
	if ((key >= 0 && key <= 2) || (key >= 12 && key <= 14))
		cam_mov(key, m);
	else if ((key >= 123 && key <= 126) || (key >= 43 && key <= 44))
		cam_rot(key, m);
	else if (key >= 45 && key <= 46)
		cam_snap(key, m);
	else
		return (FALSE);
	return (TRUE);
}

t_bool	obj_key(int key, t_mlx *m)
{
	if ((key >= 18 && key <= 21) || (key >= 34 && key <= 35))
		obj_mov(key, m);
	else if ((key >= 6 && key <= 9) || (key >= 40 && key <= 41))
		obj_rot(key, m);
	else
		return (FALSE);
	return (TRUE);
}

t_bool	mode_key(int key, t_mlx *m)
{
	int	i;

	i = -1;
	if (key == KEY_SPACE)
	{
		while (++i < m->rt.cnt.obj)
			(m->obj)[i].mat = ((m->obj)[i].mat + 1) % 3;
		print_material_status((m->obj)[0].mat);
	}
	else if (key == KEY_ENTER)
	{
		while (++i < m->rt.cnt.obj)
			(m->obj)[i].filter = ((m->obj)[i].filter + 1) % 5;
		print_filter_status((m->obj)[0].filter);
	}
	else if (key == KEY_DEL)
	{
		while (++i < m->rt.cnt.obj)
			if ((m->obj)[i].type == SPHERE)
				((t_sphere *)((m->obj)[i].data))->m =
					((((t_sphere *)((m->obj)[i].data))->m + 1) % 4);
	}
	else
		return (FALSE);
	return (TRUE);
}

t_bool	cam_cur(int key, t_mlx *m)
{
	t_camera	*c;
	double		cosine;
	double		sine;

	cosine = cos(degrees_to_radians(30.0));
	sine = cosine_to_sine(cosine);
	c = &((m->rt.c)[m->i]);
	if (key == PTR_LEFT)
	{
		(m->rt.c)[m->i].o =
			v_init(cosine * (m->rt.c)[m->i].o.x + sine * (m->rt.c)[m->i].o.z,
					(m->rt.c)[m->i].o.y,
					-sine * (m->rt.c)[m->i].o.x + cosine * (m->rt.c)[m->i].o.z);
	}
	else if (key == PTR_RIGHT)
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
