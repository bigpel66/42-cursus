/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_length_nothing_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 17:13:44 by jseo              #+#    #+#             */
/*   Updated: 2021/03/22 09:30:15 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_bool	process_length_nothing(t_form *f, va_list ap)
{
	t_bool	ret;

	ret = FL;
	if (f->length == 1)
		ret = process_nothing_l(f, (void *)va_arg(ap, long *));
	else if (f->length == 2)
		ret = process_nothing_h(f, (void *)va_arg(ap, short *));
	else if (f->length == 3)
		ret = process_nothing_ll(f, (void *)va_arg(ap, long long *));
	else if (f->length == 4)
		ret = process_nothing_hh(f, (void *)va_arg(ap, char *));
	else
		ret = process_nothing(f, (void *)va_arg(ap, int *));
	return (ret);
}
