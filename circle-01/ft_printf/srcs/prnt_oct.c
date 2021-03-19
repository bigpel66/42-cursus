/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prnt_oct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:03:19 by jseo              #+#    #+#             */
/*   Updated: 2021/03/19 15:03:21 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bool	prnt_oct(t_form *f, uintmax_t v)
{
	t_bool	pred;
	char	*oct;

	pred = ((f->flg & 8) && (f->t == 7));
	if (v == 0)
		pred = 0;
	if (!get_oct(f, v, (void **)(&oct)))
		return (FL);
	padd_non_str(f, pred);
	if (!(f->flg & 128))
		console_out(f, f->p_val, f->p_len);
	if (pred)
		f->size += write(f->fd, "0", pred);
	console_out(f, f->s_val, f->s_len);
	f->size += write(f->fd, oct + ft_strlen(oct) - f->dig, f->dig);
	if (f->flg & 128)
		console_out(f, f->p_val, f->p_len);
	free_ptr((void **)(&oct));
	return (TR);
}
