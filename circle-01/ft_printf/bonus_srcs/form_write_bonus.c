/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_write_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:45:53 by jseo              #+#    #+#             */
/*   Updated: 2021/03/22 09:25:23 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	form_write(t_form *f, va_list ap)
{
	t_bool	ret;

	ret = FL;
	if (f->t == 1 || f->t == 2 || f->t == 10)
		ret = process_length_str(f, ap);
	else if (f->t == 3)
		ret = prnt_hex(f, (uintmax_t)(va_arg(ap, void *)), FL, TR);
	else if (f->t >= 4 && f->t <= 9)
		ret = process_length_nbr(f, ap);
	else if (f->t >= 11 && f->t <= 14)
		ret = process_bonus(f, ap);
	if (!ret)
		f->i = ERR;
}
