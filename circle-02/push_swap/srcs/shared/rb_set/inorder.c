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

#include "shared.h"

void	set_inorder(t_set **s)
{
	if (!*s)
		return ;
	set_inorder(&((*s)->l));
	jputnbr((*s)->v, STDOUT_FILENO);
	jputchar('\n', STDOUT_FILENO);
	set_inorder(&((*s)->r));
}
