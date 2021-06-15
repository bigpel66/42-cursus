/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 13:03:05 by jseo              #+#    #+#             */
/*   Updated: 2021/06/15 19:58:17 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_pivot(t_list *lst, int n, int *sp, int *bp)
{
	int i ;
	t_list *tmp;

	*sp = n * 1 / 3;
	*bp = n * 2 / 3;
	i = -1;
	tmp = lst;
	while (++i < *sp)
		tmp = tmp->n;
	*sp = tmp->v;
	i = -1;
	tmp = lst;
	while (++i < *bp)
		tmp = tmp->n;
	*bp = tmp->v;
	if (*sp > *bp)
	{
		i = *sp;
		*sp = *bp;
		*bp = i;
	}
}

void	b_to_a(t_ps **ps, int n)
{
	int sp;
	int bp;

	int ra;
	int rb;
	int pa;

	if (n < 3)
	{
		sort_3_dsc(ps, n);
		while (n--)
			inst_pa(ps);
		return ;
	}
	// else if (n <= 5)
	// {
	// 	sort_5(ps, n, false);
	// 	return ;
	// }
	ra = 0;
	rb = 0;
	pa = 0;
	find_pivot((*ps)->bh, n, &sp, &bp);
	while (n--)
	{
		if ((*ps)->bh->v < sp)
		{
			inst_rb(ps);
			++rb;
		}
		else
		{
			inst_pa(ps);
			++pa;
			if ((*ps)->ah->v < bp)
			{
				inst_ra(ps);
				++ra;
			}
		}
	}
	a_to_b(ps, pa - ra);
	int iter = ra;
	while (iter--)
		inst_rra(ps);
	iter = rb;
	while (iter--)
		inst_rrb(ps);
	a_to_b(ps, ra);
	b_to_a(ps, rb);
}

void	a_to_b(t_ps **ps, int n)
{
	int	sp;
	int	bp;

	int ra;
	int rb;
	int pb;

	if (n < 3)
	{
		sort_3_asc(ps, n);
		return ;
	}
	// else if (n <= 5)
	// {
	// 	sort_5(ps, n, true);
	// 	return ;
	// }
	ra = 0;
	rb = 0;
	pb = 0;
	find_pivot((*ps)->ah, n, &sp, &bp);
	while (n--)
	{
		if ((*ps)->ah->v >= bp)
		{
			inst_ra(ps);
			++ra;
		}
		else
		{
			inst_pb(ps);
			++pb;
			if ((*ps)->bh->v >= sp)
			{
				inst_rb(ps);
				++rb;
			}
		}
	}
	int iter = ra;
	while (iter--)
		inst_rra(ps);
	iter = rb;
	while (iter--)
		inst_rrb(ps);
	a_to_b(ps, ra);
	b_to_a(ps, rb);
	b_to_a(ps, pb - rb);
}
