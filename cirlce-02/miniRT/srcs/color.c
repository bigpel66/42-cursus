/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:09:41 by jseo              #+#    #+#             */
/*   Updated: 2021/04/21 16:45:22 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	c_init(t_color *c, double r, double g, double b)
{
	c->r = r;
	c->g = g;
	c->b = b;
}

t_color	c_gamma_correction(t_color c, int samples_per_pixel)
{
	double	scale;
	t_color	t;

	scale = 1.0 / (double)samples_per_pixel;
	t.r = (double)((int)(255.999 * clamp(sqrt(c.r * scale), 0.0, 0.999)));
	t.g = (double)((int)(255.999 * clamp(sqrt(c.g * scale), 0.0, 0.999)));
	t.b = (double)((int)(255.999 * clamp(sqrt(c.b * scale), 0.0, 0.999)));
	return (t);
}
