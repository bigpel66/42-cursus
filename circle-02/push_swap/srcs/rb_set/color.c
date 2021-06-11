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

void	set_red_color(t_set **r, t_set **n, t_set *u)
{
	u->c = 'B';
	(*n)->p->c = 'B';
	(*n)->p->p->c = 'R';
	(*n) = (*n)->p->p;
}

void	set_llb_color(t_set **r, t_set **n)
{
	char	c;

	c = '\0';
	if ((*n)->p == (*n)->p->p->l && (*n) == (*n)->p->l)
	{
		c = (*n)->p->c;
		(*n)->p->c = (*n)->p->p->c;
		(*n)->p->p->c = c;
		set_right_rotate(r, &((*n)->p->p));
	}
}

void	set_lrb_color(t_set **r, t_set **n)
{
	char	c;

	c = '\0';
	if ((*n)->p == (*n)->p->p->l && (*n) == (*n)->p->r)
	{
		c = (*n)->c;
		(*n)->c = (*n)->p->p->c;
		(*n)->p->p->c = c;
		set_left_rotate(r, &((*n)->p));
		set_right_rotate(r, &((*n)->p->p));
	}
}

void	set_rlb_color(t_set **r, t_set **n)
{
	char	c;

	c = '\0';
	if ((*n)->p == (*n)->p->p->r && (*n) == (*n)->p->l)
	{
		c = (*n)->c;
		(*n)->c = (*n)->p->p->c;
		(*n)->p->p->c = c;
		set_right_rotate(r, &((*n)->p));
		set_left_rotate(r, &((*n)->p->p));
	}
}

void	set_rrb_color(t_set **r, t_set **n)
{
	char	c;

	c = '\0';
	if ((*n)->p == (*n)->p->p->r && (*n) == (*n)->p->r)
	{
		c = (*n)->p->c;
		(*n)->p->c = (*n)->p->p->c;
		(*n)->p->p->c = c;
		set_left_rotate(r, &((*n)->p->p));
	}
}
