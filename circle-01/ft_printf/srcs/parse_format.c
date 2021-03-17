/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 12:30:25 by jseo              #+#    #+#             */
/*   Updated: 2021/03/17 12:30:27 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_format(t_form *f, const char *format, va_list ap)
{
	size_t	diff;
	char	*tmp;

	while (*format)
	{
		tmp = ft_strchr(format, '%');
		diff = (size_t)(tmp - format);
		f->size += write(f->fd, format, diff);
		form_read(f, tmp, ap);
		if (is_error(f))
			return (-1);
		if (!(f->flg & 1))
			form_write(f, ap);
		if (f->i == -1)
			return (-1);
		diff += (f->i);
		format += diff;
		form_init(f);
	}
	return (f->size);
}
