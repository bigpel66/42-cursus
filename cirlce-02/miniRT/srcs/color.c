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

void	c_init(t_color *c, double r, double g, double b)
{
	c->r = r / 255.0;
	c->g = g / 255.0;
	c->b = b / 255.0;
}

void	c_write(t_color c, t_p *p, int x, int y)
{
	int	i;

	i = x;
	i += ((p->x) * ((p->m->rt.r.w) / IMG_THREAD));
	i *= (p->m->img[p->i].bpp / 8);
	i += (y * p->m->img[p->i].sl);
	pthread_mutex_lock(p->l);
	(p->m->img[p->i].addr)[i] = (int)(c.r);
	(p->m->img[p->i].addr)[++i] = (int)(c.g);
	(p->m->img[p->i].addr)[++i] = (int)(c.b);
	pthread_mutex_unlock(p->l);
}

t_color	c_acc(t_color c1, t_color c2)
{
	t_color	c;

	c.r = c1.r + c2.r;
	c.g = c1.g + c2.g;
	c.b = c1.b + c2.b;
	return (c);
}

t_color	c_gamma_corr(t_color c, int samples_per_pixel)
{
	double	scale;
	t_color	t;

	scale = 1.0 / (double)samples_per_pixel;
	t.r = (double)((int)(255.999 * clamp(sqrt(c.r * scale), 0.0, 0.999)));
	t.g = (double)((int)(255.999 * clamp(sqrt(c.g * scale), 0.0, 0.999)));
	t.b = (double)((int)(255.999 * clamp(sqrt(c.b * scale), 0.0, 0.999)));
	return (t);
}
