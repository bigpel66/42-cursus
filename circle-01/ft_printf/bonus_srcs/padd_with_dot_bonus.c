/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padd_with_dot_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:47:48 by jseo              #+#    #+#             */
/*   Updated: 2021/03/22 09:28:25 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	padd_with_dot(t_form *f, int padd)
{
	long long	val;

	val = f->dig;
	f->p_len = 0;
	f->s_len = 0;
	if (f->dig < f->prec)
	{
		val = f->prec;
		f->s_len = f->prec - f->dig;
	}
	if (val + padd < f->width)
		f->p_len = f->width - (val + padd);
	f->p_val = ' ';
	if (f->prec == -2 && !(f->flg & 128) && f->flg & 16)
		padd_swap(f);
	f->s_val = '0';
}
