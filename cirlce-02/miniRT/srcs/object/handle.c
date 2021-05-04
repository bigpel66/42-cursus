/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 17:21:14 by jseo              #+#    #+#             */
/*   Updated: 2021/05/04 17:21:16 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// void	obj_mov(int key, t_mlx *m)
// {
// 	int	i;

// 	i = -1;
// 	while (++i < m->rt.cnt.obj)
// 	{
// 		if ((m->obj[i]).type == SPHERE)
// 			mov_sp(key, (t_sphere *)((m->obj)[i].data));
// 		else if ((m->obj[i]).type == PLANE)
// 			mov_pl(key, (t_plane *)((m->obj)[i].data));
// 		else if ((m->obj[i]).type == CYLINDER)
// 			mov_cy(key, (t_cylinder *)((m->obj)[i].data));
// 		else if ((m->obj[i]).type == SQUARE)
// 			mov_sq(key, (t_square *)((m->obj)[i].data));
// 		else if ((m->obj[i]).type == TRIANGLE)
// 			mov_tr(key, (t_triangle *)((m->obj)[i].data));
// 	}
// }

// void	obj_rot(int key, t_mlx *m)
// {
// 	int	i;

// 	i = -1;
// 	while (++i < m->rt.cnt.obj)
// 	{
// 		if ((m->obj[i]).type == SPHERE)
// 			rot_sp(key, (t_sphere *)((m->obj)[i].data));
// 		else if ((m->obj[i]).type == PLANE)
// 			rot_pl(key, (t_plane *)((m->obj)[i].data));
// 		else if ((m->obj[i]).type == CYLINDER)
// 			rot_cy(key, (t_cylinder *)((m->obj)[i].data));
// 		else if ((m->obj[i]).type == SQUARE)
// 			rot_sq(key, (t_square *)((m->obj)[i].data));
// 		else if ((m->obj[i]).type == TRIANGLE)
// 			rot_tr(key, (t_triangle *)((m->obj)[i].data));
// 	}
// }
