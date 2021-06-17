/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comb_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 19:53:59 by jseo              #+#    #+#             */
/*   Updated: 2021/06/17 15:53:42 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	inst_sa_rra(t_ps **ps)
{
	inst_sa(ps, "sa");
	inst_rra(ps, "rra");
}

void	inst_sa_ra(t_ps **ps)
{
	inst_sa(ps, "sa");
	inst_ra(ps, "ra");
}

void	inst_rra_sa(t_ps **ps)
{
	inst_rra(ps, "rra");
	inst_sa(ps, "sa");
}
