/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 15:00:53 by jseo              #+#    #+#             */
/*   Updated: 2021/04/28 18:07:49 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_bool	chk_root(t_sphere *sp, t_ray r, double *t, double lim)
{
	t_vec3	origin_to_center;
	double	a;
	double	half_b;
	double	c;

	origin_to_center = v_sub(r.p, sp->p);
	a = v_size_squared(r.o);
	half_b = v_dot(origin_to_center, r.o);
	c = v_size_squared(origin_to_center) - (sp->d / 2.0) * (sp->d / 2.0);
	if (half_b * half_b - a * c < 0)
		return (FALSE);
	*t = (-half_b - sqrt(half_b * half_b - a * c)) / a;
	if (*t < 0.001 || *t > lim)
	{
		*t = (-half_b + sqrt(half_b * half_b - a * c)) / a;
		if (*t < 0.001 || *t > lim)
			return (FALSE);
	}
	return (TRUE);
}

t_bool			hit_sp(t_obj obj, t_ray r, double lim, t_hit *rec)
{
	double		t;
	t_vec3		n;
	t_sphere	*sp;

	sp = (t_sphere *)(obj.data);
	if (!chk_root(sp, r, &t, lim))
		return (FALSE);
	rec->t = t;
	rec->p = v_add(r.p, v_scale(r.o, t));
	n = v_scale(v_sub(rec->p, sp->p), sp->d / 2.0);
	rec->n = n;
	rec->f = FRONT;
	if (v_dot(r.o, n) >= 0)
	{
		rec->n = v_flip(n);
		rec->f = BACK;
	}
	rec->c = sp->c;
	rec->mat = obj.mat;
	rec->fuzz = obj.fuzz;
	rec->ir = obj.ir;
	return (TRUE);
}
