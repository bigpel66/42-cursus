/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 17:49:58 by jseo              #+#    #+#             */
/*   Updated: 2021/06/11 23:12:34 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	node_corr(t_list **head, t_list **t1, t_list **t2)
{
	t_list	*r1;
	t_list	*r2;

	r1 = (*t1)->p;
	r2 = (*t2)->n;
	(*t1)->n = r2;
	(*t1)->p = (*t2);
	(*t2)->n = (*t1);
	(*t2)->p = r1;
	r1->n = (*t2);
	r2->p = (*t1);
	*head = *t2;
}

void		inst_sa(t_ps **ps)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (jlstsize((*ps)->ah) < (size_t)2)
		return ;
	tmp1 = (*ps)->ah;
	tmp2 = (*ps)->ah->n;
	if (jlstsize((*ps)->ah) == (size_t)2)
	{
		(*ps)->ah = tmp2;
		(*ps)->at = tmp1;
	}
	else
		node_corr(&((*ps)->ah), &tmp1, &tmp2);
	++((*ps)->i);
	print_stacks(ps);
}

void		inst_sb(t_ps **ps)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (jlstsize((*ps)->bh) < (size_t)2)
		return ;
	tmp1 = (*ps)->bh;
	tmp2 = (*ps)->bh->n;
	if (jlstsize((*ps)->bh) == (size_t)2)
	{
		(*ps)->bh = tmp2;
		(*ps)->bt = tmp1;
	}
	else
		node_corr(&((*ps)->bh), &tmp1, &tmp2);
	++((*ps)->i);
	print_stacks(ps);
}

void		inst_ss(t_ps **ps)
{
	inst_sa(ps);
	inst_sb(ps);
	--((*ps)->i);
}
