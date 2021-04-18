/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ambient.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:50:23 by jseo              #+#    #+#             */
/*   Updated: 2021/04/18 23:14:51 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_bool	valid_ambient(t_mlx *m)
{
	if (!valid_color(m->i.a.c))
	{
		printf("Detail: Occured on ambient color\n");
		return (FALSE);
	}
	if (m->i.a.s < 0.0 || m->i.a.s > 1.0)
	{
		printf("Detail: Occured on ambient ratio\n");
		return (FALSE);
	}
	return (TRUE);
}

t_bool			get_ambient(t_mlx *m, char *line)
{
	if (m->i.a.f)
		return (FALSE);
	m->i.a.f = TRUE;
	m->i.a.s = vdouble(&line);
	sint(&line, &(m->i.a.c.r), &(m->i.a.c.g), &(m->i.a.c.b));
	if (!valid_ambient(m))
		return (FALSE);
	return (TRUE);
}
