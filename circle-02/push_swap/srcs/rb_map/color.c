/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 23:34:06 by jseo              #+#    #+#             */
/*   Updated: 2021/06/11 10:53:21 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	map_red_color(t_map **n, t_map *u)
{
	u->c = 'B';
	(*n)->p->c = 'B';
	(*n)->p->p->c = 'R';
	(*n) = (*n)->p->p;
}

void	map_llb_color(t_map **m, t_map **n)
{
	char	c;

	c = '\0';
	if ((*n)->p == (*n)->p->p->l && (*n) == (*n)->p->l)
	{
		c = (*n)->p->c;
		(*n)->p->c = (*n)->p->p->c;
		(*n)->p->p->c = c;
		map_right_rotate(m, &((*n)->p->p));
	}
}

void	map_lrb_color(t_map **m, t_map **n)
{
	char	c;

	c = '\0';
	if ((*n)->p == (*n)->p->p->l && (*n) == (*n)->p->r)
	{
		c = (*n)->c;
		(*n)->c = (*n)->p->p->c;
		(*n)->p->p->c = c;
		map_left_rotate(m, &((*n)->p));
		map_right_rotate(m, &((*n)->p->p));
	}
}

void	map_rlb_color(t_map **m, t_map **n)
{
	char	c;

	c = '\0';
	if ((*n)->p == (*n)->p->p->r && (*n) == (*n)->p->l)
	{
		c = (*n)->c;
		(*n)->c = (*n)->p->p->c;
		(*n)->p->p->c = c;
		map_right_rotate(m, &((*n)->p));
		map_left_rotate(m, &((*n)->p->p));
	}
}

void	map_rrb_color(t_map **m, t_map **n)
{
	char	c;

	c = '\0';
	if ((*n)->p == (*n)->p->p->r && (*n) == (*n)->p->r)
	{
		c = (*n)->p->c;
		(*n)->p->c = (*n)->p->p->c;
		(*n)->p->p->c = c;
		map_left_rotate(m, &((*n)->p->p));
	}
}
