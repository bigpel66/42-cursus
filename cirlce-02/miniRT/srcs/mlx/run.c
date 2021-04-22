/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:09:11 by jseo              #+#    #+#             */
/*   Updated: 2021/04/22 17:09:13 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// static int	exit_program(int key, t_mlx *m)
// {
// 	exit(0);
// 	return (0);
// }

// static int		key_hook(int key, t_mlx *m)
// {
// 	return (0);
// }

void	mlx_run(t_mlx *m)
{
	mlx_clear_window(m->sid, m->wid);
	mlx_put_image_to_window(m->sid, m->wid, m->img.id, 0, 0);
	print_scene_count(&(m->rt));
	// mlx_hook(m->wid, 2, 1L << 0, key_hook, (void *)(m));
	// mlx_hook(m->wid, 17, 1L << 17, exit_program, m);
	mlx_loop(m->sid);
}
