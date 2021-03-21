/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wputchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 14:08:03 by jseo              #+#    #+#             */
/*   Updated: 2021/03/21 15:25:30 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_wputchar_fd(wchar_t c, int fd)
{
	ssize_t	len;
	char	s[5];

	len = 0;
	ft_memset(s, 0, 5);
	if ((c >= 0 && c <= 127) || (c >= 0 && c <= 255 && MB_CUR_MAX == 1))
		len += write(fd, &c, 1);
	else
	{
		if (!ft_wtob(s, c))
			return (ERR);
		len += write(fd, s, ft_strlen(s));
	}
	return (len);
}
