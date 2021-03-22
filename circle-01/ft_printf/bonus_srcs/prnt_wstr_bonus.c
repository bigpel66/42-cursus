/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prnt_wstr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 17:08:35 by jseo              #+#    #+#             */
/*   Updated: 2021/03/22 09:29:23 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_bool	prnt_wstr(t_form *f, wchar_t *s, t_bool str)
{
	if (str && !s)
		s = L"(null)";
	padd_str(f, str);
	if (MB_CUR_MAX != 4 && f->width != 0)
		++(f->p_len);
	if (f->flg & 128)
	{
		f->size += ft_wputstr_fd(s, f->fd);
		console_out(f, f->p_val, f->p_len);
		return (TR);
	}
	else if (f->flg & 16)
		f->p_val = '0';
	console_out(f, f->p_val, f->p_len);
	f->size += ft_wputstr_fd(s, f->fd);
	return (TR);
}
