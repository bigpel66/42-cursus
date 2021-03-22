/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_precision_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:46:53 by jseo              #+#    #+#             */
/*   Updated: 2021/03/22 09:27:28 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

long long	get_precision(t_form *f, const char *format)
{
	long long	ret;
	long long	max;

	ret = (format[(f->i)++]) - '0';
	max = ((long long)1 << 32);
	while (is_digit(format[f->i]))
	{
		ret = ret * 10 + (format[(f->i)++] - '0');
		if (ret >= 2147483648)
			ret -= max;
	}
	if (ret == 2147483647)
		return (ERR);
	else if (ret >= -2147483646 && ret <= -1)
		return (IGNR);
	else if (ret == -2147483648 || ret == -2147483647)
		ret += max;
	return (ret);
}
