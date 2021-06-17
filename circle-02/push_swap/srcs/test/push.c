/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 13:07:07 by jseo              #+#    #+#             */
/*   Updated: 2021/06/17 15:55:32 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_push(t_ps **ps)
{
	iter(ps, (*ps)->al, inst_pb, "pb");
	iter(ps, (*ps)->al, inst_pa, "pa");
}