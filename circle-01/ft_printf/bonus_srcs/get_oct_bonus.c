/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_oct_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:25:12 by jseo              #+#    #+#             */
/*   Updated: 2021/03/22 09:27:22 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_bool	get_oct(t_form *f, uintmax_t v, void **ptr)
{
	uintmax_t	tmp;
	uintmax_t	i;

	f->dig = 1;
	tmp = v / 8;
	while (tmp && ++(f->dig))
		tmp /= 8;
	i = f->dig;
	if (f->flg & 4 && f->prec == 0 && v == 0)
		f->dig = 0;
	if (!dalloc(ptr, i + 1, sizeof(char)))
		return (FL);
	while (1)
	{
		(*(char **)ptr)[--i] = "0123456789"[v % 8];
		if (!(v /= 8))
			break ;
	}
	return (TR);
}
