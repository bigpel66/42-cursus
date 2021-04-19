/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:50:27 by jseo              #+#    #+#             */
/*   Updated: 2021/04/19 14:45:55 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		camera_to_string(t_scene *rt)
{
	printf("c position: %f %f %f\n", rt->c.p.x, rt->c.p.y, rt->c.p.z);
	printf("c orientation: %f %f %f\n", rt->c.o.x, rt->c.o.y, rt->c.o.z);
	printf("c fov: %f\n", rt->c.fov);
}

static t_bool	valid_camera(t_scene *rt)
{
	t_bool	ret;

	ret = TRUE;
	if (!valid_vec3(rt->c.o))
		ret = FALSE;
	if (rt->c.fov < 0 || rt->c.fov > 180)
		ret = FALSE;
	if (!ret)
		printf("Detail: Invalid camera value\n");
	return (ret);
}

static t_bool	parse_camera(t_scene *rt, char *line)
{
	t_bool	ret;

	ret = TRUE;
	if (!sdouble(&line, &(rt->c.p.x), &(rt->c.p.y), &(rt->c.p.z)))
		ret = FALSE;
	if (!sdouble(&line, &(rt->c.o.x), &(rt->c.o.y), &(rt->c.o.z)))
		ret = FALSE;
	if (!vdouble(&line, &(rt->c.fov)))
		ret = FALSE;
	camera_to_string(rt);
	if (!is_endl(line))
	{
		printf("Detail: More info than expected on resolution\n");
		return (FALSE);
	}
	if (!ret)
		printf("Detail: Wrong parsing camera\n");
	return (ret);
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
