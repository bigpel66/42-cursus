/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:50:36 by jseo              #+#    #+#             */
/*   Updated: 2021/04/18 23:15:08 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_bool	valid_light(t_mlx *m)
{
	if (m->i.l.s < 0.0 || m->i.l.s > 1.0)
	{
		printf("Detail: Occured on light ratio\n");
		return (FALSE);
	}
	if (!valid_color(m->i.l.c))
	{
		printf("Detail: Occured on light color\n");
		return (FALSE);
	}
	return (TRUE);
}

t_bool			get_light(t_mlx *m, char *line)
{
	if (m->i.l.f)
		return (FALSE);
	m->i.l.f = TRUE;
	sdouble(&line, &(m->i.l.p.x), &(m->i.l.p.y), &(m->i.l.p.z));
	m->i.l.s = vdouble(&line);
	sint(&line, &(m->i.l.c.r), &(m->i.l.c.g), &(m->i.l.c.b));
	if (!valid_light(m))
		return (FALSE);
	return (TRUE);
}
