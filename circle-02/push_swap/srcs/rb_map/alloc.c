/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 23:34:02 by jseo              #+#    #+#             */
/*   Updated: 2021/06/11 10:53:17 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	map_alloc_root(t_map **m, t_map **n)
{
	(*n)->c = 'B';
	*m = *n;
}

void	map_alloc_rest(t_map **m, t_map **n)
{
	t_map	*i;
	t_map	*t;
	size_t	len;

	i = NULL;
	t = (*m);
	while (t)
	{
		i = t;
		len = jstrlen((*n)->k);
		if (len < jstrlen(t->k))
			len = jstrlen(t->k);
		if (jstrncmp((*n)->k, t->k, len) < 0)
			t = t->l;
		else
			t = t->r;
	}
	(*n)->p = i;
	len = jstrlen((*n)->k);
	if (len < jstrlen(i->k))
		len = jstrlen(i->k);
	if (jstrncmp((*n)->k, i->k, len) < 0)
		i->l = (*n);
	else
		i->r = (*n);
}
