/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 15:00:53 by jseo              #+#    #+#             */
/*   Updated: 2021/05/05 16:17:14 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		set_hidden_color(int m, t_vec3 n, t_hit *rec)
{
	double sine;

	sine = 0.0;
	if (m == SP_NORMAL)
	{
		n = scale(add(n, v_init(1.0, 1.0, 1.0)), 0.5);
		rec->c = c_init(255.0 * n.x, 255.0 * n.y, 255.0 * n.z);
	}
	if (m == SP_CHECKER)
	{
		sine = sin(10 * rec->p.x) * sin(10 * rec->p.y) * sin(10 * rec->p.z);
		rec->c = c_init(128, 128, 128);
		if (sine < 0)
			rec->c = c_init(255.0, 255.0, 255.0);
	}
	if (m == SP_RANDOM)
	{
		n = v_init(fabs(sin(n.x)), fabs(sin(n.y)), fabs(sin(n.z)));
		rec->c = c_init(255.0 * n.x, 255.0 * n.y, 255.0 * n.z);
	}
}

static t_bool	chk_root(t_sphere *sp, t_ray r, double *t, double lim)
{
	t_vec3	origin_to_center;
	double	a;
	double	half_b;
	double	c;

	origin_to_center = sub(r.p, sp->p);
	a = len_pow(r.o);
	half_b = dot(origin_to_center, r.o);
	c = len_pow(origin_to_center) - (sp->r * sp->r);
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

	if (obj.type != SPHERE)
		return (FALSE);
	sp = (t_sphere *)(obj.data);
	if (!chk_root(sp, r, &t, lim))
		return (FALSE);
	set_hit_point(r, t, rec);
	n = scale(sub(rec->p, sp->p), 1.0 / sp->r);
	set_normal(obj, r, n, rec);
	if (!sp->m)
		set_hit_color(sp->c, obj.filter, rec);
	else
		set_hidden_color(sp->m, unit(n), rec);
	return (TRUE);
}

t_bool			interfere_sp(t_obj obj, t_ray r, double lim)
{
	double		t;
	t_sphere	*sp;

	sp = (t_sphere *)(obj.data);
	if (!chk_root(sp, r, &t, lim))
		return (FALSE);
	return (TRUE);
}
