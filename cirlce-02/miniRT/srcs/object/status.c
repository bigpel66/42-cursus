/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 14:40:59 by jseo              #+#    #+#             */
/*   Updated: 2021/04/28 23:47:31 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	print_object_status(t_mlx *m)
{
	int		i;
	char	*s;

	i = -1;
	ostream_title("Object", 0);
	while (++i < m->rt.cnt.obj)
	{
		if ((m->obj)[i].type == SPHERE)
			s = "SPHERE\t";
		else if ((m->obj)[i].type == PLANE)
			s = "PLANE\t";
		else if ((m->obj)[i].type == SQUARE)
			s = "SQUARE\t";
		else if ((m->obj)[i].type == CYLINDER)
			s = "CYLINDER";
		else if ((m->obj)[i].type == TRIANGLE)
			s = "TRIANGLE";
		printf("The Type of Index %6d\'s Object\t\t%s", i, s);
		if ((m->obj)[i].data)
			printf("\tData\n");
		else
			printf("\tNo Data\n");
	}
	printf("\n");
}

static void	obj_alloc(t_mlx *m, int *n, int lim, int type)
{
	int	i;

	i = -1;
	while (++i < lim)
	{
		(m->obj)[*n].type = type;
		(m->obj)[*n].i = i;
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
		(m->obj)[*n].mat = (*n) % 3 + 1;
		(m->obj)[*n].fuzz = randr(0.0, 0.5);
		(m->obj)[*n].ir = 1.5;
		(m->obj)[*n].n = (*n)++;
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
	print_object_status(m);
	return (TRUE);
}

t_bool		obj_hit(t_p *p, t_ray r, t_hit *rec, t_bool hit)
{
	int		i;
	t_bool	ret;
	double	dist_so_far;

	i = -1;
	dist_so_far = INFINITY;
	while (++i < p->m->rt.cnt.obj)
	{
		if (p->m->obj[i].type == SPHERE)
			ret = hit_sp(p->m->obj[i], r, dist_so_far, rec);
		else if (p->m->obj[i].type == PLANE)
			ret = hit_pl(p->m->obj[i], r, dist_so_far, rec);
		else if (p->m->obj[i].type == SQUARE)
			ret = hit_sq(p->m->obj[i], r, dist_so_far, rec);
		else if (p->m->obj[i].type == CYLINDER)
			ret = hit_cy(p->m->obj[i], r, dist_so_far, rec);
		else if (p->m->obj[i].type == TRIANGLE)
			ret = hit_tr(p->m->obj[i], r, dist_so_far, rec);
		if (ret)
		{
			hit = TRUE;
			dist_so_far = rec->t;
		}
	}
	return (hit);
}

t_bool		obj_visible(t_obj *obj, int cnt, t_ray r, double lim)
{
	int		i;

	i = -1;
	while (++i < cnt)
	{
		if (obj[i].type == SPHERE && interfere_sp(obj[i], r, lim))
			return (0);
		else if (obj[i].type == PLANE && interfere_pl(obj[i], r, lim))
			return (0);
		else if (obj[i].type == SQUARE && interfere_sq(obj[i], r, lim))
			return (0);
		else if (obj[i].type == CYLINDER && interfere_cy(obj[i], r, lim))
			return (0);
		else if (obj[i].type == TRIANGLE && interfere_tr(obj[i], r, lim))
			return (0);
	}
	return (1);
}
