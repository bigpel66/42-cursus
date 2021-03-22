/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_length_nbr_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 18:16:42 by jseo              #+#    #+#             */
/*   Updated: 2021/03/22 09:29:58 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_bool	process_length_nbr(t_form *f, va_list ap)
{
	t_bool	ret;

	ret = FL;
	if (f->length == 1)
		ret = process_nbr_l(f, ap);
	else if (f->length == 2)
		ret = process_nbr_h(f, ap);
	else if (f->length == 3)
		ret = process_nbr_ll(f, ap);
	else if (f->length == 4)
		ret = process_nbr_hh(f, ap);
	else
		ret = process_nbr(f, ap);
	return (ret);
}
