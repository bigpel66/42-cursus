/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:48:08 by jseo              #+#    #+#             */
/*   Updated: 2021/03/22 09:28:43 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

ssize_t	parse_format(t_form *f, const char *format, va_list ap)
{
	char		*tmp;
	long long	diff;

	while (*format)
	{
		tmp = ft_strchr(format, '%');
		diff = (long long)(tmp - format);
		if (tmp)
			f->size += write(f->fd, format, diff);
		else
		{
			f->size += write(f->fd, format, ft_strlen(format));
			break ;
		}
		form_read(f, tmp, ap);
		if (!is_error(f) && !(f->flg & 1))
			form_write(f, ap);
		if (is_error(f) || f->i == ERR)
			return (ERR);
		diff += (f->i);
		format += diff;
		form_init(f);
	}
	return (f->size);
}
