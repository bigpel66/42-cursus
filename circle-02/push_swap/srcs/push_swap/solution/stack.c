/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:58:35 by jseo              #+#    #+#             */
/*   Updated: 2021/06/18 15:26:51 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			find_minimum(t_ps **ps)
{
	int		i;
	t_list	*tmp;

	i = -1;
	tmp = (*ps)->ah;
	while (++i < (*ps)->al)
	{
		if (tmp->v == (*ps)->min)
			break ;
		tmp = tmp->n;
	}
	return (i);
}

int			find_normalize(int *val, int len)
{
	if (*val > len / 2)
		*val -= len;
	if (*val < 0)
		return (~(*val) + 1);
	return (*val);
}

static void	stack_record(t_base *base, int pos, int len, int lstsize)
{
	base->len = len;
	base->s_index = pos;
	base->f_index = pos + len - 1;
	if (base->f_index >= lstsize)
		base->f_index %= lstsize;
}

void		stack_series(t_ps **ps, t_base *base)
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
		if (base->len <= i)
			stack_record(base, pos, i, (*ps)->al);
		lst = lst->n;
		pos += i;
	}
}

void		stack_correction(t_ps **ps, int pos)
{
	int	abs;

	abs = find_normalize(&pos, (*ps)->al);
	if (pos >= 0)
		iter(ps, abs, inst_ra, "ra");
	else
		iter(ps, abs, inst_rra, "rra");
}
