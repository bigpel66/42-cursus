/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_under_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 19:57:10 by jseo              #+#    #+#             */
/*   Updated: 2021/06/15 20:03:22 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3_asc(t_ps **ps, int cnt)
{
	t_list	*t;

	t = (*ps)->ah;
	if (cnt == 2)
		if (t->v > t->n->v)
			inst_sa(ps);
	if (cnt == 3)
	{
		if (t->v > t->n->v && t->n->v > t->n->n->v)
			inst_ss_rra(ps);
		if (t->v > t->n->v && t->n->v < t->n->n->v && t->v > t->n->n->v)
			inst_ra(ps);
		if (t->v > t->n->v && t->n->v < t->n->n->v && t->v < t->n->n->v)
			inst_sa(ps);
		if (t->v < t->n->v && t->n->v > t->n->n->v && t->v > t->n->n->v)
			inst_rra(ps);
		if (t->v < t->n->v && t->n->v > t->n->n->v && t->v < t->n->n->v)
			inst_sa_ra(ps);
	}
}

void	sort_3_dsc(t_ps **ps, int cnt)
{
	t_list	*t;

	t = (*ps)->bh;
	if (cnt == 2)
		if (t->v < t->n->v)
			inst_sb(ps);
	if (cnt == 3)
	{
		if (t->v < t->n->v && t->n->v < t->n->n->v)
			inst_sb_rrb(ps);
		if (t->v < t->n->v && t->n->v > t->n->n->v && t->v < t->n->n->v)
			inst_rb(ps);
		if (t->v < t->n->v && t->n->v > t->n->n->v && t->v > t->n->n->v)
			inst_sb(ps);
		if (t->v > t->n->v && t->n->v < t->n->n->v && t->v < t->n->n->v)
			inst_rrb(ps);
		if (t->v > t->n->v && t->n->v < t->n->n->v && t->v > t->n->n->v)
			inst_rrb_sb(ps);
	}
}
