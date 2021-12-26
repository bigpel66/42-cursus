/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jlstmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 20:19:35 by jseo              #+#    #+#             */
/*   Updated: 2021/12/26 23:08:51 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jfunction.h"

t_list	*jlstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*buf;
	t_list	*tmp;

	tmp = NULL;
	if (!lst || !f || !del)
		return (NULL);
	new = jlstnew(f(lst->content));
	if (!new)
		return (NULL);
	buf = new;
	lst = lst->next;
	while (lst)
	{
		tmp = jlstnew(f(lst->content));
		if (!tmp)
		{
			jlstclear(&new, del);
			return (NULL);
		}
		buf->next = tmp;
		buf = tmp;
		lst = lst->next;
	}
	return (new);
}
