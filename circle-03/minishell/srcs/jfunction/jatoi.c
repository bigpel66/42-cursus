/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jatoi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:56:47 by jseo              #+#    #+#             */
/*   Updated: 2022/01/03 20:03:25 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jfunction.h"

int	jatoi(const char *s)
{
	int			sign;
	long long	res;

	sign = 1;
	res = 0;
	while (jisspace(*s))
		++s;
	if (*s == '-' || *s == '+')
		if (*s++ == '-')
			sign = -1;
	while (jisdigit(*s))
	{
		if ((res >= 0) != ((res << 1) >= 0)
			|| (res >= 0) != ((res << 2) >= 0)
			|| (res >= 0) != ((res << 3) >= 0)
			|| (res >= 0) != (res * 10 + (*s - '0') >= 0))
		{
			if (sign == 1)
				return (-1);
			else
				return (0);
		}
		res = res * 10 + (*s++ - '0');
	}
	return (res * sign);
}
