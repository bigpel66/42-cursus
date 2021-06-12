/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 13:07:07 by jseo              #+#    #+#             */
/*   Updated: 2021/06/12 13:52:03 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_push(t_ps **ps)
{
	inst_pb(ps);
	inst_pb(ps);
	inst_pb(ps);
	jlstshow((*ps)->ah);
	jlstshow((*ps)->bh);
	inst_pa(ps);
	inst_pa(ps);
	jlstshow((*ps)->ah);
	jlstshow((*ps)->bh);
	inst_pa(ps);
	if (jlstempty((*ps)->bh))
		jputstr("Empty!\n", STDOUT_FILENO);
}
