/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padd_str_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:47:38 by jseo              #+#    #+#             */
/*   Updated: 2021/03/22 09:28:10 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	padd_str(t_form *f, t_bool str)
{
	f->p_len = 0;
	if (str && (f->flg & 4) && f->prec >= 0 && f->prec < f->dig)
	{
		f->dig = f->prec;
		if (f->prec < f->width)
			f->p_len = f->width - f->prec;
	}
	else if (f->dig < f->width)
		f->p_len = f->width - f->dig;
	f->p_val = ' ';
}
