/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 15:01:04 by jseo              #+#    #+#             */
/*   Updated: 2021/04/28 18:08:07 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_bool	chk_root(t_triangle *tr, t_ray r, double *t, double lim)
{
	double	denom;
	double	numer;

	denom = v_dot(r.o, tr->o);
	if (!denom)
		return (FALSE);
	numer = v_dot(v_sub(tr->p, r.p), tr->o);
	*t = numer / denom;
	if (*t < 0.001 || *t > lim)
		return (FALSE);
	return (TRUE);
}

static t_bool		chk_size(t_triangle *tr, t_vec3 p)
{
	t_vec3		un;
	t_vec3		vn;
	double 		denom;
	double		s;
	double 		t;

	un = v_cross(tr->o, v_sub(tr->p2, tr->p1));
	vn = v_cross(tr->o, v_sub(tr->p3, tr->p1));
	denom = v_dot(v_sub(tr->p2, tr->p1), vn);
	if (fabs(denom) < 0.001)
		return (FALSE);
	s = v_dot(v_sub(p, tr->p1), vn) / denom;
	if (s < 0 || s > 1)
		return (FALSE);
	t = v_dot(v_sub(p, tr->p1), un) / - denom;
	if (!(t >= 0 && (s + t) <= 1))
		return (FALSE);
	return (TRUE);
}

t_bool	hit_tr(t_obj obj, t_ray r, double lim, t_hit *rec)
{
	double		t;
	t_vec3		p;
	t_triangle *tr;

	tr = (t_triangle *)(obj.data);
	if (!chk_root(tr, r, &t, lim))
		return (FALSE);
	p = v_add(r.p, v_scale(r.o, t));
	if (chk_size(tr, p))
	{
		rec->t = t;
		rec->p = p;
		rec->c = tr->c;
		rec->n = tr->o;
		rec->f = FRONT;
		if (v_dot(r.o, tr->o) >= 0)
		{
			rec->n = v_flip(tr->o);
			rec->f = BACK;
		}
		rec->mat = obj.mat;
		rec->fuzz = obj.fuzz;
		rec->ir = obj.ir;
		return (TRUE);
	}
	return (FALSE);
}

t_bool	interfere_tr(t_obj obj, t_ray r, double lim)
{
	double		t;
	t_vec3		p;
	t_triangle *tr;

	tr = (t_triangle *)(obj.data);
	if (!chk_root(tr, r, &t, lim))
		return (FALSE);
	p = v_add(r.p, v_scale(r.o, t));
	if (chk_size(tr, p))
		return (TRUE);
	return (FALSE);
}
