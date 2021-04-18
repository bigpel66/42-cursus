/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_triangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:50:55 by jseo              #+#    #+#             */
/*   Updated: 2021/04/18 23:15:31 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_bool	valid_triangle(t_mlx *m)
{
	if (!valid_color(m->i.tr.c))
	{
		printf("Detail: Occured on triangle color\n");
		return (FALSE);
	}
	return (TRUE);
}

t_bool			get_triangle(t_mlx *m, char *line)
{
	if (m->i.tr.f)
		return (FALSE);
	m->i.tr.f = TRUE;
	sdouble(&line, &(m->i.tr.p1.x), &(m->i.tr.p1.y), &(m->i.tr.p1.z));
	sdouble(&line, &(m->i.tr.p2.x), &(m->i.tr.p2.y), &(m->i.tr.p2.z));
	sdouble(&line, &(m->i.tr.p3.x), &(m->i.tr.p3.y), &(m->i.tr.p3.z));
	sint(&line, &(m->i.tr.c.r), &(m->i.tr.c.g), &(m->i.tr.c.b));
	if (!valid_triangle(m))
		return (FALSE);
	return (TRUE);
}
