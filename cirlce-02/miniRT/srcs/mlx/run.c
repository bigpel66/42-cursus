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

void		mlx_run(t_mlx *m)
{
	mlx_clear_window(m->sid, m->wid);
	mlx_put_image_to_window(m->sid, m->wid, (m->img)[m->i].id, 0, 0);
	mlx_hook(m->wid, 2, 1L << 0, key_hook, m);
	mlx_hook(m->wid, 4, 1L << 2, mouse_press_hook, m);
	mlx_hook(m->wid, 5, 1L << 3, mouse_release_hook, m);
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
