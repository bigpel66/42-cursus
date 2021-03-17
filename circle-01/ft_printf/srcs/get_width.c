/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 12:27:48 by jseo              #+#    #+#             */
/*   Updated: 2021/03/17 12:27:57 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_width(t_form *f, const char *format)
{
	unsigned long long	ret;
	unsigned long long	max32;
	unsigned long long	max64;

	ret = (format[(f->i)++]) - '0';
	max32 = ((unsigned long long)1 << 31);
	max64 = ((unsigned long long)1 << 63);
	while (is_digit(format[f->i]))
	{
		ret = ret * 10 + (format[(f->i)++] - '0');
		if (ret >= max64)
			ret -= max64;
	}
	if (ret >= max32 - 1 && ret <= max64 - 1)
		return (-1);
	return (ret);
}
