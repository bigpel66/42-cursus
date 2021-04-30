/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 15:00:42 by jseo              #+#    #+#             */
/*   Updated: 2021/04/28 18:07:45 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	hit_pl(t_obj obj, t_ray r, double lim, t_hit *rec)
{
	// double t;
	// t_vec3 n;
	// t_plane *pl;

	// pl = (t_plane *)(obj.data);
	// if (!chk_root(pl, r, &t, lim))
	// 	return (FALSE);
	// rec->t = t;
	// rec->p = v_add(r.p, v_scale(r.o, t));
	// n = v_sub(v_sub(v_scale(pl->o, 2.0), v_init(1.0, 1.0, 1.0)), );

	void *p1;
	void *p2;
	void *p3;
	void *p4;
	p1 = &obj;
	p2 = &r;
	p3 = &lim;
	p4 = rec;
	return (FALSE);
}

t_bool	interfere_pl(t_obj obj, t_ray r, double lim)
{
	void *p1;
	void *p2;
	void *p3;

	p1 = &obj;
	p2 = &r;
	p3 = &lim;
	return (TRUE);
}
