/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 15:00:42 by jseo              #+#    #+#             */
/*   Updated: 2021/04/28 15:00:44 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool					hit_pl(t_obj obj, t_ray r, double t_max, t_hit *rec)
{
	t_obj o;
	t_ray t;
	double b;
	t_hit h;

	o = obj;
	t = r;
	b = t_max;
	h = *rec;
	return (FALSE);
}
