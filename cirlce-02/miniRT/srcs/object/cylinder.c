/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 15:00:38 by jseo              #+#    #+#             */
/*   Updated: 2021/05/02 20:49:59 by jseo             ###   ########.fr       */
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

	v = v_sub(r.p, cy->p);
	a = v_size_squared(v_cross(r.o, cy->o));
	half_b = v_dot(v_cross(r.o, cy->o), v_cross(v, cy->o));
	c = v_size_squared(v_cross(v, cy->o)) - (cy->d / 2) * (cy->d / 2);
	if (half_b * half_b - a * c < 0)
		return (INFINITY);
	t = (-half_b - sqrt(half_b * half_b - a * c)) / a;
	if (t < 0.001 || t > lim)
	{
		t = (-half_b + sqrt(half_b * half_b - a * c)) / a;
		if (t < 0.001 || t > lim)
			return (INFINITY);
	}
	if (v_dot(cy->o, v_sub(v_add(r.p, v_scale(r.o, t)), cy->tc)) > 0)
		return (INFINITY);
	if (v_dot(cy->o, v_sub(v_add(r.p, v_scale(r.o, t)), cy->bc)) < 0)
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

	denom = v_dot(r.o, cy->o);
	if (!denom)
		return (INFINITY);
	tv = v_sub(cy->tc, r.p);
	tt = v_dot(tv, cy->o) / denom;
	if (v_size_squared(v_sub(v_add(r.p, v_scale(r.o, tt)), cy->tc)) >
		(cy->d / 2) * (cy->d / 2))
		tt = INFINITY;
	bv = v_sub(cy->bc, r.p);
	bt = v_dot(bv, cy->o) / denom;
	if (v_size_squared(v_sub(v_add(r.p, v_scale(r.o, bt)), cy->bc)) >
		(cy->d / 2) * (cy->d / 2))
		bt = INFINITY;
	if (tt < 0.001 || tt > lim)
		tt = INFINITY;
	if (bt < 0.001 || bt > lim)
		bt = INFINITY;
	if (tt < bt)
		return (tt);
	else
		return (bt);
}

static void		result_by_rectangle(t_cylinder *cy, t_ray r, t_hit *rec, double t)
{
	t_vec3	n;
	t_vec3	cc;

	rec->t = t;
	rec->p = v_add(r.p, v_scale(r.o, t));
	cc = v_scale(cy->o, v_dot(cy->o, v_sub(rec->p, cy->p)));
	cc = v_add(cc, cy->p);
	n = v_unit(v_sub(rec->p, cc));
	rec->n = n;
	rec->f = FRONT;
	if (v_dot(r.o, n) >= 0)
	{
		rec->n = v_flip(n);
		rec->f = BACK;
	}
}

static void		result_by_circle(t_cylinder *cy, t_ray r, t_hit *rec, double t)
{
	rec->t = t;
	rec->p = v_add(r.p, v_scale(r.o, t));
	rec->n = cy->o;
	rec->f = FRONT;
	if (v_dot(r.o, rec->n) >= 0)
	{
		rec->n = v_flip(rec->n);
		rec->f = BACK;
	}
}

t_bool			hit_cy(t_obj obj, t_ray r, double lim, t_hit *rec)
{
	t_cylinder	*cy;
	double		r_t;
	double		c_t;

	cy = (t_cylinder *)(obj.data);
	r_t = root_rectangle(cy, r, lim);
	c_t = root_circle(cy, r, lim);
	if (r_t == INFINITY && c_t == INFINITY)
		return (FALSE);
	if (r_t < c_t)
		result_by_rectangle(cy, r, rec, r_t);
	else
		result_by_circle(cy, r, rec, c_t);
	rec->c = cy->c;
	rec->mat = obj.mat;
	rec->fuzz = obj.fuzz;
	rec->ir = obj.ir;
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
