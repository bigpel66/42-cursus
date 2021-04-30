/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 18:07:12 by jseo              #+#    #+#             */
/*   Updated: 2021/04/28 18:07:14 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	r_diffuse(t_ray *r, t_hit *h, t_color *att)
{
	t_vec3 v;

	v = v_add(h->n, v_rand_unit());
	if (v_near_zero(v))
		v = h->n;
	*r = r_init(h->p, v);
	*att = c_mul(*att, h->c);
	return (TRUE);
}

t_bool	r_reflect(t_ray *r, t_hit *h, t_color *att)
{
	t_vec3 v;

	v = v_reflect(v_unit(r->o), h->n);
	*r = r_init(h->p, v_add(v, v_scale(v_rand_in_unit_sphere(), h->fuzz)));
	*att = c_mul(*att, h->c);
	return (v_dot(r->o, h->n) > 0.0);
}

static double reflectance(double cosine, double ref_idx)
{
	double r0;

	r0 = (1 - ref_idx)/ (1 + ref_idx);
	r0 = r0 * r0;
	return (r0 + (1 - r0) * pow((1 - cosine), 5));
}

t_bool	r_refract(t_ray *r, t_hit *h, t_color *att)
{
	double ratio;
	double cosine;
	double sine;
	t_vec3 v;

	*att = c_mul(*att, c_val(1.0, 1.0, 1.0));
	ratio = h->ir;
	if (h->f)
		ratio = 1.0 / h->ir;
	r->o = v_unit(r->o);
	cosine = fmin(v_dot(v_flip(r->o), h->n), 1.0);
	sine = sqrt(1.0 - cosine * cosine);
	if (ratio * sine > 1.0 || reflectance(cosine, ratio) > randv())
		v = v_reflect(r->o, h->n);
	else
		v = v_refract(r->o, h->n, ratio);
	*r = r_init(h->p, v);
	return(TRUE);
}

t_bool	r_lighting(t_mlx *m, t_light *l, t_hit *rec, double *scale)
{
	t_ray r;
	double radius_squared;

	l->to = v_sub(rec->p, l->p);
	radius_squared = v_size_squared(l->to);
	l->td = sqrt(radius_squared);
	l->to = v_unit(l->to);
	l->tc = c_val(l->c.r * l->s, l->c.g * l->s, l->c.b * l->s);
	l->tc.r = l->tc.r / (4 * M_PI * radius_squared);
	l->tc.g = l->tc.g / (4 * M_PI * radius_squared);
	l->tc.b = l->tc.b / (4 * M_PI * radius_squared);
	r = r_init(v_add(rec->p, v_scale(rec->n, 1e-4)), v_flip(l->to));
	*scale = v_dot(rec->n, v_flip(l->to));
	if (*scale < 0)
		*scale = 0;
	return (obj_visible(m->obj, m->rt.cnt.obj, r, l->td));
}
