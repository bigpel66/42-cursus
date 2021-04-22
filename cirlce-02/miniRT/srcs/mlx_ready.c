/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_ready.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:44:34 by jseo              #+#    #+#             */
/*   Updated: 2021/04/21 20:01:18 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	mlx_ready(t_mlx *m, t_scene *rt, const char *filename)
{
	ft_memset((void *)m, 0, sizeof(t_mlx));
	m->sid = mlx_init();
	if (!(m->sid))
		e_mlx_screen_connection(rt);
	m->wid = mlx_new_window(m->sid, rt->r.w, rt->r.h, (char *)filename);
	if (!(m->wid))
		e_mlx_window(rt);
}
