/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jlstclear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 15:25:13 by jseo              #+#    #+#             */
/*   Updated: 2021/06/09 15:32:13 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	jlstclear(t_list **lst)
{
	t_list	**tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = &((*lst)->p);
		jlstdelone(lst);
		lst = tmp;
	}
}
