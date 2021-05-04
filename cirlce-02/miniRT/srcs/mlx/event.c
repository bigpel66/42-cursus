/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 11:29:24 by jseo              #+#    #+#             */
/*   Updated: 2021/05/05 00:16:26 by jseo             ###   ########.fr       */
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
	if (!cam_key(key, m) && !obj_key(key, m) && !mode_key(key, m))
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

int	mouse_press_hook(int key, int x, int y, t_mlx *m)
{
	t_p	*p;

	p = NULL;
	if (!cur_init(key, x, y, &(m->p)) && !cam_cur_no_left(key, m))
		return (VALID);
	if (key != PTR_LEFT)
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

int	mouse_release_hook(int key, int x, int y, t_mlx *m)
{
	t_p		*p;

	p = NULL;
	if (!cur_init(key, x, y, &(m->r)))
		return (VALID);
	cam_cur_left(m);
	cam_init(&(m->rt.c[m->i]), v_init(0, 1, 0), m->rt.r.ar);
	if (!dalloc((void **)(&p), 1, sizeof(t_p)))
		e_memory_alloc(m);
	p_init(p, NULL, p, m);
	p_update(p, m->i, -1, NULL);
	mlx_img_calc((void *)p);
	mlx_clear_window(m->sid, m->wid);
	mlx_put_image_to_window(m->sid, m->wid, (m->img)[m->i].id, 0, 0);
	free_ptr((void **)(&p));
	return (VALID);
}
