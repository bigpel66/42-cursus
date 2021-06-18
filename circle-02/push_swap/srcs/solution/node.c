/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 18:38:55 by jseo              #+#    #+#             */
/*   Updated: 2021/06/18 12:19:59 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_to_b(t_ps **ps)
{
	int	i;

	i = -1;
	while (++i < (*ps)->os_pos)
		inst_pb(ps, "pb");
}

void	b_to_a(t_ps **ps)
{
	int		i;
	t_pred	tmp;
	t_pred	min;
	t_list	*lst;

	while ((*ps)->bl)
	{
		i = -1;
		lst = (*ps)->bh;
		pred_init(&min);
		while (++i < (*ps)->bl)
		{
			pred_find(ps, &tmp, lst->v, i);
			pred_swap(&tmp, &min);
			lst = lst->n;
		}
		pred_exec(ps, &min);
	}
}
