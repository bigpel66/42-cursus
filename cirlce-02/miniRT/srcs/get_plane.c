/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:50:39 by jseo              #+#    #+#             */
/*   Updated: 2021/04/19 10:50:14 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_bool	valid_plane(t_scene *rt)
{
	if (!valid_vec3(rt->pl.o))
	{
		printf("Detail: Invalid plane orientation\n");
		return (FALSE);
	}
	if (!valid_color(rt->pl.c))
	{
		printf("Detail: Invalid plane color\n");
		return (FALSE);
	}
	return (TRUE);
}

static t_bool	parse_plane(t_scene *rt, char *line)
{
	if (!sdouble(&line, &(rt->pl.p.x), &(rt->pl.p.y), &(rt->pl.p.z)))
	{
		printf("Detail: Wrong parsing plane position\n");
		return (FALSE);
	}
	if (!sdouble(&line, &(rt->pl.o.x), &(rt->pl.o.y), &(rt->pl.o.z)))
	{
		printf("Detail: Wrong parsing plane orientation\n");
		return (FALSE);
	}
	if (!sint(&line, &(rt->pl.c.r), &(rt->pl.c.g), &(rt->pl.c.b)))
	{
		printf("Detail: Wrong parsing  plane color\n");
		return (FALSE);
	}
	return (TRUE);
}

t_bool			get_plane(t_scene *rt, char *line)
{
	if (rt->pl.f)
		return (FALSE);
	rt->pl.f = TRUE;
	if (!parse_plane(rt, line) || !valid_plane(rt))
		return (FALSE);
	return (TRUE);
}
