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
	double mint[3] = {-1.0, -1.0, -1.0};
	double val = INFINITY;
	double	cos2a = cos(co->a) * cos(co->a);
	double	sin2a = 1 - cos2a;
	t_vec3	pa = add(co->p, scale(co->o, co->h));
	t_vec3	va = flip(co->o);
	t_vec3	deltaP = sub(r.p, pa);
	double c1 = dot(r.o, va);
	t_vec3 c2 = scale(va, c1);
	double c3 = dot(deltaP, va);
	t_vec3 c4 = scale(va, c3);
	double radius = co->h * tan(co->a);
	double denom = dot(r.o, co->o);
	double t1;
	double t2;
	double t3;
	t_vec3 oc = sub(co->p, r.p);
	t_bool flag = FALSE;
	double IRD = len_sqrt(r.o);

	double	a = cos2a * len_pow(sub(r.o, c2)) - sin2a * c1 * c1;
	double	h_b = cos2a * dot(sub(r.o, c2), sub(deltaP, c4)) - sin2a * (c1 * c3);
	double	c = cos2a * len_pow(sub(deltaP, c4)) - sin2a * (c3 * c3);

	if (h_b * h_b - a * c < 0)
		return (FALSE);
	t1 = (-h_b - sqrt(h_b * h_b - a * c)) / a;
	t2 = (-h_b + sqrt(h_b * h_b - a * c)) / a;
	if (t1 >= 0)
		if (dot(co->o, add(sub(r.p, co->p), scale(r.o, t1))) > 0 && dot(co->o, add(sub(r.p, pa), scale(r.o, t1))) < 0)
			mint[0] = t1;
	if (t2 >= 0)
		if (dot(co->o, add(sub(r.p, co->p), scale(r.o, t2))) > 0 && dot(co->o, add(sub(r.p, pa), scale(r.o, t2))) < 0)
			mint[1] = t2;
	if (denom > 1e-6)
	{
		t3 = dot(oc, co->o) / denom;
		if (t3 > 0 && len_pow(sub(scale(r.o, t3), oc)) <= radius * radius)
			mint[2] = t3;
	}

	int i = -1;
	while (++i < 3)
	{
		if (mint[i] != -1.0)
		{
			if (val > mint[i] && mint[i] >= 0)
			{
				val = mint[i];
				flag = TRUE;
			}
		}
	}
	if (flag)
	 	*t = val / IRD;
	else
		return (FALSE);
	if (*t > lim)
		return (FALSE);
	return (TRUE);
}

t_bool			hit_co(t_obj obj, t_ray r, double lim, t_hit *rec)
{
	double	t;
	t_cone	*co;

	if (obj.type != CONE)
		return (FALSE);
	co = (t_cone *)(obj.data);
	if (!chk_root(co, r, &t, lim))
		return (FALSE);
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




// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   cone.c                                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2021/05/05 22:09:28 by jseo              #+#    #+#             */
// /*   Updated: 2021/05/05 22:33:03 by jseo             ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "minirt.h"

// static t_bool	chk_root(t_cone *co, t_ray r, double *t, double lim)
// {
// 	t_vec3	oc;
// 	double	a;
// 	double	h_b;
// 	double	c;

// 	oc = sub(r.p, co->p);
// 	a = pow(dot(r.o, co->o), 2) - pow(cos(co->a), 2);
// 	h_b = dot(r.o, co->o) * dot(oc, co->o) - dot(r.o, oc) * pow(cos(co->a), 2);
// 	c = pow(dot(oc, co->o), 2) - dot(oc, oc) * pow(cos(co->a), 2);
// 	if (h_b * h_b - a * c < 0)
// 		return (FALSE);
// 	*t = (-h_b - sqrt(h_b * h_b - a * c)) / a;
// 	if (*t < 0.001 || *t > lim)
// 	{
// 		// *t = (-h_b + sqrt(h_b * h_b - a * c)) / a;
// 		// if (*t < 0.001 || *t > lim)
// 			return (FALSE);
// 	}
// 	return (TRUE);
// }

// t_bool			hit_co(t_obj obj, t_ray r, double lim, t_hit *rec)
// {
// 	double	t;
// 	double	h;
// 	t_vec3	p;
// 	t_cone	*co;

// 	if (obj.type != CONE)
// 		return (FALSE);
// 	co = (t_cone *)(obj.data);
// 	if (!chk_root(co, r, &t, lim))
// 		return (FALSE);
// 	p = add(r.p, scale(r.o, t));
// 	h = dot(sub(p, co->p), co->o);
// 	if (h < 0 || h > co->h)
// 		return (FALSE);
// 	set_hit_point(r, t, rec);
// 	set_normal(obj, r, co->o, rec);
// 	set_hit_color(co->c, obj.filter, rec);
// 	return (TRUE);
// }

// t_bool			interfere_co(t_obj obj, t_ray r, double lim)
// {
// 	double	t;
// 	double	h;
// 	t_cone	*co;
// 	t_vec3	p;


// 	co = (t_cone *)(obj.data);
// 	if (!chk_root(co, r, &t, lim))
// 		return (FALSE);
// 	p = add(r.p, scale(r.o, t));
// 	h = dot(sub(p, co->p), co->o);
// 	if (h < 0 || h > co->h)
// 		return (FALSE);
// 	return (TRUE);
// }
