/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padd_non_str_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:47:33 by jseo              #+#    #+#             */
/*   Updated: 2021/03/22 09:28:03 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	padd_non_str(t_form *f, int padd)
{
	if (f->flg & 4)
		padd_with_dot(f, padd);
	else
		padd_without_dot(f, padd);
}
