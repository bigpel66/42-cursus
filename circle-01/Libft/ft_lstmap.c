/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 20:19:35 by jseo              #+#    #+#             */
/*   Updated: 2020/12/30 10:52:45 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*buf;
	t_list	*tmp;

	new = NULL;
	buf = NULL;
	tmp = NULL;
	if (!f || !del)
		return (NULL);
	if (!lst || !(new = ft_lstnew(f(lst->content))))
		return (NULL);
	buf = new;
	lst = lst->next;
	while (lst)
	{
		if (!(tmp = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		buf->next = tmp;
		buf = tmp;
		lst = lst->next;
	}
	return (new);
}
