/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dec_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 17:09:27 by jseo              #+#    #+#             */
/*   Updated: 2021/03/19 17:09:28 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bool	get_dec_unsigned(t_form *f, uintmax_t v, void **ptr)
{
	uintmax_t	tmp;
	uintmax_t	i;

	f->dig = 1;
	tmp = v / 10;
	while (tmp && ++(f->dig))
		tmp /= 10;
	i = f->dig;
	if (f->flg & 4 && f->prec == 0 && v == 0)
		f->dig = 0;
	if (!dalloc(ptr, i + 1, sizeof(char)))
		return (FL);
	while (1)
	{
		(*(char **)ptr)[--i] = "0123456789"[v % 10];
		if (!(v /= 10))
			break ;
	}
	return (TR);
}
