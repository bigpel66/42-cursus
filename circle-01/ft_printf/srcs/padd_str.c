/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padd_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 12:41:31 by jseo              #+#    #+#             */
/*   Updated: 2021/03/17 12:41:33 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*padd_str(t_form *f, long long *p_len, int string)
{
	char	*buf;

	*p_len = 0;
	if (string && f->prec >= 0 && f->prec < f->dig)
	{
		f->dig = f->prec;
		if (f->prec < f->width)
			*p_len = f->width - f->prec;
	}
	else if (f->dig < f->width)
		*p_len = f->width - f->dig;
	if (!(buf = (char *)ft_calloc(*p_len + 1, sizeof(char))))
		return (NULL);
	ft_memset(buf, 32, *p_len);
	return (buf);
}
