/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ambient.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:50:23 by jseo              #+#    #+#             */
/*   Updated: 2021/04/19 14:47:02 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		ambient_to_string(t_scene *rt)
{
	printf("A ratio: %f\n", rt->a.s);
	printf("A color: %d %d %d\n", rt->a.c.r, rt->a.c.g, rt->a.c.b);
}

static t_bool	valid_ambient(t_scene *rt)
{
	t_bool	ret;

	ret = TRUE;
	if (rt->a.s < 0.0 || rt->a.s > 1.0)
		ret = FALSE;
	if (!valid_color(rt->a.c))
		ret = FALSE;
	if (!ret)
		printf("Detail: Invalid ambient value\n");
	return (ret);
}

static t_bool	parse_ambient(t_scene *rt, char *line)
{
	t_bool	ret;

	ret = TRUE;
	if (!vdouble(&line, &(rt->a.s)))
		ret = FALSE;
	if (!sint(&line, &(rt->a.c.r), &(rt->a.c.g), &(rt->a.c.b)))
		ret = FALSE;
	ambient_to_string(rt);
	if (!is_endl(line))
	{
		printf("Detail: More info than expected on resolution\n");
		return (FALSE);
	}
	if (!ret)
		printf("Detail: Wrong parsing ambient\n");
	return (ret);
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
