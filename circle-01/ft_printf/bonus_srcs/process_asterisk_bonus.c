/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_asterisk_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:48:38 by jseo              #+#    #+#             */
/*   Updated: 2021/03/22 09:29:30 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	process_asterisk(t_form *f, va_list ap)
{
	f->width = va_arg(ap, int);
	if (f->width >= -2147483646 && f->width <= 2147483646)
	{
		if (f->width < 0)
		{
			f->flg |= (1 << 7);
			f->width = ~(f->width) + 1;
		}
	}
	else
		f->width = ERR;
}
