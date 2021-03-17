/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 12:30:14 by jseo              #+#    #+#             */
/*   Updated: 2021/03/17 12:30:17 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_check(const char *format, va_list ap)
{
	int		bytes;
	t_form	*f;

	bytes = 0;
	f = NULL;
	if (!(f = form_create(f)))
		return (-1);
	f->fd = 1;
	if (!(ft_strchr(format, '%')))
		bytes = write(f->fd, format, ft_strlen(format));
	else
		bytes = parse_format(f, format, ap);
	free_ptr((void *)(&f));
	return (bytes);
}
