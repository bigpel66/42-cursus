/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:48:44 by jseo              #+#    #+#             */
/*   Updated: 2021/03/19 17:23:16 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bool	process_bonus(t_form *f, va_list ap)
{
	t_bool	ret;

	ret = FL;
	if (f->t == 11)
		ret = process_length_nothing(f, ap);
	return (ret);
}
