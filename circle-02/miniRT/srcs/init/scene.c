/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 18:38:01 by jseo              #+#    #+#             */
/*   Updated: 2021/05/07 18:38:02 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	scene_init(t_scene *rt)
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
