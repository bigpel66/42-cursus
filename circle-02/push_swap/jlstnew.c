/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jlstnew.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:46:50 by jseo              #+#    #+#             */
/*   Updated: 2021/06/09 15:07:38 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	jlstnew(t_list **lst, int v)
{
	if (!jcalloc((void **)(lst), 1, sizeof(t_list)))
		return (FALSE);
	(*lst)->v = v;
	(*lst)->p = NULL;
	return (TRUE);
}
