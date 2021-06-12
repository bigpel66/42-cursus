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
	inst_sa(ps);
	jlstshow((*ps)->ah);
	inst_pb(ps);
	inst_pb(ps);
	inst_pb(ps);
	inst_sb(ps);
	jlstshow((*ps)->ah);
	jlstshow((*ps)->bh);
}
