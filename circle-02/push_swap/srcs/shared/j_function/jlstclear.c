/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jlstclear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 15:25:13 by jseo              #+#    #+#             */
/*   Updated: 2021/06/15 14:40:26 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void	jlstclear(t_list *head, t_list *tail)
{
	t_list	*tmp;

	if (!(head && tail))
		return ;
	if (head == tail)
	{
		free(head);
		return ;
	}
	while (true)
	{
		tmp = tail->p;
		free(tail);
		if (tmp == head)
		{
			free(head);
			return ;
		}
		tail = tmp;
	}
}
