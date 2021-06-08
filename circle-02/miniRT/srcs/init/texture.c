/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 17:51:16 by jseo              #+#    #+#             */
/*   Updated: 2021/05/07 17:51:18 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	txr_init(t_mlx *m)
{
	int	i;

	i = -1;
	if (!m->rt.cnt.sp)
		return (TRUE);
	if (!dalloc((void **)(&(m->txr)), m->rt.cnt.sp, sizeof(t_txr)))
		return (FALSE);
	while (++i < m->rt.cnt.sp)
	{
		(m->txr)[i].i = i;
		(m->txr)[i].f = (m->rt.sp)[i].f;
	}
	import_bmp(m);
	i = -1;
	while (++i < m->rt.cnt.obj)
		if ((m->obj)[i].type == SPHERE)
			(m->obj)[i].txr = &((m->txr)[(m->obj)[i].i]);
	return (TRUE);
}
