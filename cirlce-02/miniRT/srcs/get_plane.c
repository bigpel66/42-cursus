/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:50:39 by jseo              #+#    #+#             */
/*   Updated: 2021/04/18 23:15:10 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_bool	valid_plane(t_mlx *m)
{
	if (!valid_vec3(m->i.pl.d))
	{
		printf("Detail: Occured on plane direction\n");
		return (FALSE);
	}
	if (!valid_color(m->i.pl.c))
	{
		printf("Detail: Occured on plane color\n");
		return (FALSE);
	}
	return (TRUE);
}

t_bool			get_plane(t_mlx *m, char *line)
{
	if (m->i.pl.f)
		return (FALSE);
	m->i.pl.f = TRUE;
	sdouble(&line, &(m->i.pl.p.x), &(m->i.pl.p.y), &(m->i.pl.p.z));
	sdouble(&line, &(m->i.pl.d.x), &(m->i.pl.d.y), &(m->i.pl.d.z));
	sint(&line, &(m->i.pl.c.r), &(m->i.pl.c.g), &(m->i.pl.c.b));
	if (!valid_plane(m))
		return (FALSE);
	return (TRUE);
}
