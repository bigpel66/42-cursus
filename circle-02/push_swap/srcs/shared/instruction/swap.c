/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 17:49:58 by jseo              #+#    #+#             */
/*   Updated: 2021/06/17 15:55:09 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

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

void		inst_sa(t_ps **ps, char *cmd)
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
	jputstr(cmd, STDOUT_FILENO);
	if (*cmd)
		jputchar('\n', STDOUT_FILENO);
}

void		inst_sb(t_ps **ps, char *cmd)
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
	jputstr(cmd, STDOUT_FILENO);
	if (*cmd)
		jputchar('\n', STDOUT_FILENO);
}

void		inst_ss(t_ps **ps, char *cmd)
{
	inst_sa(ps, "");
	inst_sb(ps, "");
	jputstr(cmd, STDOUT_FILENO);
	jputchar('\n', STDOUT_FILENO);
}
