/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 15:00:42 by jseo              #+#    #+#             */
/*   Updated: 2021/05/02 20:50:08 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_bool	chk_root(t_plane *pl, t_ray r, double *t, double lim)
{
	double	denom;
	double	numer;

	denom = dot(r.o, pl->n);
	if (!denom)
		return (FALSE);
	numer = dot(sub(pl->p, r.p), pl->n);
	*t = numer / denom;
	if (*t < 0.001 || *t > lim)
		return (FALSE);
	return (TRUE);
}

t_bool			hit_pl(t_obj obj, t_ray r, double lim, t_hit *rec)
{
	double	t;
	t_plane	*pl;

	pl = (t_plane *)(obj.data);
	if (!chk_root(pl, r, &t, lim))
		return (FALSE);
	set_hit_color(pl->c, obj.filter, rec);
	set_hit_point(r, t, rec);
	set_normal(obj, r, pl->n, rec);
	return (TRUE);
}

t_bool			interfere_pl(t_obj obj, t_ray r, double lim)
{
	double	t;
	t_plane	*pl;

	pl = (t_plane *)(obj.data);
	if (!chk_root(pl, r, &t, lim))
		return (FALSE);
	return (TRUE);
}
