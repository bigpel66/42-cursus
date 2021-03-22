/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_str_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:49:01 by jseo              #+#    #+#             */
/*   Updated: 2021/03/22 09:31:55 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_bool	process_str(t_form *f, va_list ap)
{
	t_bool	ret;
	char	*s;

	ret = FL;
	s = NULL;
	if (f->t == 1 || f->t == 10)
	{
		if (!dalloc((void **)(&s), 2, sizeof(char)))
			return (ret);
		s[0] = '%';
		if (f->t == 1)
			s[0] = (t_char)va_arg(ap, int);
		ret = prnt_str(f, s, FL);
		free_ptr((void **)(&s));
	}
	else if (f->t == 2)
		ret = prnt_str(f, va_arg(ap, char *), TR);
	return (ret);
}
