/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padd_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:47:43 by jseo              #+#    #+#             */
/*   Updated: 2021/03/18 12:47:44 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	padd_swap(t_form *f)
{
	char		tmp;
	long long	len;

	tmp = f->p_val;
	f->p_val = f->s_val;
	f->s_val = tmp;
	len = f->p_len;
	f->p_len = f->s_len;
	f->s_len = len;
}
