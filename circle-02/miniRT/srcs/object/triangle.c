/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 15:01:04 by jseo              #+#    #+#             */
/*   Updated: 2021/05/04 00:28:00 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_bool	chk_root(t_triangle *tr, t_ray r, double *t, double lim)
{
	double	denom;
	double	numer;

	denom = dot(r.o, tr->n);
	if (!denom)
		return (FALSE);
	numer = dot(sub(tr->p, r.p), tr->n);
	*t = numer / denom;
	if (*t < 0.001 || *t > lim)
		return (FALSE);
	return (TRUE);
}

static t_bool	chk_size(t_triangle *tr, t_vec3 p)
{
	t_vec3	un;
	t_vec3	vn;
	double	denom;
	double	s;
	double	t;

	un = cross(tr->n, sub(tr->p2, tr->p1));
	vn = cross(tr->n, sub(tr->p3, tr->p1));
	denom = dot(sub(tr->p2, tr->p1), vn);
	if (fabs(denom) < 0.001)
		return (FALSE);
	s = dot(sub(p, tr->p1), vn) / denom;
	if (s < 0 || s > 1)
		return (FALSE);
	t = dot(sub(p, tr->p1), un) / -denom;
	if (!(t >= 0 && (s + t) <= 1))
		return (FALSE);
	return (TRUE);
}

t_bool			hit_tr(t_obj obj, t_ray r, double lim, t_hit *rec)
{
	double		t;
	t_vec3		p;
	t_triangle	*tr;

	if (obj.type != TRIANGLE)
		return (FALSE);
	tr = (t_triangle *)(obj.data);
	if (!chk_root(tr, r, &t, lim))
		return (FALSE);
	p = add(r.p, scale(r.o, t));
	if (chk_size(tr, p))
	{
		set_hit_point(r, t, rec);
		set_normal(obj, r, tr->n, rec);
		set_hit_color(tr->c, obj.filter, rec);
		return (TRUE);
	}
	return (FALSE);
}

t_bool			interfere_tr(t_obj obj, t_ray r, double lim)
{
	double		t;
	t_vec3		p;
	t_triangle	*tr;

	tr = (t_triangle *)(obj.data);
	if (!chk_root(tr, r, &t, lim))
		return (FALSE);
	p = add(r.p, scale(r.o, t));
	if (chk_size(tr, p))
		return (TRUE);
	return (FALSE);
}
