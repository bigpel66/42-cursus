/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 15:00:38 by jseo              #+#    #+#             */
/*   Updated: 2021/05/05 21:48:14 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	root_rectangle(t_cylinder *cy, t_ray r, double lim)
{
	t_vec3	v;
	double	a;
	double	half_b;
	double	c;
	double	t;

	v = sub(r.p, cy->p);
	a = len_pow(cross(r.o, cy->o));
	half_b = dot(cross(r.o, cy->o), cross(v, cy->o));
	c = len_pow(cross(v, cy->o)) - cy->r * cy->r;
	if (half_b * half_b - a * c < 0)
		return (INFINITY);
	t = (-half_b - sqrt(half_b * half_b - a * c)) / a;
	if (t < 0.001 || t > lim)
	{
		t = (-half_b + sqrt(half_b * half_b - a * c)) / a;
		if (t < 0.001 || t > lim)
			return (INFINITY);
	}
	if (dot(cy->o, sub(add(r.p, scale(r.o, t)), cy->tc)) > 0)
		return (INFINITY);
	if (dot(cy->o, sub(add(r.p, scale(r.o, t)), cy->bc)) < 0)
		return (INFINITY);
	return (t);
}

static double	root_circle(t_cylinder *cy, t_ray r, double lim)
{
	t_vec3	tv;
	t_vec3	bv;
	double	denom;
	double	tt;
	double	bt;

	denom = dot(r.o, cy->o);
	if (!denom)
		return (INFINITY);
	tv = sub(cy->tc, r.p);
	tt = dot(tv, cy->o) / denom;
	if (len_pow(sub(add(r.p, scale(r.o, tt)), cy->tc)) > cy->r * cy->r)
		tt = INFINITY;
	bv = sub(cy->bc, r.p);
	bt = dot(bv, cy->o) / denom;
	if (len_pow(sub(add(r.p, scale(r.o, bt)), cy->bc)) > cy->r * cy->r)
		bt = INFINITY;
	if (tt < 0.001 || tt > lim)
		tt = INFINITY;
	if (bt < 0.001 || bt > lim)
		bt = INFINITY;
	if (tt < bt)
		return (tt);
	return (bt);
}

t_bool			hit_cy(t_obj obj, t_ray r, double lim, t_hit *rec)
{
	t_cylinder	*cy;
	double		r_t;
	double		c_t;

	if (obj.type != CYLINDER)
		return (FALSE);
	cy = (t_cylinder *)(obj.data);
	r_t = root_rectangle(cy, r, lim);
	c_t = root_circle(cy, r, lim);
	if (r_t == INFINITY && c_t == INFINITY)
		return (FALSE);
	if (r_t < c_t)
	{
		set_hit_point(r, r_t, rec);
		set_normal(obj, r, unit(sub(rec->p, add(scale(cy->o,
			dot(cy->o, sub(rec->p, cy->p))), cy->p))), rec);
	}
	else
	{
		set_hit_point(r, c_t, rec);
		set_normal(obj, r, cy->o, rec);
	}
	set_hit_color(cy->c, obj.filter, rec);
	return (TRUE);
}

t_bool			interfere_cy(t_obj obj, t_ray r, double lim)
{
	t_cylinder	*cy;
	double		r_t;
	double		c_t;

	cy = (t_cylinder *)(obj.data);
	r_t = root_rectangle(cy, r, lim);
	c_t = root_circle(cy, r, lim);
	if (r_t == INFINITY && c_t == INFINITY)
		return (FALSE);
	return (TRUE);
}
