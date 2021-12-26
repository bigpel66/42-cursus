/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jlstadd_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 17:30:00 by jseo              #+#    #+#             */
/*   Updated: 2021/12/26 23:25:46 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jfunction.h"

void	jlstadd_back(t_lst **lst, t_lst *new)
{
	t_lst	*tmp;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		tmp = jlstlast(*lst);
		tmp->next = new;
	}
}
