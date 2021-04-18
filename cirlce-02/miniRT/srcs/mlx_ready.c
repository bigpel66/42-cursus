/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_ready.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:44:34 by jseo              #+#    #+#             */
/*   Updated: 2021/04/18 20:44:36 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	mlx_ready(t_mlx *m)
{
	m->sid = mlx_init();
	if (!(m->sid))
		e_screen_connection();
	m->wid = mlx_new_window(m->sid, 400, 300, "miniRT");
	if (!(m->wid))
		e_window();
}
