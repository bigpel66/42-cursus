/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_str_l.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 17:09:15 by jseo              #+#    #+#             */
/*   Updated: 2021/03/19 17:09:17 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bool	process_str_l(t_form *f, va_list ap)
{
	t_bool	ret;
	wchar_t	*s;

	ret = FL;
	s = NULL;
	if (f->t == 1 || f->t == 10)
	{
		if (!dalloc((void **)(&s), 2, sizeof(wchar_t)))
			return (ret);
		s[0] = '%';
		if (f->t == 1)
			s[0] = va_arg(ap, wint_t);
		if (s[0] >= 0)
			ret = prnt_wstr(f, s, 1);
		free_ptr((void **)(&s));
	}
	else if (f->t == 2)
		ret = prnt_wstr(f, va_arg(ap, wchar_t *), 1);
	return (ret);
}
