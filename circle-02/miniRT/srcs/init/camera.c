/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 17:46:21 by jseo              #+#    #+#             */
/*   Updated: 2021/05/07 17:46:23 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	cam_init(t_camera *c, t_vec3 up, double ar)
{
	double	theta;
	double	height;
	double	viewport_height;
	double	viewport_width;

	if (c->o.x == 0 && c->o.y != 0 && c->o.z == 0)
		up = v_init(0.0, c->o.y, 0.001);
	theta = degrees_to_radians(c->fov);
	height = tan(theta / 2.0);
	viewport_height = 2.0 * height;
	viewport_width = ar * viewport_height;
	c->w = unit(flip(c->o));
	c->u = unit(cross(up, c->w));
	c->v = cross(c->w, c->u);
	c->hor = scale(c->u, viewport_width);
	c->ver = scale(c->v, viewport_height);
	c->llc = v_init(c->p.x - c->hor.x / 2 - c->ver.x / 2 - c->w.x,
					c->p.y - c->hor.y / 2 - c->ver.y / 2 - c->w.y,
					c->p.z - c->hor.z / 2 - c->ver.z / 2 - c->w.z);
}
