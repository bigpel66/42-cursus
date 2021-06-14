/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yield.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 13:03:05 by jseo              #+#    #+#             */
/*   Updated: 2021/06/14 15:40:57 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <stdio.h>

void	find_pivot(t_list *lst, int cnt, int *sp, int *bp)
{
	t_list	*tmp;
	int		len;
	int		max;

	max = INT32_MIN;
	while (cnt)
	{
		tmp = lst;
		len = 0;
		while (--cnt && (lst->v < lst->n->v))
		{
			++len;
			lst = lst->n;
		}
		if (max < len)
		{
			max = len;
			*sp = tmp->v;
			*bp = lst->v;
		}
		lst = lst->n;
	}
}

void	a_to_b(t_ps **ps, int n)
{
	int	sp;
	int	bp;

	// make collection;
	// add init function;
	// int ra;
	// int rb;
	// int pb;

	if (n <= 3) // with sorting
		return ;
	find_pivot((*ps)->ah, n, &sp, &bp);
	printf("%d %d\n", sp, bp);
	while (n--)
	{
		// if with cnt
		// ra
		// else with cnt
		// {
		// pb
		// if with cnt
		// rb
		// }
	}

	// a_to_b(ps, ra);
	// b_to_a(ps, rb);
	// b_to_a(ps, pb - rb);
}
