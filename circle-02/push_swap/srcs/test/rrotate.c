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
	inst_rra(ps);
	inst_rra(ps);
	jlstshow((*ps)->ah);
	inst_pb(ps);
	inst_pb(ps);
	inst_pb(ps);
	inst_rrb(ps);
	jlstshow((*ps)->bh);
	inst_rrr(ps);
	jlstshow((*ps)->ah);
	jlstshow((*ps)->bh);
}
