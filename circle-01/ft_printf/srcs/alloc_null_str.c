/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_null_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:45:24 by jseo              #+#    #+#             */
/*   Updated: 2021/03/18 12:45:26 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*alloc_null_str(void)
{
	char	*buf;

	if (!dalloc((void **)(&buf), 7, sizeof(char)))
		return (NULL);
	buf[0] = '(';
	buf[1] = 'n';
	buf[2] = 'u';
	buf[3] = 'l';
	buf[4] = 'l';
	buf[5] = ')';
	return (buf);
}
