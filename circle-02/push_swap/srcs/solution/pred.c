/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pred.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 12:20:14 by jseo              #+#    #+#             */
/*   Updated: 2021/06/18 12:20:16 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pre_init(t_pred *pred)
{
	pred->dst_index = -1;
	pred->src_index = -1;
	pred->sort_inst = -1;
	pred->total_inst = -1;
}


void	pred_find(t_ps **ps, t_pred *pred, int v, int i)
{
	;
}

void	pred_swap(t_pred *tmp, t_pred *min)
{
	if (min->total_inst > tmp->total_inst)
	{
		min->dst_index = tmp->dst_index;
		min->src_index = tmp->src_index;
		min->sort_inst = tmp->sort_inst;
		min->total_inst = tmp->total_inst;
	}
}

void	pred_exec(t_ps **ps, t_pred *min)
{
	;
}
