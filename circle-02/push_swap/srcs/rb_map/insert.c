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

static bool	map_update(t_map **r, char *k, char *v)
{
	t_map	*n;
	size_t	len;

	n = *r;
	while (n)
	{
		len = jstrlen(n->k);
		if (len < jstrlen(k))
			len = jstrlen(k);
		if (jstrncmp(n->k, k, len) > 0)
			n = n->l;
		else if (jstrncmp(n->k, k, len) < 0)
			n = n->r;
		else
		{
			n->v = v;
			return (true);
		}
	}
	return (false);
}

static bool	map_new_node(t_map **n, char *k, char *v)
{
	if (!jcalloc((void **)(n), 1, sizeof(t_map)))
		return (false);
	(*n)->k = k;
	(*n)->v = v;
	(*n)->l = NULL;
	(*n)->r = NULL;
	(*n)->p = NULL;
	return (true);
}

static void	map_fix_tree(t_map **r, t_map **n)
{
	t_map	*u;

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
			map_red_color(r, n, u);
		else
		{
			map_llb_color(r, n);
			map_lrb_color(r, n);
			map_rlb_color(r, n);
			map_rrb_color(r, n);
		}
	}
	(*r)->c = 'B';
}

bool		map_insert(t_map **r, char *k, char *v)
{
	t_map	*n;

	if (map_update(r, k, v))
		return (true);
	if (!map_new_node(&n, k, v))
		return (false);
	if (!(*r))
		map_alloc_root(r, &n);
	else
	{
		map_alloc_rest(r, &n);
		map_fix_tree(r, &n);
	}
	return (true);
}
