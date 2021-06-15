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

void	set_alloc_root(t_set **s, t_set **n)
{
	(*n)->c = 'B';
	*s = *n;
}

void	set_alloc_rest(t_set **s, t_set **n)
{
	t_set	*i;
	t_set	*t;

	i = NULL;
	t = (*s);
	while (t)
	{
		i = t;
		if ((*n)->v < t->v)
			t = t->l;
		else
			t = t->r;
	}
	(*n)->p = i;
	if ((*n)->v > i->v)
		i->r = (*n);
	else
		i->l = (*n);
}
