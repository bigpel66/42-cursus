/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jlstnew.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 20:10:20 by jseo              #+#    #+#             */
/*   Updated: 2021/12/26 23:26:43 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jfunction.h"

t_lst	*jlstnew(void *content)
{
	t_lst	*tmp;

	if (!jcalloc((void **)(&tmp), 1, sizeof(t_lst)))
		return (NULL);
	tmp->content = content;
	tmp->next = NULL;
	return (tmp);
}
