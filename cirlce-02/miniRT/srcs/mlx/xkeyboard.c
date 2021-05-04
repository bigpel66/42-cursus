/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xkeyboard.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 00:16:11 by jseo              #+#    #+#             */
/*   Updated: 2021/05/05 01:13:19 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	cam_key(int key, t_mlx *m)
{
	if ((key >= 0 && key <= 2) || (key >= 12 && key <= 14))
		cam_mov(key, m);
	else if ((key >= 123 && key <= 126) || (key >= 43 && key <= 44))
		cam_rot(key, m);
	else if (key >= 45 && key <= 46)
		cam_snap(key, m);
	else
		return (FALSE);
	return (TRUE);
}

t_bool	obj_key(int key, t_mlx *m)
{
	if ((key >= 18 && key <= 21) || (key >= 34 && key <= 35))
		printf("%d %d\n", key, m->rt.cnt.obj);
	// obj_mov(key, m);
	else if ((key >= 6 && key <= 9) || (key >= 40 && key <= 41))
		printf("%d %d\n", key, m->rt.cnt.obj);
	// obj_rot(key, m);
	else
		return (FALSE);
	return (TRUE);
}

void	mode_material(int key, t_mlx *m)
{
	printf("%d %d\n", key, m->rt.cnt.obj);
}

void	mode_filter(int key, t_mlx *m)
{
	printf("%d %d\n", key, m->rt.cnt.obj);
}

t_bool	mode_key(int key, t_mlx *m)
{
	if (key == KEY_SPACE)
		mode_material(key, m);
	else if (key == KEY_ENTER)
		mode_filter(key, m);
	else
		return (FALSE);
	return (TRUE);
}
