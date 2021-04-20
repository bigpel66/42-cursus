/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:50:39 by jseo              #+#    #+#             */
/*   Updated: 2021/04/20 11:18:23 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		plane_to_string(t_scene *rt)
{
	printf("pl position: %f %f %f\n", rt->pl.p.x, rt->pl.p.y, rt->pl.p.z);
	printf("pl orientation: %f %f %f\n", rt->pl.o.x, rt->pl.o.y, rt->pl.o.z);
	printf("pl color: %d %d %d\n", rt->pl.c.r, rt->pl.c.g, rt->pl.c.b);
}

static t_bool	valid_plane(t_scene *rt)
{
	t_bool	ret;

	ret = TRUE;
	if (!valid_vec3(rt->pl.o))
		ret = FALSE;
	if (!valid_color(rt->pl.c))
		ret = FALSE;
	if (!ret)
		printf("Detail: Invalid plane value\n");
	return (ret);
}

static t_bool	parse_plane(t_scene *rt, char *line)
{
	t_bool	ret;

	ret = TRUE;
	if (!sdouble(&line, &(rt->pl.p.x), &(rt->pl.p.y), &(rt->pl.p.z)))
		ret = FALSE;
	if (!sdouble(&line, &(rt->pl.o.x), &(rt->pl.o.y), &(rt->pl.o.z)))
		ret = FALSE;
	if (!sint(&line, &(rt->pl.c.r), &(rt->pl.c.g), &(rt->pl.c.b)))
		ret = FALSE;
	plane_to_string(rt);
	if (!is_endl(line))
	{
		printf("Detail: More info than expected on plane\n");
		return (FALSE);
	}
	if (!ret)
		printf("Detail: Wrong parsing plane\n");
	return (ret);
}

t_bool			get_plane(t_scene *rt, char *line)
{
	if (rt->pl.f)
	{
		printf("Detail: Duplicated info on plane\n");
		return (FALSE);
	}
	rt->pl.f = TRUE;
	if (!parse_plane(rt, line) || !valid_plane(rt))
		return (FALSE);
	return (TRUE);
}
