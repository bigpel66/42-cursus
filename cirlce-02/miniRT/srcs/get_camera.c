/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:50:27 by jseo              #+#    #+#             */
/*   Updated: 2021/04/18 23:15:00 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_bool	valid_camera(t_mlx *m)
{
	if (!valid_vec3(m->i.c.d))
	{
		printf("Detail: Occured on camera direction\n");
		return (FALSE);
	}
	if (m->i.c.fov < 0 || m->i.c.fov > 180)
	{
		printf("Detail: Occured on camera fov\n");
		return (FALSE);
	}
	return (TRUE);
}
t_bool			get_camera(t_mlx *m, char *line)
{
	if (m->i.c.f)
		return (FALSE);
	m->i.c.f = TRUE;
	sdouble(&line, &(m->i.c.p.x), &(m->i.c.p.y), &(m->i.c.p.z));
	sdouble(&line, &(m->i.c.d.x), &(m->i.c.d.y), &(m->i.c.d.z));
	m->i.c.fov = vint(&line);
	if (!valid_camera(m))
		return (FALSE);
	return (TRUE);
}
