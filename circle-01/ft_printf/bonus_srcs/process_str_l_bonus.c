/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_str_l_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 17:09:15 by jseo              #+#    #+#             */
/*   Updated: 2021/03/22 09:32:02 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_bool	process_str_l(t_form *f, va_list ap)
{
	t_bool	ret;
	wchar_t	*s;

	ret = FL;
	s = NULL;
	if (f->t == 1)
	{
		if (!dalloc((void **)(&s), 2, sizeof(wchar_t)))
			return (ret);
		s[0] = (wchar_t)va_arg(ap, wint_t);
		f->dig = ft_wstrlen(s);
		if (f->dig)
			ret = prnt_wstr(f, s, FL);
		free_ptr((void **)(&s));
	}
	else if (f->t == 2 && MB_CUR_MAX == 4)
		ret = prnt_wstr(f, va_arg(ap, wchar_t *), TR);
	return (ret);
}
