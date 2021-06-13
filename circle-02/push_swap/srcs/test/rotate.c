/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 13:41:52 by jseo              #+#    #+#             */
/*   Updated: 2021/06/12 13:43:23 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_rotate(t_ps **ps)
{
	int cnt;

	cnt = (*ps)->cnt / 2;
	while (cnt--)
		inst_pb(ps);
	iterate(ps, 4, inst_ra);
	iterate(ps, 4, inst_rb);
	iterate(ps, 4, inst_rr);
}
