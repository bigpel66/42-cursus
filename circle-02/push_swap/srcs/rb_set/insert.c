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

static bool	set_exist(t_set **s, int v)
{
	t_set	*n;

	n = *s;
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

static void	set_fix_tree(t_set **s, t_set **n)
{
	t_set	*u;

	while (*n != *s && *n != (*s)->l && *n != (*s)->r && (*n)->p->c == 'R')
	{
		u = NULL;
		if ((*n)->p && (*n)->p->p && (*n)->p == (*n)->p->p->l)
			u = (*n)->p->p->r;
		else if ((*n)->p && (*n)->p->p && (*n)->p == (*n)->p->p->r)
			u = (*n)->p->p->l;
		if (!u)
			(*n) = (*n)->p->p;
		else if (u->c == 'R')
			set_red_color(n, u);
		else
		{
			set_llb_color(s, n);
			set_lrb_color(s, n);
			set_rlb_color(s, n);
			set_rrb_color(s, n);
		}
	}
	(*s)->c = 'B';
}

bool		set_insert(t_set **s, int v)
{
	t_set	*n;

	if (set_exist(s, v) || !set_new_node(&n, v))
		return (false);
	if (!(*s))
		set_alloc_root(s, &n);
	else
	{
		set_alloc_rest(s, &n);
		set_fix_tree(s, &n);
	}
	return (true);
}
