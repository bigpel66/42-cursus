/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 22:09:28 by jseo              #+#    #+#             */
/*   Updated: 2021/05/06 18:33:04 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		set_promising_t(t_co_arg *p, t_cone *co, t_ray r, double *t)
{
	int		i;
	double	tmp;

	i = -1;
	tmp = INFINITY;
	if (p->t1 >= 0)
		if (dot(co->o, add(sub(r.p, co->p), scale(r.o, p->t1))) > 0)
			if (dot(co->o, add(sub(r.p, co->tp), scale(r.o, p->t1))) < 0)
				(p->t)[0] = p->t1;
	if (p->t2 >= 0)
		if (dot(co->o, add(sub(r.p, co->p), scale(r.o, p->t2))) > 0)
			if (dot(co->o, add(sub(r.p, co->tp), scale(r.o, p->t2))) < 0)
				(p->t)[1] = p->t2;
	if (p->t3 >= 0)
		if (len_pow(sub(scale(r.o, p->t3), sub(co->p, r.p))) <= co->r * co->r)
			(p->t)[2] = p->t3;
	while (++i < 3)
		if ((p->t)[i] != -1.0 && tmp > (p->t)[i])
			tmp = (p->t)[i];
	if (tmp != INFINITY)
		*t = tmp / len_sqrt(r.o);
	else
		*t = INFINITY;
}

static void		set_co_arg(t_co_arg *p, t_cone *co, t_ray r)
{
	p->tc = sub(r.p, co->tp);
	p->c1 = dot(r.o, co->to);
	p->c2 = scale(co->to, p->c1);
	p->c3 = dot(p->tc, co->to);
	p->c4 = scale(co->to, p->c3);
	p->t[0] = -1.0;
	p->t[1] = -1.0;
	p->t[2] = -1.0;
	p->t1 = -1.0;
	p->t2 = -1.0;
	p->t3 = -1.0;
	p->denom = dot(r.o, co->o);
	if (p->denom > 1e-8)
		p->t3 = dot(sub(co->p, r.p), co->o) / p->denom;
}

static t_bool	chk_root(t_cone *co, t_ray r, double *t, double lim)
{
	double		d;
	double		a;
	double		h_b;
	double		c;
	t_co_arg	p;

	set_co_arg(&p, co, r);
	a = co->cos2 * len_pow(sub(r.o, p.c2)) - co->sin2 * p.c1 * p.c1;
	h_b = co->cos2 * dot(sub(r.o, p.c2), sub(p.tc, p.c4)) - co->sin2 * p.c1 * p.c3;
	c = co->cos2 * len_pow(sub(p.tc, p.c4)) - co->sin2 * p.c3 * p.c3;
	d = h_b * h_b - a * c;
	if (d < 0)
		return (FALSE);
	p.t1 = (-h_b - sqrt(d)) / a;
	p.t2 = (-h_b + sqrt(d)) / a;
	set_promising_t(&p, co, r, t);
	if (*t == INFINITY || *t > lim)
		return (FALSE);
	return (TRUE);
}

t_bool			hit_co(t_obj obj, t_ray r, double lim, t_hit *rec)
{
	double	t;
	t_cone	*co;

	if (obj.type != CONE)
		return (FALSE);
	co = (t_cone *)(obj.data);
	if (!chk_root(co, r, &t, lim))
		return (FALSE);
	set_hit_point(r, t, rec);
	set_normal(obj, r, co->o, rec);
	set_hit_color(co->c, obj.filter, rec);
	return (TRUE);
}

t_bool			interfere_co(t_obj obj, t_ray r, double lim)
{
	double	t;
	t_cone	*co;

	co = (t_cone *)(obj.data);
	if (!chk_root(co, r, &t, lim))
		return (FALSE);
	return (TRUE);
}
