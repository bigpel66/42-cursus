/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:50:32 by jseo              #+#    #+#             */
/*   Updated: 2021/04/18 23:15:04 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_bool	valid_cylinder(t_mlx *m)
{
	if (!valid_vec3(m->i.cy.d))
	{
		printf("Detail: Occured on cylinder direction\n");
		return (FALSE);
	}
	if (m->i.cy.r <= 0.0)
	{
		printf("Detail: Occured on cylinder radius\n");
		return (FALSE);
	}
	if (m->i.cy.h <= 0.0)
	{
		printf("Detail: Occured on cylinder height\n");
		return (FALSE);
	}
	if (!valid_color(m->i.cy.c))
	{
		printf("Detail: Occured on cylinder color\n");
		return (FALSE);
	}
	return (TRUE);
}

t_bool			get_cylinder(t_mlx *m, char *line)
{
	if (m->i.cy.f)
		return (FALSE);
	m->i.cy.f = TRUE;
	sdouble(&line, &(m->i.cy.p.x), &(m->i.cy.p.y), &(m->i.cy.p.z));
	sdouble(&line, &(m->i.cy.d.x), &(m->i.cy.d.y), &(m->i.cy.d.z));
	m->i.cy.r = vdouble(&line) / 2;
	m->i.cy.h = vdouble(&line);
	sint(&line, &(m->i.cy.c.r), &(m->i.cy.c.g), &(m->i.cy.c.b));
	if (!valid_cylinder(m))
		return (FALSE);
	return (TRUE);
}
