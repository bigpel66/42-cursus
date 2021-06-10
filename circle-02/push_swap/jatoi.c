/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jatoi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:56:47 by jseo              #+#    #+#             */
/*   Updated: 2021/06/10 14:20:24 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	jatoi(char **s, int *v)
{
	int	sign;
	int	tmp;

	while (jisspace(**s))
		++(*s);
	sign = 1;
	if (**s == '+' || **s == '-')
		if (*((*s)++) == '-')
			sign = -1;
	if (!jisdigit(**s))
		return (false);
	*v = (*((*s)++) - '0') * sign;
	while (jisdigit(**s))
	{
		tmp = (*((*s)++) - '0');
		if (sign < 0)
			tmp = ~(tmp) + 1;
		tmp = *v * 10 + tmp;
		if ((tmp >= 0) != (*v >= 0))
			return (false);
		*v = tmp;
	}
	return (true);
}
