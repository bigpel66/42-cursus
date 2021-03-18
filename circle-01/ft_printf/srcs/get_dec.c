/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:46:21 by jseo              #+#    #+#             */
/*   Updated: 2021/03/18 12:46:23 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_dec(t_form *f, long long v)
{
	long long	tmp;
	long long	i;
	char		*buf;

	f->dig = 1;
	tmp = v / 10;
	while (tmp && ++(f->dig))
		tmp /= 10;
	i = f->dig;
	if (f->flg & 4 && f->prec == 0 && v == 0)
		f->dig = 0;
	if (v < 0)
		v = ~(v) + 1;
	if (!dalloc((void **)(&buf), i + 1, sizeof(char)))
		return (NULL);
	while (1)
	{
		buf[--i] = "0123456789"[v % 10];
		if (!(v /= 10))
			break ;
	}
	return (buf);
}
