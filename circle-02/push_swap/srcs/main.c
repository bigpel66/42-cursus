/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 14:01:05 by jseo              #+#    #+#             */
/*   Updated: 2021/06/14 12:48:16 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** This is the instruction test
** Paste one of those into the "else" phrase
**
** test_push(&ps);
** test_rotate(&ps);
** test_rrotate(&ps);
** test_swap(&ps);
*/

static void	find_minimum(t_ps **ps)
{
	t_set	*s;

	s = (*ps)->s;
	while (s && s->l)
		s = s->l;
	(*ps)->min = s->v;
}

static void	find_maximum(t_ps **ps)
{
	t_set	*s;

	s = (*ps)->s;
	while (s && s->r)
		s = s->r;
	(*ps)->max = s->v;
}

int			main(int argc, char **argv)
{
	t_ps	*ps;
	bool	sorted;

	ps = NULL;
	sorted = true;
	if (!jcalloc((void **)(&ps), 1, sizeof(t_ps))
			|| !args_check(argc, argv, &ps)
			|| !args_unique(&ps, &sorted))
		exit_invalid(&ps);
	else
	{
		if (!sorted)
		{
			find_minimum(&ps);
			find_maximum(&ps);
			a_to_b(&ps, ps->cnt);
		}
	}
	exit_valid(&ps);
}
