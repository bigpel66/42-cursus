/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dec_signed_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:46:21 by jseo              #+#    #+#             */
/*   Updated: 2021/03/22 09:26:48 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_bool	get_dec_signed(t_form *f, intmax_t v, void **ptr)
{
	intmax_t	tmp;
	intmax_t	i;

	f->dig = 1;
	tmp = v / 10;
	while (tmp && ++(f->dig))
		tmp /= 10;
	i = f->dig;
	if (f->flg & 4 && f->prec == 0 && v == 0)
		f->dig = 0;
	if (v < 0)
		v = ~(v) + 1;
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
