/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 22:09:28 by jseo              #+#    #+#             */
/*   Updated: 2021/05/05 22:33:03 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_bool	chk_root(t_cone *co, t_ray r, double *t, double lim)
{
	t_vec3	oc;
	double	a;
	double	h_b;
	double	c;

	oc = sub(r.p, co->p);
	a = pow(dot(r.o, co->o), 2) - pow(cos(co->a), 2);
	h_b = dot(r.o, co->o) * dot(oc, co->o) - dot(r.o, oc) * pow(cos(co->a), 2);
	c = pow(dot(oc, co->o), 2) - dot(oc, oc) * pow(cos(co->a), 2);
	// v = sub(r.p, co->p);
	// a = pow(cos(co->a * len_pow(cross(r.o, co->o))), 2.0);
	// a -= pow(sin(co->a * pow(dot(r.o, co->o), 2.0)), 2.0);
	// h_b = pow(cos(co->a * dot(cross(r.o, co->o), cross(v, co->o))), 2.0);
	// h_b -= pow(sin(co->a * dot(r.o, co->o) * dot(v, co->o)), 2.0);
	// c = pow(cos(co->a * len_pow(cross(v, co->o))), 2.0);
	// c -= pow(sin(co->a * pow(dot(v, co->o), 2.0)), 2.0);
	if (h_b * h_b - a * c < 0)
		return (FALSE);
	*t = (-h_b - sqrt(h_b * h_b - a * c)) / a;
	if (*t < 0.001 || *t > lim)
	{
		*t = (-h_b + sqrt(h_b * h_b - a * c)) / a;
		if (*t < 0.001 || *t > lim)
			return (FALSE);
	}
	return (TRUE);
}

t_bool			hit_co(t_obj obj, t_ray r, double lim, t_hit *rec)
{
	double	t;
	t_vec3	p;
	t_cone	*co;

	if (obj.type != CONE)
		return (FALSE);
	co = (t_cone *)(obj.data);
	if (!chk_root(co, r, &t, lim))
		return (FALSE);
	p = add(r.p, scale(r.o, t));
	// if (dot(sub(p, co->p), co->o) > 0)
	// 	return (FALSE);
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
