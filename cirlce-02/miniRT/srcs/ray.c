/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 15:32:40 by jseo              #+#    #+#             */
/*   Updated: 2021/04/30 15:06:38 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	r_init(t_vec3 p, t_vec3 o)
{
	t_ray	r;

	r.p = p;
	r.o = o;
	return (r);
}

t_ray	r_corr(t_p *p, double s, double t)
{
	t_camera	*c;
	t_vec3		o;

	s = (p->x) * ((p->m->rt.r.w) / IMG_THREAD) + s;
	s = (s + randv()) / (double)(p->m->rt.r.w - 1);
	t = (t + randv()) / (double)(p->m->rt.r.h - 1);
	c = &((p->m->rt.c)[p->i]);
	o.x = c->llc.x + c->hor.x * s + c->ver.x * t - c->p.x;
	o.y = c->llc.y + c->hor.y * s + c->ver.y * t - c->p.y;
	o.z = c->llc.z + c->hor.z * s + c->ver.z * t - c->p.z;
	return (r_init(c->p, v_unit(o)));
}

t_bool	r_lighting(t_mlx *m, t_light *l, t_hit *rec, double *scale)
{
	t_ray	r;
	double	radius_squared;

	l->to = v_sub(rec->p, l->p);
	radius_squared = v_size_squared(l->to);
	l->td = sqrt(radius_squared);
	l->to = v_unit(l->to);
	l->tc = c_init(l->c.r * l->s, l->c.g * l->s, l->c.b * l->s);
	l->tc.r = l->tc.r / (4 * M_PI * radius_squared);
	l->tc.g = l->tc.g / (4 * M_PI * radius_squared);
	l->tc.b = l->tc.b / (4 * M_PI * radius_squared);
	r = r_init(v_add(rec->p, v_scale(rec->n, 1e-4)), v_flip(l->to));
	*scale = v_dot(rec->n, v_flip(l->to));
	if (*scale < 0)
		*scale = 0;
	return (obj_visible(m->obj, m->rt.cnt.obj, r, l->td));
}

t_color	r_light_color(t_mlx *m, t_light l, t_hit *rec)
{
	t_color	c;
	double	scale;
	t_bool	visible;

	visible = r_lighting(m, &l, rec, &scale);
	c.r = visible * rec->c.r * scale * 180 / M_PI * l.tc.r * 5;
	c.g = visible * rec->c.g * scale * 180 / M_PI * l.tc.g * 5;
	c.b = visible * rec->c.b * scale * 180 / M_PI * l.tc.b * 5;
	return (c);
}

t_color	r_trace(t_p *p, t_ray r, int depth)
{
	int		i;
	t_hit	rec;
	t_color	att;
	t_color	emt;

	i = -1;
	if (depth <= 0)
		return (c_init(0.0, 0.0, 0.0));
	if (obj_hit(p, r, &rec, FALSE))
	{
		att.r = (p->m->rt.a.s) * p->m->rt.a.c.r * 0.001 * rec.c.r;
		att.g = (p->m->rt.a.s) * p->m->rt.a.c.g * 0.001 * rec.c.g;
		att.b = (p->m->rt.a.s) * p->m->rt.a.c.b * 0.001 * rec.c.b;
		emt = c_init(0.0, 0.0, 0.0);
		while (++i < p->m->rt.cnt.l)
			emt = c_add(emt, r_light_color(p->m, (p->m->rt.l)[i], &rec));
		if (r_scatter(&r, &rec))
		{
			if (rec.mat == METAL || rec.mat == DIELECTRIC)
				return (c_add(c_add(att, emt), r_trace(p, r, depth - 1)));
			return (c_add(att, emt));
		}
		return (c_init(0.0, 0.0, 0.0));
	}
	return (c_init(0.0, 0.0, 0.0));
}
