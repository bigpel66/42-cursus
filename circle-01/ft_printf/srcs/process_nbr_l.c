/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_nbr_l.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 18:16:54 by jseo              #+#    #+#             */
/*   Updated: 2021/03/18 18:16:56 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bool	process_nbr_l(t_form *f, va_list ap)
{
	t_bool	ret;

	ret = FL;
	if (f->t == 4 || f->t == 5)
		ret = prnt_dec(f, va_arg(ap, long), TR);
	else if (f->t == 6)
		ret = prnt_dec(f, va_arg(ap, unsigned long), FL);
	else if (f->t == 7)
		ret = prnt_hex(f, va_arg(ap, unsigned long), FL, FL);
	else if (f->t == 8)
		ret = prnt_hex(f, va_arg(ap, unsigned long), TR, FL);
	return (ret);
}
