/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 22:42:24 by jseo              #+#    #+#             */
/*   Updated: 2021/06/11 23:02:57 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	inst_rra(t_ps **ps)
{
	t_list	*tmp;

	if (jlstempty((*ps)->at))
		return ;
	tmp = (*ps)->at;
	(*ps)->ah = tmp;
	(*ps)->at = tmp->p;
}

void	inst_rrb(t_ps **ps)
{
	t_list	*tmp;

	if (jlstempty((*ps)->bt))
		return ;
	tmp = (*ps)->bt;
	(*ps)->bh = tmp;
	(*ps)->bt = tmp->p;
}

void	inst_rrr(t_ps **ps)
{
	inst_rra(ps);
	inst_rrb(ps);
}
