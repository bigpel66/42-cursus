/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pred.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 12:20:14 by jseo              #+#    #+#             */
/*   Updated: 2021/06/19 15:37:45 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		pred_init(t_pred *pred)
{
	pred->dst_index = 0;
	pred->src_index = 0;
	pred->dst_rot = 0;
	pred->src_rot = 0;
	pred->total_inst = INT32_MAX;
	pred->is_former = false;
	pred->is_coordinated = false;
}

static void	dst_index(t_ps **ps, t_pred *pred, int val)
{
	int		i;
	t_list	*lst;
	int64_t	min;
	int64_t	diff;

	i = -1;
	lst = (*ps)->ah;
	min = INT64_MAX;
	while (++i < (*ps)->al)
	{
		diff = (lst->v - val);
		if (diff < 0)
			diff = ~(diff) + 1;
		if (min > diff)
		{
			min = diff;
			pred->dst_index = i;
			pred->is_former = (lst->v) > val;
		}
		lst = lst->n;
	}
}

void		pred_find(t_ps **ps, t_pred *pred, int val, int pos)
{
	dst_index(ps, pred, val);
	pred->dst_rot = find_normalize(&(pred->dst_index), (*ps)->al);
	if (pred->dst_index >= 0 && !pred->is_former)
		++(pred->dst_rot);
	if (pred->dst_index < 0 && !pred->is_former)
		--(pred->dst_rot);
	pred->src_index = pos;
	pred->src_rot = find_normalize(&(pred->src_index), (*ps)->bl);
	pred->is_coordinated = (pred->dst_index >= 0 == pred->src_index >= 0);
	if (pred->is_coordinated && pred->dst_rot >= pred->src_rot)
		pred->total_inst = pred->dst_rot;
	if (pred->is_coordinated && pred->dst_rot < pred->src_rot)
		pred->total_inst = pred->src_rot;
	if (!pred->is_coordinated)
		pred->total_inst = pred->dst_rot + pred->src_rot;
}

void		pred_swap(t_pred *tmp, t_pred *min)
{
	if (min->total_inst > tmp->total_inst)
	{
		min->dst_index = tmp->dst_index;
		min->src_index = tmp->src_index;
		min->dst_rot = tmp->dst_rot;
		min->src_rot = tmp->src_rot;
		min->total_inst = tmp->total_inst;
		min->is_former = tmp->is_former;
		min->is_coordinated = tmp->is_coordinated;
	}
}

void		pred_exec(t_ps **ps, t_pred *min)
{
	while (min->dst_rot && min->src_rot && min->is_coordinated)
	{
		if (min->dst_index >= 0)
			inst_rr(ps, "rr");
		else
			inst_rrr(ps, "rrr");
		--(min->dst_rot);
		--(min->src_rot);
	}
	if (min->dst_index >= 0)
		iter(ps, min->dst_rot, inst_ra, "ra");
	else
		iter(ps, min->dst_rot, inst_rra, "rra");
	if (min->src_index >= 0)
		iter(ps, min->src_rot, inst_rb, "rb");
	else
		iter(ps, min->src_rot, inst_rrb, "rrb");
	inst_pa(ps, "pa");
}
