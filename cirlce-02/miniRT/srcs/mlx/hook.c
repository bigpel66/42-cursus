/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 11:29:24 by jseo              #+#    #+#             */
/*   Updated: 2021/05/04 11:29:35 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	exit_program(t_mlx *m)
{
	printf("Program terminated by exit code 0\n");
	mlx_free(m);
	exit(VALID);
	return (VALID);
}
int	key_hook(int key, t_mlx *m)
{
	t_p	*p;

	p = NULL;
	if (key == KEY_TERM)
		return (exit_program(m));
	if (((key >= 0 && key <= 2) || (key >= 12 && key <= 14)) ||
		((key >= 123 && key <= 126) || (key >= 43 && key <= 44)) ||
		(key >= 45 && key <= 46))
		cam_handle(key, m);
	else
		return (VALID);
	if (!(key >= 45 && key <= 46))
	{
		cam_init(&(m->rt.c[m->i]), v_init(0, 1, 0), m->rt.r.ar);
		if (!dalloc((void **)(&p), 1, sizeof(t_p)))
			e_memory_alloc(m);
		p_init(p, NULL, p, m);
		p_update(p, m->i, -1, NULL);
		mlx_img_calc((void *)p);
	}
	mlx_clear_window(m->sid, m->wid);
	mlx_put_image_to_window(m->sid, m->wid, (m->img)[m->i].id, 0, 0);
	free_ptr((void **)(&p));
	return (VALID);
}

int	mouse_press_hook(int key, t_mlx *m)
{
	int x;
	int y;
	void *p;

	p = m;

	x = 0;
	y = 0;
	// mlx_mouse_get_pos(m->wid, &x, &y);
	printf("press key, x, y : %d %d %d\n", key, x, y);
	return (VALID);
}

int mouse_release_hook(int key, t_mlx *m)
{
	int x;
	int y;
	void *p;

	p = m;

	x = 1;
	y = 1;
	// mlx_mouse_get_pos(m->wid, &x, &y);
	printf("press key, x, y : %d %d %d\n", key, x, y);
	return (VALID);
}
