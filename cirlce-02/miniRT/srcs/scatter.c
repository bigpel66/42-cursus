/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scatter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 17:21:35 by jseo              #+#    #+#             */
/*   Updated: 2021/04/30 17:21:39 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_bool	r_diffuse(t_ray *r, t_hit *rec)
{
	t_vec3	v;

	v = v_add(rec->n, v_rand_unit());
	if (v_near_zero(v))
		v = rec->n;
	*r = r_init(rec->p, v);
	return (TRUE);
}

static t_bool	r_reflect(t_ray *r, t_hit *rec)
{
	t_vec3	v;

	v = v_reflect(v_unit(r->o), rec->n);
	*r = r_init(rec->p, v_add(v, v_scale(v_rand_in_unit_sphere(), rec->fuzz)));
	return (v_dot(r->o, rec->n) > 0.0);
}

static double	reflectance(double cosine, double ref_idx)
{
	double	r0;

	r0 = (1 - ref_idx) / (1 + ref_idx);
	r0 = r0 * r0;
	return (r0 + (1 - r0) * pow((1 - cosine), 5));
}

static t_bool	r_refract(t_ray *r, t_hit *rec)
{
	double	ratio;
	double	cosine;
	double	sine;
	t_vec3	v;

	ratio = rec->ir;
	if (rec->f)
		ratio = 1.0 / rec->ir;
	r->o = v_unit(r->o);
	cosine = fmin(v_dot(v_flip(r->o), rec->n), 1.0);
	sine = sqrt(1.0 - cosine * cosine);
	if (ratio * sine > 1.0 || reflectance(cosine, ratio) > randv())
		v = v_reflect(r->o, rec->n);
	else
		v = v_refract(r->o, rec->n, ratio);
	*r = r_init(rec->p, v);
	return (TRUE);
}

t_bool			r_scatter(t_ray *r, t_hit *rec)
{
	t_bool	ret;

	ret = FALSE;
	if (rec->mat == LAMBERTIAN)
		ret = r_diffuse(r, rec);
	else if (rec->mat == METAL)
		ret = r_reflect(r, rec);
	else if (rec->mat == DIELECTRIC)
		ret = r_refract(r, rec);
	return (ret);
}
