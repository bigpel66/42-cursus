/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 18:15:41 by jseo              #+#    #+#             */
/*   Updated: 2021/03/08 18:34:34 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_format(const char *format, va_list ap)
{
	int		bytes;
	t_info	*i;

	bytes = 0;
	i = NULL;
	if (!(i = ft_create_info(i)))
		return (-1);
	i->fd = 1;
	if (!(ft_strchr(format, '%')))
		bytes = write(i->fd, format, ft_strlen(format));
	else
		bytes = ft_process_info(i, format, ap);
	if (i)
		free(i);
	i = NULL;
	return (bytes);
}
