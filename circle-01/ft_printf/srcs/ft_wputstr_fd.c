/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wputstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 14:08:12 by jseo              #+#    #+#             */
/*   Updated: 2021/03/21 14:08:14 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_wputstr_fd(wchar_t *s, int fd)
{
	ssize_t	len;

	len = 0;
	if (!ft_wcheck_mb_cur_max(s))
		return (ERR);
	while (*s)
		len += ft_wputchar_fd(*s++, fd);
	return (len);
}
