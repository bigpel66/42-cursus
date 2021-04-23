/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:09:11 by jseo              #+#    #+#             */
/*   Updated: 2021/04/23 22:30:39 by jseo             ###   ########.fr       */
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

static void	camera_translation(int key, t_mlx *m)
{
	if (key == KEY_W)
		(m->rt.c)[m->i].p.y += 0.5;
	if (key == KEY_A)
		(m->rt.c)[m->i].p.x -= 0.5;
	if (key == KEY_S)
		(m->rt.c)[m->i].p.y -= 0.5;
	if (key == KEY_D)
		(m->rt.c)[m->i].p.x += 0.5;
	if (key == KEY_Q)
		(m->rt.c)[m->i].p.z -= 0.5;
	if (key == KEY_E)
		(m->rt.c)[m->i].p.z += 0.5;
	to_string_c(&((m->rt.c)[m->i]), m->i + 1);
}

static void	camera_rotation(int key, t_mlx *m)
{
	double	*tmp;

	if (key == KEY_UP || key == KEY_DOWN)
		tmp = &((m->rt.c)[m->i].o.y);
	if (key == KEY_LEFT || key == KEY_RIGHT)
		tmp = &((m->rt.c)[m->i].o.x);
	if (key == KEY_CMA || key == KEY_SLH)
		tmp = &((m->rt.c)[m->i].o.z);
	if (key == KEY_LEFT || key == KEY_DOWN || key == KEY_CMA)
		*tmp = clamp(*tmp - 0.1, 0.0, 1.0);
	else
		*tmp = clamp(*tmp + 0.1, 0.0, 1.0);
	to_string_c(&((m->rt.c)[m->i]), m->i + 1);
}

static void	image_index(int key, t_mlx *m)
{
	int	idx;

	idx = m->i;
	if (key == KEY_N)
	{
		m->i = (--idx) % m->rt.cnt.c;
		if (m->i < 0)
			m->i += m->rt.cnt.c;
	}
	if (key == KEY_M)
		m->i = (++idx) % m->rt.cnt.c;
	printf("testing index %d\n", (m->i) + 1);
}

static int	key_hook(int key, t_mlx *m)
{
	if (key == KEY_TERM)
		return (exit_program(m));
	if ((key >= 0 && key <= 2) || (key >= 12 && key <= 14))
		camera_translation(key, m);
	else if ((key >= 123 && key <= 126) || (key >= 43 && key <= 44))
		camera_rotation(key, m);
	else if (key >= 45 && key <= 46)
		image_index(key, m);
	else
		return (0);
	mlx_calc();
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
