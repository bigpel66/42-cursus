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

	denom = v_dot(r.o, sq->o);
	if (denom == 0)
		return (FALSE);
	numer = v_dot(v_sub(sq->p, r.p), sq->o);
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

	if (fabs(sq->o.y) == 1)
		side = v_cross(sq->o, v_init(1.0, 0.0, 0.0));
	else
		side = v_cross(sq->o, v_init(0.0, 1.0, 0.0));
	v = v_sub(p, sq->p);
	cosine = fabs(v_dot(side, v) / (v_size(side) * v_size(v)));
	if (cosine < sqrt(2) / 2)
		cosine = cos(M_PI_2 - acos(cosine));
	limit = (sq->l / 2) / cosine;
	if (v_size(v) <= limit)
		return (TRUE);
	return (FALSE);
}

t_bool			hit_sq(t_obj obj, t_ray r, double lim, t_hit *rec)
{
	double		t;
	t_vec3		p;
	t_vec3		n;
	t_square	*sq;

	sq = (t_square *)(obj.data);
	if (!chk_root(sq, r, &t, lim))
		return (FALSE);
	p = v_add(r.p, v_scale(r.o, t));
	if (chk_size(sq, p))
	{
		rec->t = t;
		rec->p = p;
		rec->c = sq->c;
		n = sq->o;
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
	p = v_add(r.p, v_scale(r.o, t));
	if (chk_size(sq, p))
		return (TRUE);
	return (FALSE);
}
