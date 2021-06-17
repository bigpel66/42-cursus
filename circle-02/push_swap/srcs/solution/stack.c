/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:58:35 by jseo              #+#    #+#             */
/*   Updated: 2021/06/17 16:00:01 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		stack_len(t_ps **ps)
{
	(*ps)->al = jlstsize((*ps)->ah);
	(*ps)->bl = jlstsize((*ps)->bh);
}

static void	stack_record(t_ps **ps, int pos, int len)
{
	int		i;
	t_list	*lst;

	lst = (*ps)->ah;
	(*ps)->o = len;
	(*ps)->min_pos = pos;
	(*ps)->max_pos = pos + len - 1;
	if ((*ps)->max_pos >= (*ps)->al)
		(*ps)->max_pos %= (*ps)->al;
	i = -1;
	while (++i < (*ps)->min_pos)
		lst = lst->n;
	(*ps)->min = lst->v;
	i = -1;
	while (++i < len - 1)
		lst = lst->n;
	(*ps)->max = lst->v;
	printf("%d %d %d %d %d\n",
			(*ps)->min,
			(*ps)->max,
			(*ps)->o,
			(*ps)->min_pos,
			(*ps)->max_pos);
}

void		stack_series(t_ps **ps)
{
	t_list	*lst;
	t_list	*tmp;
	int		pos;
	int		i;

	lst = (*ps)->ah;
	pos = 0;
	while (pos < (*ps)->al)
	{
		tmp = lst;
		i = 1;
		while (i <= (*ps)->al && lst->v < lst->n->v && ++i)
			lst = lst->n;
		if ((*ps)->o <= i)
			stack_record(ps, pos, i);
		lst = lst->n;
		pos += i;
	}
}

void		stack_correction(t_ps **ps)
{
	int cnt;

	cnt = ((*ps)->max_pos + 1) % (*ps)->al;
	if (cnt > (*ps)->al / 2)
		cnt -= (*ps)->al;
	if (cnt > 0)
		iter(ps ,cnt, inst_ra, "ra");
	else
	{
		cnt = ~cnt + 1;
		iter(ps, cnt, inst_rra, "rra");
	}
}
