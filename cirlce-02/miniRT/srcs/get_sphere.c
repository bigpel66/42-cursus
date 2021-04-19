/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:50:47 by jseo              #+#    #+#             */
/*   Updated: 2021/04/19 14:43:36 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		sphere_to_string(t_scene *rt)
{
	printf("sp position: %f %f %f\n", rt->sp.p.x, rt->sp.p.y, rt->sp.p.z);
	printf("sp diameter: %f\n", rt->sp.d);
	printf("sp color: %d %d %d\n", rt->sp.c.x, rt->sp.c.y, rt->sp.c.z);
}

static t_bool	valid_sphere(t_scene *rt)
{
	t_bool	ret;

	ret = TRUE;
	if (rt->sp.d <= 0.0)
		ret = FALSE;
	if (!valid_color(rt->sp.c))
		ret = FALSE;
	if (!ret)
		printf("Detail: Invalid sphere value\n");
	return (ret);
}

static t_bool	parse_sphere(t_scene *rt, char *line)
{
	t_bool	ret;

	ret = TRUE;
	if (!sdouble(&line, &(rt->sp.p.x), &(rt->sp.p.y), &(rt->sp.p.z)))
		ret = FALSE;
	if (!vdouble(&line, &(rt->sp.d)))
		ret = FALSE;
	if (!sint(&line, &(rt->sp.c.r), &(rt->sp.c.g), &(rt->sp.c.b)))
		ret = FALSE;
	sphere_to_string(rt);
	if (!ret)
		printf("Detail: Wrong parsing sphere\n");
	return (ret);
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
