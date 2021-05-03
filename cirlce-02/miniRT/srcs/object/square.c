/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 15:00:57 by jseo              #+#    #+#             */
/*   Updated: 2021/05/02 20:50:31 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_bool	chk_root(t_square *sq, t_ray r, double *t, double lim)
{
	double	denom;
	double	numer;

	denom = dot(r.o, sq->n);
	if (!denom)
		return (FALSE);
	numer = dot(sub(sq->p, r.p), sq->n);
	*t = numer / denom;
	if (*t < 0.001 || *t > lim)
		return (FALSE);
	return (TRUE);
}

static t_bool	chk_size(t_square *sq, t_vec3 p)
{
	t_vec3	v;
	t_vec3	side;
	double	cosine;
	double	limit;

	if (fabs(sq->n.y) == 1)
		side = cross(sq->n, v_init(1.0, 0.0, 0.0));
	else
		side = cross(sq->n, v_init(0.0, 1.0, 0.0));
	v = sub(p, sq->p);
	cosine = fabs(dot(side, v) / (len_sqrt(side) * len_sqrt(v)));
	if (cosine < sqrt(2) / 2)
		cosine = cos(M_PI_2 - acos(cosine));
	limit = (sq->l / 2) / cosine;
	if (len_sqrt(v) <= limit)
		return (TRUE);
	return (FALSE);
}

t_bool			hit_sq(t_obj obj, t_ray r, double lim, t_hit *rec)
{
	double		t;
	t_vec3		p;
	t_square	*sq;

	sq = (t_square *)(obj.data);
	if (!chk_root(sq, r, &t, lim))
		return (FALSE);
	p = add(r.p, scale(r.o, t));
	if (chk_size(sq, p))
	{
		set_hit_point(r, sq->c, t, rec);
		set_normal(obj, r, sq->n, rec);
		return (TRUE);
	}
	return (FALSE);
}

t_bool			interfere_sq(t_obj obj, t_ray r, double lim)
{
	double		t;
	t_vec3		p;
	t_square	*sq;

	sq = (t_square *)(obj.data);
	if (!chk_root(sq, r, &t, lim))
		return (FALSE);
	p = add(r.p, scale(r.o, t));
	if (chk_size(sq, p))
		return (TRUE);
	return (FALSE);
}
