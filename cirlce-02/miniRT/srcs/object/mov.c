/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 17:17:34 by jseo              #+#    #+#             */
/*   Updated: 2021/05/04 17:21:22 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	mov_sp(int key, t_sphere *sp)
{
	double *tmp;

	if (key == KEY_1 || key == KEY_2)
		tmp = &(sp->p.x);
	if (key == KEY_3 || key == KEY_4)
		tmp = &(sp->p.y);
	if (key == KEY_I || key == KEY_P)
		tmp = &(sp->p.z);
	if (key == KEY_2 || key == KEY_4 || key == KEY_P)
		*tmp = *tmp + 0.5 * 6;
	else
		*tmp = *tmp - 0.5 * 6;
}

void	mov_pl(int key, t_plane *pl)
{
	double *tmp;

	if (key == KEY_1 || key == KEY_2)
		tmp = &(pl->p.x);
	if (key == KEY_3 || key == KEY_4)
		tmp = &(pl->p.y);
	if (key == KEY_I || key == KEY_P)
		tmp = &(pl->p.z);
	if (key == KEY_2 || key == KEY_4 || key == KEY_P)
		*tmp = *tmp + 0.5 * 6;
	else
		*tmp = *tmp - 0.5 * 6;
}

void	mov_cy(int key, t_cylinder *cy)
{
	double *tmp;

	if (key == KEY_1 || key == KEY_2)
		tmp = &(cy->p.x);
	if (key == KEY_3 || key == KEY_4)
		tmp = &(cy->p.y);
	if (key == KEY_I || key == KEY_P)
		tmp = &(cy->p.z);
	if (key == KEY_2 || key == KEY_4 || key == KEY_P)
		*tmp = *tmp + 0.5 * 6;
	else
		*tmp = *tmp - 0.5 * 6;
}

void	mov_sq(int key, t_square *sq)
{
	double *tmp;

	if (key == KEY_1 || key == KEY_2)
		tmp = &(sq->p.x);
	if (key == KEY_3 || key == KEY_4)
		tmp = &(sq->p.y);
	if (key == KEY_I || key == KEY_P)
		tmp = &(sq->p.z);
	if (key == KEY_2 || key == KEY_4 || key == KEY_P)
		*tmp = *tmp + 0.5 * 6;
	else
		*tmp = *tmp - 0.5 * 6;
}

void	mov_tr(int key, t_triangle *tr)
{
	double *tmp;

	if (key == KEY_1 || key == KEY_2)
		tmp = &(tr->p.x);
	if (key == KEY_3 || key == KEY_4)
		tmp = &(tr->p.y);
	if (key == KEY_I || key == KEY_P)
		tmp = &(tr->p.z);
	if (key == KEY_2 || key == KEY_4 || key == KEY_P)
		*tmp = *tmp + 0.5 * 6;
	else
		*tmp = *tmp - 0.5 * 6;
}
