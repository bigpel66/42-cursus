/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 23:34:22 by jseo              #+#    #+#             */
/*   Updated: 2021/06/11 10:53:34 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	set_exist(t_set **r, int v)
{
	t_set	*n;

	n = *r;
	while (n)
	{
		if (v < n->v)
			n = n->l;
		else if (v > n->v)
			n = n->r;
		else
			return (true);
	}
	return (false);
}

static bool	set_new_node(t_set **n, int v)
{
	if (!jcalloc((void **)(n), 1, sizeof(t_set)))
		return (false);
	(*n)->v = v;
	(*n)->l = NULL;
	(*n)->r = NULL;
	(*n)->p = NULL;
	return (true);
}

static void	set_fix_tree(t_set **r, t_set **n)
{
	t_set	*u;

	while (*n != *r && *n != (*r)->l && *n != (*r)->r && (*n)->p->c == 'R')
	{
		u = NULL;
		if ((*n)->p && (*n)->p->p && (*n)->p == (*n)->p->p->l)
			u = (*n)->p->p->r;
		else if ((*n)->p && (*n)->p->p && (*n)->p == (*n)->p->p->r)
			u = (*n)->p->p->l;
		if (!u)
			(*n) = (*n)->p->p;
		else if (u->c == 'R')
			set_red_color(r, n, u);
		else
		{
			set_llb_color(r, n);
			set_lrb_color(r, n);
			set_rlb_color(r, n);
			set_rrb_color(r, n);
		}
	}
	(*r)->c = 'B';
}

bool		set_insert(t_set **r, int v)
{
	t_set	*n;

	if (set_exist(r, v) || !set_new_node(&n, v))
		return (false);
	if (!(*r))
		set_alloc_root(r, &n);
	else
	{
		set_alloc_rest(r, &n);
		set_fix_tree(r, &n);
	}
	return (true);
}
