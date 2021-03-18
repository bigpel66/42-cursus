/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prnt_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:48:26 by jseo              #+#    #+#             */
/*   Updated: 2021/03/18 12:48:27 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bool	prnt_hex(t_form *f, t_dlong v, t_bool cap, t_bool adr)
{
	t_bool	pred;
	char	*hex;

	pred = (f->t == 3 || ((f->flg & 8) && (f->t == 7 || f->t == 8))) * 2;
	if (!adr && v == 0)
		pred = 0;
	if (!((hex = get_hex(f, v, cap))))
		return (FL);
	padd_non_str(f, pred);
	if (!(f->flg & 128))
		console_out(f, f->p_val, f->p_len);
	if (cap && pred)
		f->size += write(f->fd, "0X", pred);
	if (!cap && pred)
		f->size += write(f->fd, "0x", pred);
	console_out(f, f->s_val, f->s_len);
	f->size += write(f->fd, hex + ft_strlen(hex) - f->dig, f->dig);
	if (f->flg & 128)
		console_out(f, f->p_val, f->p_len);
	free_ptr((void *)(&hex));
	return (TR);
}
