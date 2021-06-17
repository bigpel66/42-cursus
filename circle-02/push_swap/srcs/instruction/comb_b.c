/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comb_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 19:53:59 by jseo              #+#    #+#             */
/*   Updated: 2021/06/17 15:53:54 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	inst_sb_rrb(t_ps **ps)
{
	inst_sb(ps, "sb");
	inst_rrb(ps, "rrb");
}

void	inst_sb_rb(t_ps **ps)
{
	inst_sb(ps, "sb");
	inst_rb(ps, "rb");
}

void	inst_rrb_sb(t_ps **ps)
{
	inst_rrb(ps, "rrb");
	inst_sb(ps, "sb");
}
