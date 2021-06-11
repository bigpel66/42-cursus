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

void	map_inorder(t_map **r)
{
	if (!*r)
		return ;
	map_inorder(&((*r)->l));
	jputstr((*r)->k, STDOUT_FILENO);
	jputchar(':', STDOUT_FILENO);
	jputstr((*r)->v, STDOUT_FILENO);
	jputchar('\n', STDOUT_FILENO);
	map_inorder(&((*r)->r));
}
