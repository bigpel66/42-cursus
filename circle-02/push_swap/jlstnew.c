/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jlstnew.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:46:50 by jseo              #+#    #+#             */
/*   Updated: 2021/06/10 11:44:19 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	jlstnew(t_list **lst, int v)
{
	if (!jcalloc((void **)(lst), 1, sizeof(t_list)))
		return (false);
	(*lst)->v = v;
	(*lst)->n = NULL;
	(*lst)->p = NULL;
	return (true);
}
