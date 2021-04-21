/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:50:32 by jseo              #+#    #+#             */
/*   Updated: 2021/04/21 15:37:56 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		cylinder_to_string(t_scene *rt)
{
	ostream_vector(&(rt->cy.p), "Cylinder Position");
	ostream_vector(&(rt->cy.o), "Cylinder Orientation");
	ostream_floating_point(rt->cy.d, "Cylinder Diameter");
	ostream_floating_point(rt->cy.h, "Cylinder Height");
	ostream_color(&(rt->cy.c), "Cylinder Color");
}

static t_bool	valid_cylinder(t_scene *rt)
{
	t_bool	ret;

	ret = TRUE;
	if (!valid_vec3(rt->cy.o))
		ret = FALSE;
	if (rt->cy.d <= 0.0)
		ret = FALSE;
	if (rt->cy.h <= 0.0)
		ret = FALSE;
	if (!valid_color(rt->cy.c))
		ret = FALSE;
	if (!ret)
		printf("Detail: Invalid cylinder value\n");
	return (ret);
}

static t_bool	parse_cylinder(t_scene *rt, char *line)
{
	t_bool	ret;

	ret = TRUE;
	if (!sdouble(&line, &(rt->cy.p.x), &(rt->cy.p.y), &(rt->cy.p.z)))
		ret = FALSE;
	if (!sdouble(&line, &(rt->cy.o.x), &(rt->cy.o.y), &(rt->cy.o.z)))
		ret = FALSE;
	if (!udouble(&line, &(rt->cy.d)))
		ret = FALSE;
	if (!udouble(&line, &(rt->cy.h)))
		ret = FALSE;
	if (!sint(&line, &(rt->cy.c.r), &(rt->cy.c.g), &(rt->cy.c.b)))
		ret = FALSE;
	cylinder_to_string(rt);
	if (!is_endl(line))
	{
		printf("Detail: More info than expected on cylinder\n");
		return (FALSE);
	}
	if (!ret)
		printf("Detail: Wrong parsing cylinder\n");
	return (ret);
}

t_bool			get_cylinder(t_scene *rt, char *line)
{
	if (rt->cy.f)
	{
		printf("Detail: Duplicated info on cylinder\n");
		return (FALSE);
	}
	rt->cy.f = TRUE;
	if (!parse_cylinder(rt, line) || !valid_cylinder(rt))
		return (FALSE);
	return (TRUE);
}
