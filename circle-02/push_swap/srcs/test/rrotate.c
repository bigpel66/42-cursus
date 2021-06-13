/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_rrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 13:43:48 by jseo              #+#    #+#             */
/*   Updated: 2021/06/12 13:45:01 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_rrotate(t_ps **ps)
{
	int cnt;

	cnt = (*ps)->cnt / 2;
	while (cnt--)
		inst_pb(ps);
	iterate(ps, 4, inst_rra);
	iterate(ps, 4, inst_rrb);
	iterate(ps, 4, inst_rrr);
}
