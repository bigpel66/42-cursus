/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:50:51 by jseo              #+#    #+#             */
/*   Updated: 2021/04/21 16:46:12 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		square_to_string(t_scene *rt)
{
	ostream_vector(&(rt->sq.p), "Square Position");
	ostream_vector(&(rt->sq.o), "Square Orientation");
	ostream_floating_point(rt->sq.l, "Square Side Length");
	ostream_color(&(rt->sq.c), "Square Color");
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
	int		r;
	int		g;
	int		b;

	ret = TRUE;
	if (!sdouble(&line, &(rt->sq.p.x), &(rt->sq.p.y), &(rt->sq.p.z)))
		ret = FALSE;
	if (!sdouble(&line, &(rt->sq.o.x), &(rt->sq.o.y), &(rt->sq.o.z)))
		ret = FALSE;
	if (!udouble(&line, &(rt->sq.l)))
		ret = FALSE;
	if (!sint(&line, &r, &g, &b))
		ret = FALSE;
	c_init(&(rt->sq.c), r, g, b);
	square_to_string(rt);
	if (!is_endl(line))
		ret = FALSE;
	if (!ret)
		printf("Detail: Wrong parsing square\n");
	return (ret);
}

t_bool			get_square(t_scene *rt, char *line)
{
	if (rt->sq.f)
	{
		printf("Detail: Duplicated info on square\n");
		return (FALSE);
	}
	rt->sq.f = TRUE;
	if (!parse_square(rt, line) || !valid_square(rt))
		return (FALSE);
	return (TRUE);
}
