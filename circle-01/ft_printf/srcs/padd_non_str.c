/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padd_non_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 12:41:22 by jseo              #+#    #+#             */
/*   Updated: 2021/03/17 12:41:24 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	padd_non_str(t_form *f, char **pf, char **sf, int padd)
{
	int	ret;

	if (f->flg & 4)
		ret = allocate_with_dot(f, pf, sf, padd);
	else
		ret = allocate_without_dot(f, pf, sf, padd);
	if (!ret)
		return (0);
	return (1);
}
