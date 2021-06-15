/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 19:53:59 by jseo              #+#    #+#             */
/*   Updated: 2021/06/15 19:54:00 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	inst_ss_rra(t_ps **ps)
{
	inst_ss(ps);
	inst_rra(ps);
}

void	inst_sa_ra(t_ps **ps)
{
	inst_sa(ps);
	inst_ra(ps);
}

void	inst_sb_rrb(t_ps **ps)
{
	inst_sb(ps);
	inst_rrb(ps);
}

void	inst_rrb_sb(t_ps **ps)
{
	inst_rrb(ps);
	inst_sb(ps);
}
