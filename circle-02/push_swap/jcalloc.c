/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jcalloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:50:08 by jseo              #+#    #+#             */
/*   Updated: 2021/06/09 17:30:31 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	jcalloc(void **ptr, size_t cnt, size_t n)
{
	*ptr = (void *)malloc(cnt * n);
	if (!*ptr)
		return (FALSE);
	jmemset(*ptr, 0, cnt * n);
	return (true);
}
