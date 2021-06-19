/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yield.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 19:58:24 by jseo              #+#    #+#             */
/*   Updated: 2021/06/19 17:55:10 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	prerequisite(t_ps **ps, t_base *base)
{
	(*ps)->al = jlstsize((*ps)->ah);
	stack_series(ps, base);
	stack_correction(ps, (base->f_index + 1) % (*ps)->al);
	stack_series(ps, base);
}

static void	sort_3(t_ps **ps)
{
	t_list	*lst;

	lst = (*ps)->ah;
	if (lst->v > lst->n->v && lst->v < lst->n->n->v)
		inst_sa(ps, "sa");
	else if (lst->v > lst->n->n->v)
		inst_ra(ps, "ra");
}

static void	sort_5(t_ps **ps, t_base *base)
{
	if (base->len < 3)
	{
		iter(ps, (*ps)->al - 3, inst_pb, "pb");
		sort_3(ps);
	}
	else
		a_to_b(ps, base);
	b_to_a(ps);
	stack_correction(ps, find_minimum(ps));
}

static void	sort_others(t_ps **ps, t_base *base)
{
	a_to_b(ps, base);
	b_to_a(ps);
	stack_correction(ps, find_minimum(ps));
}

void		yield(t_ps **ps)
{
	t_base	base;

	base.len = 0;
	base.s_index = 0;
	base.f_index = 0;
	prerequisite(ps, &base);
	if ((*ps)->al <= 2)
		return ;
	else if ((*ps)->al == 3)
		sort_3(ps);
	else if ((*ps)->al <= 5)
		sort_5(ps, &base);
	else
		sort_others(ps, &base);
}
