/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:49:01 by jseo              #+#    #+#             */
/*   Updated: 2021/03/18 18:17:30 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bool	process_str(t_form *f, va_list ap)
{
	t_bool	ret;
	char	*s;

	ret = FL;
	s = NULL;
	if (f->t == 1 || f->t == 9)
	{
		if (!dalloc((void **)(&s), 2, sizeof(char)))
			return (ret);
		s[0] = '%';
		if (f->t == 1)
			s[0] = va_arg(ap, int);
		ret = prnt_str(f, s, 0);
		free_ptr((void *)(&s));
	}
	else if (f->t == 2)
		ret = prnt_str(f, va_arg(ap, char *), 1);
	return (ret);
}
