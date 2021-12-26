/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jlstdelone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 19:34:53 by jseo              #+#    #+#             */
/*   Updated: 2021/12/27 01:19:24 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jfunction.h"

void	jlstdelone(t_lst *lst, void (*del)(void **))
{
	if (!lst)
		return ;
	if (del)
		del(&(lst->content));
	jfree((void **)(&lst));
}
