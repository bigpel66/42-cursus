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

t_bool	r_diffuse(t_ray *r, t_hit *rec, t_color *att)
{
	t_vec3 scatter_direction;

	scatter_direction = v_add(rec->n, v_rand_unit());
	if (v_near_zero(scatter_direction))
		scatter_direction = rec->n;
	*r = r_init(rec->p, scatter_direction);
	*att = rec->c;
	return (TRUE);
}

t_bool	r_reflect(t_ray *r, t_hit *rec, t_color *att)
{
	t_vec3 reflected;

	reflected = v_reflect(v_unit(r->o), rec->n);
	*r = r_init(rec->p, v_add(reflected, v_scale(v_rand_in_unit_sphere(), rec->fuzz)));
	*att = rec->c;
	return (v_dot(r->o, rec->n) > 0.0);
}

static double reflectance(double cosine, double ref_idx)
{
	double r0;

	r0 = (1 - ref_idx)/ (1 + ref_idx);
	r0 = r0 * r0;
	return (r0 + (1 - r0) * pow((1 - cosine), 5));
}

t_bool	r_refract(t_ray *r, t_hit *rec, t_color *att)
{
	double refraction_ratio;
	t_vec3 unit_direction;
	double cos_theta;
	double sin_theta;
	t_bool cannot_refract;
	t_vec3 direction;

	*att = c_val(1.0, 1.0, 1.0);
	refraction_ratio = rec->f ? (1.0 / rec->ir) : rec->ir;
	unit_direction = v_unit(r->o);
	cos_theta = fmin(v_dot(v_flip(unit_direction), rec->n), 1.0);
	sin_theta = sqrt(1.0 - cos_theta * cos_theta);
	cannot_refract = refraction_ratio * sin_theta > 1.0;
	if (cannot_refract || reflectance(cos_theta, refraction_ratio) > randv())
		direction = v_reflect(unit_direction, rec->n);
	else
		direction = v_refract(unit_direction, rec->n, refraction_ratio);
	*r = r_init(rec->p, direction);
	return(TRUE);
}
