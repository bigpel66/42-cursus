/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:09:11 by jseo              #+#    #+#             */
/*   Updated: 2021/04/25 17:21:36 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	exit_program(t_mlx *m)
{
	printf("Program terminated by exit code 0\n");
	mlx_free(m);
	exit(VALID);
	return (VALID);
}

static int	key_hook(int key, t_mlx *m)
{
	t_arg	*arg;

	if (key == KEY_TERM)
		return (exit_program(m));
	if ((key >= 0 && key <= 2) || (key >= 12 && key <= 14))
		camera_translation(key, m);
	else if ((key >= 123 && key <= 126) || (key >= 43 && key <= 44))
		camera_rotation(key, m);
	else if (key >= 45 && key <= 46)
		camera_index(key, m);
	else
		return (0);
	if (!arg_init((void **)(&arg), NULL, m, m->i))
		e_thread_param(NULL, NULL, m);
	mlx_img_calc((void *)arg);
	mlx_clear_window(m->sid, m->wid);
	mlx_put_image_to_window(m->sid, m->wid, (m->img)[m->i].id, 0, 0);
	return (0);
}

void		mlx_run(t_mlx *m)
{
	mlx_clear_window(m->sid, m->wid);
	mlx_put_image_to_window(m->sid, m->wid, (m->img)[m->i].id, 0, 0);
	mlx_hook(m->wid, 2, 1L << 0, key_hook, m);
	mlx_hook(m->wid, 17, 1L << 17, exit_program, m);
	mlx_loop(m->sid);
}
