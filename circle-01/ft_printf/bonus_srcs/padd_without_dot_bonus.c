/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padd_without_dot_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:47:54 by jseo              #+#    #+#             */
/*   Updated: 2021/03/22 09:28:31 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	padd_without_dot(t_form *f, int padd)
{
	char	*tmp;

	tmp = NULL;
	f->p_len = 0;
	f->s_len = 0;
	if (f->dig + padd < f->width)
		f->p_len = f->width - (f->dig + padd);
	f->p_val = ' ';
	if (!(f->flg & 128) && f->flg & 16)
		padd_swap(f);
	f->s_val = '0';
}
