/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_dot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:48:50 by jseo              #+#    #+#             */
/*   Updated: 2021/03/18 12:48:52 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process_dot(t_form *f, const char *format, va_list ap)
{
	if (format[f->i] == '*')
	{
		++(f->i);
		f->prec = va_arg(ap, int);
		if (f->prec < 0)
			f->prec = IGNR;
		else if (f->prec == 2147483647)
			f->prec = ERR;
	}
	else if (is_digit(format[f->i]))
		f->prec = get_precision(f, format);
}
