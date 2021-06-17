/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 13:41:52 by jseo              #+#    #+#             */
/*   Updated: 2021/06/17 15:56:08 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_rotate(t_ps **ps)
{
	int	e;

	e = (*ps)->al / 2;
	iter(ps, e, inst_pb, "pb");
	iter(ps, 4, inst_ra, "ra");
	iter(ps, 4, inst_rb, "rb");
	iter(ps, 4, inst_rr, "rr");
}
