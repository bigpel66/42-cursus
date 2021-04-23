/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:44:34 by jseo              #+#    #+#             */
/*   Updated: 2021/04/22 17:08:58 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	mlx_setup(t_mlx *m, const char *filename)
{
	t_img	*i;
	t_scene	*rt;

	i = &(m->img);
	rt = &(m->rt);
	if (rt->r.w <= 0 || rt->r.h <= 0)
		e_mlx_setup(m);
	m->sid = mlx_init();
	if (!(m->sid))
		e_mlx_screen_connection(m);
	m->wid = mlx_new_window(m->sid, rt->r.w, rt->r.h, (char *)filename);
	if (!(m->wid))
		e_mlx_window(m);
	i->id = mlx_new_image(m->sid, rt->r.w, rt->r.h);
	if (!(i->id))
		e_mlx_image(m);
	i->addr = mlx_get_data_addr(i->id, &(i->bpp), &(i->sl), &(i->endian));
}