/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:48:44 by jseo              #+#    #+#             */
/*   Updated: 2021/03/18 12:48:45 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bool	process_bonus(t_form *f, va_list ap)
{
	int	test1;
	int	test2;

	test1 = f->flg & 0;
	test2 = va_arg(ap, int);
	return (1);
}
