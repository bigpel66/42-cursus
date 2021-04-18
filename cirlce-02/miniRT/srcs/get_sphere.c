/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:50:47 by jseo              #+#    #+#             */
/*   Updated: 2021/04/18 23:15:20 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_bool	valid_sphere(t_mlx *m)
{
	if (m->i.sp.r <= 0.0)
	{
		printf("Detail: Occured on sphere radius\n");
		return (FALSE);
	}
	if (!valid_color(m->i.sp.c))
	{
		printf("Detail: Occured on sphere color\n");
		return (FALSE);
	}
	return (TRUE);
}

t_bool			get_sphere(t_mlx *m, char *line)
{
	if (m->i.sp.f)
		return (FALSE);
	m->i.sp.f = TRUE;
	sdouble(&line, &(m->i.sp.p.x), &(m->i.sp.p.y), &(m->i.sp.p.z));
	m->i.sp.r = vdouble(&line) / 2;
	sint(&line, &(m->i.sp.c.r), &(m->i.sp.c.g), &(m->i.sp.c.b));
	if (!valid_sphere(m))
		return (FALSE);
	return (TRUE);
}
