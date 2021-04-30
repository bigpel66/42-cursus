/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 15:32:40 by jseo              #+#    #+#             */
/*   Updated: 2021/04/30 00:08:38 by jseo             ###   ########.fr       */
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
	t_vec3		r_vec;
	t_vec3		o_vec;
	t_camera	*c;

	s = (p->x) * ((p->m->rt.r.w) / IMG_THREAD) + s;
	s = (s + randv()) / (double)(p->m->rt.r.w - 1);
	t = (t + randv()) / (double)(p->m->rt.r.h - 1);
	c = &((p->m->rt.c)[p->i]);
	r_vec = v_scale(v_rand_in_unit_disk(), c->r);
	o_vec = v_add(v_scale(c->u, r_vec.x), v_scale(c->v, r_vec.y));
	return (r_init(v_add(c->p, o_vec),
			v_sub(v_sub(v_add(c->llc,
						v_add(v_scale(c->hor, s), v_scale(c->ver, t))),
					c->p), o_vec)));
}

t_bool	r_scatter(t_ray *r, t_hit *rec, t_color *att)
{
	t_bool	ret;

	ret = FALSE;
	if (rec->mat == LAMBERTIAN)
		ret = r_diffuse(r, rec, att);
	else if (rec->mat == METAL)
		ret = r_reflect(r, rec, att);
	else if (rec->mat == DIELECTRIC)
		ret = r_refract(r, rec, att);
	return (ret);
}

t_color	r_light_color(t_mlx *m, t_light l, t_hit *rec)
{
	t_color	c;
	double	scale;
	t_bool	visible;

	visible = r_lighting(m, &l, rec, &scale);
	c.r = visible * rec->c.r * scale * 180 / M_PI * l.tc.r * 500;
	c.g = visible * rec->c.g * scale * 180 / M_PI * l.tc.g * 500;
	c.b = visible * rec->c.b * scale * 180 / M_PI * l.tc.b * 500;
	// c.r = visible * rec->c.r * l.tc.r; //* 5000;
	// c.g = visible * rec->c.g * l.tc.g; //* 5000;
	// c.b = visible * rec->c.b * l.tc.b; //* 5000;
	// ostream_color(&c, "lighting color");
	return (c);
}

// r_emitted

t_color	r_trace(t_p *p, t_ray r, int depth)
{
	int		i;
	t_hit	rec;
	t_color	att;
	t_color	emt;

	i = -1;
	if (depth <= 0)
		return (c_val(0.0, 0.0, 0.0));
	if (obj_hit(p, r, &rec, FALSE))
	{
		att.r = (p->m->rt.a.s) * p->m->rt.a.c.r * 0.001 * rec.c.r;
		att.g = (p->m->rt.a.s) * p->m->rt.a.c.g * 0.001 * rec.c.g;
		att.b = (p->m->rt.a.s) * p->m->rt.a.c.b * 0.001 * rec.c.b;
		while (++i <  p->m->rt.cnt.l)
		{
			emt = r_light_color(p->m, (p->m->rt.l)[i], &rec);
			att = c_add(att, emt);
		}
		return (att);
	}
	return (c_val(0.0, 0.0, 0.0));
	// if (!obj_hit(p, r, &rec, FALSE))
	// 	return (c_val(0.0, 0.0, 0.0));
	// att.r = (p->m->rt.a.s) * p->m->rt.a.c.r;
	// att.g = (p->m->rt.a.s) * p->m->rt.a.c.g;
	// att.b = (p->m->rt.a.s) * p->m->rt.a.c.b;
	// emt = c_val(0.0, 0.0, 0.0);
	// while (++i < p->m->rt.cnt.l)
	// 	emt = c_add(emt, r_light_color(p->m, (p->m->rt.l)[i], &rec));
	// if (!r_scatter(&r, &rec, &att))
	// 	return (c_val(0.0, 0.0, 0.0));
	// return (c_add(emt, c_mul(att, r_trace(p, r, depth - 1))));
}
