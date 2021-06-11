/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 23:34:28 by jseo              #+#    #+#             */
/*   Updated: 2021/06/11 10:53:38 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	map_left_rotate(t_map **r, t_map **n)
{
	t_map	*u;

	if (!(*n) || !(*n)->r)
		return ;
	u = (*n)->r;
	(*n)->r = u->l;
	if ((*n)->r)
		(*n)->r->p = (*n);
	u->p = (*n)->p;
	if (!((*n)->p))
		*r = u;
	else if ((*n) == (*n)->p->l)
		(*n)->p->l = u;
	else
		(*n)->p->r = u;
	u->l = (*n);
	(*n)->p = u;
}

void	map_right_rotate(t_map **r, t_map **n)
{
	t_map	*u;

	if (!(*n) || !(*n)->l)
		return ;
	u = (*n)->l;
	(*n)->l = u->r;
	if (u->r)
		u->r->p = (*n);
	u->p = (*n)->p;
	if (!(u->p))
		*r = u;
	else if ((*n) == (*n)->p->l)
		(*n)->p->l = u;
	else
		(*n)->p->r = u;
	u->r = (*n);
	(*n)->p = u;
}
