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

static t_color	set_texture_color(t_obj o, t_hit *rec)
{
	double	u;
	double	v;
	int		offset;
	t_color	c;

	u = clamp((atan2(-(rec->n.z), rec->n.x) + M_PI) / (2 * M_PI), 0.0, 1.0);
	v = 1.0 - clamp(acos(-(rec->n.y)) / M_PI, 0.0, 1.0);
	u = (double)((int)(u * o.txr->width));
	v = (double)((int)(v * o.txr->height));
	if (u >= o.txr->width)
		u = o.txr->width - 1;
	if (v >= o.txr->height)
		v = o.txr->height - 1;
	offset = (o.txr->b_h + o.txr->d_h) + v * o.txr->sl + u * (o.txr->bpp / 8);
	c.b = *((o.txr->color) + offset++);
	c.g = *((o.txr->color) + offset++);
	c.r = *((o.txr->color) + offset);
	return (c);
}

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
	t_vec3	oc;
	double	a;
	double	h_b;
	double	c;

	oc = sub(r.p, sp->p);
	a = len_pow(r.o);
	h_b = dot(oc, r.o);
	c = len_pow(oc) - (sp->r * sp->r);
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
	if (!sp->m && !sp->f)
		set_hit_color(sp->c, obj.filter, rec);
	else if (!sp->m && sp->f)
		set_hit_color(set_texture_color(obj, rec), obj.filter, rec);
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
