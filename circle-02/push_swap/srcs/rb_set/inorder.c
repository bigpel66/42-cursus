/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inorder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 23:34:18 by jseo              #+#    #+#             */
/*   Updated: 2021/06/11 10:54:53 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_inorder(t_set **r)
{
	if (!*r)
		return ;
	set_inorder(&((*r)->l));
	jputnbr((*r)->v, STDOUT_FILENO);
	jputchar('\n', STDOUT_FILENO);
	set_inorder(&((*r)->r));
}
