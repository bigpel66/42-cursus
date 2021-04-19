/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:50:47 by jseo              #+#    #+#             */
/*   Updated: 2021/04/19 10:37:10 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_bool	valid_sphere(t_scene *rt)
{
	if (rt->sp.d <= 0.0)
	{
		printf("Detail: Invalid sphere diameter\n");
		return (FALSE);
	}
	if (!valid_color(rt->sp.c))
	{
		printf("Detail: Invalid sphere color\n");
		return (FALSE);
	}
	return (TRUE);
}

static t_bool	parse_sphere(t_scene *rt, char *line)
{
	if (!sdouble(&line, &(rt->sp.p.x), &(rt->sp.p.y), &(rt->sp.p.z)))
	{
		printf("Detail: Wrong parsing sphere position\n");
		return (FALSE);
	}
	if (!vdouble(&line, &(rt->sp.d)))
	{
		printf("Detail: Wrong parsing sphere diameter\n");
		return (FALSE);
	}
	if (!sint(&line, &(rt->sp.c.r), &(rt->sp.c.g), &(rt->sp.c.b)))
	{
		printf("Detail: Wrong parsing sphere color\n");
		return (FALSE);
	}
	return (TRUE);
}

t_bool			get_sphere(t_scene *rt, char *line)
{
	if (rt->sp.f)
		return (FALSE);
	rt->sp.f = TRUE;
	if (!parse_sphere(rt, line) || !valid_sphere(rt))
		return (FALSE);
	return (TRUE);
}
