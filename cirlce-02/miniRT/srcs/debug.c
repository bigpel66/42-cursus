/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 13:12:18 by jseo              #+#    #+#             */
/*   Updated: 2021/04/22 13:46:33 by jseo             ###   ########.fr       */
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

void	print_title(const char *s, int idx)
{
	size_t	i;

	i = -1;
	while (++i < 70)
		printf("=");
	printf("\n");
	if (idx)
		printf("\t\t\t\t%s %d\t\t\t\t\n", s, idx);
	else
		printf("\t\t\t\t%s\t\t\t\t\n", s);
	i = -1;
	while (++i < 70)
		printf("=");
	printf("\n");
}

void	print_scene_count(t_scene *rt)
{
	print_title("Count", 0);
	if (rt->cnt.r == 1)
		printf("Resolution\t\t\tReady\n");
	else
		printf("Resolution\t\t\tNot Exist\n");
	if (rt->cnt.a == 1)
		printf("Ambient\t\t\t\tReady\n");
	else
		printf("Ambient\t\t\t\tNot Exist\n");
	ostream_integer(rt->cnt.c, "The Number of Camera\t\t");
	ostream_integer(rt->cnt.l, "The Number of Light\t\t");
	ostream_integer(rt->cnt.sp, "The Number of Sphere\t\t");
	ostream_integer(rt->cnt.pl, "The Number of Plane\t\t");
	ostream_integer(rt->cnt.sq, "The Number of Square\t\t");
	ostream_integer(rt->cnt.cy, "The Number of Cylinder\t\t");
	ostream_integer(rt->cnt.tr, "The Number of Triangle\t\t");
	printf("\n");
}

void	ostream_vector(const t_vec3 *v, const char *s)
{
	printf("%s%12.6f\t%12.6f\t%12.6f\n", s, v->x, v->y, v->z);
}

void	ostream_color(const t_color *c, const char *s)
{
	printf("%s%12.6f\t%12.6f\t%12.6f\n", s, c->r, c->g, c->b);
}

void	ostream_floating_point(double d, const char *s)
{
	printf("%s%12.6f\n", s, d);
}

void	ostream_integer(int i, const char *s)
{
	printf("%s%d\n", s, i);
}
