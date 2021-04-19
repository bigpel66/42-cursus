/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:50:32 by jseo              #+#    #+#             */
/*   Updated: 2021/04/19 10:44:42 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_bool	valid_cylinder(t_scene *rt)
{
	if (!valid_vec3(rt->cy.o))
	{
		printf("Detail: Invalid cylinder orientation\n");
		return (FALSE);
	}
	if (rt->cy.d <= 0.0)
	{
		printf("Detail: Invalid cylinder diameter\n");
		return (FALSE);
	}
	if (rt->cy.h <= 0.0)
	{
		printf("Detail: Invalid cylinder height\n");
		return (FALSE);
	}
	if (!valid_color(rt->cy.c))
	{
		printf("Detail: Invalid cylinder color\n");
		return (FALSE);
	}
	return (TRUE);
}

static t_bool	parse_cylinder(t_scene *rt, char *line)
{
	if (!sdouble(&line, &(rt->cy.p.x), &(rt->cy.p.y), &(rt->cy.p.z)))
	{
		printf("Detail: Wrong parsing cylinder position\n");
		return (FALSE);
	}
	if (!sdouble(&line, &(rt->cy.o.x), &(rt->cy.o.y), &(rt->cy.o.z)))
	{
		printf("Detail: Wrong parsing cylinder orientation\n");
		return (FALSE);
	}
	if (!vdouble(&line, &(rt->cy.d)))
	{
		printf("Detail: Wrong parsing cylinder diameter\n");
		return (FALSE);
	}
	if (!vdouble(&line, &(rt->cy.h)))
	{
		printf("Detail: Wrong parsing cylinder height\n");
		return (FALSE);
	}
	if (!sint(&line, &(rt->cy.c.r), &(rt->cy.c.g), &(rt->cy.c.b)))
	{
		printf("Detail: Wrong parsing cylinder color\n");
		return (FALSE);
	}
	return (TRUE);
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
