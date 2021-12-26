/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jitoa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 22:04:48 by jseo              #+#    #+#             */
/*   Updated: 2021/12/26 22:55:03 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jfunction.h"

char	*jitoa(int n)
{
	int		neg;
	int		i;
	int		cnt;
	char	*buf;

	neg = 0;
	i = -1;
	if (n < 0)
		++neg;
	if (neg)
		++i;
	cnt = (int)jnumlen(n);
	if (!jcalloc((void **)(&buf), cnt + 1, sizeof(char)))
		return (NULL);
	if (neg)
		buf[0] = '-';
	while (++i < cnt)
	{
		buf[cnt - (!neg) - i] = "0123456789"[jabs(n % 10)];
		n /= 10;
	}
	buf[cnt] = '\0';
	return (buf);
}
