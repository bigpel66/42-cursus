/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_dot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 12:32:14 by jseo              #+#    #+#             */
/*   Updated: 2021/03/17 12:32:15 by jseo             ###   ########.fr       */
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
			f->prec = -2;
		else if (f->prec == 2147483647)
			f->prec = -1;
	}
	else if (is_digit(format[f->i]))
		f->prec = get_precision(f, format);
}
