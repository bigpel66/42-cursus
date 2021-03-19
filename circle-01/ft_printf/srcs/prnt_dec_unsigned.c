/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prnt_dec_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 17:09:40 by jseo              #+#    #+#             */
/*   Updated: 2021/03/19 17:09:41 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bool	prnt_dec_unsigned(t_form *f, uintmax_t v, t_bool sig)
{
	t_bool	pred;
	char	*dec;

	pred = sig && (v < 0 || (v >= 0 && (f->flg & 64 || f->flg & 32)));
	if (!get_dec_unsigned(f, v, (void **)(&dec)))
		return (FL);
	padd_non_str(f, pred);
	if (sig && v >= 0 && !(f->flg & 64) && f->flg & 32)
		f->size += write(f->fd, " ", 1);
	if (sig && v < 0 && f->p_val == '0')
		f->size += write(f->fd, "-", 1);
	if (!(f->flg & 128))
		console_out(f, f->p_val, f->p_len);
	if (sig && v < 0 && f->p_val != '0')
		f->size += write(f->fd, "-", 1);
	else if (sig && f->flg & 64)
		f->size += write(f->fd, "+", 1);
	console_out(f, f->s_val, f->s_len);
	f->size += write(f->fd, dec, f->dig);
	if (f->flg & 128)
		console_out(f, f->p_val, f->p_len);
	free_ptr((void **)(&dec));
	return (TR);
}
