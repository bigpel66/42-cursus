/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_triangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:50:55 by jseo              #+#    #+#             */
/*   Updated: 2021/04/19 10:40:15 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_bool	valid_triangle(t_scene *rt)
{
	if (!valid_color(rt->tr.c))
	{
		printf("Detail: Invalid triangle color\n");
		return (FALSE);
	}
	return (TRUE);
}

static t_bool	parse_triangle(t_scene *rt, char *line)
{
	if (!sdouble(&line, &(rt->tr.p1.x), &(rt->tr.p1.y), &(rt->tr.p1.z)))
	{
		printf("Detail: Wrong parsing triangle position1\n");
		return (FALSE);
	}
	if (!sdouble(&line, &(rt->tr.p2.x), &(rt->tr.p2.y), &(rt->tr.p2.z)))
	{
		printf("Detail: Wrong parsing triangle position2\n");
		return (FALSE);
	}
	if (!sdouble(&line, &(rt->tr.p3.x), &(rt->tr.p3.y), &(rt->tr.p3.z)))
	{
		printf("Detail: Wrong parsing triangle position3\n");
		return (FALSE);
	}
	if (!sint(&line, &(rt->tr.c.r), &(rt->tr.c.g), &(rt->tr.c.b)))
	{
		printf("Detail: Wrong parsing triangle color\n");
		return (FALSE);
	}
	return (TRUE);
}

t_bool			get_triangle(t_scene *rt, char *line)
{
	if (rt->tr.f)
		return (FALSE);
	rt->tr.f = TRUE;
	if (!parse_triangle(rt, line) || !valid_triangle(rt))
		return (FALSE);
	return (TRUE);
}
