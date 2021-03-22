/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console_out_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:45:34 by jseo              #+#    #+#             */
/*   Updated: 2021/03/22 09:24:45 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	console_out(t_form *f, t_char c, long long len)
{
	while (len--)
		f->size += write(f->fd, &c, 1);
}
