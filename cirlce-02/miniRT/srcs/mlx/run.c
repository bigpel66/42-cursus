/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:09:11 by jseo              #+#    #+#             */
/*   Updated: 2021/04/28 17:55:15 by jseo             ###   ########.fr       */
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
	t_p	*p;

	p = NULL;
	if (key == KEY_TERM)
		return (exit_program(m));
	if (((key >= 0 && key <= 2) || (key >= 12 && key <= 14))
		|| ((key >= 123 && key <= 126) || (key >= 43 && key <= 44))
		|| (key >= 45 && key <= 46))
		cam_handle(key, m);
	else
		return (0);
	if (!(key >= 45 && key <= 46))
	{
		cam_init(&(m->rt.c[m->i]), v_init(0, 1, 0), m->rt.r.ar, 10.0);
		if (!dalloc((void **)(&p), 1, sizeof(t_p)))
			e_memory_alloc(m);
		p_init(p, NULL, p, m);
		p_update(p, m->i, -1, NULL);
		mlx_img_calc((void *)p);
	}
	mlx_clear_window(m->sid, m->wid);
	mlx_put_image_to_window(m->sid, m->wid, (m->img)[m->i].id, 0, 0);
	free_ptr((void **)(&p));
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

void		mlx_write(t_color c, t_p *p, int x, int y)
{
	int	i;

	i = x;
	i += (p->x * (p->m->rt.r.w / IMG_THREAD));
	i *= (p->m->img[p->i].bpp / 8);
	i += ((p->m->rt.r.h - 1) - y) * (p->m->img[p->i].sl);
	pthread_mutex_lock(p->l);
	(p->m->img[p->i].addr)[i] = (int)(c.b);
	(p->m->img[p->i].addr)[++i] = (int)(c.g);
	(p->m->img[p->i].addr)[++i] = (int)(c.r);
	pthread_mutex_unlock(p->l);
}
