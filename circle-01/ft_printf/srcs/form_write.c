/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 12:24:25 by jseo              #+#    #+#             */
/*   Updated: 2021/03/17 12:24:28 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	form_write(t_form *f, va_list ap)
{
	int	code;

	code = 0;
	if (f->t == 1 || f->t == 2 || f->t == 9)
		code = process_str(f, ap);
	else if (f->t == 3)
		code = print_hex(f, (unsigned long long)(va_arg(ap, void *)), 0);
	else if (f->t >= 4 && f->t <= 8)
		code = process_nbr(f, ap);
	else if (f->t >= 10 && f->t <= 13)
		code = process_bonus(f, ap);
	if (!code)
		f->i = -1;
}
