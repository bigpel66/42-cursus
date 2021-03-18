/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:46:35 by jseo              #+#    #+#             */
/*   Updated: 2021/03/18 12:46:36 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_hex(t_form *f, t_long v, t_bool cap)
{
	int		shift;
	int		offset;
	int		i;
	char	*buf;

	f->dig = 1;
	shift = sizeof(void *) * 2;
	offset = shift;
	if (!dalloc((void **)(&buf), offset + 1, sizeof(char)))
		return (NULL);
	while (--shift >= 0)
	{
		i = (val & (t_long)15 << (shift * 4)) >> (shift * 4);
		if (cap)
			buf[offset - (shift + 1)] = "0123456789ABCDEF"[i];
		else
			buf[offset - (shift + 1)] = "0123456789abcdef"[i];
		if (f->dig == 1 && i)
			f->dig = shift + 1;
	}
	if (f->flg & 4 && f->prec == 0 && v == 0)
		f->dig = 0;
	return (buf);
}
