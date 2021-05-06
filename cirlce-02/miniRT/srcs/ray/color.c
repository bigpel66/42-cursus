/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:09:41 by jseo              #+#    #+#             */
/*   Updated: 2021/04/27 00:22:52 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	c_init(double r, double g, double b)
{
	t_color	c;

	c.r = r;
	c.g = g;
	c.b = b;
	return (c);
}

t_color	c_add(t_color c1, t_color c2)
{
	t_color	c;

	c.r = c1.r + c2.r;
	c.g = c1.g + c2.g;
	c.b = c1.b + c2.b;
	return (c);
}

t_color	c_mul(t_color c1, t_color c2)
{
	t_color	c;

	c.r = c1.r * c2.r;
	c.g = c1.g * c2.g;
	c.b = c1.b * c2.b;
	return (c);
}

t_color	c_corr(t_color c, int samples_per_pixel)
{
	double	s;
	t_color	t;

	s = 1.0 / ((double)samples_per_pixel * N_DEP);
	t.r = clamp(c.r * s, 0.0, 255.0);
	t.g = clamp(c.g * s, 0.0, 255.0);
	t.b = clamp(c.b * s, 0.0, 255.0);
	return (t);
}
