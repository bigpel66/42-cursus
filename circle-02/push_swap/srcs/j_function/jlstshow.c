/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jlstshow.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 13:02:13 by jseo              #+#    #+#             */
/*   Updated: 2021/06/12 13:55:42 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	jlstshow(t_list *lst)
{
	t_list	*tmp;

	if (!lst)
		return ;
	tmp = lst;
	jputstr("\nList Size: ", STDOUT_FILENO);
	jputnbr(jlstsize(lst), STDOUT_FILENO);
	jputstr("\nList Elements: ", STDOUT_FILENO);
	while (true)
	{
		jputnbr(lst->v, STDOUT_FILENO);
		jputchar('\t', STDOUT_FILENO);
		lst = lst->n;
		if (lst == tmp)
		{
			jputchar('\n', STDOUT_FILENO);
			jputchar('\n', STDOUT_FILENO);
			return ;
		}
	}
}
