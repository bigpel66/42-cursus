/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 21:20:54 by jseo              #+#    #+#             */
/*   Updated: 2021/06/19 21:25:02 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	do_push(t_ps **ps, char *line, size_t len)
{
	if (!jstrncmp(line, "pa", len))
		inst_pa(ps, "");
	else if (!jstrncmp(line, "pb", len))
		inst_pb(ps, "");
}

void	do_rotate(t_ps **ps, char *line, size_t len)
{
	if (!jstrncmp(line, "ra", len))
		inst_ra(ps, "");
	else if (!jstrncmp(line, "rb", len))
		inst_rb(ps, "");
	else if (!jstrncmp(line, "rr", len))
		inst_rr(ps, "");
}

void	do_rrotate(t_ps **ps, char *line, size_t len)
{
	if (!jstrncmp(line, "rra", len))
		inst_rra(ps, "");
	else if (!jstrncmp(line, "rrb", len))
		inst_rrb(ps, "");
	else if (!jstrncmp(line, "rrr", len))
		inst_rrr(ps, "");
}

void	do_swap(t_ps **ps, char *line, size_t len)
{
	if (!jstrncmp(line, "sa", len))
		inst_sa(ps, "");
	else if (!jstrncmp(line, "sb", len))
		inst_sb(ps, "");
	else if (!jstrncmp(line, "ss", len))
		inst_ss(ps, "");
}
