/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jcalloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 23:04:45 by jseo              #+#    #+#             */
/*   Updated: 2021/08/04 23:05:14 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	jcalloc(void **ptr, size_t cnt, size_t n)
{
	*ptr = (void *)malloc(cnt * n);
	if (!*ptr)
		return (false);
	jmemset(*ptr, 0, cnt * n);
	return (true);
}
