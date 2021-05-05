/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 14:40:50 by jseo              #+#    #+#             */
/*   Updated: 2021/04/23 14:40:52 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	print_scene_status(t_scene *rt)
{
	ostream_title("Count", 0);
	if (rt->cnt.r == 1)
		printf("Resolution\t\t\tReady\n");
	else
		printf("Resolution\t\t\tNot Exist\n");
	if (rt->cnt.a == 1)
		printf("Ambient\t\t\t\tReady\n");
	else
		printf("Ambient\t\t\t\tNot Exist\n");
	printf("%s%d\n", "The Number of Camera\t\t", rt->cnt.c);
	printf("%s%d\n", "The Number of Light\t\t", rt->cnt.l);
	printf("%s%d\n", "The Number of Sphere\t\t", rt->cnt.sp);
	printf("%s%d\n", "The Number of Plane\t\t", rt->cnt.pl);
	printf("%s%d\n", "The Number of Square\t\t", rt->cnt.sq);
	printf("%s%d\n", "The Number of Cylinder\t\t", rt->cnt.cy);
	printf("%s%d\n", "The Number of Triangle\t\t", rt->cnt.tr);
	printf("%s%d\n", "The Number of Cone\t\t\t", rt->cnt.co);
	printf("%s%d\n", "Object Count\t\t\t", rt->cnt.obj);
	printf("\n");
}

t_bool		scene_init(t_scene *rt)
{
	t_bool	ret;

	ret = TRUE;
	if (!dalloc((void **)(&(rt->c)), rt->cnt.c, sizeof(t_camera)))
		ret = FALSE;
	if (!dalloc((void **)(&(rt->l)), rt->cnt.l, sizeof(t_light)))
		ret = FALSE;
	if (!dalloc((void **)(&(rt->sp)), rt->cnt.sp, sizeof(t_sphere)))
		ret = FALSE;
	if (!dalloc((void **)(&(rt->pl)), rt->cnt.pl, sizeof(t_plane)))
		ret = FALSE;
	if (!dalloc((void **)(&(rt->sq)), rt->cnt.sq, sizeof(t_square)))
		ret = FALSE;
	if (!dalloc((void **)(&(rt->cy)), rt->cnt.cy, sizeof(t_cylinder)))
		ret = FALSE;
	if (!dalloc((void **)(&(rt->tr)), rt->cnt.tr, sizeof(t_triangle)))
		ret = FALSE;
	if (!dalloc((void **)(&(rt->co)), rt->cnt.co, sizeof(t_cone)))
		ret = FALSE;
	print_scene_status(rt);
	return (ret);
}
