/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:46:05 by jseo              #+#    #+#             */
/*   Updated: 2021/03/22 11:27:56 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	ssize_t	ret;
	va_list	ap;

	if (!format)
		return (ERR);
	va_start(ap, format);
	ret = parse_check(format, ap);
	va_end(ap);
	return (ret);
}
