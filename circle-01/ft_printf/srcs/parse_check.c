/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:48:01 by jseo              #+#    #+#             */
/*   Updated: 2021/03/18 12:48:02 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	parse_check(const char *format, va_list ap)
{
	ssize_t	bytes;
	t_form	*f;

	bytes = 0;
	f = NULL;
	if (!dalloc((void **)(&f), 1, sizeof(t_form)))
		return (ERR);
	f->fd = 1;
	if (!(ft_strchr(format, '%')))
		bytes = write(f->fd, format, ft_strlen(format));
	else
		bytes = parse_format(f, format, ap);
	free_ptr((void **)(&f));
	return (bytes);
}
