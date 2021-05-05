/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:44:34 by jseo              #+#    #+#             */
/*   Updated: 2021/05/05 20:54:24 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	img_init(t_mlx *m)
{
	int		idx;
	t_img	*i;

	idx = -1;
	while (++idx < m->rt.cnt.c)
	{
		i = &((m->img)[idx]);
		i->id = mlx_new_image(m->sid, m->rt.r.w, m->rt.r.h);
		if (!(i->id))
			e_mlx_image(m);
		i->addr = mlx_get_data_addr(i->id, &(i->bpp), &(i->sl), &(i->endian));
	}
	print_image_status(m);
}

void		mlx_setup(t_mlx *m, char *f)
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
