/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:47:00 by jseo              #+#    #+#             */
/*   Updated: 2021/03/18 12:47:01 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_width(t_form *f, const char *format)
{
	t_dlong	ret;
	t_dlong	max32;
	t_dlong	max64;

	ret = (format[(f->i)++]) - '0';
	max32 = ((t_dlong)1 << 31);
	max64 = ((t_dlong)1 << 63);
	while (is_digit(format[f->i]))
	{
		ret = ret * 10 + (format[(f->i)++] - '0');
		if (ret >= max64)
			ret -= max64;
	}
	if (ret >= max32 - 1 && ret <= max64 - 1)
		return (ERR);
	return (ret);
}
