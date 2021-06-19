/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jlstsize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 17:52:45 by jseo              #+#    #+#             */
/*   Updated: 2021/06/12 13:59:42 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

size_t	jlstsize(t_list *lst)
{
	size_t	i;
	t_list	*tmp;

	i = 0;
	if (!lst)
		return (i);
	tmp = lst;
	while (true)
	{
		tmp = tmp->n;
		++i;
		if (tmp == lst)
			return (i);
	}
}
