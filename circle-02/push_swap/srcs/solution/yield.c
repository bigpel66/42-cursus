/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yield.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 19:58:24 by jseo              #+#    #+#             */
/*   Updated: 2021/06/17 17:55:39 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_ps **ps)
{
	t_list	*lst;

	lst = (*ps)->ah;
	if (lst->v > lst->n->v && lst->v < lst->n->n->v)
		inst_sa(ps, "sa");
	else if (lst->v > lst->n->n->v)
		inst_ra(ps, "ra");
}

void	sort_5(t_ps **ps)
{
	if ((*ps)->ol < 3)
	{
		iter(ps, (*ps)->al - 3, inst_pb, "pb");
		sort_3(ps);
	}
	else
		a_to_b(ps);
	b_to_a(ps);
	stack_correction(ps, stack_min(ps));
}

void	sort_others(t_ps **ps)
{
	a_to_b(ps);
	b_to_a(ps);
	stack_correction(ps, stack_min(ps));
}

void	yield(t_ps **ps)
{
	if ((*ps)->al == 3)
		sort_3(ps);
	else if ((*ps)->al <= 5)
		sort_5(ps);
	else
		sort_others(ps);
}
