/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:58:35 by jseo              #+#    #+#             */
/*   Updated: 2021/06/17 18:58:08 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			stack_min(t_ps **ps)
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
	(*ps)->ol = len;
	(*ps)->os_pos = pos;
	(*ps)->of_pos = pos + len - 1;
	if ((*ps)->of_pos >= (*ps)->al)
		(*ps)->of_pos %= (*ps)->al;
	i = -1;
	while (++i < (*ps)->os_pos)
		lst = lst->n;
	(*ps)->min = lst->v;
	i = -1;
	while (++i < len - 1)
		lst = lst->n;
	(*ps)->max = lst->v;
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
		if ((*ps)->ol <= i)
			stack_record(ps, pos, i);
		lst = lst->n;
		pos += i;
	}
}

void		stack_correction(t_ps **ps, int i)
{
	if (i > (*ps)->al / 2)
		i -= (*ps)->al;
	if (i > 0)
		iter(ps, i, inst_ra, "ra");
	else
	{
		i = ~i + 1;
		iter(ps, i, inst_rra, "rra");
	}
}
