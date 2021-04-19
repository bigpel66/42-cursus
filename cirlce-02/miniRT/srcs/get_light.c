/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:50:36 by jseo              #+#    #+#             */
/*   Updated: 2021/04/19 10:33:10 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_bool	valid_light(t_scene *rt)
{
	if (rt->l.s < 0.0 || rt->l.s > 1.0)
	{
		printf("Detail: Invalid light ratio\n");
		return (FALSE);
	}
	if (!valid_color(rt->l.c))
	{
		printf("Detail: Invalid light color\n");
		return (FALSE);
	}
	return (TRUE);
}

static t_bool	parse_light(t_scene *rt, char *line)
{
	if (!sdouble(&line, &(rt->l.p.x), &(rt->l.p.y), &(rt->l.p.z)))
	{
		printf("Detail: Wrong parsing light position\n");
		return (FALSE);
	}
	if (!vdouble(&line, &(rt->l.s)))
	{
		printf("Detail: Wrong parsing light ratio\n");
		return (FALSE);
	}
	if (!sint(&line, &(rt->l.c.r), &(rt->l.c.g), &(rt->l.c.b)))
	{
		printf("Detail: Wrong parsing light color\n");
		return (FALSE);
	}
	return (TRUE);
}

t_bool			get_light(t_scene *rt, char *line)
{
	if (rt->l.f)
		return (FALSE);
	rt->l.f = TRUE;
	if (!parse_light(rt, line) || !valid_light(rt))
		return (FALSE);
	return (TRUE);
}
