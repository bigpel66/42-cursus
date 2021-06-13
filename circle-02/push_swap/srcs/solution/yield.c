/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yield.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 13:03:05 by jseo              #+#    #+#             */
/*   Updated: 2021/06/14 00:20:30 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <stdio.h>

static void solve_a(t_ps **ps, int n)
{
	if (n == 2)
		if ((*ps)->ah->v > (*ps)->ah->n->v)
			inst_sa(ps);
	if (n == 3)
	{
		if ((*ps)->ah->v < (*ps)->ah->n->v && (*ps)->ah->n->v > (*ps)->ah->n->n->v)
		{
			inst_rra(ps);
			inst_sa(ps);
		}
		else if ((*ps)->ah->v > (*ps)->ah->n->v && (*ps)->ah->n->v < (*ps)->ah->n->n->v)
		{
			inst_sa(ps);
		}
		else if ((*ps)->ah->v > (*ps)->ah->n->v && (*ps)->ah->n->v > (*ps)->ah->n->n->v)
		{
			inst_rra(ps);
		}
	}
}

static void solve_b(t_ps **ps, int n)
{
	if (n == 2)
		if ((*ps)->bh->v > (*ps)->bh->n->v)
			inst_sb(ps);
	if (n == 3)
	{
		if ((*ps)->bh->v < (*ps)->bh->n->v && (*ps)->bh->n->v > (*ps)->bh->n->n->v)
		{
			inst_rrb(ps);
			inst_sb(ps);
		}
		else if ((*ps)->bh->v > (*ps)->bh->n->v && (*ps)->ah->n->v < (*ps)->ah->n->n->v)
		{
			inst_sa(ps);
		}
		else if ((*ps)->ah->v > (*ps)->ah->n->v && (*ps)->ah->n->v > (*ps)->ah->n->n->v)
		{
			inst_rra(ps);
		}
	}
}

static void stack_b()
{;
}

void sol_yield(t_ps **ps, int n, int sp, int bp)
{
	int i;
	int ra;
	int rb;

	i = -1;
	ra = 0;
	rb = 0;
	if (n < 3)
	{
		solve_a(ps, n);
		print_stacks(ps);
	}
	else
	{
		while (++i < n)
		{
			if ((*ps)->ah->v > bp)
			{
				inst_ra(ps);
				print_stacks(ps);
				++ra;
			}
			else
			{
				inst_pb(ps);
				print_stacks(ps);
				if ((*ps)->bh->v > sp)
				{
					inst_rb(ps);
					print_stacks(ps);
					++rb;
				}
			}
		}
		i = -1;
		while (i < ra)
			inst_rra(ps);
		i = -1;
		while (i < rb)
			inst_rrb(ps);
		sol_yield(ps, ra, (sp - 1 + bp - 1) / 3, (sp - 1 + bp - 1) * 2 / 3);
		// stack_b
	}
}
