/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_nbr_ll.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 18:17:02 by jseo              #+#    #+#             */
/*   Updated: 2021/03/19 15:35:38 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bool	process_nbr_ll(t_form *f, va_list ap)
{
	t_bool	ret;

	ret = FL;
	if (f->t == 4 || f->t == 5)
		ret = prnt_signed_dec(f, va_arg(ap, long long), TR);
	else if (f->t == 6)
		ret = prnt_unsigned_dec(f, va_arg(ap, unsigned long long), FL);
	else if (f->t == 7)
		ret = prnt_oct(f, va_arg(ap, unsigned long long));
	else if (f->t == 8)
		ret = prnt_hex(f, va_arg(ap, unsigned long long), FL, FL);
	else if (f->t == 9)
		ret = prnt_hex(f, va_arg(ap, unsigned long long), TR, FL);
	return (ret);
}
