/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_omega.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:44:34 by jseo              #+#    #+#             */
/*   Updated: 2021/05/07 17:46:06 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_scene(t_scene *rt)
{
	if (rt->c)
		free_ptr((void **)(&(rt->c)));
	if (rt->l)
		free_ptr((void **)(&(rt->l)));
	if (rt->sp)
		free_ptr((void **)(&(rt->sp)));
	if (rt->pl)
		free_ptr((void **)(&(rt->pl)));
	if (rt->sq)
		free_ptr((void **)(&(rt->sq)));
	if (rt->cy)
		free_ptr((void **)(&(rt->cy)));
	if (rt->tr)
		free_ptr((void **)(&(rt->tr)));
	if (rt->co)
		free_ptr((void **)(&(rt->co)));
}

void	free_thread(void **t, void **p, t_mux *l)
{
	free_ptr(t);
	free_ptr(p);
	if (l)
		pthread_mutex_destroy(l);
}

void	mlx_free(t_mlx *m)
{
	int	i;

	i = -1;
	while (++i < m->rt.cnt.c)
	{
		if (m->sid && (m->img)[i].id)
			mlx_destroy_image(m->sid, (m->img)[i].id);
	}
	if (m->sid && m->wid)
		mlx_destroy_window(m->sid, m->wid);
	free_scene(&(m->rt));
	free_ptr((void **)(&(m->obj)));
	free_ptr((void **)(&(m->img)));
	i = -1;
	while (++i < m->rt.cnt.sp)
	{
		free_ptr((void **)(&((m->txr)[i].f)));
		free_ptr((void **)(&((m->txr)[i].color)));
	}
	free_ptr((void **)(&(m->txr)));
}

void	mlx_setup(t_mlx *m, char *f)
{
	t_scene	*rt;

	rt = &(m->rt);
	if (rt->r.w <= 0 || rt->r.h <= 0 || !rt->cnt.c)
		e_mlx_setup(m);
	m->sid = mlx_init();
	if (!(m->sid))
		e_mlx_screen_connection(m);
	m->wid = mlx_new_window(m->sid, rt->r.w, rt->r.h, f);
	if (!(m->wid))
		e_mlx_window(m);
	if (!dalloc((void **)(&(m->img)), m->rt.cnt.c, sizeof(t_img)))
		e_memory_alloc(m);
	img_init(m);
}
