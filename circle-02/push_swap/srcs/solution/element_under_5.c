/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_under_5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 19:57:15 by jseo              #+#    #+#             */
/*   Updated: 2021/06/15 20:03:27 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_5_asc(t_ps **ps, int e, int mid)
{
	int	cnt;

	cnt = 0;
	while (cnt < 2)
	{
		if ((*ps)->ah->v < mid && ++cnt)
			inst_pb(ps);
		else
			inst_ra(ps);
	}
	sort_3_dsc(ps, 2);
	sort_3_asc(ps, e - 2);
	inst_pa(ps);
	inst_pa(ps);
}

static void	sort_5_dsc(t_ps **ps, int e, int mid)
{
	int	cnt;

	cnt = 0;
	while (cnt < 2)
	{
		if ((*ps)->bh->v > mid && ++cnt)
			inst_pa(ps);
		else
			inst_rb(ps);
	}
	sort_3_asc(ps, 2);
	sort_3_dsc(ps, e - 2);
	inst_pb(ps);
	inst_pb(ps);
}

static bool	sort_5_term(t_set **mid, int **arr, bool sig)
{
	set_delete(mid);
	jfree((void **)(arr));
	return (sig);
}

bool		sort_5(t_ps **ps, int e, bool asc)
{
	int		i;
	int		*arr;
	t_list	*tmp;
	t_set	*mid;

	if (!jcalloc((void **)(&arr), 5, sizeof(int)))
		return (false);
	tmp = (*ps)->ah;
	mid = NULL;
	if (!asc)
		tmp = (*ps)->bh;
	i = -1;
	while (++i < e)
	{
		if (!set_insert(&mid, tmp->v))
			return (sort_5_term(&mid, &arr, false));
		tmp = tmp->n;
	}
	i = 0;
	set_inorder_save(&mid, arr, 5, &i);
	if (asc)
		sort_5_asc(ps, e, arr[2]);
	else
		sort_5_dsc(ps, e, arr[2]);
	return (sort_5_term(&mid, &arr, true));
}
