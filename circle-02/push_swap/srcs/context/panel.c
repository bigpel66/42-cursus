/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 10:20:04 by jseo              #+#    #+#             */
/*   Updated: 2021/06/14 13:49:14 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_clear(void)
{
	jputstr("\E[H\E[2J\E[3J", STDOUT_FILENO);
}

static void	print_number(t_list **lst, t_list **prv, bool former, bool print)
{
	size_t	num;
	size_t	pad;

	num = 0;
	if (*lst && print)
		num = jnumlen((*lst)->v);
	pad = 19 - num;
	if (*lst && print && !former)
		jputnbr((*lst)->v, STDOUT_FILENO);
	while (pad--)
		jputchar(' ', STDOUT_FILENO);
	if (*lst && print && former)
		jputnbr((*lst)->v, STDOUT_FILENO);
	if (print)
	{
		*prv = *lst;
		*lst = (*lst)->n;
	}
}

void		print_stacks(t_ps **ps)
{
	t_list		*tmp1;
	t_list		*tmp2;
	t_list		*prv1;
	t_list		*prv2;
	uint64_t	delay;

	tmp1 = (*ps)->ah;
	tmp2 = (*ps)->bh;
	prv1 = NULL;
	prv2 = NULL;
	delay = 1000000000;
	while (delay--)
		;
	print_clear();
	jputstr("            Stack A | STACK B            \n", STDOUT_FILENO);
	jputstr("-----------------------------------------\n", STDOUT_FILENO);
	while (true)
	{
		print_number(&tmp1, &prv1, true, prv1 != (*ps)->at);
		jputstr(" | ", STDOUT_FILENO);
		print_number(&tmp2, &prv2, false, prv2 != (*ps)->bt);
		jputchar('\n', STDOUT_FILENO);
		if (prv1 == (*ps)->at && prv2 == (*ps)->bt)
			return ;
	}
}
