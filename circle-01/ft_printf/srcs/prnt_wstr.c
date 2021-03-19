/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prnt_wstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 17:08:35 by jseo              #+#    #+#             */
/*   Updated: 2021/03/19 17:08:37 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bool	prnt_wstr(t_form *f, wchar_t *s, t_bool str)
{
	if (!s)
		if (!alloc_null_wstr(&s))
			return (FL);
	f->dig = 1;
	if (str)
		f->dig = ft_strlen((const char *)s);
	padd_str(f, str);
	if (f->flg & 128)
	{
		f->size += write(f->fd, s, f->dig);
		console_out(f, f->p_val, f->p_len);
		return (TR);
	}
	else if (f->flg & 16)
		f->p_val = '0';
	console_out(f, f->p_val, f->p_len);
	f->size += write(f->fd, s, f->dig);
	return (TR);
}
