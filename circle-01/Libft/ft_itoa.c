/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 18:55:45 by jseo              #+#    #+#             */
/*   Updated: 2020/12/24 15:03:07 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_intlen(int n)
{
	size_t	len;

	len = n < 0 ? 1 : 0;
	while (1)
	{
		++len;
		if (!(n / 10))
			break ;
		n /= 10;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	int		neg;
	int		i;
	int		cnt;
	char	*buf;

	neg = n < 0 ? 1 : 0;
	i = neg ? 0 : -1;
	cnt = (int)ft_intlen(n);
	if (!(buf = (char *)ft_calloc(cnt + 1, sizeof(char))))
		return (NULL);
	if (neg)
		buf[0] = '-';
	while (++i < cnt)
	{
		buf[cnt - (!neg) - i] = "0123456789"[n % 10];
		n /= 10;
	}
	buf[cnt] = '\0';
	return (buf);
}
