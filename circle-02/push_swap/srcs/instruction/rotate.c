/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 22:42:17 by jseo              #+#    #+#             */
/*   Updated: 2021/06/11 22:42:20 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	inst_ra(t_ps **ps)
{
	t_list *tmp;

	if (jlstempty((*ps)->ah))
		return ;
	tmp = (*ps)->ah;
	(*ps)->ah = tmp->n;
	(*ps)->at = tmp;
}

void	inst_rb(t_ps **ps)
{
	t_list *tmp;

	if (jlstempty((*ps)->bh))
		return ;
	tmp = (*ps)->bh;
	(*ps)->bh = tmp->n;
	(*ps)->bt = tmp;
}

void	inst_rr(t_ps **ps)
{
	inst_ra(ps);
	inst_rb(ps);
}
