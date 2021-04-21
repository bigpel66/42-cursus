/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 13:12:18 by jseo              #+#    #+#             */
/*   Updated: 2021/04/21 19:58:14 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_error_list(void)
{
	size_t	i;

	i = -1;
	while (++i < 107)
		printf("%zu: %s\n", i, strerror(i));
}

void	print_scene_count(t_scene *rt)
{
	ostream_integer(rt->cnt.r, "The Number of Resolution");
	ostream_integer(rt->cnt.a, "The Number of Ambient");
	ostream_integer(rt->cnt.c, "The Number of Camera");
	ostream_integer(rt->cnt.l, "The Number of Light");
	ostream_integer(rt->cnt.sp, "The Number of Sphere");
	ostream_integer(rt->cnt.pl, "The Number of Plane");
	ostream_integer(rt->cnt.sq, "The Number of Square");
	ostream_integer(rt->cnt.cy, "The Number of Cylinder");
	ostream_integer(rt->cnt.tr, "The Number of Triangle");
}

void	ostream_vector(const t_vec3 *v, const char *s)
{
	printf("%s: %f %f %f\n", s, v->x, v->y, v->z);
}

void	ostream_color(const t_color *c, const char *s)
{
	printf("%s: %f %f %f\n", s, c->r, c->g, c->b);
}

void	ostream_floating_point(double d, const char *s)
{
	printf("%s: %f\n", s, d);
}

void	ostream_integer(int i, const char *s)
{
	printf("%s: %d\n", s, i);
}
