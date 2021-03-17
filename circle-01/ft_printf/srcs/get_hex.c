/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 12:36:27 by jseo              #+#    #+#             */
/*   Updated: 2021/03/17 12:39:28 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_hex(t_form *f, unsigned long long val, int capital)
{
	int		shift;
	int		offset;
	int		i;
	char	*buf;

	f->dig = 0;
	shift = sizeof(void *) * 2;
	offset = shift;
	if (!(buf = (char *)ft_calloc(offset + 1, sizeof(char))))
		return (NULL);
	while (--shift >= 0)
	{
		i = (val & (unsigned long long)15 << (shift * 4)) >> (shift * 4);
		if (capital)
			buf[offset - (shift + 1)] = "0123456789ABCDEF"[i];
		else
			buf[offset - (shift + 1)] = "0123456789abcdef"[i];
		if (!f->dig && i)
			f->dig = shift + 1;
	}
	return (buf);
}
