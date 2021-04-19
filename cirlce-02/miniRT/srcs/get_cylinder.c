/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:50:32 by jseo              #+#    #+#             */
/*   Updated: 2021/04/19 14:37:09 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		cylinder_to_string(t_scene *rt)
{
	printf("cy position: %f %f %f\n", rt->cy.p.x, rt->cy.p.y, rt->cy.p.z);
	printf("cy orientation: %f %f %f\n", rt->cy.o.x, rt->cy.o.y, rt->cy.o.z);
	printf("cy diameter: %f\n", rt->cy.d);
	printf("cy height: %f\n", rt->cy.h);
	printf("cy color: %d %d %d\n", rt->cy.c.r, rt->cy.c.g, rt->cy.c.b);
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
	if (!vdouble(&line, &(rt->cy.d)))
		ret = FALSE;
	if (!vdouble(&line, &(rt->cy.h)))
		ret = FALSE;
	if (!sint(&line, &(rt->cy.c.r), &(rt->cy.c.g), &(rt->cy.c.b)))
		ret = FALSE;
	cylinder_to_string(rt);
	if (!ret)
		printf("Detail: Wrong parsing cylinder\n");
	return (ret);
}

t_bool			get_cylinder(t_scene *rt, char *line)
{
	if (rt->cy.f)
		return (FALSE);
	rt->cy.f = TRUE;
	if (!parse_cylinder(rt, line) || !valid_cylinder(rt))
		return (FALSE);
	return (TRUE);
}
