/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 18:17:47 by jseo              #+#    #+#             */
/*   Updated: 2021/04/22 18:24:50 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	mlx_free(t_mlx *m)
{
	int i;

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
}
