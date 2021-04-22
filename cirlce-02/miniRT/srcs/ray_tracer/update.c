/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 15:32:40 by jseo              #+#    #+#             */
/*   Updated: 2021/04/22 17:07:45 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ray_update(t_ray *r)
{
	r->cur = v_add(v_scale(r->a, r->t), r->b);
}

void	camera_update(t_camera *c, t_vec3 vup, double ar, double focus_dist)
{
	double	theta;
	double	height;
	double	viewport_height;
	double	viewport_width;

	theta = degrees_to_radians(c->fov);
	height = tan(theta / 2.0);
	viewport_height = 2.0 * height;
	viewport_width = ar * viewport_height;
	c->w = v_unit(v_sub(c->p, c->o));
	c->u = v_unit(v_cross(vup, c->w));
	c->v = v_cross(c->w, c->u);
	c->hor = v_scale(c->u, focus_dist * viewport_width);
	c->ver = v_scale(c->v, focus_dist * viewport_height);
	c->llc = v_sub(v_sub(v_sub(c->p,
					v_scale(c->hor, 1.0 / 2.0)),
				v_scale(c->ver, 1.0 / 2.0)),
			v_scale(c->w, focus_dist));
	c->r = 0.05;
}
