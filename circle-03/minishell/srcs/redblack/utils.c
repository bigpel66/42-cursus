/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:40:05 by jseo              #+#    #+#             */
/*   Updated: 2021/12/22 18:58:58 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	rb_left(t_rb **t, t_rb **x)
{
	t_rb	*y;

	y = (*x)->r;
	(*x)->r = y->l;
	if (y->l != NULL)
		y->l->p = *x;
	y->p = (*x)->p;
	if ((*x)->p == NULL)
		*t = y;
	else if (*x == (*x)->p->l)
		(*x)->p->l = y;
	else
		(*x)->p->r = y;
	y->l = *x;
	(*x)->p = y;
}

void	rb_right(t_rb **t, t_rb **x)
{
	t_rb	*y;

	y = (*x)->l;
	(*x)->l = y->r;
	if (y->r != NULL)
		y->r->p = *x;
	y->p = (*x)->p;
	if ((*x)->p == NULL)
		*t = y;
	else if (*x == (*x)->p->l)
		(*x)->p->l = y;
	else
		(*x)->p->r = y;
	y->r = *x;
	(*x)->p = y;
}

void	rb_transplant(t_rb **t, t_rb **u, t_rb **v)
{
	if ((*u)->p == NULL)
		*t = *v;
	else if (*u == (*u)->p->l)
		(*u)->p->l = *v;
	else
		(*u)->p->r = *v;
	if (*v != NULL)
		(*v)->p = (*u)->p;
}
