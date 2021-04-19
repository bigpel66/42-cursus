/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:50:51 by jseo              #+#    #+#             */
/*   Updated: 2021/04/19 14:40:46 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		square_to_string(t_scene *rt)
{
	printf("sq position: %f %f %f\n", rt->sq.p.x, rt->sq.p.y, rt->sq.p.z);
	printf("sq orientation: %f %f %f\n", rt->sq.o.x, rt->sq.o.y, rt->sq.o.z);
	printf("sq side length: %f\n", rt->sq.l);
	printf("sq color: %d %d %d\n", rt->sq.c.r, rt->sq.c.g, rt->sq.c.b);
}

static t_bool	valid_square(t_scene *rt)
{
	t_bool	ret;

	ret = TRUE;
	if (!valid_vec3(rt->sq.o))
		ret = FALSE;
	if (rt->sq.l <= 0.0)
		ret = FALSE;
	if (!valid_color(rt->sq.c))
		ret = FALSE;
	if (!ret)
		printf("Detail: Invalid square value\n");
	return (ret);
}

static t_bool	parse_square(t_scene *rt, char *line)
{
	t_bool	ret;

	ret = TRUE;
	if (!sdouble(&line, &(rt->sq.p.x), &(rt->sq.p.y), &(rt->sq.p.z)))
		ret = FALSE;
	if (!sdouble(&line, &(rt->sq.o.x), &(rt->sq.o.y), &(rt->sq.o.z)))
		ret = FALSE;
	if (!vdouble(&line, &(rt->sq.l)))
		ret = FALSE;
	if (!sint(&line, &(rt->sq.c.r), &(rt->sq.c.g), &(rt->sq.c.b)))
		ret = FALSE;
	square_to_string(rt);
	if (!is_endl(line))
	{
		printf("Detail: More info than expected on resolution\n");
		return (FALSE);
	}
	if (!ret)
		printf("Detail: Wrong parsing square\n");
	return (ret);
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
