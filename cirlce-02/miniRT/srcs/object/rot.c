/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 17:17:40 by jseo              #+#    #+#             */
/*   Updated: 2021/05/04 17:21:26 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	rot_pl(int key, t_plane *pl)
{
	double *tmp;

	if (key == KEY_Z || key == KEY_X)
		tmp = &(pl->n.x);
	if (key == KEY_C || key == KEY_V)
		tmp = &(pl->n.y);
	if (key == KEY_K || key == KEY_SEMI)
		tmp = &(pl->n.z);
	if (key == KEY_X || key == KEY_V || key == KEY_SEMI)
		*tmp = clamp(*tmp + 0.1 * 2, -1.0, 1.0);
	else
		*tmp = clamp(*tmp - 0.1 * 2, -1.0, 1.0);
}

void	rot_cy(int key, t_cylinder *cy)
{
	double *tmp;

	if (key == KEY_Z || key == KEY_X)
		tmp = &(cy->o.x);
	if (key == KEY_C || key == KEY_V)
		tmp = &(cy->o.y);
	if (key == KEY_K || key == KEY_SEMI)
		tmp = &(cy->o.z);
	if (key == KEY_X || key == KEY_V || key == KEY_SEMI)
		*tmp = clamp(*tmp + 0.1 * 2, -1.0, 1.0);
	else
		*tmp = clamp(*tmp - 0.1 * 2, -1.0, 1.0);
}

void	rot_sq(int key, t_square *sq)
{
	double *tmp;

	if (key == KEY_Z || key == KEY_X)
		tmp = &(sq->n.x);
	if (key == KEY_C || key == KEY_V)
		tmp = &(sq->n.y);
	if (key == KEY_K || key == KEY_SEMI)
		tmp = &(sq->n.z);
	if (key == KEY_X || key == KEY_V || key == KEY_SEMI)
		*tmp = clamp(*tmp + 0.1 * 2, -1.0, 1.0);
	else
		*tmp = clamp(*tmp - 0.1 * 2, -1.0, 1.0);
}

void	rot_tr(int key, t_triangle *tr)
{
	double *tmp;

	if (key == KEY_Z || key == KEY_X)
		tmp = &(tr->n.x);
	if (key == KEY_C || key == KEY_V)
		tmp = &(tr->n.y);
	if (key == KEY_K || key == KEY_SEMI)
		tmp = &(tr->n.z);
	if (key == KEY_X || key == KEY_V || key == KEY_SEMI)
		*tmp = clamp(*tmp + 0.1 * 2, -1.0, 1.0);
	else
		*tmp = clamp(*tmp - 0.1 * 2, -1.0, 1.0);
}
