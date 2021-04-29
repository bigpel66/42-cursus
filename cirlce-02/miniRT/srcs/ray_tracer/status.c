/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 15:32:40 by jseo              #+#    #+#             */
/*   Updated: 2021/04/27 14:55:05 by jseo             ###   ########.fr       */
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

t_color	r_trace(t_p *p, t_ray r, int depth)
{
	t_hit	rec;
	t_color	att;
	double	t;

	if (depth <= 0)
		return (c_val(0.0, 0.0, 0.0));
	if (obj_hit(p, r, &rec, FALSE))
	{
		if (r_scatter(&r, &rec, &att))
			return (c_mul(att, r_trace(p, r, depth - 1)));
		return (c_val(0.0, 0.0, 0.0));
	}
	t = ((v_unit(r.o)).y + 1.0) * 0.5;
	return (c_val(1.0 - 0.5 * t, 1.0 - 0.3 * t, 1.0));
}
