/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 15:00:53 by jseo              #+#    #+#             */
/*   Updated: 2021/04/28 15:00:54 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool					hit_sp(t_obj obj, t_ray r, double t_max, t_hit *rec)
{
	t_vec3 oc;
	double a;
	double half_b;
	double c;

	double discriminant;
	double sqrtd;
	double root;
	t_vec3 outward_normal;

	oc = v_sub(r.p, ((t_sphere *)(obj.data))->p);
	a = v_size_squared(r.o);
	half_b = v_dot(oc, r.o);
	c = v_size_squared(oc) - (((t_sphere *)(obj.data))->d / 2) * (((t_sphere *)(obj.data))->d / 2);

	discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
		return (FALSE);
	sqrtd = sqrt(discriminant);
	root = (-half_b - sqrtd) / a;
	if (root < 0.001 || root > t_max)
	{
		root = (-half_b + sqrtd) / a;
		if (root < 0.001 || root > t_max)
			return (FALSE);
	}
	rec->t = root;
	rec->p = v_add(r.p, v_scale(r.o, root));
	outward_normal = v_scale(v_sub(rec->p, ((t_sphere *)(obj.data))->p), (((t_sphere *)(obj.data))->d / 2));
	rec->mat = obj.mat;
	return (TRUE);
}
