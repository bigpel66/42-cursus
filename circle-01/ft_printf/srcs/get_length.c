/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 12:27:23 by jseo              #+#    #+#             */
/*   Updated: 2021/03/17 12:27:31 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_length(t_form *f, const char *format)
{
	int	opt;

	f->len = get_index("lh", format[(f->i)++]);
	opt = get_index("lh", format[f->i]);
	if (f->len == opt)
	{
		++(f->i);
		f->len += 2;
	}
}
