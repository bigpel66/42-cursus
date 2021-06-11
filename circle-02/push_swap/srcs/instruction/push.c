/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 16:36:13 by jseo              #+#    #+#             */
/*   Updated: 2021/06/11 16:40:17 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void node_export(t_list **head, t_list **tail)
{
	if (*head != (*head)->n)
	{
		*head = (*head)->n;
		(*head)->p = *tail;
		(*tail)->n = *head;
	}
	else
	{
		*head = NULL;
		*tail = NULL;
	}
}

static void node_import(t_list **head, t_list **tail, t_list **tmp)
{
	if (!(*head))
	{
		*head = *tmp;
		*tail = *tmp;
		(*head)->p = *tail;
		(*tail)->n = *head;
	}
	else
	{
		(*tmp)->n = *head;
		(*tmp)->p = *tail;
		(*head)->p = *tmp;
		(*tail)->n = *tmp;
		(*head) = *tmp;
	}
}

void inst_pa(t_ps **ps)
{
	t_list *tmp;

	if (!((*ps)->bh))
		return;
	tmp = (*ps)->bh;
	node_export(&((*ps)->bh), &((*ps)->bt));
	node_import(&((*ps)->ah), &((*ps)->at), &tmp);
}

void inst_pb(t_ps **ps)
{
	t_list *tmp;

	if (!((*ps)->ah))
		return;
	tmp = (*ps)->ah;
	node_export(&((*ps)->ah), &((*ps)->at));
	node_import(&((*ps)->bh), &((*ps)->bt), &tmp);
}