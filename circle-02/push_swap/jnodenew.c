/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jnodenew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 15:08:30 by jseo              #+#    #+#             */
/*   Updated: 2021/06/10 15:34:00 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	jnodenew(t_node **n, int v)
{
	if (!jcalloc((void **)(n), 1, sizeof(t_node)))
		return (false);
	(*n)->v = v;
	(*n)->c = 'r';
	(*n)->l = NULL;
	(*n)->r = NULL;
	(*n)->p = NULL;
	return (true);
}
