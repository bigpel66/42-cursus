/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:50:36 by jseo              #+#    #+#             */
/*   Updated: 2021/04/21 15:38:00 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		light_to_string(t_scene *rt)
{
	ostream_vector(&(rt->l.p), "Light Position");
	ostream_floating_point(rt->l.s, "Light Ratio");
	ostream_color(&(rt->l.c), "Light Color");
}

static t_bool	valid_light(t_scene *rt)
{
	t_bool	ret;

	ret = TRUE;
	if (rt->l.s < 0.0 || rt->l.s > 1.0)
		ret = FALSE;
	if (!valid_color(rt->l.c))
		ret = FALSE;
	if (!ret)
		printf("Detail: Invalid light value\n");
	return (ret);
}

static t_bool	parse_light(t_scene *rt, char *line)
{
	t_bool	ret;

	ret = TRUE;
	if (!sdouble(&line, &(rt->l.p.x), &(rt->l.p.y), &(rt->l.p.z)))
		ret = FALSE;
	if (!udouble(&line, &(rt->l.s)))
		ret = FALSE;
	if (!sint(&line, &(rt->l.c.r), &(rt->l.c.g), &(rt->l.c.b)))
		ret = FALSE;
	light_to_string(rt);
	if (!is_endl(line))
	{
		printf("Detail: More info than expected on light\n");
		return (FALSE);
	}
	if (!ret)
		printf("Detail: Wrong parsing light\n");
	return (ret);
}

t_bool			get_light(t_scene *rt, char *line)
{
	if (rt->l.f)
	{
		printf("Detail: Duplicated info on light\n");
		return (FALSE);
	}
	rt->l.f = TRUE;
	if (!parse_light(rt, line) || !valid_light(rt))
		return (FALSE);
	return (TRUE);
}
