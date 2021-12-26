/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jlstshow.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 23:00:06 by jseo              #+#    #+#             */
/*   Updated: 2021/12/26 23:26:34 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jfunction.h"

void	jlstshow(t_lst *lst)
{
	if (!lst)
		return ;
	jputstr("\nList Size: ", STDOUT_FILENO);
	jputnbr(jlstsize(lst), STDOUT_FILENO);
	jputstr("\nList Elements: ", STDOUT_FILENO);
	while (lst)
	{
		jputstr((char *)(lst->content), STDOUT_FILENO);
		jputchar('\t', STDOUT_FILENO);
		lst = lst->next;
	}
	jputendl("\n", STDOUT_FILENO);
}
