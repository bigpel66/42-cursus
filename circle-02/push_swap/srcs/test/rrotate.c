/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 13:43:48 by jseo              #+#    #+#             */
/*   Updated: 2021/06/17 15:56:12 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_rrotate(t_ps **ps)
{
	int	e;

	e = (*ps)->al / 2;
	iter(ps, e, inst_pb, "pb");
	iter(ps, 4, inst_rra, "rra");
	iter(ps, 4, inst_rrb, "rrb");
	iter(ps, 4, inst_rrr, "rrr");
}
