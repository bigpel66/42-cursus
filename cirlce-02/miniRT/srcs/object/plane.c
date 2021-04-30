/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 15:00:42 by jseo              #+#    #+#             */
/*   Updated: 2021/04/30 20:28:26 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_bool	chk_root(t_plane *pl, t_ray r, double *t, double lim)
{
	double	denom;
	double	numer;

	denom = v_dot(r.o, pl->o);
	if (denom == 0)
		return (FALSE);
	numer = v_dot(v_sub(pl->p, r.p), pl->o);
	*t = numer / denom;
	if (*t < 0.001 || *t > lim)
		return (FALSE);
	return (TRUE);
}

t_bool			hit_pl(t_obj obj, t_ray r, double lim, t_hit *rec)
{
	double	t;
	t_vec3	n;
	t_plane	*pl;

	pl = (t_plane *)(obj.data);
	if (!chk_root(pl, r, &t, lim))
		return (FALSE);
	rec->t = t;
	rec->p = v_add(r.p, v_scale(r.o, t));
	rec->c = pl->c;
	n = (pl->o);
	rec->n = n;
	rec->f = FRONT;
	if (v_dot(r.o, n) >= 0)
	{
		rec->n = v_flip(n);
		rec->f = BACK;
	}
	rec->mat = obj.mat;
	rec->fuzz = obj.fuzz;
	rec->ir = obj.ir;
	return (TRUE);
}

t_bool			interfere_pl(t_obj obj, t_ray r, double lim)
{
	double	empty_t;
	t_plane	*pl;

	pl = (t_plane *)(obj.data);
	if (!chk_root(pl, r, &empty_t, lim))
		return (FALSE);
	return (TRUE);
}
