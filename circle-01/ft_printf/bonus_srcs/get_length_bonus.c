/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_length_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:46:49 by jseo              #+#    #+#             */
/*   Updated: 2021/03/22 09:27:16 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	get_length(t_form *f, const char *format)
{
	int	opt;

	f->length = get_index("lh", format[(f->i)++]);
	opt = get_index("lh", format[f->i]);
	if (f->length == opt)
	{
		++(f->i);
		f->length += 2;
	}
}
