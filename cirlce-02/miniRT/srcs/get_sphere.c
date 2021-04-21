/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:50:47 by jseo              #+#    #+#             */
/*   Updated: 2021/04/21 15:42:41 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		sphere_to_string(t_scene *rt)
{
	ostream_vector(&(rt->sp.p), "Sphere Position");
	ostream_floating_point(rt->sp.d, "Sphere Diameter");
	ostream_color(&(rt->sp.c), "Sphere Color");
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
	if (!udouble(&line, &(rt->sp.d)))
		ret = FALSE;
	if (!sint(&line, &(rt->sp.c.r), &(rt->sp.c.g), &(rt->sp.c.b)))
		ret = FALSE;
	sphere_to_string(rt);
	if (!is_endl(line))
	{
		printf("Detail: More info than expected on sphere\n");
		return (FALSE);
	}
	if (!ret)
		printf("Detail: Wrong parsing sphere\n");
	return (ret);
}

t_bool			get_sphere(t_scene *rt, char *line)
{
	if (rt->sp.f)
	{
		printf("Detail: Duplicated info on sphere\n");
		return (FALSE);
	}
	rt->sp.f = TRUE;
	if (!parse_sphere(rt, line) || !valid_sphere(rt))
		return (FALSE);
	return (TRUE);
}
