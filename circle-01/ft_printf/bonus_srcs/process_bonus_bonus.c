/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:48:44 by jseo              #+#    #+#             */
/*   Updated: 2021/03/22 09:29:37 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_bool	process_bonus(t_form *f, va_list ap)
{
	t_bool	ret;

	ret = FL;
	if (f->t == 11)
		ret = process_length_nothing(f, ap);
	return (ret);
}
