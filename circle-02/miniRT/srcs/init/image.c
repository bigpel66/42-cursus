/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 17:46:25 by jseo              #+#    #+#             */
/*   Updated: 2021/05/07 17:46:27 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	img_init(t_mlx *m)
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
