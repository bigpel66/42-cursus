/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prnt_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:48:31 by jseo              #+#    #+#             */
/*   Updated: 2021/03/21 14:23:46 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bool	prnt_str(t_form *f, char *s, t_bool str)
{
	if (str && !s)
		s = "(null)";
	f->dig = 1;
	if (str)
		f->dig = ft_strlen(s);
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
