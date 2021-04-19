/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:50:27 by jseo              #+#    #+#             */
/*   Updated: 2021/04/19 10:31:49 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_bool	valid_camera(t_scene *rt)
{
	if (!valid_vec3(rt->c.o))
	{
		printf("Detail: Occured on camera orientation\n");
		return (FALSE);
	}
	if (rt->c.fov < 0 || rt->c.fov > 180)
	{
		printf("Detail: Occured on camera fov\n");
		return (FALSE);
	}
	return (TRUE);
}

static t_bool	parse_camera(t_scene *rt, char *line)
{
	if (!sdouble(&line, &(rt->c.p.x), &(rt->c.p.y), &(rt->c.p.z)))
	{
		printf("Detail: Wrong parsing camera position\n");
		return (FALSE);
	}
	if (!sdouble(&line, &(rt->c.o.x), &(rt->c.o.y), &(rt->c.o.z)))
	{
		printf("Detail: Wrong parsing camera orientation\n");
		return (FALSE);
	}
	if (!vdouble(&line, &(rt->c.fov)))
	{
		printf("Detail: Wrong parsing camera fov\n");
		return (FALSE);
	}
	return (TRUE);
}

t_bool			get_camera(t_scene *rt, char *line)
{
	if (rt->c.f)
		return (FALSE);
	rt->c.f = TRUE;
	if (!parse_camera(rt, line) || !valid_camera(rt))
		return (FALSE);
	return (TRUE);
}
