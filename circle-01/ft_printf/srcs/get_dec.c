/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 12:36:02 by jseo              #+#    #+#             */
/*   Updated: 2021/03/17 12:36:04 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_dec(t_form *f, long long val)
{
	long long	tmp;
	long long	i;
	char		*buf;

	tmp = val;
	f->dig = 0;
	while (tmp && ++(f->dig))
		tmp /= 10;
	i = f->dig;
	if (val < 0)
		val = ~(val) + 1;
	if (!(buf = (char *)ft_calloc(i + 1, sizeof(char))))
		return (NULL);
	while (val)
	{
		buf[--i] = "0123456789"[val % 10];
		val /= 10;
	}
	return (buf);
}
