/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:48:44 by jseo              #+#    #+#             */
/*   Updated: 2021/03/18 18:16:38 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bool	process_bonus(t_form *f, va_list ap)
{
	t_bool	ret;

	ret = FL;
	if (f->t == 10)
		ret = prnt_nothing(f, va_arg(ap, int *));
	else if (f->t == 11)
		ret = TR;
	else if (f->t == 12)
		ret = TR;
	else if (f->t == 13)
		ret = TR;
	return (ret);
}
