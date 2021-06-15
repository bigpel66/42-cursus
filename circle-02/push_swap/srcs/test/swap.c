/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 13:41:14 by jseo              #+#    #+#             */
/*   Updated: 2021/06/12 13:41:27 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_swap(t_ps **ps)
{
	int cnt;

	cnt = (*ps)->e / 2;
	while (cnt--)
		inst_pb(ps);
	print_stacks(ps);
	iterate(ps, 2, inst_sa);
	iterate(ps, 2, inst_sb);
	iterate(ps, 2, inst_ss);
}
