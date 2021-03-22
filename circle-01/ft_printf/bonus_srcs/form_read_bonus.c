/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_read_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:45:49 by jseo              #+#    #+#             */
/*   Updated: 2021/03/22 09:25:20 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	form_read(t_form *f, const char *format, va_list ap)
{
	++(f->i);
	while (1)
	{
		if (is_flag(format[f->i]))
			get_flag(f, format, ap);
		else if (is_digit(format[f->i]))
			f->width = get_width(f, format);
		else if (is_length(format[f->i]))
			get_length(f, format);
		else if (is_type(format[f->i]))
		{
			f->t = get_index("cspdiuoxX%nfge", format[(f->i)++]);
			break ;
		}
		else
		{
			f->flg |= 1;
			break ;
		}
	}
}
