/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:50:51 by jseo              #+#    #+#             */
/*   Updated: 2021/04/19 10:47:53 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_bool	valid_square(t_scene *rt)
{
	if (!valid_vec3(rt->sq.o))
	{
		printf("Detail: Occured on square orientation\n");
		return (FALSE);
	}
	if (rt->sq.l <= 0.0)
	{
		printf("Detail: Occured on square side length\n");
		return (FALSE);
	}
	if (!valid_color(rt->sq.c))
	{
		printf("Detail: Occured on square color\n");
		return (FALSE);
	}
	return (TRUE);
}
static t_bool	parse_square(t_scene *rt, char *line)
{
	if (!sdouble(&line, &(rt->sq.p.x), &(rt->sq.p.y), &(rt->sq.p.z)))
	{
		printf("Detail: Wrong parsing square position\n");
		return (FALSE);
	}
	if (!sdouble(&line, &(rt->sq.o.x), &(rt->sq.o.y), &(rt->sq.o.z)))
	{
		printf("Detail: Wrong parsing square orientation\n");
		return (FALSE);
	}
	if (!vdouble(&line, &(rt->sq.l)))
	{
		printf("Detail: Wrong parsing square side length\n");
		return (FALSE);
	}
	if (!sint(&line, &(rt->sq.c.r), &(rt->sq.c.g), &(rt->sq.c.b)))
	{
		printf("Detail: Wrong parsing square color\n");
		return (FALSE);
	}
	return (TRUE);
}

t_bool			get_square(t_scene *rt, char *line)
{
	if (rt->sq.f)
		return (FALSE);
	rt->sq.f = TRUE;
	if (!parse_square(rt, line) || !valid_square(rt))
		return (FALSE);
	return (TRUE);
}
