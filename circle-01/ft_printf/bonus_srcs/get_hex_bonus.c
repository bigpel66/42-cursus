/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hex_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:46:35 by jseo              #+#    #+#             */
/*   Updated: 2021/03/22 09:27:07 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_bool	get_hex(t_form *f, uintmax_t v, t_bool cap, void **ptr)
{
	int	shift;
	int	offset;
	int	i;

	f->dig = 1;
	shift = sizeof(uintmax_t) * 2;
	offset = shift;
	if (!dalloc(ptr, offset + 1, sizeof(char)))
		return (FL);
	while (--shift >= 0)
	{
		i = (v & (uintmax_t)15 << (shift * 4)) >> (shift * 4);
		if (cap)
			(*(char **)ptr)[offset - (shift + 1)] = "0123456789ABCDEF"[i];
		else
			(*(char **)ptr)[offset - (shift + 1)] = "0123456789abcdef"[i];
		if (f->dig == 1 && i)
			f->dig = shift + 1;
	}
	if (f->flg & 4 && f->prec == 0 && v == 0)
		f->dig = 0;
	return (TR);
}
