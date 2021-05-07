/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scatter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 17:21:35 by jseo              #+#    #+#             */
/*   Updated: 2021/05/07 17:38:33 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_bool	r_lambertian(t_ray *r, t_hit *rec)
{
	t_vec3	v;

	v = add(rec->n, v_rand_unit());
	if (near_zero(v))
		v = rec->n;
	*r = r_init(rec->p, v);
	return (TRUE);
}

static t_bool	r_metal(t_ray *r, t_hit *rec)
{
	t_vec3	v;

	v = reflect(unit(r->o), rec->n);
	*r = r_init(rec->p, add(v, scale(v_rand_in_unit_sphere(), rec->fuzz)));
	return (dot(r->o, rec->n) > 0.0);
}

static double	reflectance(double cosine, double ref_idx)
{
	double	r0;

	r0 = (1 - ref_idx) / (1 + ref_idx);
	r0 = r0 * r0;
	return (r0 + (1 - r0) * pow((1 - cosine), 5));
}

static t_bool	r_dielectric(t_ray *r, t_hit *rec)
{
	double	ratio;
	double	cosine;
	double	sine;
	t_vec3	v;

	ratio = rec->ir;
	if (rec->f)
		ratio = 1.0 / rec->ir;
	r->o = unit(r->o);
	cosine = fmin(dot(flip(r->o), rec->n), 1.0);
	sine = sqrt(1.0 - cosine * cosine);
	if (ratio * sine > 1.0 || reflectance(cosine, ratio) > randv())
		v = reflect(r->o, rec->n);
	else
		v = refract(r->o, rec->n, ratio);
	*r = r_init(rec->p, v);
	return (TRUE);
}

t_bool			r_scatter(t_ray *r, t_hit *rec)
{
	t_bool	ret;

	ret = FALSE;
	if (rec->mat == LAMBERTIAN)
		ret = r_lambertian(r, rec);
	else if (rec->mat == METAL)
		ret = r_metal(r, rec);
	else if (rec->mat == DIELECTRIC)
		ret = r_dielectric(r, rec);
	return (ret);
}
