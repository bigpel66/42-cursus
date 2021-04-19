/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ambient.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:50:23 by jseo              #+#    #+#             */
/*   Updated: 2021/04/19 13:55:32 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		ambient_to_string(t_scene *rt)
{
	printf("ambient ratio: %lf\n", rt->a.s);
	printf("ambient color: %d %d %d\n", rt->a.c.r, rt->a.c.g, rt->a.c.b);
}

static t_bool	valid_ambient(t_scene *rt)
{
	if (rt->a.s < 0.0 || rt->a.s > 1.0)
	{
		printf("Detail: Invalid ambient ratio\n");
		return (FALSE);
	}
	if (!valid_color(rt->a.c))
	{
		printf("Detail: Invalid ambient color\n");
		return (FALSE);
	}
	return (TRUE);
}

static t_bool	parse_ambient(t_scene *rt, char *line)
{
	if (!vdouble(&line, &(rt->a.s)))
	{
		printf("Detail: Wrong parsing ambient ratio\n");
		return (FALSE);
	}
	if (!sint(&line, &(rt->a.c.r), &(rt->a.c.g), &(rt->a.c.b)))
	{
		printf("Detail: Wrong parsing ambient color\n");
		return (FALSE);
	}
	ambient_to_string(rt);
	return (TRUE);
}

t_bool			get_ambient(t_scene *rt, char *line)
{
	if (rt->a.f)
		return (FALSE);
	rt->a.f = TRUE;
	if (!parse_ambient(rt, line) || !valid_ambient(rt))
		return (FALSE);
	return (TRUE);
}
