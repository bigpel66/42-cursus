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
	inst_ra(ps);
	inst_ra(ps);
	jlstshow((*ps)->ah);
	inst_pb(ps);
	inst_pb(ps);
	inst_pb(ps);
	inst_rb(ps);
	jlstshow((*ps)->bh);
	inst_rr(ps);
	jlstshow((*ps)->ah);
	jlstshow((*ps)->bh);
}
