/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_triangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:50:55 by jseo              #+#    #+#             */
/*   Updated: 2021/04/21 15:43:48 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		triangle_to_string(t_scene *rt)
{
	ostream_vector(&(rt->tr.p1), "Triangle Position 1");
	ostream_vector(&(rt->tr.p2), "Triangle Position 2");
	ostream_vector(&(rt->tr.p3), "Triangle Position 3");
	ostream_color(&(rt->tr.c), "Triangle Color");
}

static t_bool	valid_triangle(t_scene *rt)
{
	t_bool	ret;

	ret = TRUE;
	if (!valid_color(rt->tr.c))
		ret = FALSE;
	if (!ret)
		printf("Detail: Invalid triangle value\n");
	return (ret);
}

static t_bool	parse_triangle(t_scene *rt, char *line)
{
	t_bool	ret;

	ret = TRUE;
	if (!sdouble(&line, &(rt->tr.p1.x), &(rt->tr.p1.y), &(rt->tr.p1.z)))
		ret = FALSE;
	if (!sdouble(&line, &(rt->tr.p2.x), &(rt->tr.p2.y), &(rt->tr.p2.z)))
		ret = FALSE;
	if (!sdouble(&line, &(rt->tr.p3.x), &(rt->tr.p3.y), &(rt->tr.p3.z)))
		ret = FALSE;
	if (!sint(&line, &(rt->tr.c.r), &(rt->tr.c.g), &(rt->tr.c.b)))
		ret = FALSE;
	triangle_to_string(rt);
	if (!is_endl(line))
	{
		printf("Detail: More info than expected on triangle\n");
		return (FALSE);
	}
	if (!ret)
		printf("Detail: Wrong parsing triangle\n");
	return (ret);
}

t_bool			get_triangle(t_scene *rt, char *line)
{
	if (rt->tr.f)
	{
		printf("Detail: Duplicated info on triangle\n");
		return (FALSE);
	}
	rt->tr.f = TRUE;
	if (!parse_triangle(rt, line) || !valid_triangle(rt))
		return (FALSE);
	return (TRUE);
}
