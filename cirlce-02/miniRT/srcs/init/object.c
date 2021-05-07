/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 14:40:59 by jseo              #+#    #+#             */
/*   Updated: 2021/05/07 17:46:30 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	obj_alloc(t_mlx *m, int *n, int lim, int type)
{
	int	i;

	i = -1;
	while (++i < lim)
	{
		(m->obj)[*n].type = type;
		if (type == SPHERE)
			(m->obj)[*n].data = (void *)(&((m->rt.sp)[i]));
		else if (type == PLANE)
			(m->obj)[*n].data = (void *)(&((m->rt.pl)[i]));
		else if (type == SQUARE)
			(m->obj)[*n].data = (void *)(&((m->rt.sq)[i]));
		else if (type == CYLINDER)
			(m->obj)[*n].data = (void *)(&((m->rt.cy)[i]));
		else if (type == TRIANGLE)
			(m->obj)[*n].data = (void *)(&((m->rt.tr)[i]));
		else if (type == CONE)
			(m->obj)[*n].data = (void *)(&((m->rt.co)[i]));
		(m->obj)[*n].i = i;
		(m->obj)[*n].fuzz = 0.0;
		(m->obj)[*n].ir = 1.5;
		(m->obj)[*n].n = *n;
		if (*n != m->rt.cnt.obj - 1)
			++(*n);
	}
}

t_bool		obj_init(t_mlx *m)
{
	int	n;

	n = 0;
	if (!dalloc((void **)(&(m->obj)), m->rt.cnt.obj, sizeof(t_obj)))
		return (FALSE);
	obj_alloc(m, &n, m->rt.cnt.sp, SPHERE);
	obj_alloc(m, &n, m->rt.cnt.pl, PLANE);
	obj_alloc(m, &n, m->rt.cnt.sq, SQUARE);
	obj_alloc(m, &n, m->rt.cnt.cy, CYLINDER);
	obj_alloc(m, &n, m->rt.cnt.tr, TRIANGLE);
	obj_alloc(m, &n, m->rt.cnt.co, CONE);
	print_object_status(m);
	return (TRUE);
}
